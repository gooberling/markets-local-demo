<?php

/**
 * Signup Settings
 */
function cmc_framework_contact_settings() {
  
  $form = array();
    
  // get all the webforms
  $result = db_select('node', 'n')
    ->fields('n', array('nid', 'title', 'created'))
    ->condition('type', 'webform', '=')
    ->execute();
  
  $options = array();
  while ($record = $result->fetchObject()) {
    $options[$record->nid] = $record->title;
  }
  
  $form['cmc_framework_contact_webform'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#title' => t('Contact Us Webform'),
    '#required' => TRUE,
    '#default_value' => variable_get('cmc_framework_contact_webform', ''),
  );
  
  
  $form['cmc_framework_contact_location'] = array(
    '#markup' => t('Contact details should be set up in the ')
              . l('SEO Footer', 'admin/config/cmc/seo_footer'),
  );
  
  $form['cmc_framework_gmap_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps V3 Key'),
    '#required' => TRUE,
    '#default_value' => variable_get('cmc_framework_gmap_key', 'AIzaSyA_qHQq0YnfW4Q_-CZgC8E4QqP-3Gz4ouE'),
  );
  
  $form['cmc_framework_gmap_zoom'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps Zoom Value'),
    '#required' => TRUE,
    '#default_value' => variable_get('cmc_framework_gmap_zoom', '16'),
  );
      
  return system_settings_form($form);
}


/**
 *
 */
function cmc_framework_contact_map_block() {
  
  $data = array();
  
  // seo footer functions/variables
  module_load_include('inc', 'cmc_framework', 'includes/cmc_seo_footer');
  $lid = variable_get('cmc_framework_seo_footer_location', '');
  $location = location_load_location($lid);
  
  $data = array(
    'location' => $location,
    'address' => cmc_framework_seo_footer_get_location($lid),
    'gmap_key' => variable_get('cmc_framework_gmap_key', 'AIzaSyA_qHQq0YnfW4Q_-CZgC8E4QqP-3Gz4ouE'),
    'gmap_zoom' => variable_get('cmc_framework_gmap_zoom', '16'),
  );
  
  return theme('cmc_contact_map', $data);
}


/**
 *
 */
function cmc_framework_contact_form_block() {
  
  $data = array();
  
  $webform_nid = variable_get('cmc_framework_contact_webform', '');
  $block = module_invoke('webform', 'block_view', 'client-block-' . $webform_nid);
  
  // seo footer functions/variables
  module_load_include('inc', 'cmc_framework', 'includes/cmc_seo_footer');
  
  $lid = variable_get('cmc_framework_seo_footer_location', '');
  $location = cmc_framework_seo_footer_get_location($lid);
  $telephone = variable_get('cmc_framework_seo_footer_telephone', '+44(0)207 7170 8200');
  $fax = variable_get('cmc_framework_seo_footer_fax', '+44(0)207 7170 8499');
  $email = variable_get('cmc_framework_seo_footer_email', 'info@cmcmarkets.co.uk');
  
  $data = array(
    'form' => render($block['content']),
    'location' => $location,
    'telephone' => $telephone,
    'fax' => $fax,
    'email' => $email,
  );
  
  return theme('cmc_contact_form', $data);
}

