<?php

/**
   Overview page, displays the list of strings for translation
*/
function translation_dashboard_overview() {
  $output = drupal_get_form('translation_dashboard_form');

  return $output;
}

/**
   Form which contains the filters for searching translatable strings as well as the list of
   strings in a table.
*/
function translation_dashboard_form($form, &$form_state) {
  // do we already have filters for this user's session?
  $values = array_key_exists('translation_dashboard_filter', $_SESSION) ?
    $_SESSION['translation_dashboard_filter'] :
    array('context' => 'all', 'language' => 'all');

  $all = array('all' => t('All'));

  $contexts = array_merge($all, translation_dashboard_get_contexts());

  $form['context'] = array(
    '#type' => 'select',
    '#options' => $contexts,
    '#title' => t('Context'),
    '#default_value' => $values['context']
  );

  $languages = array_merge($all, translation_dashboard_languages());

  $form['language'] = array(
    '#type' => 'select',
    '#options' => $languages,
    '#title' => t('Language'),
    '#default_value' => $values['language']
  );

  $form['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Filter')
  );

  $form['translations'] = translation_dashboard_translations($values);

  return $form;
}

/**
   Store new filter settings in the user session
*/
function translation_dashboard_form_submit($form, &$form_state) {
  $_SESSION['translation_dashboard_filter'] = array(
    'context' => $form_state['values']['context'],
    'language' => $form_state['values']['language']
  );

  $form_state['rebuild'] = TRUE;
}

/**
   Get a list of translation contexts
*/
function translation_dashboard_get_contexts() {
  $contexts = array();
  $result = db_query("SELECT DISTINCT(context) AS context FROM {locales_source}");

  foreach ($result as $row) {
    if ($row->context == '') {
      $contexts['Global'] = 'Global';
    } else {
      $contexts[$row->context] = $row->context;
    }
  }

  return $contexts;
}

/**
   Generate the form API table showing translatable strings
*/
function translation_dashboard_translations($values) {
  $languages = translation_dashboard_languages();

  if (isset($values['language']) && $values['language'] != 'all') {
    $languages = array_intersect_key($languages, array($values['language'] => 0));
  }

  $header = array(
    array('data' => t('Source'), 'field' => 'ls.source', 'sort' => 'asc'),
    array('data' => t('Context'), 'field' => 'ls.context', 'sort' => 'asc'),
  );

  foreach ($languages as $lang) {
    $header[] = array(
      'data' => $lang
    );
  }

  $rows = translation_dashboard_search($values, $header);

  $output = array(
    'results' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows
    ),
    'pager' => array(
      '#theme' => 'pager'
    )
  );

  return $output;
}

/**
   Perform a search for translatable strings
   @param $values The filter values
   @param $header The table headings (needed for TableSort)
*/
function translation_dashboard_search($values, $header) {

  /**
     This is a slightly complex query.  We do our filtering on the locales_source table, but we also do a
     LEFT JOIN on the locales_target table in order to pull in details of available translations.
     We then use GROUP BY and GROUP_CONCAT to give us a single result row for each source string, with
     a comma-separated list of languages for which translations exist.
   */
  $query = db_select('locales_source', 'ls')
    ->extend('PagerDefault')->limit(50)
    ->extend('TableSort')->orderByHeader($header)
    ->fields('ls', array('lid', 'source', 'context'))
    ->groupBy('ls.lid');

  $query->leftJoin('locales_target', 'lt', 'ls.lid = lt.lid');
  // GROUP_CONCAT will give us a comma-separated list of 'language' fields in the locales_target table
  // which were LEFT JOINed
  $query->addExpression('GROUP_CONCAT(lt.language)', 'languages');

  if ($values['context'] != 'all') {
    if ($values['context'] == 'Global') {
      $query->condition('ls.context', '', '=');
    } else {
      $query->condition('ls.context', $values['context'], '=');
    }
  }

  $result = $query->execute();

  $languages = translation_dashboard_languages();
  if (isset($values['language']) && $values['language'] != 'all') {
    $languages = array_intersect_key($languages, array($values['language'] => 0));
  }

  $rows = array();

  foreach ($result->fetchAll() as $result) {
    $row = array(
      'source' => $result->source,
      'context' => $result->context
    );

    if ($row['context'] == '') { $row['context'] = 'Global'; }

    // figure out if we have translations by seeing which languages are in that comma-separated field
    $translated_languages = explode(',', $result->languages);

    foreach ($languages as $key => $lang) {
      // @todo redirect back to overview
      $edit_url = 'admin/config/regional/translate/edit/' . $result->lid . '/' . $key;
      if (array_search($key, $translated_languages) !== FALSE) {
        $row[$key] = l('Y', $edit_url);
      } else {
        $row[$key] = l('N', $edit_url);
      }
    }

    $rows[] = $row;
  }

  return $rows;
}

/**
   Get the list of languages which are translation targets. Basically just filter out 'en'
   @todo filter by domain/permissions too?
*/
function translation_dashboard_languages() {
  return array_diff_key(locale_language_list(), array('en' => 0));
}

/**
   Form for editing of individual translations
   @param $lid the string ID
   @param $lang the language to translate to
*/
function translation_dashboard_edit_form($form, &$form_state, $lid, $lang) {
  $query = db_select('locales_source', 'ls')
    ->fields('ls')
    ->condition('ls.lid', $lid, '=');

  $source = $query->execute()->fetchObject();

  $lang_name = locale_language_name($lang);

  $form['original'] = array(
    '#type' => 'textarea',
    '#title' => t('Original'),
    '#value' => $source->source,
    '#disabled' => TRUE
  );

  $form['new'] = array(
    '#type' => 'textarea',
    '#title' => t('Translation into %lang', array('%lang' => $lang_name)),
    '#default_value' => locale($source->source, $source->context, $lang)
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );

  $form_state['lang'] = $lang;
  $form_state['lid'] = $lid;

  return $form;
}

function translation_dashboard_edit_form_submit($form, &$form_state) {
  $query = db_select('locales_target', 'lt')
    ->fields('lt', array('translation'))
    ->condition('lt.lid', $form_state['lid'], '=')
    ->condition('lt.language', $form_state['lang'], '=');

  if ($query->execute()->fetchField()) {
    // translation exists, update
    db_update('locales_target')
      ->fields(array('translation' => $form_state['values']['new']))
      ->condition('lid', $form_state['lid'], '=')
      ->condition('language', $form_state['lang'], '=')
      ->execute();
  } else {
    db_insert('locales_target')
      ->fields(array(
          'lid' => $form_state['lid'],
          'language' => $form_state['lang'],
          'translation' => $form_state['values']['new']
        ))
      ->execute();
  }

  $form_state['rebuild'] = TRUE;
}