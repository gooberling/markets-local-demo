<?php

function cmc_appforms_live_form($form_id, $form_state, $machine_name, $product, $application_type)  {
  global $language;

  $config = cmc_appforms_get_config_by_country($machine_name, $application_type, $product);
  $country = cmc_appforms_load_country_machine_name($machine_name);
  
  $config['data'] = unserialize($config['data'] );
  
  $js_config = array(
    'product' => $product,
    'language' => $language->language,
    'application_type' => $application_type,
    'config' => $config,
  );
  

  drupal_add_js(array('cmcOnBoarding' => $js_config),
    array(
      'type' => 'setting',
      'every_page' => FALSE
    ));
  
  
  
  
  // Create a new AppFormConfig object
  $appFormConfig = new AppFormConfig($machine_name, $product, $application_type);
  $template = cmc_appforms_template_load($country['template_id']);
  $features = unserialize($template['data']);

  $formClasses = cmc_appforms_allforms($application_type) ;
  
  $form['application_type'] = array('#type' => 'value', '#value' => $application_type);
  $form['country_machine_name'] = array('#type' => 'value', '#value' => $country['machine_name']);

  // Foreach product and country, Loop through all modules / classes that have 
  // Extended liveRegistration and demoRegistration
  
  $template = cmc_appforms_template_load($country['template_id']);
  $features = unserialize($template['data']);
    
  $appFormConfig = new AppFormConfig($country['template_id'], $product, $application_type);
    
  module_load_include('inc', 'cmc_appforms', 'includes/cmc_appforms.misc');
  
  foreach($formClasses as $formClass) {
    foreach($features as $fid => $feature) {
      if (($feature) && (method_exists($formClass, "getSettingsForm"))) {
        $elements = $formClass->getApplicationForm($fid, $appFormConfig);
        if ($elements) {
          $form = array_merge($form, $elements);
        }
      }
    }
  }

  return $form;
}