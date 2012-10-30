<?php

function aus_live_about_you($form_id, $form_state, $options = array() ) {
  $form = array();
  $values = isset($form_state['values']) ? $form_state['values'] : NULL;
  $context = (!empty($options['context']))? array('context' => $options['context']) : FALSE ;

  $form['#js_validation'] = array(
    'enabled' => TRUE,
    'handlers' => array(
      'load' => 'step3Load',
      'change' => 'nextCheck',
        
    )
  );

  $js = drupal_get_path('module', 'cmc_registration') . '/js/registration.address.js';
  $form['#attached']['js'][] = $js;

  $registration_titles = array(
    "Mr" => t("Mr", array(), $context),
    "Ms" => t("Ms", array(), $context),
    "Mrs" => t("Mrs", array(), $context),
    "Miss" => t("Miss", array(), $context),
    "Doctor" => t("Doctor", array(), $context),
  );

  $form['personaldetails'] = array(
    '#type' => 'fieldset',
    // '#title' => t('About You'),
    '#tree' => FALSE,
  );

  $form['personaldetails']['name_title'] = array(
    '#type' => 'select',
    '#options' =>  $registration_titles,
    '#title' => t('Title', array(), $context),
    '#required' => TRUE,
    '#default_value' => !empty($values['name_title'])? $values['name_title'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      ),
    )
  );

  $form['personaldetails']['gender'] = array(
    '#type' => 'select',
    '#options' => array(
      'MALE' => t('Male', array(), $context),
      'FEMALE' => t('Female', array(), $context),
    ),
    '#title' => t('Gender', array(), $context),
   // '#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'),
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
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'),
    '#required' => TRUE,
    '#default_value' => !empty($values['forename']) ? $values['forename'] : NULL,
    '#js_validator'  => array(
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
    '#required' => TRUE,
    '#default_value' => !empty($values['surname'])? $values['surname'] : NULL,
    '#js_validator'  => array(
      'validators' => array(
        'surnameValidator' => array()
      ),
    ),
  );


  // @todo can we limit selection of invalid dates?
  $form['personaldetails']['dob'] = array(
    '#type' => 'date',
    '#title' => t('Date of birth', array(), $context),
    '#description' => t('You must be 18 to open a Spread  betting / CFD account with CMC markets', array(), $context),
    '#required' => TRUE,
    '#pre_render' => array('_cmc_registration_dob_prerender'),
    '#default_value' => !empty($values['dob'])? $values['dob'] : array('year' => 0, 'month' => 0, 'day' => 0),
    '#js_validator' => array(
      'validators' => array(
        'dobValidator' => array(18),
        'dateRequiredValidator' => array(),
      ),
      'errorHandler' => 'dateErrorHandler'
    ),
  );

  $registration_nationality = _cmc_registration_live_nationality();

  $form['personaldetails']['nationality'] = array(
    '#type' => 'select',
    '#options' => $registration_nationality,
    '#required' => TRUE,
    '#title' => t('Nationality', array(), $context),
    '#default_value' => !empty($values['nationality'])? $values['nationality'] : 'Australian',
    '#js_validator' => array(
      'errorHandler' => 'nullErrorHandler'
    )
  );

  $form['youraddress'] = array(
    '#type' => 'fieldset',
    '#title' => t('Your address', array(), $context),
    '#tree' => FALSE,
  );

  $form['youraddress']['address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address line 1',  $context),
    '#description' => t('This must be your residential address. PO Boxes are not allowed. <br><br>All postal correspondence will be sent here.', array(), $context) ,
    '#required' => TRUE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['address_1'])? $values['address_1'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    )
  );

  $form['youraddress']['address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address line 2', array(), $context),
    '#required' => FALSE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['address_2'])?$values['address_2'] : NULL
  );

  $form['youraddress']['address_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Address line 3', array(), $context),
    '#required' => FALSE,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['address_3'])? $values['address_3'] : NULL
  );

  $form['youraddress']['town'] = array(
    '#type' => 'textfield',
    '#title' => t('Town / Suburb', array(), $context),
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['town'])? $values['town'] : NULL
  );

  $aus_states = _aus_live_states();

  $form['youraddress']['state'] = array(
    '#type' => 'select',
    '#title' => t('State', array(), $context),
    '#required' => TRUE,
    '#options' => $aus_states,
    '#maxlength' => CMC_REGISTRATION_GENERIC_TEXT_LENGTH,
    '#default_value' => !empty($values['state'])? $values['state'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      )
    ),
  );

  $form['youraddress']['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode', array(), $context),
    '#description' => t('Please enter the postcode of your permanent residence. <br><br> We will use this address to confirm your identity. <br><br>Click \'Get address\' and then select your full address from the list shown.', array(), $context),
    '#maxlength' => CMC_REGISTRATION_POSTCODE_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => TRUE,
    '#default_value' => !empty($values['postcode']) ? $values['postcode'] : NULL,
    '#js_validator'  => array(
      'validators' => array(
        'ausPostcodeValidator' => array(),
      ),
    ),
  );

  $form['youraddress']['get_postcode'] = array(
    '#type' => 'button',
    '#value' => t('Get Address', array(), $context),
    '#prefix' => '<div class="form-item form-type-button form-item-get-postcode">',
    '#suffix' => '</div>'
  );

  $form['youraddress']['country'] = array(
    '#type' => 'select',
    '#options' => array(
      'AUS' => t('Australia', array(), $context),
    ),

    '#title' => t('Country', array(), $context),
    '#required' => TRUE,
    '#default_value' => !empty($values['country'])? $values['country'] : 'aus',
    '#js_validator' => array()
  );

  $form['contactdetails'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact details'),
    '#tree' => FALSE,
  );

  $form['contactdetails']['phone'] = array(
    '#type' => 'telfield',

    '#title' => t('Phone', array(), $context),
    '#description' => t('Please enter a valid telephone number including area code.',array(), $context) ,

    '#maxlength' => CMC_REGISTRATION_PHONE_NUMBER_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => TRUE,
    '#default_value' => !empty($values['phone']) ? $values['phone'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'ausPhoneValidator' => array(),
        'phoneValidator' => array()
      )
    ),
  );

  $form['contactdetails']['other_phone'] = array(
    '#type' => 'telfield',
    '#title' => t('Other phone', array(), $context),

    '#description' => t('Please enter a valid telephone number including area code.',array(), $context) ,

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
 
  // Multicurrency and Multilanguage settings 
  $form = array_merge($form, _cmc_get_registration_extra_fields('live',
                        array(CMC_REGISTRATION_MULTICURRENCY, CMC_REGISTRATION_MULTILANGUAGE),
                        array('context' => $context, 'group' => array('title' => 'Account', 'description' =>'How would you like your account to be setup' ), 'product' => $options['product'])));


  $form['drivinglicense'] = array(
    '#type' => 'fieldset',
    '#title' => t('Driving licence', array(), $context),
    '#tree' => FALSE,
  );

  $form['drivinglicense']['license_no'] = array(
    '#type' => 'textfield',
    '#description' => t('Please enter your driving licence number located on the front of your driving licence.',array(), $context) ,
    '#title' => t('Driving licence number', array(), $context),
    '#maxlength' => 9, // @todo make this a constant
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['license_no']) ? $values['license_no'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'drivingLicenseValidator' => array('#edit-license-card-no', '#edit-state', '#edit-license-expiry-date'),
      ),
      'subscribe' => array('#edit-license-card-no', '#edit-license-expiry-date', '#edit-state')
    )
  );

  $form['drivinglicense']['license_card_no'] = array(
    '#type' => 'textfield',
    '#description' => t('Please enter your licence card number located on the top right of your driving licence.', array(), $context) ,
    '#title' => t('Licence card number', array(), $context),
    '#maxlength' => 10, // @todo make this a constant?
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#default_value' => !empty($values['license_card_no'])? $values['license_card_no'] : NULL,
    '#states' => array(
      'visible' => array(
        ':input[name=state]' => array('value' => 'NSW')
      )
    ),
    '#js_validator' => array(
      'validators' => array(
        'drivingLicenseCardNumberValidator' => array('#edit-license-no', '#edit-state'),
      ),
      'ignore' => array(
        'ignoreIfNotVal' => array(':input[name=state]', 'NSW'),
      ),
      'subscribe' => array('#edit-license-no', '#edit-state')
    ),
  );

  $form['drivinglicense']['license_expiry_date'] = array(
    '#type' => 'date',
    '#required' => FALSE,
    '#title' => t('Licence expiry date', array(), $context),
    '#pre_render' => array('_cmc_registration_license_prerender'),
    '#default_value' => !empty($values['license_expiry_date'])? $values['license_expiry_date'] : array('year' => 0, 'month' => 0, 'day' => 0),
    '#states' => array(
      'visible' => array(
        ':input[name=state]' => array('value' => 'WA')
      )
    ),
    '#element_validate' => array('aus_live_license_expiry_date_validate'),
    '#js_validator' => array(
      'validators' => array(
        'drivingLicenseExpiryValidator' => array('#edit-license-no', '#edit-state')
      ),
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-state', 'WA'),
        'ignoreIfEmpty' => array('#edit-license-no')
      ),
      'subscribe' => array('#edit-license-no', '#edit-state')
    )
  );

   
  $form['bankdetails'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bank details', array(), $context),
    '#tree' => FALSE,
  );

  $form['bankdetails']['bsb_code'] = array(
    '#type' => 'textfield',
    '#title' => t('BSB Code', array(), $context),
    '#description' => ($form_state['step_info'][1]['stored_values']['account_type'] == CA || $form_state['step_info'][1]['stored_values']['account_type'] == TAI || $form_state['step_info'][1]['stored_values']['account_type'] == TAC) ? t('This account must be held in the same name as that of your CMC trading account. e.g. ABC Pty Limited', array(), $context) : t('Please enter your Bank State Branch (BSB) code.', array(), $context),
    '#maxlength' => CMC_REGISTRATION_BSB_CODE_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => FALSE,
    '#default_value' => !empty($values['bsb_code']) ? $values['bsb_code'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'bsbValidator' => array(),
        'requiredIfSetValidator' => array('#edit-account-number')
      ),
      'subscribe' => array('#edit-account-number')
    )
  );

  $form['bankdetails']['account_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Account number', array(), $context),
    '#description' => t('Please enter your bank account number.', array(), $context),
    '#maxlength' => CMC_REGISTRATION_AUS_ACCOUNT_NUMBER_LENGTH,
    '#size' => CMC_REGISTRATION_FIELD_WIDTH,
    '#required' => FALSE,
    '#default_value' => !empty($values['account_number'])? $values['account_number'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'bankAccountValidator' => array(),
        'requiredIfSetValidator' => array('#edit-bsb-code')
      ),
      'subscribe' => array('#edit-bsb-code')
    )
  );


  return $form;
}

function aus_live_license_expiry_date_validate($element, &$form_state, $form) {
  $value = $element['#value'];

  $license_blank = strlen($form_state['values']['license_no']) == 0;
  $date_blank = $value['month'] == 0 && $value['day'] == 0 && $value['year'] == 0;

  if ($license_blank && $date_blank) {
    return;
  }

  if ($form_state['values']['state'] != 'WA') {
    return;
  }

  date_validate($element);
}


/********************************************************************
 *  ALL FORM VALIDATORS
 ********************************************************************/

function aus_live_about_you_validate($form, &$form_state) {
  module_load_include('inc', 'cmc_registration', 'cmc_registration.validate');
  $values = $form_state['values'];

  $bank_values_set = (strlen($values['bsb_code']) > 0) || (strlen($values['account_number']) > 0);

  if (!isset($_SESSION['bank_warning'])) {
    $_SESSION['bank_warning'] = 0;
    $_SESSION['bank_isvalid'] = FALSE;
  }

  $bank_warning_level =& $_SESSION['bank_warning'];

  if ($bank_values_set) {
    if (($bank_warning_level < 2) && !cmc_registration_validate_bank_account($values['sortcode'], $values['account'])) {
      $_SESSION['bank_isvalid'] = FALSE;
      $bank_warning_level = $bank_warning_level + 1;  
      if ($bank_warning_level === 1) {
        form_set_error('account_number', t('Your bank details could not be validated, please check and try again'));
      } elseif ($bank_warning_level === 2) {
        form_set_error('account_number', t('Your bank details could not be validated, however please continue with your application'));
      }
    } 
    else {
      $_SESSION['bank_isvalid'] = TRUE;
    }
  }
  
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

  if (!empty($values['driving_license_expiry'])) {
    if(!_cmc_registration_validate_rules('driving_license_expiry', $values['license_expiry_date'])) {
      form_set_error('drivinglicense][license_no', 'Expiry date of driving license cannot be in past');
    }
  }

  // Bank code check
  if(empty($values['bsb_code']) || (empty($values['account_number']))) {
    $form_state['bsb_code_warning'] = TRUE;
  }

  if (!empty($values['bsb_code'])) {
    if (!is_numeric($values['bsb_code']) || (strlen(strval($values['bsb_code'])) < 6) ) {
      form_set_error('bsb_code', 'BSB code is invalid');
    }
  }

  if (!empty($values['account_number']) && !is_numeric($values['account_number'])) {
    form_set_error('account_number', 'Account number is invalid');
  }

  // Special case for NSW State

  if ($values['state'] == "NSW" && !empty($values['license_no']) && (empty($values['license_card_no']))) {
    form_set_error('license_no', t('Driving license number required for given lincense card number'));
  }

  if ($values['state'] == "NSW" && !empty($values['license_card_no']) && (empty($values['license_no']))) {
    form_set_error('license_card_no', t('License card number only required when driving license issued in New South Wales'));
  }

   _cmc_registration_get_form_errors();

}
