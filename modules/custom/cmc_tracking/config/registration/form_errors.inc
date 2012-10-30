<?php

function cmc_tracking_registration_form_errors() {
  return array(
    'email' => array(
      'category' => '',
      'action' => 'signup_error_email',
      'opt_label' => 'signup_error_email',
    ),
    'password' => array(
      'category' => '',
      'action' => 'signup_error_password',
      'opt_label' => 'signup_error_password',
    ),
    'captcha_response' => array(
      'category' => '',
      'action' => 'signup_error_captcha',
      'opt_label' => 'signup_error_captcha',
    ),
    'pass1' => array(
      'category' => '',
      'action' => 'signup_error_new_password',
      'opt_label' => 'signup_error_new_password',
    ),
    'pass2' => array(
      'category' => '',
      'action' => 'signup_error_new_password_confirm',
      'opt_label' => 'signup_error_new_password_confirm',
    ),
    'new_email' => array(
      'category' => '',
      'action' => 'signup_error_new_email_in_use',
      'opt_label' => 'signup_error_new_email_in_use',
    ),
    'new_email_confirm' => array(
      'category' => '',
      'action' => 'signup_error_new_email_confirm',
      'opt_label' => 'signup_error_new_email_confirm',
    ),
    'employed][job_title' => array(
      'category' => '',
      'action' => 'signup_error_employed_job_title',
      'opt_label' => 'signup_error_employed_job_title',
    ),
    'agreed_to_proceed' => array(
      'category' => '',
      'action' => 'signup_error_agreed_to_proceed',
      'opt_label' => 'signup_error_agreed_to_proceed',
    ),
  );
}