<?php

function cmc_appforms_templates_settings_add($form, $form_state, $template_id = NULL) {
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");

  if ($template_id) {
    $template = cmc_appforms_template_load($template_id);
        
    $form['template_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $template_id,
    );

  }
 
  $form['template_name'] = array(
    '#type' => 'textfield',
    '#title' => t("Title of new template"),
    '#default_value' => !empty($template) ? $template['name'] : "",
    '#required' => TRUE,
  );
  
  foreach(cmc_appforms_get_application_features() as $item) {
    foreach($item['features'] as $key => $feature) {
      $keys[$key] = $feature['name'];
    }
  }

  $form['feature'] = array(
    '#type' => 'fieldset',
    '#title' => t('Features'),
  );
  $form['feature']['features'] = array(
    '#type' => 'checkboxes',
    '#options' => $keys,
    '#default_value' => !empty($template) ? unserialize($template['data']) : "",
    '#required' => TRUE,
  );
  
  $form['Save'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration template'),
    '#submit' => array('cmc_appforms_templates_settings_form_submit'),
  );
  
  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('cmc_appforms_templates_settings_delete'),
  );
  
  
  $form['regions'] = array(
    '#prefix' => "<div>",
    '#type' => 'markup',
    '#markup' => _cmc_appforms_templates(),
    '#suffix' =>'</div>',
  );
    
  
  
 return $form;
}


function cmc_appforms_templates_settings_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['template_id'])) {
    db_update('cmc_appforms_templates')
      ->fields(
      array(
        'name' => $form_state['values']['template_name'],
        'data' => serialize($form_state['values']['features']),
      ))
      ->condition('template_id', $form_state['values']['template_id'], '=') 
      ->execute();
  } 
  else {
    db_insert('cmc_appforms_templates')
    ->fields(
      array(
        'name' => $form_state['values']['template_name'],
        'data' => serialize($form_state['values']['features']),
      ))
    ->execute();
  }
  
  drupal_goto('admin/config/appforms/regions/templates');
}


/** 
 * List of regions themed as table
 * @return type]
 */
function _cmc_appforms_templates() {
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");
  
  $rows = array();
  $header = array(
    'name' => array('data' => t('Name'), 'field' => 'r.name', 'sort' => 'desc'),
  );
  
  $features = cmc_appforms_get_application_features();
  
  foreach( $features as $item) {
    foreach($item['features'] as $key => $feature) {
      $header[$key] = array('data' => $feature['name']);
    }
  }
  
  $result = db_select('cmc_appforms_templates', 'r') 
    ->fields('r', array('template_id', 'name', 'data'))
    ->extend('PagerDefault')->extend('TableSort')
    ->limit(50)
    ->orderByHeader($header)
    ->execute();
  
  while($template = $result->fetchAssoc()) {
    $row = array(
      'name' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $template['name'],
          '#href' => 'admin/config/appforms/regions/templates/' .$template['template_id'], 
          '#suffix' => ' ',
        ),
      ),
    );
  
    $data = unserialize($template['data']);
    foreach( $features as $item) {
      foreach($item['features'] as $key => $feature) {
        if (in_array($key, $data)) {
          $row[$key] = array('data' => t('Yes'));
        }
      }
    }
    
    $rows[] = $row;  
  }
  
  $data = theme('table', array(
  'header' => $header,
  'rows' => $rows,
  'attributes' => array('class' => array('mytable'))
  ));
  
  return $data .theme('pager', array('tags' => array()));
}

function cmc_appforms_templates_settings_delete($form, $form_state) {
  db_delete("cmc_appforms_templates")
    ->condition('template_id', $form_state['values']['template_id'], '=')
    ->execute();
  drupal_goto("admin/config/appforms/regions/templates");
}


/**
 * Settings for regions
 * @return string
 */
function cmc_appforms_region_settings_form($form, $form_state, $region_id = NULL) {
  global $language;
  $form = array();
  
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");
  
  if ($region_id) {
    $region = cmc_appforms_country_load($region_id);
    
    $form['region_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $region_id,
    );
  }
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of region'),
    '#default_value' => !empty($region) ? $region['name'] : "",
    '#required' => TRUE,
  );
    
  $form['prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('prefix to be used for the region, shall be used to form url pattern eg. /en/registration/cfd'),
    '#required' => TRUE,
    '#default_value' => !empty($region) ? $region['prefix'] : "",
  );
  
  foreach(language_list() as $key=>$item) {
    $languages[$item->language] = $item->name;
  }
  $form['language'] = array(
    '#type' => 'select',
    '#options' => $languages,
    '#title' => t('Default language for the region/ country'),
    '#required' => TRUE,
    '#default_value' => !empty($region) ? $region['language'] : $language->language,
  );   
  
  foreach(cmc_appforms_template_load() as $template) {
    $templates[$template->template_id] = $template->name;
  }
  
  
  $form['config_template'] = array(
    '#type' => 'select',
    '#title' => t('Choose config template for the region'),
    '#options' => $templates ,
    '#default_value' => !empty($region) ? $region['template_id'] : "",
  );
  

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('cmc_appforms_region_settings_form_submit'),
  );
 
  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('cmc_appforms_region_settings_delete'),
  );
  
  
  $form['regions'] = array(
    '#prefix' => "<div>",
    '#type' => 'markup',
    '#markup' => _cmc_get_regions(),
    '#suffix' =>'</div>',
  );
    
  return $form;
}

/**
 * Submit handler for filter
 * @param type $form_id
 * @param type $form_state 
 */
function cmc_appforms_settings_form_filter($form_id, &$form_state) {
  $args = func_get_args();
  drupal_goto('admin/config/appforms/registration/' .$form_state['values']['region_id']);
  
}


/*
 * Submit handler for region settings form
 */
function cmc_appforms_region_settings_form_submit($form, $form_state) {
  if (!empty($form_state['values']['region_id'])) {
    db_update('cmc_appforms_region')
      ->fields(
      array(
        'name' => $form_state['values']['name'],
        'prefix' => $form_state['values']['prefix'],
        'language' => $form_state['values']['language'],
      ))
      ->condition('region_id', $form_state['values']['region_id']) 
      ->execute();
  } 
  else {
    db_insert('cmc_appforms_region')
    ->fields(
      array(
        'name' => $form_state['values']['name'],
        'prefix' => $form_state['values']['prefix'],
        'language' => $form_state['values']['language'],
      ))
    ->execute();
  }
}


/** 
 * List of regions themed as table
 * @return type]
 */
function _cmc_get_regions() {
  $rows = array();
  $header = array(
    'name' => array('data' => t('Name'), 'field' => 'r.name', 'sort' => 'desc'),
    'prefix' => array('data' => t('Prefix'), 'field' => 'r.prefix'),
    'language' => array('data' => t('Language'), 'field' => 'r.language', 'sort' => 'desc'),
  );
  
  
  $result = db_select('cmc_appforms_region', 'r') 
    ->fields('r', array('region_id', 'name', 'prefix', 'language'))
    ->extend('PagerDefault')->extend('TableSort')
    ->limit(50)
    ->orderByHeader($header)
    ->execute();
  
  while($region = $result->fetchAssoc()) {
    $rows[] = array(
      'name' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $region['name'],
          '#href' => 'admin/config/appforms/regions/' .$region['region_id'], 
          '#suffix' => ' ',
        ),
      ),
      'prefix' => $region['prefix'],
      'language' => $region['language'],
    );
  }
  
  $data = theme('table', array(
  'header' => $header,
  'rows' => $rows,
  'attributes' => array('class' => array('mytable'))
  ));
  
  return $data .theme('pager', array('tags' => array()));
}


/**
 * Sumit handler for delete function
 * @param type $form
 * @param type $form_state 
 */
function cmc_appforms_region_settings_delete($form, $form_state) {
  db_delete("cmc_appforms_region")
    ->condition('region_id', $form_state['values']['region_id'], '=')
    ->execute();
  drupal_goto("admin/config/appforms/regions");
}