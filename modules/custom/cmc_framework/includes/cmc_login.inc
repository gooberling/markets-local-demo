<?php
/**
 * Login Settings
 */
function cmc_framework_login_settings() {
  
  $form = array();
  
  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header Signup/Login buttons'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['header']['cmc_framework_header_login_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Login Link text'),
    '#default_value' => variable_get('cmc_framework_header_login_text', 'Login'),
  );
  
  $form['header']['cmc_framework_header_login_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Login Link URL'),
    '#default_value' => variable_get('cmc_framework_header_login_url', '#'),
  );
  
  $form['header']['cmc_framework_header_signup_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Signup Link text'),
    '#default_value' => variable_get('cmc_framework_header_signup_text', 'Sign Up'),
  );
  
  $form['header']['cmc_framework_header_signup_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Signup Link URL'),
    '#default_value' => variable_get('cmc_framework_header_signup_url', '#'),
  );
  
  
  // http://stackoverflow.com/questions/7690295/drupal-module-configuration-process-uploaded-file
  $form['header']['cmc_framework_header_login_promo_image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Login Promo Image'),
  	'#description' => t('Uploading a file will replace the content image. This should be a generic image so it can be used for multiple languages. E.g. Don\'t put text into it'),
    '#upload_location' => 'public://cmc_framework/'
  );
  
  $form['header']['cmc_framework_header_login_promo_image_delete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete Promo Image'),
  );
  
  $image_fid = variable_get('cmc_framework_header_login_promo_image', '');
  
  $image = file_load($image_fid);
  
  if (!empty($image->fid)) {
    $data = array(
      'path' => file_create_url($image->uri),
    );
    $form['header']['cmc_framework_header_login_promo_image']['#description'] .= '<br />' . theme('image', $data);
    
  }
  //print_r($image);
  
  $form['#submit'][] = 'cmc_framework_login_process_uploaded_file';
  $form['#validate'][] = 'cmc_framework_login_validate_uploaded_file';
  
  
  //$login_content = variable_get('cmc_framework_header_login_promo_text', 'Login Promo Text');
  $textarea_defaults = variable_get('cmc_framework_header_login_promo_text', array('value' => 'Login Promo Text', 'format' => 'cmc_editor'));
  $form['header']['cmc_framework_header_login_promo_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Login Promo Content') . ' :: Please do not put in images in textarea',
  	'#default_value' => $textarea_defaults['value'],
    '#format' => $textarea_defaults['format'],
    '#description' => 'Please do not put in images in textarea',
  );
  
  
  
  $form['link1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login Box Link 1'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['link1']['cmc_framework_login_link_text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => variable_get('cmc_framework_login_link_text1', 'Spreadbet login'),
  );
  
  $form['link1']['cmc_framework_login_link_url1'] = array(
    '#type' => 'textfield',
    '#title' => t('URL 1'),
    '#default_value' => variable_get('cmc_framework_login_link_url1', 'https://www.mycmc.co.uk/Main.html?launchpoint=livesignin'),
  );
  
  $form['link1']['cmc_framework_login_link_class1'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_login_link_class1', 'spreadbet'),
  );
  
  
  $form['link2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login Box Link 2'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['link2']['cmc_framework_login_link_text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => variable_get('cmc_framework_login_link_text2', 'CFD login'),
  );
  
  $form['link2']['cmc_framework_login_link_url2'] = array(
    '#type' => 'textfield',
    '#title' => t('URL 2'),
    '#default_value' => variable_get('cmc_framework_login_link_url2', 'https://cfd.mycmc.co.uk/Main.html?launchpoint=livesignin'),
  );
  
  $form['link2']['cmc_framework_login_link_class2'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_login_link_class2', 'cfd'),
  );
    
  
  $form['link3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login Box Link 3'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['link3']['cmc_framework_login_link_text3'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => variable_get('cmc_framework_login_link_text3', 'Marketmaker login'),
  );
  
  $form['link3']['cmc_framework_login_link_url3'] = array(
    '#type' => 'textfield',
    '#title' => t('URL 3'),
    '#default_value' => variable_get('cmc_framework_login_link_url3', 'https://uk.cfd.cmcmarkets.com/cfd/home'),
  );
  
  $form['link3']['cmc_framework_login_link_class3'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_login_link_class3', 'marketmaker'),
  );
  
  
  
  $form['link4'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login Box Link 4'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['link4']['cmc_framework_login_link_text4'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#default_value' => variable_get('cmc_framework_login_link_text4', ''),
  );
  
  $form['link4']['cmc_framework_login_link_url4'] = array(
    '#type' => 'textfield',
    '#title' => t('URL 4'),
    '#default_value' => variable_get('cmc_framework_login_link_url4', ''),
  );
  
  $form['link4']['cmc_framework_login_link_class4'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' => variable_get('cmc_framework_login_link_class4', 'marketmaker'),
  );
  
  return system_settings_form($form);
}


// http://stackoverflow.com/questions/7690295/drupal-module-configuration-process-uploaded-file
function cmc_framework_login_validate_uploaded_file($form, &$form_state) {
 
  if (!isset($form_state['values']['cmc_framework_header_login_promo_image']) || !is_numeric($form_state['values']['cmc_framework_header_login_promo_image'])) {
    form_set_error('cmc_framework_header_login_promo_image', t('Please select an file to upload.'));
  }
}

// http://stackoverflow.com/questions/7690295/drupal-module-configuration-process-uploaded-file
// TODO:
// should push this into a generic form process function
// where it inspects the form and does this action for all managed_file input #type
// similar function in cmc_markets_landing
// cmc_framework_markets_landing_process_uploaded_file
function cmc_framework_login_process_uploaded_file($form, &$form_state) {

  if ($form_state['values']['cmc_framework_header_login_promo_image'] != 0) {
      // The new file's status is set to 0 or temporary and in order to ensure
      // that the file is not removed after 6 hours we need to change it's status
      // to 1.
      $file = file_load($form_state['values']['cmc_framework_header_login_promo_image']);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      
      // delete current file
      $image_fid = variable_get('cmc_framework_header_login_promo_image', '');
      watchdog('cmc_login', 'blah ' . $image_fid);
      if ($image_fid) {
        $f = file_load($image_fid);
        if (!empty($f->fid) && file_delete($f)) {
          drupal_set_message($f->filename . ' deleted');
        }
      }
      
   }
   else {
     $image_delete = $form_state['values']['cmc_framework_header_login_promo_image_delete'];
     if (!$image_delete) {
       unset($form_state['values']['cmc_framework_header_login_promo_image']);
     }
     else {
       $image_fid = variable_get('cmc_framework_header_login_promo_image', '');
       $file = file_load($image_fid);
  
       if (file_delete($file)) {
         drupal_set_message($file->filename . ' deleted');
       }
       else {
         drupal_set_message($file->filename . ' could not be deleted. ');
         
         // so we still keep a record fo the file
         unset($form_state['values']['cmc_framework_header_login_promo_image']);
       }
     }
   }
}

/**
 *
 * Enter description here ...
 */
function cmc_framework_login_block() {
  
  $path = drupal_get_path('module', 'cmc_framework');
  drupal_add_js($path . '/js/cmc_framework.js');
  
  $data = array();
  $data['edit'] = '';
  if (user_access('administer cmc_login')) {
    $data['edit'] = l(t('Edit login content'), 'admin/config/cmc/login');
  }
    
  $fields = array(
  	'class' => 'cmc_framework_login_link_class',
  	'text' => 'cmc_framework_login_link_text',
  	'url' => 'cmc_framework_login_link_url'
  );
  
  
  for ($i=1; $i<=4; $i++) {
    foreach($fields as $field => $var_name) {
      $data[$field . $i] = t(variable_get($var_name . $i, ''));
    }
  }
  
  $data['login']['text'] = variable_get('cmc_framework_header_login_text', 'Login');
  $data['login']['url'] = variable_get('cmc_framework_header_login_url', '#');
  
  $data['signup']['text'] = variable_get('cmc_framework_header_signup_text', 'Sign Up');
  $data['signup']['url'] = variable_get('cmc_framework_header_signup_url', '#');
  
  $promo_content = variable_get('cmc_framework_header_login_promo_text', 'Login Promo Text');
  
  $promo_content = check_markup($promo_content['value'], $promo_content['format']);
  $data['promo']['content'] = $promo_content;
  
  
  $image_fid = variable_get('cmc_framework_header_login_promo_image', '');
  $image = file_load($image_fid);
  
  if (!empty($image->fid)) {
    $imagedata = array(
      'path' => file_create_url($image->uri),
    );
    $data['promo']['image'] = theme('image', $imagedata);
  }
  
  return theme('cmc_login', array('data' => $data));
}

