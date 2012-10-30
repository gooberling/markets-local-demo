<?php
/**
 * @File : Provides blocks and features for members homepage
 */

/**
 * TMA registration form
 */
function _tma_registration_form_user_register_form_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = '_tma_registration_validate';
  unset($form['#submit'][0]);
  $form['#submit'][] = '_tma_registration_form_submit'; 
  
  $form['field_company']['#ajax'] =  array(
    'callback' => '_tma_ajax_address_fields',
    'wrapper' => 'replace_address_div',
  );
 
  $form['company_address_replace'] = array(
    '#markup' => '<div id="replace_address_div"></div>',
    '#weight' => 100,
  );
  
  $form['#fieldgroups']['group_user_company_group']->children[] = 'company_address_replace';
  $form['#group_children']['company_address_replace'] = 'group_user_company_group';
  
//  print_r($form['field_company']);
  
}



function _tma_registration_validate($form, &$form_state) {
//  $education_domains = (variable_get('tma_registration_academic_domains')) ? explode(',', variable_get('tma_registration_academic_domains')): FALSE;
//  $govt_domains = (variable_get('tma_registration_govt_domains')) ? explode(',', variable_get('tma_registration_govt_domains')) : FALSE ;
//   
//  // Validate if this user is to be allowed to register
//  
//  
//  if (!empty($form_state['values']['mail']) && valid_email_address($form_state['values']['mail'])) {
//    $domain = substr(strrchr($form_state['values']['mail'], "@"), 1);
//  
//    if (in_array(trim($domain), $education_domains)) {
//      print('Inside');
//      form_set_error('mail', t('@msg', array('@msg' => variable_get('tma_registration_academic_domains_message'))));
//    }
//    
//    if (in_array($domain, $govt_domains)) {
//      form_set_error(t('@msg', array('@msg' => variable_get('tma_registration_govt_domains'))));
//    }
//  }  
}



function _tma_registration_form_submit($form, &$form_state) {
  //user_register_submit
  $education_domains = (variable_get('tma_registration_academic_domains')) ? explode(',', variable_get('tma_registration_academic_domains')): FALSE;
  $govt_domains = (variable_get('tma_registration_govt_domains')) ? explode(',', variable_get('tma_registration_govt_domains')) : FALSE ;

  
  $domain = substr(strrchr($form_state['values']['mail'], "@"), 1);
  if (in_array(trim($domain), $education_domains)) {
    drupal_set_message(t('@msg', array('@msg' => variable_get('tma_registration_academic_domains_message'))));
    drupal_mail('tma_registration', 'tma_registration_academic', $form_state['values']['mail'], FALSE, FALSE, FALSE); 
    $form_state['redirect'] = '';
  } 
  else if (in_array($domain, $govt_domains)) {
    drupal_set_message(t('@msg', array('@msg' => variable_get('tma_registration_govt_domains_message'))));
    drupal_mail('tma_registration', 'tma_registration_govt', $form_state['value']['mail'], FALSE, FALSE, FALSE);
    $form_state['redirect'] = '';
  } 
  else {
    user_register_submit($form, $form_state);
    
  }
}


function _tma_ajax_address_fields(&$form, &$form_state) {
  $form['address'] = array(
    '#type' => 'textfield',
    '#title' => 'Addresss',
  );
  
  return ($form['address']);
}