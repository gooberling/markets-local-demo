<?php

/*
 * @file Contains required helper functions and API for the forms
 */

/**
 * Build and display appropriate form for demo and live registrations
 * @param type $form_id
 * @param type $form_state
 * @param type $form_type
 * @param type $product
 * @return type 
 */
function cmc_registration_get_form($form_id, $form_state, $form_type, $product) {
  
  $form = array();
  
  $config = cmc_registration_get_configs($product, $form_type);
  $function = "cmc_registration_{$form_type }_form";
  
  
  form_load_include($form_state, 'inc', 'cmc_registration_nextgen', "includes/cmc_registration_nextgen.{$form_type}");
  $form = call_user_func($function, $form_id, $form_state);
//  drupal_alter('cmc_registration_form_config', $config);
//
//  if (function_exists($function)) {
//    $form = array_merge($form, call_user_func($function, $form_id, $form_state, $config));
    
    // Provide alter hook for both demo and live regitration forms so that other modules
    // can add in additional form elements etc
   // drupal_alter($function, array($form_id, $form_state, $config));
//  }
  
  return $form;
}

//Helper functions

/******
 * Helper functions that are common to all forms go here
 */

function _cmc_registration_live_nationality() {
  $registration_nationality = array(
    "Afghan" => t("Afghan"),
    "Albanian" => t("Albanian"),
    "Algerian" => t("Algerian"),
    "American" => t("American"),
    "Andorran" => t("Andorran"),
    "Angolan" => t("Angolan"),
    "Antiguan" => t("Antiguan"),
    "Argentine" => t("Argentine"),
    "Armenian" => t("Armenian"),
    "Aruban" => t("Aruban"),
    "Australian" => t("Australian"),
    "Austrian" => t("Austrian"),
    "Azerbaijani" => t("Azerbaijani"),
    "Bahamian" => t("Bahamian"),
    "Bahraini" => t("Bahraini"),
    "Bangladeshi" => t("Bangladeshi"),
    "Barbadian" => t("Barbadian"),
    "Barbudan" => t("Barbudan"),
    "Batswanan" => t("Batswanan"),
    "Belarusian" => t("Belarusian"),
    "Belgian" => t("Belgian"),
    "Belizean" => t("Belizean"),
    "Bermudian" => t("Bermudian"),
    "Bolivian" => t("Bolivian"),
    "Bosnian" => t("Bosnian"),
    "Brazilian" => t("Brazilian"),
    "British" => t("British"),
    "Bruneian" => t("Bruneian"),
    "Bulgarian" => t("Bulgarian"),
    "Burmese" => t("Burmese"),
    "Burundian" => t("Burundian"),
    "Cambodian" => t("Cambodian"),
    "Cameroonian" => t("Cameroonian"),
    "Canadian" => t("Canadian"),
    "Cape Verdean" => t("Cape Verdean"),
    "Caymanian" => t("Caymanian"),
    "Chadian" => t("Chadian"),
    "Chilean" => t("Chilean"),
    "Chinese" => t("Chinese"),
    "Colombian" => t("Colombian"),
    "Comorian" => t("Comorian"),
    "Congolese" => t("Congolese"),
    "Costa Rican" => t("Costa Rican"),
    "Croatian" => t("Croatian"),
    "Cuban" => t("Cuban"),
    "Cypriot" => t("Cypriot"),
    "Czech" => t("Czech"),
    "Danish" => t("Danish"),
    "Djiboutian" => t("Djiboutian"),
    "Dominican" => t("Dominican"),
    "Dutch" => t("Dutch"),
    "Ecuadorian" => t("Ecuadorian"),
    "Egyptian" => t("Egyptian"),
    "Emirati" => t("Emirati"),
    "Eritrean" => t("Eritrean"),
    "Estonian" => t("Estonian"),
    "Ethiopian" => t("Ethiopian"),
    "Fijian" => t("Fijian"),
    "Filipino" => t("Filipino"),
    "Finnish" => t("Finnish"),
    "French" => t("French"),
    "Gabonese" => t("Gabonese"),
    "Gambian" => t("Gambian"),
    "Georgian" => t("Georgian"),
    "German" => t("German"),
    "Ghanaian" => t("Ghanaian"),
    "Greek" => t("Greek"),
    "Greenlandic" => t("Greenlandic"),
    "Guatemalan" => t("Guatemalan"),
    "Guinean" => t("Guinean"),
    "Guyanese" => t("Guyanese"),
    "Haitian" => t("Haitian"),
    "Honduran" => t("Honduran"),
    "Hungarian" => t("Ungarisch"),
    "Icelandic" => t("Icelandic"),
    "Indian" => t("Indian"),
    "Indonesian" => t("Indonesian"),
    "Iranian" => t("Iranian"),
    "Iraqi" => t("Iraqi"),
    "Irish" => t("Irish"),
    "Israeli" => t("Israeli"),
    "Italian" => t("Italian"),
    "Ivorian" => t("Ivorian"),
    "Jamaican" => t("Jamaican"),
    "Japanese" => t("Japanese"),
    "Jordanian" => t("Jordanian"),
    "Kazakhstani" => t("Kazakhstani"),
    "Kenyan" => t("Kenyan"),
    "Kosovar" => t("Kosovar"),
    "Kuwaiti" => t("Kuwaiti"),
    "Kyrgyzstani" => t("Kyrgyzstani"),
    "Lao" => t("Lao"),
    "Latvian" => t("Latvian"),
    "Lebanese" => t("Lebanese"),
    "Liberian" => t("Liberian"),
    "Libyan" => t("Libyan"),
    "Lithuanian" => t("Lithuanian"),
    "Luxembourg" => t("Luxembourg"),
    "Macedonian" => t("Macedonian"),
    "Malawian" => t("Malawian"),
    "Malaysian" => t("Malaysian"),
    "Maldivian" => t("Maldivian"),
    "Malian" => t("Malian"),
    "Maltese" => t("Maltese"),
    "Mauritanian" => t("Mauritanian"),
    "Mauritian" => t("Mauritian"),
    "Mexican" => t("Mexican"),
    "Moldovan" => t("Moldovan"),
    "Mongolian" => t("Mongolian"),
    "Moroccan" => t("Moroccan"),
    "Mozambican" => t("Mozambican"),
    "Namibian" => t("Namibian"),
    "Nepalese" => t("Nepalese"),
    "New Caledonian" => t("New Caledonian"),
    "New Zealander" => t("New Zealander"),
    "Nicaraguan" => t("Nicaraguan"),
    "Nigerian" => t("Nigerian"),
    "Nigerien" => t("Nigerien"),
    "North Korean" => t("North Korean"),
    "Norwegian" => t("Norwegian"),
    "Omani" => t("Omani"),
    "Pakistani" => t("Pakistani"),
    "Panamanian" => t("Panamanian"),
    "Papua New Guinean" => t("Papua New Guinean"),
    "Paraguayan" => t("Paraguayan"),
    "Peruvian" => t("Peruvian"),
    "Polish" => t("Polish"),
    "Portuguese" => t("Portuguese"),
    "Puerto Rican" => t("Puerto Rican"),
    "Qatari" => t("Qatari"),
    "Romanian" => t("Romanian"),
    "Russian" => t("Russian"),
    "Rwandan" => t("Rwandan"),
    "Salvadoran" => t("Salvadoran"),
    "Samoan" => t("Samoan"),
    "Saudi Arabian" => t("Saudi Arabian"),
    "Senegalese" => t("Senegalese"),
    "Serbian" => t("Serbian"),
    "Sierra Leonean" => t("Sierra Leonean"),
    "Singaporean" => t("Singaporean"),
    "Slovak" => t("Slovak"),
    "Slovenian" => t("Slovenian"),
    "Somali" => t("Somali"),
    "South African" => t("South African"),
    "South Korean" => t("South Korean"),
    "Spanish" => t("Spanish"),
    "Sri Lankan" => t("Sri Lankan"),
    "Sudanese" => t("Sudanese"),
    "Swazi" => t("Swazi"),
    "Swedish" => t("Swedish"),
    "Swiss" => t("Swiss"),
    "Syrian" => t("Syrian"),
    "Taiwanese" => t("Taiwanese"),
    "Tajikistani" => t("Tajikistani"),
    "Tanzanian" => t("Tanzanian"),
    "Thai" => t("Thai"),
    "Togolese" => t("Togolese"),
    "Tongan" => t("Tongan"),
    "Tunisian" => t("Tunisian"),
    "Turkish" => t("Turkish"),
    "Turkmen" => t("Turkmen"),
    "Ugandan" => t("Ugandan"),
    "Ukrainian" => t("Ukrainian"),
    "Uruguayan" => t("Uruguayan"),
    "Uzbek" => t("Uzbek"),
    "Venezuelan" => t("Venezuelan"),
    "Vietnamese" => t("Vietnamese"),
    "Yemeni" => t("Yemeni"),
    "Zambian" => t("Zambian"),
    "Zimbabwean" => t("Zimbabwean"),
  );
  return $registration_nationality;

}


/**
 * Provides a set of extra fields related to multicurrency, multilanguage etc 
 * based on settings for the region
 * @param type $form_type
 * @param type $elements 
 * @param type $options
 *   context: context array used for translation;
 *   group: array with title & description that is used to create a fieldset. if 
 *         fields are not be grouped pass an empty array()
 *   product: CFD, SB etc
 *  
 */
function _cmc_get_registration_extra_fields($form_type, $elements = array(), $options = array()) {

  $context = $options['context'];
  $group = $options['group'];
  $fields = array();
  if (!empty($elements)) {
    foreach($elements as $option_type) {
      switch($option_type) {
        case CMC_REGISTRATION_MULTICURRENCY :
          // If a region is set for multi currency then show additinal drop down to choose currency
          if (variable_get('cmc_registration_multicurrency_' .$form_type) && (variable_get('cmc_registration_allowed_currencies_demo_'.strtolower($options['product'])))) {
            $currencies = explode(',',variable_get('cmc_registration_allowed_currencies_'.$form_type .'_'.strtolower($options['product'])));
            foreach($currencies as $currency) {
              $c[$currency] = t($currency);
            }
            //$c = (array_combine($currencies, $currencies));
            $fields['currency'] = array(
              '#type' => 'select',
              '#options' => $c,
              '#required' => TRUE,
              '#title' => t('Currency of account (cannot be changed once the account is set-up)'),
              '#default_value' => !empty($values['currency']) ? $values['currency'] : NULL,
              '#description' => t('Please select currency of account. <br /><br />Trading account 
currency 
cannot be changed once the account is set-up.') ,
              '#js_validator' => array(
                'validators' => array(
                  'selectValidator' => array(),
                  'requiredValidator' => array(variable_get('cmc_registration_currency'))
                )
              ),
            );
          }
          
          break;
        
        case CMC_REGISTRATION_MULTILANGUAGE:
          if (variable_get('cmc_registration_multilanguage_' .$form_type)) {
              $languages = explode(',',variable_get('cmc_registration_allowed_languages_' .$form_type));
              $language_options = array();
              foreach($languages as $item) {
                $l = explode("|", $item); 
                  $language_options[$l[0]] = $l[1];

              }

              $fields['preferred_language'] = array(
                '#type' => 'select',
                '#title' => t('Preferred language of the account'),
                '#default_value' => !empty($values['preferred_language']) ? $values['preferred_language'] : cmc_registration_get_language(),
                '#description' => t('Select language of trading platform and for all correspondence') ,
                '#options' => $language_options,
                '#required' => TRUE,
                '#js_validator' => array(
                  'validators' => array(
                    'requiredValidator' => array()
                  )
                )
              );
            }
          break;
      }
    }
  }
  
  if (!empty($fields)) {
    if (!empty($group)) {
      $grouped_fields['optional_fields'] = array(
      '#type' => 'fieldset',
      '#title' => (!empty($group['title'])) ? t($group['title']) : t('Group'),
      '#description' => (!empty($group['description'])) ? t($group['description']) : "",
      '#tree' => FALSE,
     );
     
      // Check if fields are set if yes assign them to form
      if (!empty($fields)) {
        foreach($fields as $id => $field) {
          $grouped_fields['optional_fields'][$id] = $field;
        }
        return $grouped_fields;
      }
    }
  }
  
  return $fields;  
}



function _cmc_registration_live_employment_status() {
  $registration_employment_status = array(
    'Employed' => t("Employed"),
    'Self employed' => t("Self employed"),
    'Retired' => t("Retired"),
    'Student' => t("Student"),
    'Unemployed' => t("Unemployed"),
  );

  return $registration_employment_status;
}


function _cmc_registration_live_nature_of_business() {
  $registration_nature_of_business = array(
    "Accountancy" => t("Accountancy"),
    "Admin/Secretarial" => t("Admin / Secretarial"),
    "Agriculture" => t("Agriculture"),
    "Catering/Hospitality" => t("Catering / Hospitality"),
    "Creative/Media" => t("Creative / Media"),
    "Education" => t("Education"),
    "Emergency services" => t("Emergency Services"),
    "Engineering" => t("Engineering"),
    "Financial Services - Banking" => t("Financial Services - Banking"),
    "Financial Services - Insurance" => t("Financial Services - Insurance"),
    "Financial Services - Other" => t("Financial Services - Other"),
    "Government/Public Sector" => t("Government / Public Sector"),
    "Health/Medicine" => t("Health / Medicine"),
    "HM Forces" => t("Armed Forces"),
    "Human Resources" => t("Human Resources"),
    "IT" => t("IT"),
    "Legal" => t("Legal"),
    "Leisure/Entertainment/Tourism" => t("Leisure / Entertainment / Tourism"),
    "Manufacturing" => t("Manufacturing"),
    "Marketing/PR/Advertising" => t("Marketing / PR / Advertising"),
    "Other" => t("Other"),
    "Pharmaceuticals" => t("Pharmaceuticals"),
    "Property/Construction/Trades" => t("Property / Construction / Trades"),
    "Retail" => t("Retail"),
    "Sales" => t("Sales"),
    "Social Care/Services" => t("Social Care / Services"),
    "Telecommunications" => t("Telecommunications"),
    "Transport/Logistics" => t("Transport / Logistics"),
  );

  asort($registration_nature_of_business);
  return $registration_nature_of_business;
}

function _cmc_registration_live_other_source_of_funds() {
  return  array(
    'Savings & Investment' => t('Savings & Investment'),
    'Family or Partner Income' => t('Family or Partner Income'),
    'Benefits or Borrowing' => t('Benefits or Borrowing'),
    'Property Income' => t('Property Income'),
    'Part-time work' => t('Part-time work')
  );
}

function _cmc_registration_live_retired_source_of_funds() {
  return  array(
    'Savings & Investment' => t('Savings & Investment'),
    'Family or Partner Income' => t('Family or Partner Income'),
    'Benefits or Borrowing' => t('Benefits or Borrowing'),
    'Pension' => t('Pension'),
    'Property Income' => t('Property Income'),
    'Part-time work' => t('Part-time work')
  );
}

function _cmc_registration_live_experience() {
  return array(
    CMC_REGISTRATION_TRADING_EXPERIENCE_WORK => t("Work in a financial institution"),
    CMC_REGISTRATION_TRADING_EXPERIENCE_QUALIFICATION => t("Professional qualification"),
    CMC_REGISTRATION_TRADING_EXPERIENCE_BOTH => t("Both of the above"),
    CMC_REGISTRATION_TRADING_EXPERIENCE_NEITHER => t("Neither")
  );
}

function _cmc_registration_live_trading_frequency() {
  return array(
    CMC_REGISTRATION_TRADING_FREQUENCY_REGULARLY => t("Regularly"),
    CMC_REGISTRATION_TRADING_FREQUENCY_OCCASIONALLY => t("Occasionally"),
    CMC_REGISTRATION_TRADING_FREQUENCY_RARELY => t("Rarely"),
    CMC_REGISTRATION_TRADING_FREQUENCY_NEVER => t("Never")
  );
}

function _cmc_registration_live_money_ranges() {
  return array(
    "100000" => t("Over 100,000"),
    "75000" => t("50,000 - 99,999"),
    "35000" => t("20,000 - 49,999"),
    "10000" => t("Less than 20,000"),
  );
}


/*
  Returns a language identifier for use with back-end service calls.  This will mostly be the same as
  Drupal's language code, but because of the en-Custom language we do need to do some re-mapping.  Further
  re-mapping may be necessary where the front-end supports languages that the back-end does not.
*/
function cmc_registration_get_language() {
  global $language;

  $lang = explode('-', $language->language);
  return $lang[0];
}

/**
 * Implements hook_preprocess_reg_forms
 * @param type $vars 
 */
function cmc_registration_preprocess_reg_forms(&$vars) {
  /**
   * These are two most important lines else template_process throws warnings and errors.
   * Not sure why it needs empty arrays for each of these.
   */
   $vars['classes_array'] = array();
   $vars['content_attributes_array'] = $vars['attributes_array'] = $vars['title_attributes_array'] = false;

   $messages = _cmc_registration_get_form_errors();
   if(!empty($messages)) {
     $vars['messages'] = theme('cmc_registration_form_errors',  _cmc_registration_get_form_errors());
   }
}

/**
 * Helper function that 
 * @param type $url 
 */
function cmc_registration_goto($url) {
  $options = array();

  if (isset($_GET['inapp'])) {
    $options['query'] = array('inapp' => $_GET['inapp']);
  }

  drupal_goto($url, $options);
}


function cmc_registration_url_outbound_alter(&$path, &$options, $original_path) {
  if (isset($_GET['inapp']) && ($_GET['inapp'] == 1)) {
    if (substr($path, 0, 7) != 'http://') {
      $options['query']['inapp'] = 1;
    }
  }
}

/**
 * This function is being used to destory sessions once user is on registration/final/%
 * If you need to add more additional functions and prefer to call this page from other sections
 * of site , make sure you are wrapping your code in a if condition to match relevant path, else
 * this could result in unexpected behaviour
 * if(current_path() == 'foo') {
 *   -- Your code --
 * }
 */
function cmc_registration_finish() {
  //Cleanup all session data if the page thats just completed processing is final
  $path = current_path();
  if (strpos($path, '/final/')) {
    session_destroy();
  }
}

function cmc_registration_get_configs($product, $type = 'live') {
  $config = array();
  $domain = (domain_get_domain());
  $context = $domain['sitename'] . " ".strtoupper($type);

  // Retrieve General Settings
  module_load_include('inc', 'cmc_registration_nextgen', 'admin/cmc_registration_nextgen.admin' );
  $form = cmc_registration_settings_form();
  cmc_registration_get_live_config($form, $config, $product);
  // Retrieve form specific settings LIVE Vs Demo
  switch ($type) {
    case CMC_REGISTRATION_LIVE:
        module_load_include('inc', 'cmc_registration_nextgen', 'admin/cmc_registration_nextgen.admin.live' );    
        $form = cmc_registration_live_settings_form();
        cmc_registration_get_live_config($form[$product], $config, $product);
      
      break;
    
    case CMC_REGISTRATION_DEMO:
      break;
  }
 
  return array('context' => $context,
               'domain' => $domain,
               'params' => $config,
               'product' => $product,
            );
}

/**
 * Load all config vars from a given form. To be used only for admin forms that 
 * provide configurations set via variable_set
 * @param type $form
 * @param type $config
 * @return boolean 
 */
function cmc_registration_get_live_config($frm, &$config, $product = FALSE) {
  foreach (element_children($frm) as $child) {
    if ($frm[$child]['#type'] == "fieldset") {
      cmc_registration_get_live_config($frm[$child], $config, $product);
    }
    
    if (!in_array($frm[$child]['#type'], array('fieldset' ,'actions', 'submit'))){
      // Check if the variable is a node
      $key = (strpos($child, "_{$product}")) ? substr($child, 0, strpos($child, "_{$product}")) : $child;
              
      if (preg_match('/node\/.?(\\d)$/', variable_get($child))) {
        $var = explode('/', variable_get($child));
        $node = cmc_registration_node_load_translated($var[1]);
        $body = field_get_items('node', $node, 'body');
        $val = field_view_value('node', $node, 'body', $body[0]);
        $config[$key] = $val['#markup'];
      }  

      else {
        $config[$key] = variable_get($child);  
      }
    }
  }
  return $config;
}


/**
 * Returns list of language mappings
 * if langcode is passed and is part of mapping, returns appropriate langcode.
 * If no langcode is pased returns list of all language codes
 * If language code is not found, returns FALSE.
 * 
 * @param type $langcode
 * @return mixed 
 */
function cmc_registration_get_language_mapping($langcode) {
  $langcodes = array(
      'zh'  => 'zho',
      'en'  => 'eng',
      'de'  => 'deu',
  );
}


/**
 * Returns relevant translated node for in a given language
 * If no langcode is provided, then retruns traslated node in the 
 * current global language.
 * 
 * @global type $language
 * @param type $nid
 * @param type $langcode
 * @return type 
 */
function cmc_registration_node_load_translated($nid, $langcode = NULL) {
  global $language; 

  if (!$langcode) {
    $langcode = $language->language;
  }
  
  // Check to see if a node has been translated, this can be found from a 
  // attribute tnid set on node object.
  $node = node_load($nid);
  
  // Node has not been translated
  if ($node->tnid > 0 ) {
     $translations = translation_node_get_translations($node->tnid);
     if (isset($translations[$langcode])) {
       $node = node_load($translations[$langcode]->nid);
     }
  }
  
  return $node;
}