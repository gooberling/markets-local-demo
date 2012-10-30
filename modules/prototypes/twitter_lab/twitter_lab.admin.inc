<?php
function twitter_lab_admin_settings() {
  $form['twitter_lab_twitter_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter username'),
    '#description' => t('Twitter username of the user to track'),
    '#default_value' => variable_get('twitter_lab_twitter_user'),
  );
  $form['twitter_lab_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer key'),
    '#default_value' => variable_get('twitter_lab_consumer_key'),
  );
  $form['twitter_lab_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer secret'),
    '#default_value' => variable_get('twitter_lab_consumer_secret'),
  );
  $form['twitter_lab_oauth_callback'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth callback'),
    '#default_value' => variable_get('twitter_lab_oauth_callback'),
  );
  $form['twitter_lab_auth_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Autentication token'),
    '#default_value' => variable_get('twitter_lab_auth_token'),
  );
  $form['twitter_lab_auth_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Authentication token secret'),
    '#default_value' => variable_get('twitter_lab_auth_secret'),
  );
  
  return system_settings_form($form);
} 