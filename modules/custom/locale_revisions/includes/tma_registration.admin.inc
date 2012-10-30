<?php
/**
 * @File : Provides blocks and features for members homepage
 */

/**
 * TMA registration form
 */

function tma_registration_settings() {
  $form = array();

  $form['academic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic orgnaziation settings')
  );
  $form['academic']['tma_registration_academic_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains that are not allowed to signup '),
    '#description' => t('Enter full domain names or partial domain names that are to be disapproved. Users with email addresses matching
                         these domain names will not be allowed to register at the site. Seperate each domain with a ","'),
    '#cols' => 15,
    '#rows' => 3,
    '#required' => TRUE,
    '#default_value' => variable_get('tma_registration_academic_domains'),
  );
  $form['academic']['tma_registration_academic_domains_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message to Academic organization users '),
    '#cols' => 15,
    '#rows' => 3,
    '#required' => TRUE,
    '#default_value' => variable_get('tma_registration_academic_domains_message'),
  );
  
  $form['government'] = array(
    '#type' => 'fieldset',
    '#title' => t('Government orgnaziation settings')
  );
  $form['government']['tma_registration_govt_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains of Government organizations '),
    '#description' => t('Enter full domain names or partial domain names that are to be disapproved. Users with email addresses matching
                         these domain names will not be allowed to register at the site. Seperate each domain with a ","'),
    '#cols' => 15,
    '#rows' => 3,
    '#required' => TRUE,
    '#default_value' => variable_get('tma_registration_govt_domains'),
  );
  $form['government']['tma_registration_govt_domains_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message to government organization users '),
    '#col' => 15,
    '#rows' => 3,
    '#required' => TRUE,
    '#default_value' => variable_get('tma_registration_govt_domains_message'),
  );
  
  
 $form['state_test'] = array(
   '#type' => 'radios',
   '#title' => 'form state test',
   '#options' => array('yes' => 'yes', 'no' => 'no'),
     
 );
 
  $form['Name'] = array(
   '#type' => 'textfield',
   '#title' => 'Firstname',
   '#states' => array(
     'visible' => array(   // action to take.
        ':input[name=state_test]' => array('value' => t('yes')),
      ), 
     'required' => array(   // action to take.
        ':input[name=state_test]' => array('value' => t('yes')),
      ), 
     
   )
     
 );
  
  $form['last_name'] = array(
   '#type' => 'textfield',
   '#title' => 'Last name',
   '#states' => array(
     'visible' => array(   // action to take.
        ':input[name=state_test]' => array('value' => t('no')),
      ), 
   )
     
 );
 
  
 return system_settings_form($form);
}