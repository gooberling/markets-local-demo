<?php

function cmc_framework_signup_defaults($text) {
  return array(
    'format' => 'cmc_editor',
  	'value' => $text,
  );
}


/**
 * Signup Settings
 */
function cmc_framework_signup_settings() {
  
  $form = array();
  $form['signup1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup 1 Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $signup_defaults = variable_get('cmc_framework_signup_content1', cmc_framework_signup_defaults('Content 1'));
  $form['signup1']['cmc_framework_signup_class1'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_signup_class1', 'spreadbet'),
  );
  
  $form['signup1']['cmc_framework_signup_content1'] = array(
    '#type' => 'text_format',
    '#title' => t('Signup 1 Content'),
    '#default_value' => $signup_defaults['value'],
    '#format' => $signup_defaults['format'],
  );
  
  
  $form['signup2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup 2 Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $signup_defaults = variable_get('cmc_framework_signup_content2', cmc_framework_signup_defaults('Content 2'));
  $form['signup2']['cmc_framework_signup_class2'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_signup_class2', 'spreadbet'),
  );
  
  $form['signup2']['cmc_framework_signup_content2'] = array(
    '#type' => 'text_format',
    '#title' => t('Signup 2 Content'),
    '#default_value' => $signup_defaults['value'],
    '#format' => $signup_defaults['format'],
  );
  
  
  $form['signup3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup 3 Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $signup_defaults = variable_get('cmc_framework_signup_content3', cmc_framework_signup_defaults('Content 3'));
  $form['signup3']['cmc_framework_signup_class3'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_signup_class3', 'cfd'),
  );
  
  $form['signup3']['cmc_framework_signup_content3'] = array(
    '#type' => 'text_format',
    '#title' => t('Signup 3 Content'),
    '#default_value' => $signup_defaults['value'],
    '#format' => $signup_defaults['format'],
  );
  
  
  $form['signup4'] = array(
    '#type' => 'fieldset',
    '#title' => t('Signup 4 Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $signup_defaults = variable_get('cmc_framework_signup_content4', cmc_framework_signup_defaults('Content 4'));
  $form['signup4']['cmc_framework_signup_class4'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_signup_class3', 'cfd'),
  );
  
  $form['signup4']['cmc_framework_signup_content4'] = array(
    '#type' => 'text_format',
    '#title' => t('Signup 4 Content'),
    '#default_value' => $signup_defaults['value'],
    '#format' => $signup_defaults['format'],
  );
  
  return system_settings_form($form);
}


/**
 *
 * Enter description here ...
 */
function cmc_framework_signup_block() {
  
  $data = array();
  for ($i=1; $i<=4; $i++) {
    $key = 'signup' . $i;
    $var_name_content = 'cmc_framework_signup_content' . $i;
    $var_name_class = 'cmc_framework_signup_class' . $i;
    
    $content = variable_get($var_name_content, 'Content');
    $data['blocks'][$key]['content'] = check_markup($content['value'], $content['format']);
    
    $data['blocks'][$key]['class'] = variable_get($var_name_class, '');
    
  }
  
  $data['edit'] = '';
  if (user_access('administer cmc_login')) {
    $data['edit'] = l('Edit Signup block', 'admin/config/cmc/login');
  }
  //print_r($data);
  //admin/config/cmc/signup
  
  return theme('cmc_signup', array('data' => $data));
}

