<?php
/**
 * @File
 *
 * @author Ravi Julapalli (r.julapalli@cmcmarkets.com)
 */

/**
 * Settings for CRM Client  
 */
function cmc_crmclient_settings_form() {
  $items = array();
  $items ['crm_client_end_point'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('crm_client_end_point'),
    '#title' => t('End point of CRM web service'),
    '#description' => t('Use full path to service end point without http/https'),
  );  

  $items ['cmc_crm_client_username'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('crm_client_username'),
    '#title' => t('Username'),
    '#description' => t('Username for crm client authentication'),
  ); 
  
  $items ['cmc_crm_client_password'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('cmc_crm_client_password'),
    '#title' => t('Password'),
    '#description' => t('Password for crm client authentication'),
  );
  
  
  return system_settings_form($items);
}