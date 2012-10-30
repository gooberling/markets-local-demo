<?php

function cmc_registration_demo_settings_form($form, &$form_state) {
  $form = array();

  
  $form['title'] = array(
    '#type' => 'fieldset',
    '#title' => 'Page title',
    '#collapsable' => TRUE,
  );
  $form['title']['cmc_registration_title_demo_sb'] = array(
    '#type' => 'textfield',
    '#title' => t('Page title for spreadbet'),
    '#default_value' => variable_get('cmc_registration_title_demo_sb', NULL),
  );
  
  $form['title']['cmc_registration_title_demo_cfd'] = array(
    '#type' => 'textfield',
    '#title' => t('Page title for CFD'),
    '#default_value' => variable_get('cmc_registration_title_demo_cfd', NULL),
  );
  

  $form['optional'] = array(
      '#type' => 'fieldset',
      '#title' => t('Optional settings DEMO registration'),
      '#description' => t('Provides various options settings for the region including  Multilanguage, Multicurrency etc'),
      '#tree' => FALSE,
      '#collapsible' => TRUE,
  );
  
  $form['optional']['cmc_registration_multilanguage_demo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow multilanguage onboarding'),
    '#description' => t('Checking this box will setup region for multilanguage'),
    '#default_value' => variable_get('cmc_registration_multilanguage_demo')
  );
  
  $form['optional']['cmc_registration_allowed_languages_demo'] = array(
    '#type' => 'textfield',
    '#title' => t('List of languages allowed for the region'),
    '#description' => t('provide list of languages that are allowed for the region, language to be provided in langcode|label format. Use new line to seperate languages.'),
    '#default_value' => variable_get('cmc_registration_allowed_languages_demo'),
    '#states' => array(
      'visible' => array(
        ':input[name="cmc_registration_multilanguage_demo"]' => array('checked' => TRUE)
      ),
     'required' => array(
          ':input[name="cmc_registration_multilanguage_demo"]' => array('checked' => TRUE)
      ),
    ),
  );
  
  $form['optional']['cmc_registration_multicurrency_demo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow multicurrency'),
    '#description' => t('Checking this box will setup region for multicurrency'),
    '#default_value' => variable_get('cmc_registration_multicurrency')
  );
  
  $form['optional']['cmc_registration_allowed_currencies_demo_cfd'] = array(
    '#type' => 'textfield',
    '#title' => t('List of allowed currencies CFD'),
    '#description' => t('List of allowed currencies for CFD, seperate 
      each currency by "," e.g. GBP,EUR,CHF. These will be provided to users as option in registration forms'),
    '#default_value' => variable_get('cmc_registration_allowed_currencies_demo_cfd'),
    '#states' => array(
      'visible' => array(
        ':input[name="cmc_registration_multicurrency_demo"]' => array('checked' => TRUE)
      ),
     'required' => array(
          ':input[name="cmc_registration_multicurrency_demo"]' => array('checked' => TRUE)
      ),
    ),
  );
 
  $form['optional']['cmc_registration_allowed_currencies_demo_sb'] = array(
    '#type' => 'textfield',
    '#title' => t('List of allowed currencies Spreadbet'),
    '#description' => t('List of allowed currencies for Spreadbets, seperate 
      each currency by "," e.g. GBP,EUR,CHF. These will be provided to users as option in registration forms'),
    '#default_value' => variable_get('cmc_registration_allowed_currencies_demo_sb'),
    '#states' => array(
      'visible' => array(
        ':input[name="cmc_registration_multicurrency_demo"]' => array('checked' => TRUE)
      ),
    ),
  );
  
  
  $form['cmc_registration_demo_thankyou_cfd'] = array(
    '#type' => 'textfield',
    '#title' => t('Demo registration thankyou page for CFD'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_cfd', ''),
    '#description' => t('The path to the thankyou page for demo re
      gistration (e.g. node/123)')
  );
  
  $form['cmc_registration_demo_thankyou_sb'] = array(
    '#type' => 'textfield',
    '#title' => t('Demo registration thankyou page for SB'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_sb', ''),
    '#description' => t('The path to the thankyou page for demo registration (e.g. node/123)')
  );
  $form['spreadbet'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redirection for Spreadbet'),
    '#tree' => FALSE
  );
  
  $form['spreadbet']['cmc_registration_demo_thankyou_ios_sb'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirection URL for iOS devices (demo registration)'),
    '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_ios_sb')
  );

  $form['spreadbet']['cmc_registration_demo_thankyou_mobile_sb'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirection URL for mobile devices (demo registration)'),
    '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_mobile_sb')
  );

  $form['spreadbet']['cmc_registration_demo_thankyou_desktop_sb'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirection URL for desktop browsers (demo registration)'),
    '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_desktop_sb')
  );
  $form['cfd'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redirections for CFD'),
    '#tree' => FALSE
  );
  
  $form['cfd']['cmc_registration_demo_thankyou_ios_cfd'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirection URL for iOS devices (demo registration)'),
    '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_ios_cfd')
  );

  $form['cfd']['cmc_registration_demo_thankyou_mobile_cfd'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirection URL for mobile devices (demo registration)'),
    '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_mobile_cfd')
  );

  $form['cfd']['cmc_registration_demo_thankyou_desktop_cfd'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirection URL for desktop browsers (demo registration)'),
    '#description' => t('Where to redirect demo users following successful registration. Available tokens: !token !username'),
    '#default_value' => variable_get('cmc_registration_demo_thankyou_desktop_cfd')
  );


  return system_settings_form($form);
}
