<?php

function cmc_registration_settings_form($form, &$form_state) {
  $form = array();

  $form['cmc_registration_region_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL Logo should point to'),
    '#description' => t('URL logo should point to, enter full url starting with http://'),
    '#default_value' => variable_get('cmc_registration_region_url', NULL),
  );
  
  $form['cmc_registration_country_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Country code for this site'),
    '#description' => t('Enter the country code for this site, e.g. GBR'),
    '#default_value' => variable_get('cmc_registration_country_code', '')
  );
  
  $form['cmc_registration_currency'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Currency code'),
    '#description' => t('Enter the currency code for this site, e.g. GBP'),
    '#default_value' => variable_get('cmc_registration_currency'),
  );
  
  $form['cmc_registration_error_node'] = array(
    '#type' => 'textfield',
    '#title' => t('ID of the node containing text to display in case of catastrophic failure'),
    '#default_value' => variable_get('cmc_registration_error_node')
  );
  
  $form['cmc_registation_pdf_server_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL of pdf generation service'),
    '#description' => t('Provide full URL of pdf generation service'),
    '#default_value' => variable_get('cmc_registation_pdf_server_url', 'https://svcffe1-https-hdev3.mycmc.co.uk:24003/blazedsmain/xml-xslt-pdf-generator/?REPORT_TYPE=LIVE_ACCOUNT_REGISTRATION_REPORT'),

  );
  
  $form['legalagreements']['salestradersalt'] = array(
    '#type' => 'textfield',
    '#title' => t('Salt used to encode sales trade email'),
    '#default_value' => variable_get('salestradersalt', FALSE),
  );
 
  
  $form['cmc_registration_error_pdf'] = array(
    '#type' => 'textfield',
    '#title' => t('ID of the node containing text to display in case of PDF failure'),
    '#default_value' => variable_get('cmc_registration_error_pdf', ''),
  );
  
  foreach (cmc_registration_product_type()  as $type => $product) { 
    $form[$type] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings for :product Product', array(':product' => $product )), 
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,  
    );
    
    $form[$type]['cmc_registration_tenant_template_code_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Tenant template code for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_tenant_template_code_' .$type, NULL),
    );  
    
    $form[$type]['legalagreements'] = array(
      '#type' => 'fieldset',
      '#title' => t('Fields related to legal agreement copy'),
    );
    
    $form[$type]['legalagreements']['termsOfBusinessDocName_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Business terms doc name :product', array(':product' => $product)),
      '#default_value' => variable_get('termsOfBusinessDocName_' .$type, ''),
    );
    
    $form[$type]['legalagreements']['termsofBusinessVersion_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Business terms version for :product', array(':product' => $product)),
      '#default_value' => variable_get('termsofBusinessVersion_' .$type, ''),
    );

    $form[$type]['legalagreements']['termsOfBusinessDocName_sales_trader_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Sales trader Business terms doc name for  :product', array(':product' => $product)),
      '#default_value' => variable_get('termsOfBusinessDocName_sales_trader_' .$type, ''),
    );
    
    $form[$type]['legalagreements']['termsofBusinessVersion_sales_trader_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Sales trader Business terms version for :product', array(':product' => $product)),
      '#default_value' => variable_get('termsofBusinessVersion_sales_trader_' .$type, ''),
    );
 
    
  }
  return system_settings_form($form);
}