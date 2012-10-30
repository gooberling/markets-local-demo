<?php

/**
 * Create and Update a configuration template
 * @param type $form
 * @param type $form_state
 * @param type $template_id
 * @return type 
 */
function cmc_appforms_templates_settings($form, $form_state, $template_id = NULL) {
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
  
   $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#default_value' => !empty($template) ? $template['machine_name'] : NULL,
    '#required' => TRUE,
      '#machine_name' => array(
      'source' => array('template_name'),
      'exists' => 'cmc_appforms_template_check_machine_name',
    ),
    '#default_value' => !empty($template) ? $template['machine_name'] : "",
    '#disabled' => !empty($template['name']),
  );
  
  foreach(cmc_appforms_get_application_features() as $item) {
    foreach($item['features'] as $key => $feature) {
      $keys[$key] = $feature;
    }
  }

  $form['feature'] = array(
    '#type' => 'fieldset',
    '#title' => t('Features'),
  );
  
  $form['feature']['features'] = array(
    '#type' => 'checkboxes',
    '#options' => $keys,
    '#default_value' => !empty($template) ? unserialize($template['data']) : array(),
 
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

/**
 * Submit handler for cmc_appforms_templates_settings
 * @param type $form
 * @param type $form_state 
 */
function cmc_appforms_templates_settings_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['template_id'])) {
    db_update('cmc_appforms_templates')
      ->fields(
      array(
        'name' => $form_state['values']['template_name'],
        'data' => serialize($form_state['values']['features']),
        'machine_name' => $form_state['values']['machine_name'],
      ))
      ->condition('template_id', $form_state['values']['template_id'], '=') 
      ->execute();
  } 
  else {
    db_insert('cmc_appforms_templates')
    ->fields(
      array(
        'name' => $form_state['values']['template_name'],
        'machine_name' => $form_state['values']['machine_name'],
        'data' => serialize($form_state['values']['features']),
      ))
    ->execute();
  }
  
  drupal_goto('admin/config/appforms/countries/templates');
}


/** 
 * List of regions themed as table
 * @return type]
 */
function _cmc_appforms_templates() {
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");
  
  $rows = array();
  $header = array(
    'name' => array('data' => t('Name (Machine Name)'), 'field' => 'r.name', 'sort' => 'desc'),
  );
  
  $features = cmc_appforms_get_application_features();
  
  
  foreach( $features as $item) {
    foreach($item['features'] as $key => $feature) {
      $header[$key] = array('data' => $feature);
    }
  }
  
  $result = db_select('cmc_appforms_templates', 'r') 
    ->fields('r', array('template_id', 'machine_name', 'name', 'data'))
    ->extend('PagerDefault')->extend('TableSort')
    ->limit(50)
    ->orderByHeader($header)
    ->execute();
  
  while($template = $result->fetchAssoc()) {
    $row = array(
      'name' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $template['name'] .' (' .$template['machine_name']  .')',
          '#href' => 'admin/config/appforms/countries/templates/' .$template['template_id'], 
          '#suffix' => ' ',
        ),
      ),
    );
  
    $data = unserialize($template['data']);
    foreach( $features as $item) {
      foreach($item['features'] as $key => $feature) {
        if (in_array($key, $data)) {
          $row[$key] = array('data' => ($data[$key]) ? t('Yes') : t('No'));
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
  drupal_goto("admin/config/appforms/countries/templates");
}


/**
 * Settings for regions
 * @return string
 */
function cmc_appforms_region_settings_form($form, $form_state, $country_id = NULL) {
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");
  global $language;
  $form = array();
  $templates = array();
  
  foreach(cmc_appforms_template_load() as $template) {
    $templates[$template->template_id] = $template->name;
  }
  
  if (empty($templates)) {
    drupal_set_message(t("No templates found, Please !create_template before adding country", array('!create_template' => l("Create a template", "admin/config/appforms/countries/templates"))) , "error");
    return $form;
  }
  
  
  if ($country_id) {
    $country = cmc_appforms_country_load($country_id);

    $form['country_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $country_id,
    );
  }

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of country'),
    '#default_value' => !empty($country) ? $country['name'] : NULL,
    '#required' => TRUE,

  );
  
  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#default_value' => !empty($country) ? $country['machine_name'] : "",
    '#required' => TRUE,
      '#machine_name' => array(
      'source' => array('name'),
      'exists' => 'cmc_appforms_country_check_machine_name',
    ),
    '#default_value' => !empty($country) ? $country['machine_name'] : "",
    '#disabled' => !empty($country['name']),
  );
    
  $form['prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('prefix to be used for the region'),
    '#description' => t('Prefix is used to create unique URL path for country forms. E.g if prefix is <strong>UK</strong>, then live registration form for CFD shall be available at <strong>/uk/registration/cfd</strong>'),  
    '#required' => TRUE,
    '#default_value' => !empty($country) ? $country['prefix'] : NULL,
  );
  
  foreach(language_list() as $key=>$item) {
    $languages[$item->language] = $item->name .' (' .$item->language .')';
  }
  $form['language'] = array(
    '#type' => 'select',
    '#options' => $languages,
    '#title' => t('Default language for the region/ country'),
    '#required' => TRUE,
    '#default_value' => !empty($country) ? $country['language'] : NULL,
  );   
  
  $form['product'] = array(
    '#type' => 'checkboxes',
    '#options' => cmc_appforms_product_type(),
    '#title' => t('Languages form can be viewed in'),
    '#required' => TRUE,
    '#default_value' => !empty($country) ? explode(',',($country['product'])) : array(),
  ); 

  $form['display_language'] = array(
    '#type' => 'checkboxes',
    '#options' => $languages,
    '#title' => t('Languages form can be viewed in'),
    '#required' => TRUE,
    '#default_value' => !empty($country) ? unserialize($country['display_language']) : array(),
  );   
  
  $form['context'] = array(
    '#type' => 'textfield',
    '#title' => t('Context'),
    '#description' => t('Is used identify the context each traslatable string is displayed within application form, Maximum of 60 characters'),
    '#required' => TRUE,
    '#maxlength' => 60,
    '#default_value' => !empty($country) ? $country['context'] : NULL,
  );  
  
  
  $form['template_id'] = array(
    '#type' => 'select',
    '#title' => t('Choose config template for the region'),
    '#options' => $templates ,
    '#default_value' => !empty($country) ? $country['template_id'] : NULL,
    '#required' => TRUE,
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
    '#markup' => _cmc_get_countries(),
    '#suffix' =>'</div>',
  );
    
  return $form;
}


/*
 * Submit handler for region settings form
 */
function cmc_appforms_region_settings_form_submit($form, $form_state) {
  if (!empty($form_state['values']['country_id'])) {
    dsm($form_state['values']['country_id']);
    dsm($form_state);
    db_update('cmc_appforms_country')
      ->fields(
      array(
        'name' => $form_state['values']['name'],
        'machine_name' => $form_state['values']['machine_name'],
        'prefix' => $form_state['values']['prefix'],
        'language' => $form_state['values']['language'],
        'template_id' => $form_state['values']['template_id'],
        'display_language' => serialize($form_state['values']['display_language']),
        'context' => $form_state['values']['context'],
        'product' => implode(',' , $form_state['values']['product']),
      ))
      ->condition('country_id', $form_state['values']['country_id']) 
      ->execute();
  } 
  else {
    db_insert('cmc_appforms_country')
    ->fields(
      array(
        'name' => $form_state['values']['name'],
        'prefix' => $form_state['values']['prefix'],
        'machine_name' => $form_state['values']['machine_name'],
        'language' => $form_state['values']['language'],
        'template_id' => $form_state['values']['template_id'],
        'display_language' => serialize($form_state['values']['display_language']),
        'context' => $form_state['values']['context'],
        'product' => implode(',' , $form_state['values']['product']),
      ))
    ->execute();
  }
}


/** 
 * List of regions themed as table
 * @return type]
 */
function _cmc_get_countries() {
  $rows = array();
  $header = array(
    'name' => array('data' => t('Name'), 'field' => 'r.name', 'sort' => 'desc'),
    'machine_name' => array('data' => t('Machine name'), 'field' => 'r.machine_name'),  
    'prefix' => array('data' => t('Prefix'), 'field' => 'r.prefix'),
    'language' => array('data' => t('Language'), 'field' => 'r.language', 'sort' => 'desc'),
    'display_language' => array('data' => t('Display language'), 'field' => 'r.display_language'),
    'product' => array('data' => t('Product'), 'field' => 'r.product'),
    'context' => array('data' => t('Context'), 'field' => 'r.context'),
    'template_id' => array('data' => t('template'), 'field' => 'r.template_id', 'sort' => 'desc')
  );
 
  
  $query = db_select('cmc_appforms_country', 'r')
           ->extend('PagerDefault')->extend('TableSort')
           ->limit(50)
           ->orderByHeader($header);
  
  $query->join('cmc_appforms_templates', 't', 'r.template_id = t.template_id');
  $query->fields('r', array('country_id', 'name', 'machine_name', 'prefix', 'language', 'display_language', 'product', 'context' ,'template_id'));
  $query->fields('t', array('name'));
           
  $result = $query->execute();
  
  
  while($region = $result->fetchAssoc()) {
    $display_languages = array();
    $languages = unserialize($region['display_language']) ;
    //dsm($languages);
    foreach($languages as $key => $val) {
       if($val) {
         
         array_push($display_languages, $key);
       }
    }
    $display_languages = implode(',', $display_languages);
    $rows[] = array(
      'name' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $region['name'],
          '#href' => 'admin/config/appforms/countries/' .$region['country_id'], 
          '#suffix' => ' ',
        ),
      ),
      'machine_name' => $region['machine_name'],  
      'prefix' => $region['prefix'],
      'language' => $region['language'],
      'display_language' => $display_languages,
      'product' => $region['product'],
      'context' => $region['context'],
      'template_id' => $region['t_name'],
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
  db_delete("cmc_appforms_country")
    ->condition('country_id', $form_state['values']['region_id'], '=')
    ->execute();
  drupal_goto("admin/config/appforms/countries");
}