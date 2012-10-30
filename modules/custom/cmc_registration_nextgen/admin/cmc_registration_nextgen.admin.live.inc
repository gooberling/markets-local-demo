<?php

function cmc_registration_live_settings_form($form, &$form_state) {
  $form = array();
  
  foreach (cmc_registration_product_type()  as $type => $product) {
    $form[$type] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings for :product Product', array(':product' => $product )), 
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,  
    );
    
    $form[$type]['cmc_registration_title_registration_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Page title for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_title_registration_' .$type, NULL),
    );
    
    $form[$type]['cmc_registration_live_dob_min_age_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Minimum age for live registration for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_live_dob_min_age_' .$type, 18),
    );
    
    $form[$type]['optional'] = array(
      '#type' => 'fieldset',
      '#title' => t('Optional fields'),
      '#description' => t('Contains settings for NIA & Multicurrency, Multilanguage etc ..'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form[$type]['optional']['cmc_registration_multilanguage_live_'.$type] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow multilanguage onboarding for :product', array(':product' => $product)),
      '#description' => t('Checking this box will setup region for multilanguage'),
      '#default_value' => variable_get('cmc_registration_multilanguage_live_' .$type)
    );
    
    $form[$type]['optional']['cmc_registration_allowed_languages_live_'.$type] = array(
      '#type' => 'textfield',
      '#title' => t('List of languages allowed for the region for :product', array(':product' => $product)),
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
    $form[$type]['optional']['cmc_registration_multicurrency_live_'.$type] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow multicurrency'),
      '#description' => t('Checking this box will setup multicurrency for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_multicurrency_live')
      );


    $form[$type]['optional']['cmc_registration_multicurrency_live_'.$type] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow multicurrency'),
      '#description' => t('Checking this box will setup multicurrency for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_multicurrency_live_'. $type)
    );
  
 
    $form[$type]['optional']['cmc_registration_allowed_currencies_live_'.$type] = array(
      '#type' => 'textfield',
      '#title' => t('List of allowed currencies'),
      '#description' => t('List of allowed currencies seperate 
        each currency by "," e.g. GBP,EUR,CHF. These will be provided to users as option in registration forms'),
      '#default_value' => variable_get('cmc_registration_allowed_currencies_live_' .$type),
      '#states' => array(
        'visible' => array(
          ':input[name="cmc_registration_multicurrency_live_' .$type .'"]' => array('checked' => TRUE)
       ),
      'required' => array(
        ':input[name="cmc_registration_multicurrency_live_' .$type .'"]' => array('checked' => TRUE)
        )
      ),
    );
    
    $form[$type]['legal'] = array(
      '#type' => 'fieldset',
      '#title' => t('Legal fields'),
      '#description' => t('Contains settings for Legal documents such as Risk warning, TOBS  etc'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    $form[$type]['legal']['cmc_registration_riskwarning_'.$type] = array(
      '#type' => 'textfield',
      '#title' => t('Risk Warning Node for :product', array(':product' => $product)),
      '#description' => t("Enter the node id of the node that contains text for {$product} risk warning. Enter numeric value only. E.g 10"),
      '#default_value' => variable_get('cmc_registration_riskwarning_'.$type),
    );
    
    $form[$type]['legal']['cmc_registration_tobs_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Terms and Conditions Node for :product', array(':product' => $product)),
      '#description' => t('Enter the node id of the node that contains terms and conditions for spreadbet. Enter numeric value only. E.g 10'),
      '#default_value' => variable_get('cmc_registration_tobs_' .$type),
    );
  
    $form[$type]['legal']['appropriateness'] = array(
      '#type' => 'fieldset',
      '#title' => t('Appropriateness'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    $form[$type]['legal']['appropriateness']['cmc_registration_appr_fail_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Appropriateness FAIL node for :product', array(':product' => $product)),
      '#description' => t('Enter the node id of the node that contains Appropriateness fail text for :product. Enter numeric value only. E.g 10' , array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_appr_fail_' .$type)
    );
    
    $form[$type]['legal']['appropriateness']['cmc_registration_appr_reject_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Appropriateness REJECT node for :product', array(':product' => $product)),
      '#description' => t('Enter the node id of the node that contains Appropriateness REJECT text for :product. Enter numeric value only. E.g 10' , array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_appr_reject_' .$type)
    );
    
    $form[$type]['legal']['appropriateness']['cmc_registration_appr_pass_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Appropriateness PASS node for :product', array(':product' => $product)),
      '#description' => t('Enter the node id of the node that contains Appropriateness PASS text for :product. Enter numeric value only. E.g 10. At the moment this is only valid for Singapore' , array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_appr_pass_' .$type)
    );
    
    $form[$type]['final'] = array(
      '#type' => 'fieldset',
      '#title' => t('Final step settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form[$type]['final']['cmc_registration_live_thankyou_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Node id of live registration thank you page for :product', array(':product' => $product)),
      '#description' => t('Enter the node id of the node that contains thank you text for :product. Enter numeric value only. E.g 10', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_live_thankyou_' .$type)
    );
    
    $form[$type]['final']['cmc_registration_live_confirm_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Node id of live registration registration confirmation page for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_live_confirm_' .$type)
    );
    
    $form[$type]['pdf'] = array(
      '#type' => 'fieldset',
      '#title' => t('PDF Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    $form[$type]['pdf']['cmc_registration_pdf_tob_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Node id of PDF declarations for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_pdf_tob_' .$type)
    );
    
    $form[$type]['st'] = array(
      '#type' => 'fieldset',
      '#title' => t('Sales Trader'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    $form[$type]['st']['cmc_registration_tobs_st_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Node id of Salted Trader terms of business for :product', array(':product' => $product)),
      '#description' => t('Enter the node id of the node that contains terms and conditions for :product. Enter numeric value only. E.g 10', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_tobs_st_' .$type),
    );
    
    $form[$type]['st']['cmc_registration_pdf_tob_st_' .$type] = array(
      '#type' => 'textfield',
      '#title' => t('Node id of SALES TRADER pdf declarations for :product', array(':product' => $product)),
      '#default_value' => variable_get('cmc_registration_pdf_tob_st_' .$type)
    );
  }

  return system_settings_form($form);
}
