<?php

/**
 *
 * Enter description here ...
 */
function cmc_framework_share_this_block() {
  
  $url_options = array(
    'absolute' => TRUE
  );
  $data = array(
    'url' => url(trim(request_uri(), '/'), $url_options),
    'title' => drupal_get_title(),
    'module_path' => url(drupal_get_path('module', 'cmc_framework')),
  );
    
  return theme('cmc_share_this', array('data' => $data));
}

