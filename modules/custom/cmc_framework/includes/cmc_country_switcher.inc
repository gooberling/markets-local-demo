<?php

function cmc_framework_country_switcher_default() {
  return "United Kingdom = http://www.cmcmarkets.co.uk
Germany = http://www.cmcmarkets.de
Austria = http://www.cmcmarkets.at
Australia = http://www.cmcmarkets.com.au
Singapore = http://www.cmcmarkets.com.sg
  ";
}

/**
 * Country Switcher Settings
 */
function cmc_framework_country_switcher_settings() {
  
  $form = array();
  
  $form['cmc_framework_country_switcher_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Countries'),
    '#default_value' => variable_get('cmc_framework_country_switcher_content', cmc_framework_country_switcher_default()),
    '#description' => 'One country and url per line in format "Country = url". Include full http:// address',
  );
  
  $form['cmc_framework_country_switcher_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Switcher Text'),
    '#default_value' => variable_get('cmc_framework_country_switcher_text', 'Switch Country'),
  );
   
  return system_settings_form($form);
}


function cmc_framework_country_switcher_get_countries() {
  $countries = variable_get('cmc_framework_country_switcher_content', cmc_framework_country_switcher_default());

  $countries = explode("\n", $countries);
  
  $results = array();
  foreach ($countries as $c) {
    if (trim($c)) {
      $c = explode("=", $c);
      $results[trim($c[0])] = trim($c[1]);
    }
  }
  return $results;
}



/**
 *
 * Enter description here ...
 */
function cmc_framework_country_switcher_block() {
  
  $path = drupal_get_path('module', 'cmc_framework');
  drupal_add_css($path . '/css/cmc_framework.css');
  drupal_add_js($path . '/js/cmc_framework.js');
  
  $countries = cmc_framework_country_switcher_get_countries();
  
  $data['countries'] = $countries;
  $data['switch'] = variable_get('cmc_framework_country_switcher_text', 'Switch Country');
  $data['edit'] = '';
  if (user_access('administer cmc_country_switcher')) {
    $data['edit'] = l(t('Edit Country Switcher'), 'admin/config/cmc/country_switcher');
  }
  return theme('cmc_country_switcher', array('data' => $data));
}

