<?php

function cmc_registration_live_form($form_id, $form_state, $config) {

// start the for BG
  $context = array('context' => $config['context']);
   $form['maincontent'] = array(
   		'#tree' => FALSE,
      '#prefix' => '<div class="bg"><div class="reqd">Required fields <span>*</span></div>',
      '#suffix' => '</div>'
   );


// step 1

	$form['maincontent']['register'] = array(
	   '#type' => 'fieldset',
		'#title' => t('Register', array(), $context),
		'#attributes' => array('class' => array('one')),

	  );

  $form['maincontent']['register']['already_registered'] = array(
    '#type' => 'radios',

    '#options' => array(CMC_ALREADY_REGISTERED_YES => t(CMC_ALREADY_REGISTERED_YES),
                        CMC_ALREADY_REGISTERED_NO => t(CMC_ALREADY_REGISTERED_NO)),
    '#title' => t('Have you previously registered an email address with CMC Markets Next Generation trading?', array(), $context),
    '#default_value' => isset($values['already_registered'])
    ? $values['already_registered'] : CMC_ALREADY_REGISTERED_NO,
  );
  
  $form['maincontent']['register']['existing_user'] = array(
    '#type' => 'fieldset',
		'#title' => t('Existing account', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_YES)
      )
    )
  );

  $form['maincontent']['register']['existing_user']['email'] = array(
    '#type' => 'textfield',
     '#title' => t('Registered email address', array(), $context),
    '#default_value' => !empty($values['email']) ? $values['email'] : NULL,
    '#description' => t('<p>Please enter your existing email address to apply for a live account.</p>', array(), $context),

		'#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_YES)
      ),
      'required' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_YES)
      )
    ),
    '#js_validator' => array(
      'ignore' => array(
        'ignoreIfChecked' => array('#edit-already-registered-no'),
      ),
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'errorHandler' => 'nullErrorHandler',
    ),

  );

  $form['maincontent']['register']['existing_user']['password'] = array(
    '#type' => 'password',
    '#title' => t('Password', array() , $context),

    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_YES)
      ),
      'required' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_YES)
      )
    ),
    '#description' => t('Your CMC Markets Next Generation trading password', array(), $context),
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'ignore' => array(
        'ignoreIfChecked' => array('#edit-already-registered-no'),
      ),
      'errorHandler' => 'nullErrorHandler',
    )
  );
  
  
   $form['maincontent']['register']['new_user'] = array(
    '#type' => 'fieldset',
		'#title' => t('New account', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      )
    )
  );

  $form['maincontent']['register']['new_user']['new_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address', array() , $context),

    '#default_value' => !empty($values['new_email']) ? $values['new_email'] : NULL,
    '#description' => t('<p>Please enter a valid email address.</p><p>We will send an activation link to your $your email address at the end of the application process.</p>', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      ),
      'required' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      )
    ),
    '#js_validator' => array(
     'default' => array(
        'ignore' => array(
          'ignoreIfChecked' => array('#edit-already-registered-yes'),
        ),
        'validators' => array(
          'emailValidator' => array(),
        ),
      ),
      'zh' => array(
        'ignore' => array(
          'ignoreIfChecked' => array('#edit-already-registered-yes'),
        ),
        'validators' => array(
          'requiredValidator' => array(),
        ),

      )
    ),
  );

    $form['maincontent']['register']['new_user']['new_email_confirm'] = array(
    '#type' => 'textfield',
    '#title' => t('Confirm email address', array() , $context),

    '#default_value' => !empty($values['new_email_confirm']) ? $values['new_email_confirm'] : NULL,
    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      ),
      'required' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      )
    ),
    '#js_validator' => array(
      'default' => array(
        'ignore' => array(
          'ignoreIfChecked' => array('#edit-already-registered-yes'),
        ),
        'validators' => array(
          'ukEmailConfirmValidator' => array('#edit-new-email', FALSE),
        ) 
      ),
      'zh' => array(
        'ignore' => array(
            'ignoreIfChecked' => array('#edit-already-registered-yes'),
        ),
        'validators' => array(
            'requiredValidator' => array('#edit-new-email', FALSE),
        )
      )
    ),
  );

    $form['maincontent']['register']['new_user']['pass1'] = array(
    '#type' => 'password',
    '#title' => t('Password', array() , $context),

    '#description' =>  t('<p>For security your password should be:</p><ul><li>Between 6 and 15 characters long.</li><li>Must contain at least one lower case character and one number.</li><li>Cannot be the same as your email address.</li></ul>',array(), $context) ,
    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      ),
      'required' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      )
    ),
    '#js_validator' => array(
     'default' => array(
       'ignore' => array(
         'ignoreIfChecked' => array('#edit-already-registered-yes'),
       ),
       'validators' => array(
          'passwordValidator' => array('#edit-new-email')
       ),
     ),
     'zh' => array(
      'ignore' => array(
         'ignoreIfChecked' => array('#edit-already-registered-yes'),
       ),
       'validators' => array(
         'requiredValidator' => array('#edit-new-email')
       ),
      )
    ),
  );
    
     $form['maincontent']['register']['new_user']['pass2'] = array(
    '#type' => 'password',
    '#title' => t('Confirm password', array() , $context),

    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      ),
      'required' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_NO)
      )
    ),
    '#js_validator' => array(
      'default' => array(
        'ignore' => array(
          'ignoreIfChecked' => array('#edit-already-registered-yes'),
        ),
	'validators' => array(
          'ukPasswordConfirmValidator' => array('#edit-pass1', FALSE, '#edit-new-email'),
        ),
      ),
      'zh' => array(
        'ignore' => array(
          'ignoreIfChecked' => array('#edit-already-registered-yes'),
        ),
	'validators' => array(
          'requiredValidator' => array('#edit-pass1', FALSE, '#edit-new-email'),
        ),
      )
    ),
  );

// end step 1
  
//  RISK Warning

	$form['maincontent']['risk_warning'] = array(
	   '#type' => 'fieldset',
		'#title' => t('Risk warning', array(), $context),
		'#attributes' => array('class' => array('risk')),

	  );

    $form['maincontent']['risk_warning']['terms'] = array(
    '#prefix'  =>  '<div class="row dec"><div class="scroll" >',
    '#markup' => '<h2> CFD RISK WARNING</h2><p>Risk Warning Notice for CFD and Form 13</p>

<p>t is important that you read and understand the documents below before accepting them. Upon accepting you will be directed to next step.</p>

<p>Please scroll down to ensure that you have read the documents</p>

<p>Risk Warning Notice for CFD</p>

<p>CMC Markets Singapore Pte. Ltd. (referred to below as “CMC Markets”, “we”, “us” or “our”) is committed to treating you fairly. In this notice, we try to provide you with information to help you understand the nature and risks of our contracts for differences (“CFD”, whether singular or plural as the case may be). However, this notice does not and cannot explain all of the risks and other significant aspects involved in investing in CFD. You should take sufficient time to read all the relevant information that we provide to you, including this risk warning notice, our Terms of Business, our Order Execution Policy Summary for CFDs, and the information on our website and platform.</p>

<p>CFD is a leveraged product and can carry a high risk to your capital as prices may move rapidly against you. With leveraged products and if you invest on leverage, you can lose more than your initial investment and you may be required to make further payments. Please note that the higher the leverage, the higher the risks involved.</p>

<p>You should not enter into any transactions with us unless you fully understand the risks involved. In any case, you should seek your own independent professional advice.</p>

    CFD may not be appropriate for you',
    '#suffix'  =>  '</div>',
  );
 
    
    
    
    
  $form['maincontent']['risk_warning']['agree_risk_warning'] = array(
		
    '#type' => 'checkbox',
    '#title' => t('I have read Risk warning and agree'),
		'#prefix'  =>  '<div class="agree">', 
		'#suffix'  =>  '</div></div>',
  );

// end risk warning
// step 2  
  
  $form['maincontent']['about_you'] = array(
    '#type' => 'fieldset',
    '#title' => t('About You'),
		'#attributes' => array('class' => array('two')),
    '#tree' => FALSE,
  );
  $form['maincontent']['about_you']['personaldetails'] = array(
    '#type' => 'fieldset',
		'#title' => t('Personal Details', array(), $context),
    '#tree' => FALSE,
  );

  $titles = array(
        "Mr" => t("Mr"),
       	"Ms" => t("Ms"),
        "Mrs" => t("Mrs"),
        "Miss" => t("Miss"),
        "Doctor" => t("Doctor"),
      );
  
  $form['maincontent']['about_you']['personaldetails']['name_title'] = array(
    '#type' => 'select',
    '#options' =>  $titles, 
		'#prefix'  =>  '<div class="title">',
		
    '#title' => t('Title & Gender'),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'),
    '#required' => FALSE,
    '#default_value' => !empty($values['name_title'])? $values['name_title'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    )
  );

  $form['maincontent']['about_you']['personaldetails']['gender'] = array(
    '#type' => 'select',
		'#suffix'  =>  '</div>',
    '#options' => array(
      'MALE' => t('Male', array(), $context),
      'FEMALE' => t('Female', array(), $context),
    ),
    
    //'#description' => t('<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.</p>'),
    '#required' => FALSE,
    '#default_value' => !empty($values['gender'])? $values['gender'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    )
  );

  $form['maincontent']['about_you']['personaldetails']['forename'] = array(
    '#type' => 'textfield',

    '#title' => t('First name', array(), $context),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'),
    '#required' => FALSE,
    '#default_value' => !empty($values['forename']) ? $values['forename'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'forenameValidator' => array(),
      ),
    ),
  );

  $form['maincontent']['about_you']['personaldetails']['surname'] = array(
    '#type' => 'textfield',

    '#title' => t('Surname', array(), $context),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'),
    '#required' => FALSE,
    '#default_value' => !empty($values['surname'])? $values['surname'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'surnameValidator' => array()
      ),
    ),
  );


  // @todo can we limit selection of invalid dates?
  $form['maincontent']['about_you']['personaldetails']['dob'] = array(
    '#type' => 'date',
		'#title' => t('Date of birth', array(), $context),
    '#description' => t('<p>You must be 18 to open a Spread  betting / CFD account with CMC markets</p>', array(), $context),
    '#required' => FALSE,
    '#pre_render' => array('_cmc_registration_dob_prerender'),
    '#default_value' => !empty($values['dob'])? $values['dob'] : array('year' => 0, 'month' => 0, 'day' => 0),
    '#js_validator' => array(
      'validators' => array(
        'dobValidator' => array(18)
      ),
      'errorHandler' => 'dateErrorHandler'
    ),
  );
  
  $registration_nationality = _cmc_registration_live_nationality();

  $form['maincontent']['about_you']['personaldetails']['nationality'] = array(
    '#type' => 'select',

    '#options' => $registration_nationality,
    '#required' => FALSE,
    '#title' => t('Nationality', array(), $context),
   // '#default_value' => !empty($values['nationality'])? $values['nationality'] : $region['nationality'],
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'errorHandler' => 'nullErrorHandler'
    )
  );
	$form['maincontent']['about_you']['contact'] = array(
    '#type' => 'fieldset',
		'#title' => t('Contact', array(), $context),
   '#tree' => FALSE,
  );



  $form['maincontent']['about_you']['contact']['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode', array(), $context),
    '#description' => t('<p>Please enter the postcode of your permanent residence. <br><br> We will use this address to confirm your identity. <br><br>Click \'Get address\' and then select your full address from the list shown.</p>', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['postcode']) ? $values['postcode'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'postcodeValidator' => array(),
      ),
    ),
  );

  $form['maincontent']['about_you']['contact']['get_postcode'] = array(
    '#type' => 'markup',
    '#markup' => '<input class="noEnterSubmit form-submit" type="button" id="edit-get-postcode" name="get_postcode" value="' .t('Get Address', array(), $context) .'">',
    
    
  );

  $form['maincontent']['about_you']['contact']['address_1'] = array(
    '#type' => 'textfield',

    '#title' => t('Address Line 1', array(), $context),
    '#description' => t('<p>Your registered residential address.</p><p>All postal correspondence will be sent here.</p>', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['address_1'])? $values['address_1'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      ),
    ),
  );

  $form['maincontent']['about_you']['contact']['address_2'] = array(
    '#type' => 'textfield',

    '#title' => t('Address Line 2', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['address_2'])?$values['address_2'] : NULL
  );

  $form['maincontent']['about_you']['contact']['address_3'] = array(
    '#type' => 'textfield',

    '#title' => t('Address Line 3', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['address_3'])? $values['address_3'] : NULL
  );

  $form['maincontent']['about_you']['contact']['address_4'] = array(
    '#type' => 'textfield',

    '#title' => t('Town', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['town'])? $values['town'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      ),
    ),
  );

  $form['maincontent']['about_you']['contact']['address_5'] = array(
    '#type' => 'textfield',

    '#title' => t('County', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['country'])? $values['county'] : NULL
  );
 
  $form['maincontent']['about_you']['contact']['country'] = array(
    '#type' => 'select',
    '#options' => array(
      'GBR' => t('United Kingdom', array(), $context),
      'IMN' => t('Isle of Man', array(), $context),
      'JEY' => t('Jersey', array(), $context),
      'GGY' => t('Guernsey', array(), $context),
    ),
    '#title' => t('Country', array(), $context),

    '#required' => FALSE,
    '#default_value' => !empty($values['country'])? $values['country'] : $region['country'],
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
    ),
  );



  $form['maincontent']['about_you']['contact']['phone'] = array(
    '#type' => 'telfield',

    '#title' => t('Contact phone number', array(), $context),
    '#description' => t('<p>Please enter a valid telephone number including area code.</p><p>If you are outside of UK, Please include your country code e.g +44 (0)203 123456789</p>', array(), $context),

    '#required' => FALSE,
    '#default_value' => !empty($values['phone']) ? $values['phone'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'phoneValidator' => array()
      )
    ),
  );

  $form['maincontent']['about_you']['contact']['other_phone'] = array(
    '#type' => 'telfield',

    '#title' => t('Other phone', array(), $context),

    '#description' => t('<p>Please enter a valid telephone number including area code.</p><p>If you are outside of UK, Please include your country code e.g +44 (0)203 123456789</p>', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['other_phone'])? $values['other_phone'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'otherPhoneValidator' => array()
      ),
    ),
   );
  

// end step 2
// step 3
  
  $form['maincontent']['financials'] = array(
    '#type' => 'fieldset',
		'#attributes' => array('class' => array('three')),
    '#title' => t('Financial Background', array(), $context),
    '#tree' => FALSE,
  );

  $registration_employment_status = _cmc_registration_live_employment_status();
  $form['maincontent']['financials']['employment_status'] = array(
    '#type' => 'select',

    '#options' => $registration_employment_status,
    '#title' => t('Employment status', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['employment_status']) ? $values['employment_status'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    )
  );

  $form['maincontent']['financials'] ['employed'] = array(
    '#type' => 'fieldset',
		'#title' => t('Employed', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      )
    ),
    '#tree' => true,
  );

  $form['maincontent']['financials']['employed']['job_title'] = array(
    '#type' => 'textfield',

    '#title' => t('Job Title', array(), $context),
    '#description' => t('<p>Please note that we do not contact your employer for references as part of this registration.</p>', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      ),
      'required' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      ),
    ),
    '#default_value' => !empty($values['employed']['job_title']) ? $values['employed']['job_title'] : NULL,
    '#js_validator' => array(
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Employed'),
      ),
      'validators' => array(
        //'requiredValidator' => array(),
        'jobTitleValidator' => array(), 'jobTitleValidator' => array(),
      ),
      'subscribe' => array('#edit-employment-status')
    ),
  );

  $form['maincontent']['financials']['employed']['company_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Company Name', array(), $context),

    '#description' => t('<p>Please note that we do not contact your employer for references as part of this registration.</p>', array(), $context),

    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      ),
      'required' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      ),
    ),
    '#default_value' => !empty($values['employed']['company_name']) ? $values['employed']['company_name'] : NULL,
    '#js_validator' => array(
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Employed'),
      ),
      'validators' => array(
        'companyNameValidator' => array(),
        'requiredValidator' => array(),
      ),
      'subscribe' => array('#edit-employment-status')
    ),
  );



  $function = "_cmc_registration_live_nature_of_business" .$suffix;

 
 
  $registration_nature_of_business = _cmc_registration_live_nature_of_business($options);
  $form['maincontent']['financials']['employed']['business_nature'] = array(
    '#type' => 'select',

    '#options' => $registration_nature_of_business,
    '#title' => t('Nature of business', array(), $context),
    //'#description' => t('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      ),
      'required' => array(
        ':input[name=employment_status]' => array('value' => 'Employed')
      ),
    ),
    '#default_value' => !empty($values['employed']['business_nature']) ? $values['employed']['business_nature'] : NULL,
    '#js_validator' => array(
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Employed'),
      ),
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'subscribe' => array('#edit-employment-status')
    ),
  );

  $form['maincontent']['financials'] ['self_employed'] = array(
    '#type' => 'fieldset',
		'#title' => t('Self Employed', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Self employed')
      ),
    ),
    '#tree' => TRUE,
  );

  $form['maincontent']['financials']['self_employed']['business_name'] = array(
    '#type' => 'textfield',

    '#title' => t('Business Name', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Self employed')
      ),
      'required' => array(
        ':input[name=employment_status]' => array('value' => 'Self employed')
     ),
    ),
    '#default_value' => !empty($values['self_employed']['business_name']) ? $values['self_employed']['business_name'] : NULL,
    '#description' => t('<p>Please enter the registered business name</p>', array(), $context),
    '#js_validator' => array(
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Self employed'),
      ),
      'validators' => array(
        'businessNameValidator' => array(),
        'requiredValidator' => array(),
      ),
      'subscribe' => array('#edit-employment-status')
    ),
  );

  $form['maincontent']['financials']['self_employed']['business_nature'] = array(
    '#type' => 'select',

    '#options' => $registration_nature_of_business,
    '#title' => t('Nature of business', array(), $context),
    '#states' =>  array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Self employed')
      ),
      'required' => array(
        ':input[name=employment_status]' => array('value' => 'Self employed')
      ),
    ),
    '#default_value' => !empty($values['self_employed']['business_nature']) ? $values['self_employed']['business_nature'] : NULL,
    '#js_validator' => array(
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Self employed'),
      ),
      'validators' => array(
        'requiredValidator' => array()
      ),
      'subscribe' => array('#edit-employment-status')
    ),
  );


  $form['maincontent']['financials']['retired'] = array(
    '#type' => 'fieldset',
		'#title' => t('Retired', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Retired')
      ),
    ),
    '#tree' => TRUE,
  );

  
  $retired_source_of_funds = _cmc_registration_live_retired_source_of_funds();
  $form['maincontent']['financials']['retired']['source_of_funds'] = array(
    '#type' => 'select',

    '#options' => $retired_source_of_funds,
    '#title' => t('Source of funds', array(), $context),
    '#states' => array(
      'visible' => array(
        ':input[name=employment_status]' => array('value' => 'Retired')
      ),
      'required' => array(
        ':input[name=employment_status]' => array('value' => 'Retired')
      ),
    ),
    '#default_value' => !empty($values['retired']['source_of_funds']) ? $values['retired']['source_of_funds'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Retired'),
      ),
      'subscribe' => array('#edit-employment-status')
    )
  );

  $form['maincontent']['financials']['student'] = array(
    '#type' => 'fieldset',
		'#title' => t('Student', array(), $context),
    '#states' => array(
      'visible' => array(':input[name=employment_status]' => array('value' => 'Student')),
    ),

    '#tree' => TRUE,
  );


 $other_source_of_funds = _cmc_registration_live_other_source_of_funds();
 $form['maincontent']['financials']['student']['source_of_funds'] = array(
    '#type' => 'select',

    '#options' => $other_source_of_funds,
    '#title' => t('Source of funds', array(), $context),
    '#states' => array(
      'visible' => array(':input[name=employment_status]' => array('value' => 'Student')),
      'required' => array(':input[name=employment_status]' => array('value' => 'Student')),
    ),
    '#default_value' => !empty($values['student']['source_of_funds']) ? $values['student']['source_of_funds'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Student'),
      ),
      'subscribe' => array('#edit-employment-status')
    )
  );


 $form['maincontent']['financials']['unemployed'] = array(
    '#type' => 'fieldset',
		'#title' => t('Un-Employed', array(), $context),
    '#states' => array(
      'visible' => array(':input[name=employment_status]' => array('value' => 'Unemployed')),
    ),

    '#tree' => TRUE,
  );

  $form['maincontent']['financials']['unemployed']['source_of_funds'] = array(
    '#type' => 'select',

    '#options' => $other_source_of_funds,
    '#title' => t('Source of funds', array(), $context),
    '#states' => array(
      'visible' => array(':input[name=employment_status]' => array('value' => 'Unemployed')),
      'required' => array(':input[name=employment_status]' => array('value' => 'Unemployed')),
    ),
    '#default_value' => !empty($values['unemployed']['source_of_funds']) ? $values['unemployed']['source_of_funds'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array(),
      ),
      'ignore' => array(
        'ignoreIfNotVal' => array('#edit-employment-status', 'Unemployed'),
      ),
      'subscribe' => array('#edit-employment-status')
    )
  );


  $registration_income = _cmc_registration_live_money_ranges();

  $form['maincontent']['financials']['annual_income'] = array(
    '#type' => 'select',

    '#options' => $registration_income,
    '#title' => t('Annual income (@currency_code)', array('@currency_code' => variable_get('cmc_registration_currency')), $context),
    '#description' => t('<p>Salary, pension or returns from your savings and investments.</p>', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['annual_income']) ? $values['annual_income'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  ); 
  

  $registration_net_worth = _cmc_registration_live_money_ranges();

  $form['maincontent']['financials']['net_worth'] = array(
    '#type' => 'select',

    '#options' => $registration_net_worth,
    '#title' => t('Net worth (@currency_code)', array('@currency_code' => variable_get('cmc_registration_currency')), $context),
    '#description' => t('<p>The total value of your assets excluding mortgaged property and salary.</p>', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['net_worth']) ? $values['net_worth'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  );

  $registration_origin_of_wealth = array(
    "Savings/Investment" => t("Savings / Investment", array(), $context),
    "Inheritance/Gifts" => t("Inheritance / Gifts", array(), $context)
  );

  $form['maincontent']['financials']['origin_of_wealth'] = array(
    '#type' => 'select',

    '#options' => $registration_origin_of_wealth,
    '#title' => t('Origin of wealth', array(), $context),
    '#description' => t('<p>How you acquired your assets.</p>', array(), $context),
    '#required' => FALSE,
    '#default_value' => !empty($values['origin_of_wealth']) ? $values['origin_of_wealth'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  );


  $registration_experience = _cmc_registration_live_experience();

  $registration_trading_frequency = _cmc_registration_live_trading_frequency();

  $form['maincontent']['financials']['experience'] = array(
    '#type' => 'fieldset',
    '#title' => t('Relevant Experience', array(), $context),

  );
  $form['maincontent']['financials']['experience']['trading_experience'] = array(
    '#type' => 'select',

    '#options' => array(),
    '#title' => t('Do you have any relevant work experience or professional qualifications that provide you with a good understanding of the products you intend to trade with us?', array(), $context),
    '#options' => $registration_experience,
    '#required' => FALSE,
    '#default_value' => !empty($values['trading_experience']) ? $values['trading_experience'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['experience']['trading_history'] = array(
    '#markup' => '<div class="field-grp"><header class="header">' . t('Over the last 3 years have you traded any of the following products (only where you have made the final trade decision)?', array(), $context) . '</header>'
  );

  $form['maincontent']['financials']['experience']['shares'] = array(
    '#title' => t('Shares', array(), $context),
    '#tree' => FALSE
  );

  $form['maincontent']['financials']['experience']['shares_frequency'] = array(
    '#type' => 'select',

    '#title' => t('Shares and bonds', array(), $context),
    '#options' => $registration_trading_frequency,
    '#required' => FALSE,
    '#default_value' => !empty($values['shares_frequency']) ? $values['shares_frequency'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['experience']['derivatives_frequency'] = array(
    '#type' => 'select',

    '#title' => t('OTC derivatives (e.g. Spread bets, FX or CFDs)', array(), $context),
    '#options' => $registration_trading_frequency,
    '#required' => FALSE,
    '#default_value' => !empty($values['derivatives_frequency']) ? $values['derivatives_frequency'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['experience']['exchange_frequency'] = array(
    '#type' => 'select',
		'#suffix'  =>  '</div>',
    '#title' => t('Exchange traded derivatives (e.g Warrants, Futures, Options)', array(), $context),
    '#options' => $registration_trading_frequency,
    '#required' => FALSE,
    '#default_value' => !empty($values['exchange_frequency']) ? $values['exchange_frequency'] : NULL,
    '#js_validator' => array(
      'validators' => array(
        'requiredValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['experience']['seminar_attendee'] = array(
    '#type' => 'radios',

    '#options' => array('' => '', CMC_REGISTRATION_OPTION_YES => t('Yes', array(), $context), CMC_REGISTRATION_OPTION_NO => t('No', array(), $context),  ),
    '#title' => t('Have you ever attended an educational seminar or course on CFDs, Forex and/or Spread Betting?', array(), $context),
    '#required' => FALSE,
    '#return_value' => check_plain('seminar_attendee'),
    '#default_value' => !empty($values['seminar_attendee']) ? $values['seminar_attendee'] : '',
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  
  
  $form['maincontent']['financials']['experience']['work_experience'] = array(
    '#type' => 'radios',
    '#prefix' => '<div class="rdo-vrt">',
    '#suffix' => '</div>',
    '#title' => t('Do you have any relevant work experience during the last 10 years that provides you with a good understanding of the risks of trading CFDs <sup>1</sup>?', array(), $context),
    '#required' => TRUE,
    '#return_value' => check_plain('work_experience'),
    '#default_value' => !empty($values['work_experience']) ? $values['work_experience'] : '',
    '#options' => array(
		'' => '', 
      'MTT' => t('Worked for at least 3 consecutive years in a directly relevant role', array(), $context),
      'LTT' => t('Worked in a directly relevant role for less than 3 consecutive years, or have at least one year\'s experience as a self-directed investor', array(), $context),
      'NEI'=> t('Neither', array(), $context),
      
    ),
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['experience']['educational'] = array(
    '#type' => 'radios',
		'#prefix' => '<div class="rdo-vrt">',
    '#suffix' => '</div>',
    '#title' => t('Do you have any professional or academic qualifications that provide you with a good understanding of the risks of trading with leveraged products?', array(), $context),
    '#required' => TRUE,
		'#return_value' => check_plain('educational'),
    '#default_value' => !empty($values['educational']) ? $values['educational'] : '',
    '#options' => array(
			'' => '', // hacky default option
      'DAQ' => t('Hold a diploma or higher level academic qualifications in a relevant field<sup>2</sup>', array(), $context),
      'QNF' => t('Hold other professional or academic qualifications in a numerate or financial services-related field', array(), $context),
      'NEI'=> t('Neither', array(), $context),
      
    ),
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['understanding_features'] = array(
    '#type' => 'fieldset',
    '#title' => t('Features and Risks of CFDs', array(), $context),
    '#tree' => FALSE,
  );

  $form['maincontent']['financials']['understanding_features']['markuptext'] = array(
    '#type' => 'markup',
		 '#markup' => '<div class="field-grp"><header class="header">' . t('Do you have a good understanding that (tick as appropriate)', array(), $context) . '</header>'
    
  );
  $form['maincontent']['financials']['understanding_features']['ownership_rights'] = array(
    '#title' => t('Trading CFDs is different from other types of financial investments, and you do not own, or have any rights in, the underlying assets?', array(), $context),

    '#type' => 'radios',
    '#options' => array(
			'' => '', // hacky default option
        CMC_REGISTRATION_OPTION_YES => t('Yes'),
        CMC_REGISTRATION_OPTION_NO => t('No'),
      
     ),
    '#required' => TRUE,
    '#default_value' => !empty($values['ownership_rights']) ? $values['ownership_rights'] : '',
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['understanding_features']['concept_money_leverage'] = array(
    '#type' => 'radios',

    '#options' => array(
			'' => '', // hacky default option
      CMC_REGISTRATION_OPTION_YES => t('Yes'),
      CMC_REGISTRATION_OPTION_NO => t('No'),
      
     ),
    '#required' => TRUE,
    '#default_value' => !empty($values['concept_money_leverage']) ? $values['concept_money_leverage'] : '',
    '#title' => t('The concepts of margin and leverage apply to this account, which means that when you trade CFDs, you could lose substantially more than your initial deposit or margin payment and you might have to make further payments?', array(), $context),
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['understanding_features']['concept_volatility'] = array(
    '#title' => t('The concepts of volatility and market liquidity apply to trading on this account, which means that market circumstances may impact on pricing and on our ability to generate prices or to execute orders?', array(), $context),
    '#type' => 'radios',

    '#options' => array(
		'' => '', // hacky default option
      CMC_REGISTRATION_OPTION_YES => t('Yes'),
      CMC_REGISTRATION_OPTION_NO => t('No'),
      
    ),
    '#required' => TRUE,
    '#default_value' => !empty($values['concept_volatility']) ? $values['concept_volatility'] : '',
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['understanding_features']['familiarity_platform'] = array(
    '#title' => t('CFDs are traded on an online platform, which means you need to be familiar with using an online trading platform, including how to open and close a trading position?', array(), $context),
    '#type' => 'radios',

    '#options' => array(
			'' => '', // hacky default option
      CMC_REGISTRATION_OPTION_YES => t('Yes'),
      CMC_REGISTRATION_OPTION_NO => t('No'),
      
    ),
    '#required' => TRUE,
    '#default_value' => !empty($values['familiarity_platform']) ? $values['familiarity_platform'] : '',
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['understanding_features']['monitor_manage'] = array(
    '#title' => t('It is your responsibility to monitor your CFD position and manage the risks of trading by using tools such as stop loss orders?', array(), $context),
    '#type' => 'radios',

    
    '#options' => array(
			'' => '', // hacky default option
      CMC_REGISTRATION_OPTION_YES => t('Yes'),
      CMC_REGISTRATION_OPTION_NO => t('No'),
      
     ),
    '#required' => TRUE,
    '#default_value' => !empty($values['monitor_manage']) ? $values['monitor_manage'] : '',
    '#js_validator' => array(
      'validators' => array(
        'radioValidator' => array()
      )
    ),
  );

  $form['maincontent']['financials']['help'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="form_page_help">',
    '#markup' => t('<ul>
                    <li><sup>1</sup>Such as development of, structuring of, management of, sale of, trading of, research on or analysis of investment products (capital markets and insurance products), or the provision of training in investment products, accountancy, actuarial science, treasury, financial risk management, provision of legal advice or possession of legal expertise relating to any of the above. </li>
                    <li><sup>2</sup>Such as diploma or higher qualifications in accountancy, acturial science, business / business administration / business management / business studies, capital markets, commerce, economics, finance, financial engineering, financial planning, computational finance, or insurance or other finance related professional qualification e.g. CFA, ACCA etc.</li></ul>'),
    '#suffix' => '</div>',
 );

// end step 3
// step 4
  
 $form['maincontent']['declarations'] = array(
   '#type' => 'fieldset',
	'#attributes' => array('class' => array('four')),
   '#title' => t('Declarations', array(), $context),
   '#tree' => FALSE,
 );
  
  
  $form['maincontent']['declarations']['agreements'] = array(
    '#prefix'  =>  '<div class="row dec"><div class="scroll" >',
    '#markup' => $config['params']['cmc_registration_tobs'],
    '#suffix'  =>  '</div>',
  );

  $form['maincontent']['declarations']['agree_terms'] = array(
    '#type' => 'checkbox',
    '#required' => FALSE,
		'#prefix'  =>  '<div class="agree">', 
		'#suffix'  =>  '</div></div>',
    '#title' => t('By clicking this box, I hereby agree to be bound by each of the above declarations.', array(), $context),
    '#default_value' => !empty($values['agree_terms']) ? $values['agree_terms'] : NULL,
  );

// end step 4

// next and previous buttons

// start the for footer wrapper
  $context1 = array('context' => $config['context']);
   $form['footer'] = array(
   		'#tree' => FALSE,
      '#prefix' => '<footer class="row rb">
				<INPUT type="button" value="Previous" id="prev-risk" class="prev">
				<INPUT type="button" value="Previous" id="prev-two" class="prev">
				<INPUT type="button" value="Previous" id="prev-three" class="prev">
				<INPUT type="button" value="Previous" id="prev-four" class="prev">
				<INPUT type="button" value="Next" id="next-one" class="next">
				<INPUT type="button" value="I Accept" id="next-risk" class="next">
				<INPUT type="button" value="Next" id="next-two" class="next">
				<INPUT type="button" value="Next" id="next-three" class="next">',
      '#suffix' => '</footer>'
   );

  $form['footer']['Submit'] = array(
		'#value' => t('Finish'),
		'#attributes' => array('class' => array('next')),
    '#type' => 'button',
    '#submit' => array('cmc_registration_live_form_submit'),
  );
// end next and previous buttons
 
 // end form
 return $form;  
}

//function cmc_registration_form_live_validate() {
//  form_set_error("Error");
//}

function cmc_registration_live_form_submit($form, &$form_state) {

  $application = new ApplicationForm();
  $application->build_request('submit', $form_state['values']);

  $connection = new CrmSoapClient();
  $connection->connect();

  try {
    $response = $connection->connection->ProcessApplication($application); 
    $response_xml = $connection->connection->__getLastRequest();
    drupal_set_message("Application Id: " .$response->ApplicationID);
    drupal_set_message("Application Id: " .$response->Status);
  }
  catch(SoapFault $e) {

    $response_xml = $connection->connection->__getLastRequest();
    $response = $connection->connection->__getLastResponse();
    
  }

  return;
}

