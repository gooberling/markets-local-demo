<?php

function cmc_analytics_settings($form, $form_state) {
  $form = array();
  
  $form['default_code_adform'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default settings for Adform'),
  );
  $form['default_code_adform']['sb_adform'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('sb_adform'),
  );
  $form['default_code_adform']['cfd_adform'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('cfd_adform'),
  );
  $form['default_code_ga'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default settings for Google Analytics'),
  );
  $form['default_code_ga']['sb_ga'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('sb_ga'),
  );
  $form['default_code_ga']['cfd_ga'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('cfd_ga'),
  );
  $form['cmc_analytics_advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced analytics settings'),
  );
  $form['cmc_analytics_advanced']['cmc_analytics_show_form_options'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable form level analytics'),
    '#default_value' => variable_get('cmc_analytics_show_form_options'),
  );
  $form['cmc_analytics_advanced']['cmc_analytics_advanced_nodetypes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide code per content type'),
    '#default_value' => variable_get('cmc_analytics_advanced_nodetypes'),
  );
  
  $form['cmc_analytics_nodetype'] = array(
    '#type' => 'fieldset',
    '#collapsed' => TRUE, 
    '#collapsable' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="cmc_analytics_advanced_nodetypes"]' => array('checked' =>TRUE)
      )
    )
  );

  // Get list of all node types
  $types = node_type_get_types();
  foreach($types as $type => $item) {
    $types = node_type_get_types();
    $names = node_type_get_names();
    $form['cmc_analytics_nodetype']["cmc_analytics_{$type}"] = array(
     '#type' => 'textarea',
     '#default_value' => variable_get("cmc_analytics_{$type}"),
     '#title' => t("Analytics code for {$type}"),
     '#rows' => 3,
    );
  }
  
  return system_settings_form($form);
}