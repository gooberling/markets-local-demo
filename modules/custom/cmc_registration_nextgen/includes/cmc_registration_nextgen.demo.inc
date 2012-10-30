<?php

function cmc_registration_demo_form() {

  $context = array('context' => 'UK Demo');
  $form['already_registered'] = array(
    '#type' => 'radios',
    '#options' => array(CMC_ALREADY_REGISTERED_YES => t(CMC_ALREADY_REGISTERED_YES),
                        CMC_ALREADY_REGISTERED_NO => t(CMC_ALREADY_REGISTERED_NO)),
    '#title' => t('Have you previously registered an email address with CMC Markets Next Generation trading?', array(), $context),
    '#default_value' => isset($values['already_registered'])
    ? $values['already_registered'] : $already_registred,
  );
  
  $form['existing_user'] = array(
    '#type' => 'fieldset',
    '#states' => array(
      'visible' => array(
        ':input[name=already_registered]' => array('value' => CMC_ALREADY_REGISTERED_YES)
      )
    )
  );

  $form['existing_user']['email'] = array(
    '#type' => 'textfield',
     '#title' => t('Registered email address', array(), $context),
    '#default_value' => !empty($values['email']) ? $values['email'] : NULL,
    '#description' => t('Please enter your existing email address to apply for a live account.', array(), $context),

  );

  $form['Submit'] = array(
    '#value' => t('Submit'),
    '#type' => 'submit',
    '#submit' => array('cmc_registration_demo_form_submit'),
  );
 return $form;  
}

function cmc_registration_form_live_validate() {
  form_set_error("Error");
}

function cmc_registration_demo_form_submit($form, &$form_state) {
  return;
}