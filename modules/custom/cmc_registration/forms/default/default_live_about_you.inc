<?php

function default_cmc_registration_live_about_you($form_id, $form_state, $options) {
  $form = array();
  $values = isset($form_state['values']) ? $form_state['values'] : NULL;
  $context = (!empty($options['context']))? array('context' => $options['context']) : FALSE ;

  $values = isset($form_state['values']) ? $form_state['values'] : NULL;

  $js = drupal_get_path('module', 'cmc_registration') . '/js/registration.address.js';
  $form['#attached']['js'][] = $js;

  $form['#js_validation'] = array(
    'enabled' => TRUE,
    'handlers' => array(
      'load' => 'step3Load',
      'change' => 'nextCheck',
    ),
  );
  
  
  if(module_exists('domain')) {
    $domain = domain_get_domain();
    if($domain && !empty($domain['machine_name'])) {
      $region = $domain['machine_name'];
    }

    if(function_exists('cmc_titles_'.$region)) {
      $registration_titles = call_user_func_array('cmc_titles_'.$region, array());
    } else {
      $registration_titles = cmc_default_titles($context);
    }
  } else {
    $registration_titles = cmc_default_titles($context);
  }

  $form['personaldetails'] = array(
    '#type' => 'fieldset',
   // '#title' => t('About You'),
    '#tree' => FALSE,
  );

  $form['personaldetails']['name_title'] = array(
    '#type' => 'select',
    '#options' =>  $registration_titles,
    '#title' => t('Title'),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.')."<span></span>",
    '#required' => TRUE,
    '#default_value' => !empty($values['name_title'])? $values['name_title'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    )
  );

  $form['personaldetails']['gender'] = array(
    '#type' => 'select',
    '#options' => array(
      'MALE' => t('Male', array(), $context),
      'FEMALE' => t('Female', array(), $context),
    ),
    '#title' => t('Gender'),
   // '#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.')."<span></span>",
    '#required' => TRUE,
    '#default_value' => !empty($values['gender'])? $values['gender'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    )
  );

  $form['personaldetails']['forename'] = array(
    '#type' => 'textfield',
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#title' => t('First name', array(), $context),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.')."<span></span>",
    '#required' => TRUE,
    '#default_value' => !empty($values['forename']) ? $values['forename'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'forenameValidator' => array(),
      ),
    ),
  );

  $form['personaldetails']['surname'] = array(
    '#type' => 'textfield',
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#title' => t('Surname', array(), $context),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.')."<span></span>",
    '#required' => TRUE,
    '#default_value' => !empty($values['surname'])? $values['surname'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'surnameValidator' => array()
      ),
    ),
  );


  // @todo can we limit selection of invalid dates?
  $form['personaldetails']['dob'] = array(
    '#type' => 'date',
    '#title' => t('Date of birth', array(), $context),
    '#description' => t('You must be 18 to open a Spread  betting / CFD account with CMC markets', array(), $context)."<span></span>",
    '#required' => TRUE,
    '#pre_render' => array('_cmc_registration_dob_prerender'),
    '#default_value' => !empty($values['dob'])? $values['dob'] : array('year' => 0, 'month' => 0, 'day' => 0),
    '#js_validator' => array(
      'validators' => array(
        'dobValidator' => array(18)
      ),
      'errorHandler' => 'dateErrorHandler'
    ),
  );
  
   if(module_exists('domain')) {
    $domain = domain_get_domain();
    if($domain && !empty($domain['machine_name'])) {
      $region = $domain['machine_name'];
    }

    if(function_exists('cmc_country_'.$region)) {
      $region = call_user_func_array('cmc_country_'.$region, array());
    } else {
      $region = cmc_country_default($context);
    }
  } else {
    $region = NULL;
  }
  
  $registration_nationality = _cmc_registration_live_nationality();
  $form['personaldetails']['nationality'] = array(
    '#type' => 'select',
    '#options' => $registration_nationality,
    '#required' => TRUE,
    '#title' => t('Nationality', array(), $context),
    '#default_value' => !empty($values['nationality'])? $values['nationality'] : $region['nationality'],
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'errorHandler' => 'nullErrorHandler'
    )
  );

  $form['youraddress'] = array(
    '#type' => 'fieldset',
    '#title' => t('Your address', array(), $context),
    '#tree' => FALSE,
  );

  $form['youraddress']['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode', array(), $context),
    '#description' => t('Please enter the postcode of your permanent residence. <br><br> We will use this address to confirm your identity. <br><br>Click \'Get address\' and then select your full address from the list shown.', array(), $context)."<span></span>",
    '#maxlength' => CMC_REGISTRATION_POSTCODE_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => TRUE,
    '#default_value' => !empty($values['postcode']) ? $values['postcode'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'postcodeValidator' => array(),
      ),
    ),
  );

  $form['youraddress']['get_postcode'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="form-item form-type-button form-item-get-postcode ">',
    '#markup' => '<input class="noEnterSubmit form-submit" type="button" id="edit-get-postcode" name="get_postcode" value="' .t('Get Address', array(), $context) .'">',
    '#suffix' => '</div>',
    
  );

  $form['youraddress']['address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address Line 1', array(), $context),
    '#description' => t('Your registered residential address. <br><br>All postal correspondence will be sent here.', array(), $context)."<span></span>",
    '#required' => TRUE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['address_1'])? $values['address_1'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      ),
    ),
  );

  $form['youraddress']['address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address Line 2', array(), $context),
    '#required' => FALSE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['address_2'])?$values['address_2'] : NULL
  );

  $form['youraddress']['address_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Address Line 3', array(), $context),
    '#required' => FALSE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['address_3'])? $values['address_3'] : NULL
  );

  $form['youraddress']['town'] = array(
    '#type' => 'textfield',
    '#title' => t('Town', array(), $context),
    '#required' => TRUE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['town'])? $values['town'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      ),
    ),
  );

  $form['youraddress']['county'] = array(
    '#type' => 'textfield',
    '#title' => t('County', array(), $context),
    '#required' => FALSE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['country'])? $values['county'] : NULL
  );
 
  $form['youraddress']['country'] = array(
    '#type' => 'select',
    '#options' => array(
      'GBR' => t('United Kingdom', array(), $context),
      'IMN' => t('Isle of Man', array(), $context),
      'JEY' => t('Jersey', array(), $context),
      'GGY' => t('Guernsey', array(), $context),
    ),
    '#title' => t('Country', array(), $context),
    '#required' => TRUE,
    '#default_value' => !empty($values['country'])? $values['country'] : $region['country'],
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
    ),
  );

  $form['contactdetails'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact details', array(), $context),
    '#tree' => FALSE,
  );

  $form['contactdetails']['phone'] = array(
    '#type' => 'telfield',

    '#title' => t('Contact phone number', array(), $context),
    '#description' => t('Please enter a valid telephone number including area code. <br><br>
                         If you are outside of UK, Please include your country code e.g +44 (0)203 123456789', array(), $context)."<span></span>",

    '#maxlength' => CMC_REGISTRATION_PHONE_NUMBER_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => TRUE,
    '#default_value' => !empty($values['phone']) ? $values['phone'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'phoneValidator' => array()
      )
    ),
  );

  $form['contactdetails']['other_phone'] = array(
    '#type' => 'telfield',
    '#title' => t('Other phone', array(), $context),

    '#description' => t('Please enter a valid telephone number including area code. <br><br>
                         If you are outside of UK, Please include your country code e.g +44 (0)203 123456789', array(), $context)."<span></span>",

    '#maxlength' => CMC_REGISTRATION_PHONE_NUMBER_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => FALSE,
    '#default_value' => !empty($values['other_phone'])? $values['other_phone'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'otherPhoneValidator' => array()
      ),
    ),
   );

   // If a region is set for multi currency then show additinal drop down to choose currency
   // Settings for multilanguage and multicurrency

  $form = array_merge($form, _cmc_get_registration_extra_fields('live',
                        array(CMC_REGISTRATION_MULTICURRENCY, CMC_REGISTRATION_MULTILANGUAGE), 
                        array('context' => $context, 'group' => array('title' => 'Account', 'description' => 'How would you like your account to be setup' ), 'product' => $options['product']))); 
  return $form;
}


/********************************************************************
 *  ALL FORM VALIDATORS
 ********************************************************************/

function default_cmc_registration_live_about_you_validate($form, $form_state) {

  module_load_include('inc', 'cmc_registration', 'cmc_registration.validate');
  $values = $form_state['values'];

  if (!_cmc_registration_validate_rules('name', $values['forename'])) {
    form_set_error('forename', 'The Forename you entered is invalid');
  }

  if (!_cmc_registration_validate_rules('name', $values['surname'])) {
    form_set_error('surname', 'The Surname you entered is invalid');
  }

  if (!_cmc_registration_validate_rules('phone', $values['phone'])) {
    form_set_error('phone', 'The phone number you entered is invalid');
  }

  if (!empty($values['other_phone'])) {
    if(!_cmc_registration_validate_rules('phone', $values['other_phone'])) {
      form_set_error('other_phone', 'The phone number you entered is invalid');
    }
  }
  if(!_cmc_registration_validate_rules('dob', $values['dob'])) {
    form_set_error('dob', 'The date of birth you entered is invalid, You must be over ' .CMC_REGISTRATION_MIN_AGE .' to signup with CMC Markets');
  }
   _cmc_registration_get_form_errors();

}
