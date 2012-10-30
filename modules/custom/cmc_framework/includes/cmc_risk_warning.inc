<?php
function cmc_framework_risk_warning_defaults() {
  return array(
    'format' => 'cmc_editor',
  	'value' => '<h2>Risk Warning</h2>',
  );
}


/**
 * Risk Warning Settings
 */
function cmc_framework_risk_warning_settings() {
  
  $form = array();
  $risk_warning = variable_get('cmc_framework_risk_warning_content', cmc_framework_risk_warning_defaults());
  
  $form['cmc_framework_risk_warning_content'] = array(
    '#type' => 'text_format',
    '#title' => t('Risk Warning Content'),
    '#default_value' => $risk_warning['value'],
    '#format' => $risk_warning['format'],
    '#weight' => 0,
  );
  
  return system_settings_form($form);
}


/**
 *
 * Enter description here ...
 */
function cmc_framework_risk_warning_block() {
  $risk_warning = variable_get('cmc_framework_risk_warning_content', cmc_framework_risk_warning_defaults());
  $content = check_markup($risk_warning['value'], $risk_warning['format']);
  
  $data['content'] = $content;
  $data['edit'] = '';
  if (user_access('administer cmc_risk_warning')) {
    $data['edit'] = l(t('Edit Risk Warning'), 'admin/config/cmc/risk_warning');
  }
  return theme('cmc_risk_warning', array('data' => $data));
}

