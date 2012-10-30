<?php

//Implements hook_menu() 

function _locale_revisions_dashboard($status = LOCALE_REVISIONS_DRAFT) {
  $path = explode('/', request_path());
  $status = (isset($path[5]))? $path[5] : FALSE;
 
  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Workflow state'),
    '#default_value' => $status,
    '#options' => array(
      LOCALE_REVISIONS_DRAFT => t('Draft') ,
      LOCALE_REVISIONS_PUBLISHED => t('Published')
    ),
  );
  $form['fitler'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  
  module_load_include('inc', 'locale_revisions', 'locale_revisions');
  $rows = _locale_strings($status);
  
  // Display list of rows themed as table
  $header = array(
    'Revision' => array('data' => t('Revision'), 'field' => 'lr.rid', 'sort' => 'desc'),
    'Updated' => array('data' => t('Author'), 'field' => 'lr.uid'),
    'changed' => array('data' => t('Updated'), 'field' => 'lr.updated', 'sort' => 'desc'),
    'status' => array('data' => t('Status')),
    'operations' => array('data' => t('Operations'))
  );
  
  
  $form['translations'] = array(
    '#type' => 'markup',
    '#markup' => _locale_strings($status) ,
  );
  return $form;
}


function _locale_revisions_dashboard_submit($form, &$form_state) {
  drupal_goto("admin/config/regional/translate/dasbboard/" .$form_state['values']['status']);
}


/**
 * Revert to an existing string.
 * @param type $form
 * @param type $form_state
 * @param type $rid
 * @return string 
 */
function locale_revisions_revert($form, &$form_state , $rid) {
  
  //Include inc file
  module_load_include('inc', 'locale_revisions', 'locale_revisions');
  $revision = _locale_revisions_get_revision($rid);
  $form['original'] = array(
    '#type'  => 'item',
    '#title' => t('Original text'),
    '#markup' => check_plain(wordwrap($revision['original']['source'], 0)),
  );
  $form['lid'] = array(
    '#type'  => 'value',
    '#value' => $revision['original']['lid'],
  );
  $form['rid'] = array(
    '#type'  => 'value',
    '#value' => $rid
  );

  // Prepare table of all translations related to the revision
  $header = array(
    'title' => array('data' => t('Language')),
    'translation' => array('data' => t('Translation'), ),
  );

  $data = theme('table', array(
  'header' => $header,
  'rows' => $revision['translated'],
  'attributes' => array('class' => array('mytable'))
  ));
  
  $form['translations'] = array('#markup' => $data);
  
  $form['cancel'] = array (
    '#type' => 'submit',
    '#access' => TRUE,
    '#value' => 'Cancel',     
    '#submit' => array('locale_revisions_cancel') //This is the name of a function reproduced below
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Publish'),
    '#submit' => array('locale_revisions_publish'),
  );
  return $form;
}

/**
 * Edit interface for editing a revision
 * @param type $rid 
 */
function locale_revisions_edit_form($form, &$form_state, $rid) {
  // Fetch source string, if possible.
  
  module_load_include('inc', 'locale_revisions', 'locale_revisions');
  
  $revision = _locale_revisions_get_revision($rid); 
  
  if (!$revision) {
    drupal_set_message(t('String not found.'), 'error');
    drupal_goto('admin/config/regional/translate/dasbboard');
  }
  
  $form['original'] = array(
    '#type'  => 'item',
    '#title' => t('Original text'),
    '#markup' => check_plain(wordwrap($revision['original']['source'], 0)),
  );
  
  $form['context'] = array(
    '#type'  => 'item',
    '#title' => t('Context'),
    '#markup' => check_plain(wordwrap($revision['original']['context'], 0)),
  );
 
  // Add original text to the top and some values for form altering.
  $form['lid'] = array(
    '#type'  => 'value',
    '#value' => $revision['original']['lid'],
  );
  
  $form['rid'] = array(
    '#type'  => 'value',
    '#value' => $rid
  );
  
  // Include default form controls with empty values for all languages.
  // This ensures that the languages are always in the same order in forms.
  $languages = language_list();
  $default = language_default();
  // We don't need the default language value, that value is in $source.
  $omit = $revision['original']['textgroup'] == 'default' ? 'en' : $default->language;
  unset($languages[($omit)]);
  
  $form['translations'] = array('#tree' => TRUE);
  // Approximate the number of rows to use in the default textarea.
  $rows = min(ceil(str_word_count($revision['original']['source']) / 12), 10);
  foreach ($languages as $langcode => $language) {
    $form['translations'][$langcode] = array(
      '#type' => 'textarea',
      '#title' => t($language->name),
      '#rows' => $rows,
      '#default_value' => '',
    );
  }

  // Fetch revisions and fill in default values in the form.
  
  foreach($revision['translated'] as $key => $item) {
     $form['translations'][$item[0]]['#default_value'] = $item[1];
  }
  
  // Based on current user permissions provide ability to save translation in different workflow states
  if (user_access('Publish translations')) {
    $form['published'] = array(
      '#type' => 'radios',
      '#title' => t('Workflow state'),
      '#default_value' => LOCALE_REVISIONS_DRAFT,
      '#options' => array(
        LOCALE_REVISIONS_DRAFT => t('Draft') ,
        LOCALE_REVISIONS_PUBLISHED => t('Published')
      ),
    );
  } 
  else {
    $form['published'] = array(
      '#type'  => 'value',
      '#value' => LOCALE_REVISIONS_DRAFT,
    );
  }
  

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
      '#type' => 'submit', 
      '#value' => t('Save Revision'),
      '#submit' => array('locale_revisions_submit'),
      );
  return $form;
}


/**
 * 
 * @param type $form
 * @param type $form_state 
 */
function locale_revisions_publish($form, &$form_state) {
  global $user;
  
  //Step 1 update locales_target table with data related to this revision 
  // Prepare table of all translations related to the revision
  $result = db_select('locales_revisions', 'lr')
    ->fields('lr')
    ->condition('lr.rid', $form_state['values']['rid'], '=')
    ->execute();  
  
  while($record = $result->fetchAssoc()) {
    // Check if the string already has a translated version 
    $translation = db_query("SELECT translation FROM {locales_target} WHERE lid = :lid AND language = :language", array(':lid' => $form_state['values']['lid'], ':language' => $record['language']))->fetchField();
    // Only update or insert if we have a value to use.
    if (!empty($translation)) {
      db_update('locales_target')
        ->fields(array(
          'translation' => $record['translation'],
          ))
        ->condition('lid', $form_state['values']['lid'])
        ->condition('language', $record['language'])
        ->execute();
      }
      else {
        db_insert('locales_target')
          ->fields(array(
            'lid' => $form_state['values']['lid'],
            'translation' => $record['translation'],
            'language' => $record['language'],
          ))
          ->execute();
      }
  }
  
  //Step 2 update the pointer in locales_revisions_index
  db_update('locales_revisions_index')
    ->fields(array('current' => LOCAL_REVISIONS_CURRENT_FALSE,))
    ->condition('lid', $form_state['values']['lid'])
    ->execute();
  
  db_update('locales_revisions_index')
    ->fields(array('current' => LOCAL_REVISIONS_CURRENT_TRUE, 'uid' => $user->uid, 'status' => LOCALE_REVISIONS_PUBLISHED ))
    ->condition('rid', $form_state['values']['rid'])
    ->condition('lid', $form_state['values']['lid'])
    ->execute();
  
  //Redirect to revisions edit form
  locale_revisions_goto_lid($form_state['values']['lid']);
}