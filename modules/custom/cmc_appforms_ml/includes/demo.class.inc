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
      case "multilanguage":
          $form['multilanguage'] = array(
            '#type' => 'fieldset',
            '#title' => t(':feature settings for Live registration', array(':feature' => $feature, ':product' => $product )), 
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,  
          );
        
        
          $form[$type]['optional']['cmc_registration_multilanguage_live_'.$type] = array(
            '#type' => 'checkbox',
            '#title' => t('Allow multilanguage onboarding for :product', array(':product' => $type)),
            '#description' => t('Checking this box will setup region for multilanguage'),
            '#default_value' => variable_get('cmc_registration_multilanguage_live_' .$type)
          );

          $form[$type]['optional']['cmc_registration_allowed_languages_live_'.$type] = array(
            '#type' => 'textfield',
            '#title' => t('List of languages allowed for the region for :product', array(':product' => $type)),
            '#description' => t('provide list of languages that are allowed for the region, language to be provided in langcode|label format. Use new line to seperate languages.'),
            '#default_value' => variable_get('cmc_registration_allowed_languages_live_'.$type),
            '#states' => array(
              'visible' => array(
                ':input[name="cmc_registration_multilanguage_live_' .$type .'"]' => array('checked' => TRUE)
              ),
            'required' => array(
                  ':input[name="cmc_registration_multilanguage_live_' .$type .'"]' => array('checked' => TRUE)
              ),
            ),
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
