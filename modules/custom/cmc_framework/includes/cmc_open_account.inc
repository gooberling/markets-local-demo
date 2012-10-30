<?php
function cmc_framework_open_account_defaults() {
  return array(
    'format' => 'cmc_editor',
  	'value' => 'Losses can exceed your initial deposit, so ensure you understand the risks',
  );
}

function cmc_framework_open_account_settings() {
  $form = array();
  
  $form['link1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link 1'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['link1']['cmc_framework_open_account_link_text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => variable_get('cmc_framework_open_account_link_text1', 'Open a live account'),
  );
  
  $form['link1']['cmc_framework_open_account_link_url1'] = array(
    '#type' => 'textfield',
    '#title' => t('URL 1'),
    '#default_value' => variable_get('cmc_framework_open_account_link_url1', 'https://www.mycmc.co.uk/Main.html?launchpoint=livereg'),
  );
  
  $form['link1']['cmc_framework_open_account_link_class1'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_open_account_link_class1', 'signpost1'),
  );
  
  
  $form['link2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link 2'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['link2']['cmc_framework_open_account_link_text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => variable_get('cmc_framework_open_account_link_text2', 'Open a live account'),
  );
  
  $form['link2']['cmc_framework_open_account_link_url2'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => variable_get('cmc_framework_open_account_link_url2', 'https://www.mycmc.co.uk/Main.html?launchpoint=demoreg'),
  );
  
  $form['link2']['cmc_framework_open_account_link_class2'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_open_account_link_class2', 'signpost2'),
  );
  
  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer Disclaimer'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $disclaimer = variable_get('cmc_framework_open_account_disclaimer', cmc_framework_open_account_defaults());
  
  $form['footer']['cmc_framework_open_account_disclaimer'] = array(
    '#type' => 'text_format',
    '#title' => t('Open Account Disclaimer'),
    '#default_value' => $disclaimer['value'],
    '#format' => $disclaimer['format'],
  );
  
  return system_settings_form($form);
}


/**
 *
 * Enter description here ...
 */
function cmc_framework_open_account_block() {
  
  $disclaimer = variable_get('cmc_framework_open_account_disclaimer', cmc_framework_open_account_defaults());
  $disclaimer_content = check_markup($disclaimer['value'], $disclaimer['format']);
  
  $edit = '';
  if (user_access('administer cmc_open_account')) {
    $edit = l(t('Edit Open Account Block'), 'admin/config/cmc/open_account');
  }
  
  $data = array(
    'class1' => t(variable_get('cmc_framework_open_account_link_class1', 'signpost1')),
    'text1' => t(variable_get('cmc_framework_open_account_link_text1', 'Open a live account')),
    'url1' => t(variable_get('cmc_framework_open_account_link_url1', 'https://www.mycmc.co.uk/Main.html?launchpoint=livereg')),
    'class2' => t(variable_get('cmc_framework_open_account_link_class2', 'signpost2')),
    'text2' => t(variable_get('cmc_framework_open_account_link_text2', 'Open a live account')),
    'url2' => t(variable_get('cmc_framework_open_account_link_url2', 'https://www.mycmc.co.uk/Main.html?launchpoint=demoreg')),
    'footer' => t($disclaimer_content),
    'edit' => $edit,
  );
  
  return theme('cmc_open_account', array('data' => $data));
}