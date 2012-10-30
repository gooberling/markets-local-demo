<?php
/**
 * @File
 * @author : Ravi Julapalli 
 */

/**
 * Identity service signup form
 */
function cmc_identityservice_settings_form($form, $form_state) {

  $form = array();

  $form['cmc_identityservice_sblogin_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to Spreadbet login form'),
    '#description' =>  t('Path user should be redirected to login into flex'),
    '#default_value' => variable_get('cmc_identityservice_sblogin_path'),
  );
  
  $form['cmc_identityservice_cfdlogin_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to CFD login form'),
    '#description' =>  t('Path user should be redirected to login into flex'),
    '#default_value' => variable_get('cmc_identityservice_cfdlogin_path'),
  );
  
  $form['cmc_identityservice_reset_thankyou'] = array(
    '#type' => 'textarea',
    '#title' => t('Reset password thank you page text'),
    '#default_value' => variable_get('cmc_identityservice_reset_thankyou'),
  );
  
  $form['cmc_identityservice_forgot_password'] = array(
    '#type' => 'textarea',
    '#title' => t('Message for forgot password '),
    '#default_value' => variable_get('cmc_identityservice_forgot_password'),
  );
  
  $form['cmc_identityservice_errorpage'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for error page'),
    '#default_value' => variable_get('cmc_identityservice_errorpage', t('We are sorry but there has been an error updating your account details')),
  );

 return system_settings_form($form);
}  
