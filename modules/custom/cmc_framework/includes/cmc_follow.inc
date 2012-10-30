<?php
/**
 * Signup Settings
 */
function cmc_framework_follow_settings() {
  
  $form = array();
  $form['cmc_framework_follow_url_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter URL'),
    '#default_value' => variable_get('cmc_framework_follow_url_twitter', 'http://twitter.com/CMCMarkets'),
  );
  
  $form['cmc_framework_follow_url_youtube'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube URL'),
    '#default_value' => variable_get('cmc_framework_follow_url_youtube', 'http://www.youtube.com/user/CMCMarketsPLC'),
  );
  
  $form['cmc_framework_follow_url_facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook URL'),
    '#default_value' => variable_get('cmc_framework_follow_url_facebook', 'http://www.facebook.com/cmcmarkets'),
  );
  
  
  $form['cmc_framework_follow_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Follow Us tab text'),
    '#default_value' => variable_get('cmc_framework_follow_text', 'Follow Us'),
  );
      
  return system_settings_form($form);
}


/**
 *
 * Enter description here ...
 */
function cmc_framework_follow_block() {
    
  $data = array(
    'links' => array(
    	'facebook' => variable_get('cmc_framework_follow_url_facebook', 'http://www.facebook.com/cmcmarketsuk'),
    	'youtube' => variable_get('cmc_framework_follow_url_youtube', 'http://www.youtube.com/user/CMCMarketsPLC'),
      'twitter' => variable_get('cmc_framework_follow_url_twitter', 'http://twitter.com/CMCMarkets'),
    ),
    'text' => variable_get('cmc_framework_follow_text', 'Follow Us'),
    'module_path' => url(drupal_get_path('module', 'cmc_framework')),
  );
  
  $data['edit'] = '';
  if (user_access('administer cmc_follow')) {
    $data['edit'] = l('Edit Follow Us', 'admin/config/cmc/follow');
  }
  
  return theme('cmc_follow', array('data' => $data));
}

