<?php


/**
 * Email Vision Settings
 */
function cmc_framework_emailvision_settings() {
  $form = array();
  
  $form['cmc_framework_emailvision_optout_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Vision optout node nid'),
    '#default_value' => variable_get('cmc_framework_emailvision_optout_node', '3991'),
  );
  
  $form['cmc_framework_emailvision_optout_js'] = array(
    '#type' => 'textarea',
    '#rows' => 30,
    '#title' => t('Javscript for Email Vision Optout form'),
    '#default_value' => variable_get('cmc_framework_emailvision_optout_js', 'some javascript'),
    '#description' => t('This is inserted using the cmc_framework_node_view function'),
  );
  
  return system_settings_form($form);
}
