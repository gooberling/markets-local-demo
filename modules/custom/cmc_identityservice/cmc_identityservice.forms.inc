<?php
/**
 * @File
 * @author : Ravi Julapalli 
 */

/**
 * Identity service signup form
 */
function cmc_identityservice_password_reset_form($form, $form_state, $token) {

  
  $context = array('context' => CMC_IDENTITYSERVICE_RESET_PASSWORD);
  $form = array();
  $form['title'] = array(
    '#value' => t('Please enter your new password below'),
  );
  
  $form['#js_validation'] = array(
    'enabled' => TRUE,
    'handlers' => array(
      'load' => 'submitDisable',
      'change' => 'submitCheck',
    )
  );
  
  $form['pass1'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#description' =>  t('For security your password should be:<ul><li>Between 6 and 15 characters long.</li><li>Must contain at least one lower case character and one number.</li><li>Cannot be the same as your email address.</li></ul>', array(), $context),
    '#required' => TRUE,
    '#maxlength' => 15,
    '#size' => 25,
    '#js_validator' => array(
     'validators' => array(
         'passwordValidator' => array()
      ),
    ),
  );
  
  $form['pass2'] = array(
    '#type' => 'password',
    '#title' => t('Confirm Password'),
    '#required' => TRUE,
    '#maxlength' => 15,
    '#size' => 25,
    '#js_validator' =>  array(
      'validators' => array(
        'passwordConfirmValidator' => array('#edit-pass1', FALSE, FALSE),
      ),
    ),
  );
  
  $form['token'] = array(
    '#type' => 'value',
    '#value' => $token,
  );
 
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Change password'),
    '#required' => TRUE,
    '#maxlength' => 155,
    '#size' => '40',
    '#weight' => 100,
  );

  $form['help'] = array(
    '#type' => 'markup',
    '#value' => theme('cmc_identityservice_password_reset_help', $form),
    '#required' => TRUE,
    '#maxlength' => 155,
    '#size' => '40',
    '#weight' => 100,
  );
  $form['#theme'] = 'cmc_identityservice_password_reset';
 return $form;
}  

/**
 * Implements form_validate
 */
function cmc_identityservice_password_reset_form_validate($form, &$form_state) {
  $tmp = $form_state;
  $pass = $form_state['values']['pass1'];
  if (!$form_state['values']['token']) {
    form_error($form, t('Missing Token'));
  }
  
  password_confirm_validate($form, $tmp);

  if (preg_match('#.*^(?=.{6,15})#', $pass) == FALSE) {
    form_error($form, t('Please choose a password between 6 and 15 characters in length'));
  }
  
  if (preg_match('#.*^(?=.*[0-9]+)(?=.*[a-z])#', $pass) == FALSE) {
    form_error($form, t('Please choose a password between 6 and 15 characters in length, Must contain at least one number and one lower case letter.'));
  }

  if (preg_match('#.*^(?=.*[a-z])#', $pass) == FALSE) {
    form_error($form, t('Please choose a password between 6 and 15 characters in length, Must contain at least one number and one lower case letter.'));
  }

}

/**
 * Submit handler for cmc_identityservice_password_reset_form
 * @param type $form
 * @param type $form_state 
 */
function cmc_identityservice_password_reset_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  try {
    $result = nextgen_password_reset($values['pass1'], $values['token']);
    if ($result) {
    _cmc_registration_get_form_errors();
    drupal_goto("identity/reset-password/" . $form_state['values']['token'] . "/done");
    
   } 
   else {
     drupal_goto("identity/reset-password/" . $form_state['values']['token'] . "/fail");
   }
  }
   catch (Exception $e) {
     watchdog('Identity service - Reset password', 'Response received: %result', array('result' => var_export($e, TRUE)), WATCHDOG_DEBUG);
     drupal_goto("identity/reset-password/" . $form_state['values']['token'] . "/fail");
   }
}

function cmc_identityservice_password_reset_done($token, $status) {
  
  $teaser =  NULL;
    _cmc_registration_get_teaser($teaser);
    _cmc_registration_get_form_errors();
  if ($status == 'done') {
    
    $output = t('!password_text', array('!password_text' => variable_get('cmc_identityservice_reset_thankyou')));
    
  if (variable_get('cmc_identityservice_sblogin_path', FALSE)) {
   $output .= '<a class = "bluebutton button-inline" href="'.variable_get('cmc_identityservice_sblogin_path') .'">'. t('Login to Spreadbet') .'</a>';
  }

  if (variable_get('cmc_identityservice_cfdlogin_path', FALSE)) {
   $output .= '<a class = "bluebutton button-inline" href="'.variable_get('cmc_identityservice_cfdlogin_path') .'">'. t('Login to CFD') .'</a>';
  }
    
    $data = array('data' => array('title' => t('Success'), 'body_text' => $output)); 
                              
    return theme('cmc_registration_live_confirmation', $data);

  } 
  else {
     return theme('cmc_identityservice_error', array('title' => t('Oops...'), 'message' => t('!message', array('!message' => variable_get('cmc_identityservice_errorpage')))));
  }
}


/**
 * Identity service signup form
 */
function cmc_identityservice_forgot_password_form($form, $form_state) {

  $form = array();
  $form['title'] = array(
    '#value' => t('Please enter your email address'),
  );
  
  $form['#js_validation'] = array(
    'enabled' => TRUE,
    'handlers' => array(
      'load' => 'submitDisable',
      'change' => 'submitCheck',
    )
  );
  
  
  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => t('Please enter your valid email address below.'),
  );
  
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
    '#maxlength' => 100,
    '#size' => 25,
    '#js_validator' => array(
      'validators' => array(
        'emailValidator' => array(),
      ),
    ),
  );
  
  $gobackprevious = false;
 
  if(isset($_SERVER['HTTP_REFERER']) && !empty($_SERVER['HTTP_REFERER'])  ) {
    $gobackprevious = $_SERVER['HTTP_REFERER'];
  } else {
    $gobackprevious = 'http://www.cmcmarkets.co.uk';
  }
  
 
  
  $form['gobbackprevious'] = array('#type' => 'hidden', '#value' => $gobackprevious);
 
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#required' => TRUE,
    '#maxlength' => 155,
    '#size' => '40',
    '#weight' => 100,
  );

  
  if(isset($_SERVER['HTTP_REFERER']) && !empty($_SERVER['HTTP_REFERER'])) {
    $previous = '<a class = "back" href="'.$_SERVER['HTTP_REFERER'] .'">'.t('back').'</a>';
  }
  else {
    $previous = '<a class = "back" href="#">'.t('back').'</a>';
  }
  $form['prev'] = array(
    '#type' => 'markup',
    '#markup' => $previous,
	'#weight' => 101,
  );
  
  $form['#theme'] = 'cmc_identityservice_forgot_password';
   
 return $form;
}  

/**
 * Implements form_validate
 */
function cmc_identityservice_forgot_password_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['email'])) {
    form_error($form, t('Please enter a valid email address'));
  }
}

/**
 * Submit handler for cmc_identityservice_password_reset_form
 * @param type $form
 * @param type $form_state 
 */
function cmc_identityservice_forgot_password_form_submit($form, &$form_state) {

  $_SESSION['goback'] = $form_state['input']['gobbackprevious'];
 
  try {
    $result = nextgen_forgot_password($form_state['values']['email']);
    if ($result && $result['data']->reset == TRUE) {
      drupal_goto('identity/forgot-password/done');
    } 
    else {
       drupal_goto('identity/forgot-password/done');
    }
  } catch (Exception $e) {
       drupal_goto('identity/forgot-password/done');
  }
 }


function cmc_identityservice_forgot_password_done()  {
  $teaser =  NULL;
  _cmc_registration_get_teaser($teaser);
  _cmc_registration_get_form_errors();

  $output = variable_get('cmc_identityservice_forgot_password');
  
  if (variable_get('cmc_identityservice_sblogin_path', FALSE)) {
   $output .= '<a class = "bluebutton button-inline" href="'.variable_get('cmc_identityservice_sblogin_path') .'">'. t('Login to Spreadbet') .'</a>';
  }

  if (variable_get('cmc_identityservice_cfdlogin_path', FALSE)) {
   $output .= '<a class = "bluebutton button-inline" href="'.variable_get('cmc_identityservice_cfdlogin_path') .'">'. t('Login to CFD') .'</a>';
  }
    
  
  return theme('cmc_registration_live_confirmation',
    array('data' => array('title' => t('Forgotten password'), 
        'body_text' => t('!text', array('!text' =>  $output,))
      ) 
    )
  );  
}

