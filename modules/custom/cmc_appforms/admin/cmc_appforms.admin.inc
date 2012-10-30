<?php

function cmc_appforms_settings_form($form, &$form_state, $region_id) {

  $form = array();
  module_load_include("inc", "cmc_appforms", "includes/cmc_appforms");
  
  $countries = cmc_appforms_country_load();
  
  foreach($countries as $key => $country) {
    $country_options[$key] = $country->name;
  }
  
  $form['country_set'] = array(
    '#title' => t('Select Country from dropdown'),
    '#type' => 'fieldset',
    '#tree' => FALSE,
  ); 
  $form['country_set']['country_id'] = array(
    '#type' => 'select',
    '#title' => t('Select country'),
    '#options' => $country_options,
  );
  
  $form['country_set']['filter'] = array(
    '#type' => 'submit',
    '#title' => t('Filter'),
    '#value' => t('Filter'),
    '#submit' => array('cmc_appforms_settings_form_filter'),
  );
  
  if (empty($region_id)) return $form;

    $form['cmc_appforms_region_url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL Logo should point to'),
      '#description' => t('URL logo should point to, enter full url starting with http://'),
      '#default_value' => variable_get('cmc_appforms_region_url', NULL),
    );

    $form['cmc_appforms_country_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Country code for this site'),
      '#description' => t('Enter the country code for this site, e.g. GBR'),
      '#default_value' => variable_get('cmc_appforms_country_code', '')
    );

    $form['cmc_appforms_currency'] = array(
      '#type' => 'textfield',
      '#title' => t('Currency code'),
      '#description' => t('Enter the currency code for this site, e.g. GBP'),
      '#default_value' => variable_get('cmc_appforms_currency'),
    );

    $form['cmc_appforms_error_node'] = array(
      '#type' => 'textfield',
      '#title' => t('ID of the node containing text to display in case of catastrophic failure'),
      '#default_value' => variable_get('cmc_appforms_error_node')
    );

    $form['cmc_appforms_pdf_server_url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL of pdf generation service'),
      '#description' => t('Provide full URL of pdf generation service'),
      '#default_value' => variable_get('cmc_registation_pdf_server_url', 'https://svcffe1-https-hdev3.mycmc.co.uk:24003/blazedsmain/xml-xslt-pdf-generator/?REPORT_TYPE=LIVE_ACCOUNT_REGISTRATION_REPORT'),

    );

    $form['cmc_appforms_error_pdf'] = array(
      '#type' => 'textfield',
      '#title' => t('ID of the node containing text to display in case of PDF failure'),
      '#default_value' => variable_get('cmc_appforms_error_pdf', ''),
    );

    $form['cmc_appforms_error_pdf'] = array(
      '#type' => 'textfield',
      '#title' => t('ID of the node containing text to display in case of PDF failure'),
      '#default_value' => variable_get('cmc_appforms_error_pdf', ''),
    );

    foreach (cmc_appforms_product_type() as $type => $product) {
      $form[$type] = array(
        '#type' => 'fieldset',
        '#title' => t('LEGAL settings for :product Product', array(':product' => $product )), 
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,  
      );

      $form[$type]['business_doc_name_'.$type] = array(
        '#type' => 'textfield',
        '#title' => t('Business Doc Name for :product', array(':product' => $product)),
        '#default_value' => variable_get('cmc_registration_riskwarning_'.$type),
      );
     
      $form[$type]['business_doc_version_'.$type] = array(
        '#type' => 'textfield',
        '#title' => t('Business Doc Version for :product', array(':product' => $product)),
        '#default_value' => variable_get('cmc_registration_riskwarning_'.$type),
      );
    }

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
      '#submit' => array('cmc_appforms_settings_form_submit'),

    );

  return $form;
}


function cmc_appforms_settings_form_filter($form_id, &$form_state) {
  drupal_goto('admin/config/appforms/registration/' .$form_state['values']['country_id']);
}
