<?php

/**
 *
 * @param type $form
 * @param type $form_state
 * @param type $country_prefix
 *   Prefix used to identify country of registration
 * @param type $application_type
 * @param type $product 
 */
function cmc_appforms_onboarding_form($form, &$form_state, $country_prefix, $application_type, $product ) {
  
  $country = cmc_appforms_country_load_prefix($country_prefix);  
  //Call relevant function form builder based on if live / Demo registration
  
  if ($application_type == CMC_APPFORMS_LIVE_REG) {
    module_load_include('inc', 'cmc_appforms', 'includes/cmc_appforms.live');

    $form = cmc_appforms_live_form($form, $form_state, $country['machine_name'], $product, $application_type);
    
  } else  {
    
  }
  
  
  return $form;
  
}
/**
 * Step 0 that is dispalyed when user come along with wrong URL.
 * @global type $language
 * @param type $form_id
 * @param type $form_stateßß
 * @return string 
 */
function cmc_appforms_start($form_id, $form_state) {
  $form = array();
  $countries = array();
  $display_languages = array();
  
  global $language;;
  
  // We prepare two elements here
  // 1. Country list to show in drop down
  // 2. Array of country along with its display languages and other elements that can be passed
  //    to JS within Drupal settings
  
  foreach(cmc_appforms_country_load() as $key => $country) {
    $country_options[$country->prefix] = $country->name;
    foreach(unserialize($country->display_language) as $key => $val) {
       if($val)$display_languages[] = $key;
    }
    $countries[$country->machine_name] = array('prefix' => $country->prefix, 'product' =>explode(',', $country->product), 'name' => $country->name, 'langauge' => $country->language, 'display_langauge' => $display_languages);
  }

  drupal_add_js(array('cmcOnBoarding' => $countries),
    array(
      'type' => 'setting',
      'every_page' => FALSE
    )
  );
  
  foreach(language_list() as $key=>$item) {
    $languages[$item->language] = $item->name;
  }
  
  $form['maincontent'] = array(
  	'#tree' => FALSE,
    '#prefix' => '<div class="bg"><div class="reqd">Required fields <span>*</span></div>',
    '#suffix' => '</div>'
  );
  
  $form['maincontent']['start'] = array(
    '#type' => 'fieldset',
		'#attributes' => array('class' => array('start')),
    '#title' => t('Select appropriate form to start your registration'),
    //'#description' => t('Description and marketing content goes here'),
  );
  
  $form['maincontent']['start']['application_type'] = array(
    '#type' => 'radios',
    '#title' => t('Select type of account'),
    '#description' => t('Select the type of account you wish to setup. '),
    '#options' => array('live' => t('Live Registration'), 'demo' => t('Demo registration')),
    '#required' => TRUE, 
    '#default_value' => 'live',
  );
  
  $form['maincontent']['start']['country'] = array(
    '#type' => 'select',
    '#title' => t('Select country'),
    '#description' => t('<p>Select the type of account you wish to setup.</p> '),
    '#options' => $country_options,
    '#required' => TRUE, 
    '#default_value' => NULL,
  );
  
  $form['maincontent']['start']['language'] = array(
    '#type' => 'select',
    '#title' => t('Select language'),
    '#description' => t('<p>Choose the language you wish to view the application in.</p>'),
    '#options' => $languages,
    '#required' => TRUE,
    '#states' => array(
      'invisible' => array(
        ':input[name=country]' => array('value' => '')
      ),
    ),
  );
  
  $form['maincontent']['start']['product'] = array(
    '#type' => 'select',
    '#title' => t('Select product'),
    '#description' => t('<p>Select product you wish to signup to.</p>'),
    '#options' => cmc_appforms_product_type(),
    '#required' => TRUE,
    '#states' => array(
      'invisible' => array(
        ':input[name=country]' => array('value' => '')
      ),
    ),
  );
	// start the for footer wrapper
	  $context1 = array('context' => $config['context']);
	   $form['footer'] = array(
	   		'#tree' => FALSE,
	      '#prefix' => '<footer class="row rb">',
				'#suffix' => '</footer>'
	   );

	 
	
  
  
  $form['footer']['go'] = array(
    '#type' => 'submit',
			'#attributes' => array('class' => array('next')),
    '#value' => t('Proceed with your application'),
    '#submit' => array('cmc_application_start_submit'),
  );
// end next and previous buttons

  return $form;
  
}

/**
 * Submit handler for step 0
 * @global type $language
 * @param type $form
 * @param type $form_state 
 */
function cmc_application_start_submit($form, &$form_state) {
  global $language;
  
  $languages = language_list();
  $language = $languages[$form_state['values']['language']];
  $path = "onboarding/" .$form_state['values']['country'] ."/" .$form_state['values']['application_type'] ."/" .$form_state['values']['product'];

  drupal_goto($path, array('language' => $language ));
}


/**
 * Load list of regions
 * @param type $region_id
 * @return type 
 */
function cmc_appforms_country_load_prefix($country_prefix) {
  $db = db_select('cmc_appforms_country', 'r')
          ->fields('r');
  
  $result = $db->condition('prefix', $country_prefix, '=')
                ->execute()
                ->fetchAssoc();

  return $result;
}

/**
 * Load list of regions
 * @param type $region_id
 * @return type 
 */
function cmc_appforms_country_load($country_id = NULL) {
  $db = db_select('cmc_appforms_country', 'r')
          ->fields('r');
   
  if ($country_id) {
    $result = $db->condition('country_id', $country_id, '=')
                ->execute()
                ->fetchAssoc();
  } 
  else 
  {
    $result = $db->execute()
                  ->fetchAllAssoc('country_id');
  }
     
  return $result;
}

/**
 * Get lis of languages for a given country
 * @param type $country_machine_name
 * @return type 
 */

function cmc_appforms_language_by_country($country_machine_name) {
  
  return array('True', 'false');
}

/**
 * Check if a machine name has already been used.
 * @param type $machine_name
 * @return type 
 */
function cmc_appforms_country_check_machine_name($machine_name) {
  return (bool) db_query("SELECT COUNT(1) FROM {cmc_appforms_country} WHERE machine_name = :machine_name",
    array(':machine_name' => $machine_name)
    )->fetchField();
}

/**
 * Check if a machine name provided for a template is already in use. 
 * @param type $machine_name
 * @return type 
 */
function cmc_appforms_template_check_machine_name($machine_name) {
  return (bool) db_query("SELECT COUNT(1) FROM {cmc_appforms_templates} WHERE machine_name = :machine_name",
    array(':machine_name' => $machine_name)
    )->fetchField();
}

/**
 * Load list of templates
 * @param type $template_id
 * @return type 
 */
function cmc_appforms_template_load($template_id = NULL) {
  $db = db_select('cmc_appforms_templates', 'r')
          ->fields('r');
   
  if ($template_id) {
    $result = $db->condition('$template_id', $template_id, '=')
                ->execute()
                ->fetchAssoc();
  } 
  else 
  {
    $result = $db->execute()
                  ->fetchAllAssoc('template_id');
  }
     
  return $result;
}

/**
 * Returns list of all modules that implemtn appforms
 * @return type 
 */
function cmc_appforms_get_application_features () {
  
  $appforms_features = &drupal_static(__FUNCTION__);
  
  if (!$appforms_features) {
    foreach(module_implements('appforms_info') as $module) {
      $function = $module ."_appforms_info";
      $appforms_features[$module] = $function();
    }
  }
  
  return $appforms_features;
}


/**
 * Load form related configurations
 * @param type $machine_name
 * @param type $application_type
 * @param type $product
 * @return type 
 */
function cmc_appforms_get_config_by_country($machine_name, $application_type, $product) {
  $result = db_select('cmc_appforms_country_config', 'c')
          ->fields('c')
          ->condition('country_machine_name', $machine_name, '=')
          ->condition('application_type', $application_type, '=')
          ->condition('product', $product, '=')
          ->execute()
          ->fetchAssoc();
  
  return $result; 
}

function cmc_appforms_load_country_machine_name ($machine_name) {
  $args = func_get_args();
  dsm($args);
   $result = db_select('cmc_appforms_country', 'c')
          ->fields('c')
          ->condition('machine_name', $machine_name, '=')
          ->execute()
          ->fetchAssoc();
  
  return $result; 
  
  
}