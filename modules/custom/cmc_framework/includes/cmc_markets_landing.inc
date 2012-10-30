<?php
/**
 * Markets Landing Settings form
 */
function cmc_framework_markets_landing_settings() {
  
  $form = array();
  
  for ($i=1; $i<=5; $i++) {
    cmc_framework_markets_landing_settings_tab_section($form, $i);
  }
  
  $form['#submit'][] = 'cmc_framework_markets_landing_process_uploaded_file';
  $form['#validate'][] = 'cmc_framework_markets_landing_validate_uploaded_file';
  
  return system_settings_form($form);
}

// http://stackoverflow.com/questions/7690295/drupal-module-configuration-process-uploaded-file
function cmc_framework_markets_landing_validate_uploaded_file($form, &$form_state) {
  
  for ($i=1; $i<=5; $i++) {
    $tab = 'tab' . $i;
    $image_key = 'cmc_framework_markets_tab' . $i . '_image';
    
    if (!isset($form_state['values'][$image_key]) || !is_numeric($form_state['values'][$image_key])) {
      form_set_error($image_key, t('Please select an file to upload.'));
    }
  }
}

// http://stackoverflow.com/questions/7690295/drupal-module-configuration-process-uploaded-file
// TODO:
// should push this into a generic form process function
// where it inspects the form and does this action for all managed_file input #type
// similar function in cmc_markets_login
// cmc_framework_login_process_uploaded_file()
function cmc_framework_markets_landing_process_uploaded_file($form, &$form_state) {
  
  for ($i=1; $i<=5; $i++) {
    $tab = 'tab' . $i;
    $image_key = 'cmc_framework_markets_tab' . $i . '_image';
    $image_key_delete = 'cmc_framework_markets_tab' . $i . '_image_delete';
    
    if ($form_state['values'][$image_key] != 0) {
      // The new file's status is set to 0 or temporary and in order to ensure
      // that the file is not removed after 6 hours we need to change it's status
      // to 1.
      $file = file_load($form_state['values'][$image_key]);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      
      // delete current file
      $image_fid = variable_get($image_key, '');
      if ($image_fid) {
        $f = file_load($image_fid);
        if (!empty($f->fid) && file_delete($f)) {
          drupal_set_message($f->filename . ' deleted');
        }
      }
        
    }
    else {
      $image_delete = $form_state['values'][$image_key_delete];
      if (!$image_delete) {
        unset($form_state['values'][$image_key]);
      }
      else {
        $image_fid = variable_get($image_key, '');
        $file = file_load($image_fid);
      
        if (file_delete($file)) {
          drupal_set_message($file->filename . ' deleted');
        }
        else {
          drupal_set_message($file->filename . ' could not be deleted. ');
         
          // so we still keep a record fo the file
          unset($form_state['values'][$image_key]);
        }
      }
    }
  }

}


/**
 *
 * Enter description here ...
 * @param unknown_type $form
 * @param unknown_type $i
 */
function cmc_framework_markets_landing_settings_tab_section(&$form, $i) {
  
  $fieldset_key = 'tab' . $i;
  $title_key = 'cmc_framework_markets_tab' . $i;
  $content_key = 'cmc_framework_markets_tab' . $i . '_content';
  $pricing_key = 'cmc_framework_markets_tab' . $i . '_pricing';
  $image_key = 'cmc_framework_markets_tab' . $i . '_image';
  $image_key_delete = 'cmc_framework_markets_tab' . $i . '_image_delete';
  
  $form[$fieldset_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Tab') . $i,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form[$fieldset_key][$title_key] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get($title_key, 'Tab title'),
  );
  

  $textarea_defaults = variable_get($content_key, 'Content');
  $form[$fieldset_key][$content_key] = array(
    '#type' => 'text_format',
    '#title' => t('Content'),
  	'#default_value' => $textarea_defaults['value'],
    '#format' => $textarea_defaults['format'],
    '#description' => 'Please do not put in images in textarea',
  );
  
// http://stackoverflow.com/questions/7690295/drupal-module-configuration-process-uploaded-file
  $form[$fieldset_key][$image_key] = array(
    '#type' => 'managed_file',
    '#title' => t('Content Image'),
    '#description' => t('Uploading a file will replace the content image. This should be a generic image so it can be used for multiple languages. E.g. Don\'t put text into it'),
    '#upload_location' => 'public://cmc_framework/markets-landing'
  );
  
  $image_fid = variable_get($image_key, '');
  $image = file_load($image_fid);
  
  if (!empty($image->fid)) {
    $data = array(
      'path' => file_create_url($image->uri),
    );
    $form[$fieldset_key][$image_key]['#description'] .= '<br />' . theme('image', $data);
    
  }
  
  $form[$fieldset_key][$image_key_delete] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete Image'),
  );
  
  
  
  // pricing, only do this if module is on
  if (module_exists('cmc_pricing')) {
    
    $view = views_get_view('cmc_pricing');
    $content = $view->preview('pricing_panel_list');
  
    $options = array('' => 'None');
    foreach ($view->result as $res) {
      $options[$res->nid] = $res->node_title;
    }
    
    $form[$fieldset_key][$pricing_key] = array(
      '#type' => 'select',
      '#options' => $options,
      '#title' => t('Tab Pricing panel'),
      //'#description' => t('Time in seconds, should be < 30. Feed returns last 30 movements and we might have more than 1 movement per second'),
      '#default_value' =>  variable_get($pricing_key, ''),
    );
  }
}


/**
 *
 * Enter description here ...
 * @param unknown_type $form
 * @param unknown_type $i
 */
function cmc_framework_markets_landing_tab_section_content($i) {
  
  $fieldset_key = 'tab' . $i;
  $title_key = 'cmc_framework_markets_tab' . $i;
  $content_key = 'cmc_framework_markets_tab' . $i . '_content';
  $pricing_key = 'cmc_framework_markets_tab' . $i . '_pricing';
  $image_key = 'cmc_framework_markets_tab' . $i . '_image';
  
  
  $content = variable_get($content_key, t('Content'));
  
  $edit_link = '';
  if (user_access('administer cmc_markets_landing')) {
    $edit_link = l('Edit Content', 'admin/config/cmc/markets_landing');
  }
  
  $pricing = '';
  $pricing_nid = variable_get($pricing_key, '');
  if ($pricing_nid) {
    
    $pricing_node = node_load($pricing_nid);
    $instruments = cmc_pricing_node_get_instruments($pricing_node);

    $data = array(
      'node' => $pricing_node,
      'instruments' => $instruments,
      'i' => $i,
      'edit_link' => '',
    );
    
    if (user_access('administer cmc_pricing')) {
      $options = array(
        'attributes' => array(
          'class' => 'pricing-edit',
        ),
        'query' => array('destination' => $_GET['q']),
      );
      $data['edit_link'] = l('Edit Pricing Panel', 'node/' . $pricing_node->nid . '/edit', $options);
    }
    
    $pricing = theme('cmc_pricing_panel', $data);
  }
  
  
  $tab = array(
    'title' => variable_get($title_key, t('Title')),
    'content' => check_markup($content['value'], $content['format']),
    'pricing' => $pricing,
    'edit_link' => $edit_link,
  );
  
  // add in the image if one is uploaded
  $image_fid = variable_get($image_key, '');
  $image = file_load($image_fid);
  
  if (!empty($image->fid)) {
    $imagedata = array(
      'path' => file_create_url($image->uri),
    );
    $tab['image'] = theme('image', $imagedata);
  }
  
  return $tab;
}


/**
 *
 */
function cmc_framework_markets_landing_block() {
  $data = array();
  
  for ($i=1; $i<=5; $i++) {
    $data['tabs'][] = cmc_framework_markets_landing_tab_section_content($i);
  }
  
  return theme('cmc_markets_landing', $data);
}














