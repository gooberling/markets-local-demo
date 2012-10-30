<?php

function nextgen_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['nextgen_bridge_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Bridge URL'),
    '#description' => t('The base URL for the Quercus Java/PHP bridge system, e.g. http://10.0.0.1/quercus/scripts/index.php'),
    '#default_value' => variable_get('nextgen_bridge_url', '')
  );

  $form['nextgen_log_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log all responses'),
    '#description' => t('If ticked, all responses from back-end system will be logged'),
    '#default_value' => variable_get('nextgen_log_all', FALSE)
  );

  return system_settings_form($form);
}