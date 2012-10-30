<?php

/**
 * This form is purely for Live Registration 
 * @param type $form
 * @param type $form_state
 * @param type $country
 * @return string 
 */
function cmc_appforms_config_settings_form($form, $form_state, $form_type, $country_id) {
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");
  $subforms = array();

  $application_type = ($form_type == 'live') ? CMC_APPFORMS_LIVE_REG : CMC_APPFORMS_DEMO_REG;
  
  $countries = cmc_appforms_country_load();
  
  foreach($countries as $key => $country) {
    $country_options[$key] = $country->name;
  }
  $form['form_type'] = array(
    '#type' => 'hidden',
    '#default_value' => $form_type
  );
  
  $form['country_set'] = array(
    '#title' => t('Select Country from dropdown'),
    '#type' => 'fieldset',
    '#tree' => FALSE,
  ); 
  
  $form['country_set']['country_id'] = array(
    '#type' => 'select',
    '#title' => t('Select Country'),
    '#options' => $country_options,
    '#default_value' => !empty($country_id) ? $country_id : "",
  );
  
  $form['country_set']['filter'] = array(
    '#type' => 'submit',
    '#title' => t('Filter'),
    '#value' => t('Filter'),
    '#submit' => array('cmc_appforms_config_settings_form_filter'),
  );

  // Once a region is selected, we are aware of what template it uses and also the 
  // features that are to be supported for that template
  if ((!$country_id) || $country_id == NULL) return $form;
  
  // We need some hidden variables to  identify country machine & product id etc
  
  $template = cmc_appforms_template_load($countries[$country_id]->template_id);
  $features = unserialize($template['data']);
  $formClasses = cmc_appforms_allforms($application_type) ;
  
  $form['application_type'] = array('#type' => 'value', '#value' => $application_type);
  $form['country_machine_name'] = array('#type' => 'value', '#value' => $countries[$country_id]->machine_name);
 
  $products = explode(',', $countries[$country_id]->product);
  
  // Foreach product and country, Loop through all modules / classes that have 
  // Extended liveRegistration and demoRegistration
  foreach ($products as $product) {
    if(!$product) continue;
    
    $appFormConfig = new AppFormConfig($countries[$country_id]->machine_name, $product, $application_type);
    
    $form["product_{$product}"] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings for :product', array(':product' => $product)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach($formClasses as $formClass) {
      foreach($features as $fid => $feature) {
        if (($feature) && (method_exists($formClass, "getSettingsForm"))) {
          $elements = $formClass->getSettingsForm($fid, $appFormConfig);
          if ($elements) {
            $form["product_{$product}"] = array_merge($form["product_{$product}"], $elements);
          }
        }
      }
    }
  }
  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save @form_type configuration', array('@form_type' => $form_type)),
    '#submit' => array('cmc_appforms_config_settings_form_submit'),
  );
   return $form;
}

function cmc_appforms_config_settings_form_submit($form, &$form_state) {
  $application_type = $form_state['values']['application_type'];
  $country_machine_name = $form_state['values']['country_machine_name'];
  $product_values = array();
  // Parse through values and prepare seperate arrays for each product

  foreach(cmc_appforms_product_type() as $product_id => $product) {
    $product_values = _cmc_appforms_extract_form_product_values($product_id, $form_state['values']);

    $appFormConfig = new AppFormConfig($country_machine_name, $product_id, $application_type);
    $appFormConfig->setConfig($product_values);
    $appFormConfig->save();
  }
}

function cmc_appforms_config_settings_form_filter($form, &$form_state) {
  drupal_goto('admin/config/appforms/registration/'. $form_state['values']['form_type'] .'/' .$form_state['values']['country_id']);
}