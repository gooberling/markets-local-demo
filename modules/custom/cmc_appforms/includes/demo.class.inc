<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of demo
 *
 * @author ravi
 */
class demoRegistration extends AppForm implements AppFormInterface {
  function __construct() {
    
  }
  
  function getSettingsForm($feature, AppFormConfig $appFormConfig) {
    $form = array();
    $type = $appFormConfig->getProduct_Id();
    
    $config = !empty($appFormConfig->config) ? $appFormConfig->config : array();
    
    switch($feature) {
      case "core":
          $form['core'] = array(
            '#type' => 'fieldset',
            '#title' => t(':feature settings for Live registration', array(':feature' => $feature, ':product' => $product )), 
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,  
          );

          $form['cmc_registration_demo_thankyou_'.$type] = array(
            '#type' => 'textfield',
            '#title' => t('Demo registration thankyou page for CFD'),
            '#description' => t('The path to the thankyou page for demo registration (e.g. node/123)'),
            '#default_value' => !empty($config['cmc_registration_demo_thankyou_' .$type]) ? $config['cmc_registration_demo_thankyou_' .$type] : "",
          );

          $form['spreadbet']['cmc_registration_demo_thankyou_ios_' .$type] = array(
            '#type' => 'textfield',
            '#title' => t('Redirection URL for iOS devices (demo registration)'),
            '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
            '#default_value' => !empty($config['cmc_registration_demo_thankyou_ios_' .$type]) ? $config['cmc_registration_demo_thankyou_ios_' .$type] : "",
          );

          $form['spreadbet']['cmc_registration_demo_thankyou_mobile_' .$type] = array(
            '#type' => 'textfield',
            '#title' => t('Redirection URL for mobile devices (demo registration)'),
            '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
            '#default_value' => !empty($config['cmc_registration_demo_thankyou_mobile_' .$type]) ? $config['cmc_registration_demo_thankyou_mobile_' .$type] : "",
          );

          $form['spreadbet']['cmc_registration_demo_thankyou_desktop_' .$type] = array(
            '#type' => 'textfield',
            '#title' => t('Redirection URL for desktop browsers (demo registration)'),
            '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
            '#default_value' => !empty($config['cmc_registration_demo_thankyou_desktop_' .$type]) ? $config['cmc_registration_demo_thankyou_desktop_' .$type] : "",
          );


          $form['core']['legal']['appropriateness']['cmc_registration_appr_pass_' .$type] = array(
            '#type' => 'textfield',
            '#title' => t('Appropriateness PASS node for :product', array(':product' => $product)),
            '#description' => t('Enter the node id of the node that contains Appropriateness PASS text for :product. Enter numeric value only. E.g 10. At the moment this is only valid for Singapore' , array(':product' => $product)),
            '#default_value' => !empty($config['cmc_registration_appr_pass_' .$type]) ? $config['cmc_registration_appr_pass_' .$type] : "",
          );        
        break;
    }

    return $form;
  }
  
  function getApplicationForm($feature, AppFormConfig $AppFormConfig) {}
  
  function getMappings() {}

  function preprocess() {}
  
  
}
?>
