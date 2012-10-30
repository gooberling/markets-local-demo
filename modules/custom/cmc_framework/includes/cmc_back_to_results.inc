<?php
/**
 *
 * Enter description here ...
 */
function cmc_framework_back_to_results_block() {
  
  $data = array();
  $referer = $_SERVER['HTTP_REFERER'];
  
  // if referer matches /education we should go back to referer
  // as it might have the filter params in query string
  // if no referer or doesn't match /education
  // we redirect to education
  // stupid really as this doesn't really work longer term.
  if (strpos($referer, '/education') > -1) {
    $data['referer'] = $referer;
  }
  else {
    $data['referer'] = 'education';
  }
  
  $options = array();
  $data['link'] = l(t('< Back to education'), $data['referer'], $options);
  return theme('cmc_back_to_results', array('data' => $data));
}

