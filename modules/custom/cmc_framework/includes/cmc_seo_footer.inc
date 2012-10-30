<?php
/**
 * SEO Footer Settings
 */
function cmc_framework_seo_footer_settings() {
  
  $domain = domain_get_domain();
  $menu_seo = domain_conf_variable_get($domain['domain_id'], 'menu_seo_links_source');
  $menu_seo = menu_load($menu_seo);
  
  $form = array();
  
  if (module_exists('cmc_location') && !empty($menu_seo)) {
    
    $menu_link = l($menu_seo['title'], 'admin/structure/menu/manage/' . $menu_seo['menu_name']);
    $form['#prefix'] = t('The SEO Menu is currently "') . $menu_link . t('". It is set in the ') . l('domain settings', 'admin/structure/domain');
    
    $form['cmc_framework_seo_footer_location'] = array(
      '#type' => 'select',
      '#options' => cmc_framework_seo_footer_location_options(),
      '#title' => t('Location'),
      '#default_value' => variable_get('cmc_framework_seo_footer_location', ''),
    );
  }
  else if (empty($menu_seo)) {
    $form['#prefix'] .= '<br />' . t('Please set the seo menu in the ') . l('domain settings', 'admin/structure/domain');
  }
  else {
    $form['#prefix'] .= '<br />' . t('Please turn on the cmc_location module');
  }
  
  
  $form['cmc_framework_seo_footer_telephone'] = array(
    '#type' => 'textfield',
    '#title' => t('Telephone'),
    '#default_value' => variable_get('cmc_framework_seo_footer_telephone', '+44(0)207 7170 8200'),
  );
  
  $form['cmc_framework_seo_footer_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax'),
    '#default_value' => variable_get('cmc_framework_seo_footer_fax', '+44(0)207 7170 8499'),
  );
  
  $form['cmc_framework_seo_footer_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => variable_get('cmc_framework_seo_footer_email', 'info@cmcmarkets.co.uk'),
  );
  
  
  return system_settings_form($form);
}


/**
 * return an array of the address elements
 * @param unknown_type $lid
 */
function cmc_framework_seo_footer_get_location($lid, $params=array()) {
  $location = location_load_location($lid);
    
  $loc = array(
    $location['name'],
    $location['street'],
    $location['city'],
    $location['postal_code'],
    $location['country_name']
  );
  
  if (count($params)) {
    // if we only want specific parts of the location
    $loc = array();
    foreach ($params as $key) {
      $loc[] = $location[$key];
    }
  }
      
  $loc = array_filter($loc); // remove empty elements
  return $loc;
}

/**
 * Return select options for locations
 * To be used in the settings form
 */
function cmc_framework_seo_footer_location_options() {
  
  $options = array();
  $view = views_get_view('cmc_location');
  $view->preview('list');
  
  foreach($view->result as $i => $res) {
    $loc = cmc_framework_seo_footer_get_location($res->location_lid);
    $options[$res->location_lid] = $res->node_title . ' :: ' . implode(", ", $loc);
  }
  return $options;
}


/**
 *
 */
function cmc_framework_seo_footer_block() {
  
  $domain = domain_get_domain();
  $menu_seo = domain_conf_variable_get($domain['domain_id'], 'menu_seo_links_source');
  $menu_seo = menu_load($menu_seo);
  
  // get all the seo links
  $menu_tree = menu_tree_all_data($menu_seo['menu_name']);
  $links = array();
  
  foreach ($menu_tree as $id => $item) {
    
    $link_section = array(
    	'heading' => $item['link'],
      'tree' => $item['below'],
    );
    
    $links[] = $link_section;
  }
  
  //print_r($links);
  
  // get the location
  $lid = variable_get('cmc_framework_seo_footer_location', '');
  $loc = cmc_framework_seo_footer_get_location($lid);
  
  $edit = '';
  if (user_access('administer cmc_seo_footer')) {
    $edit = l(t('Edit SEO Footer'), 'admin/config/cmc/seo_footer');
  }
  
  
  $email = variable_get('cmc_framework_seo_footer_email', 'info@cmcmarkets.co.uk');
  $email = '<a href="mailto:' . $email .'">' . $email . '</a>';
  
  // data to be passed to theme
  $data = array(
    'links' => $links,
    'location' => $loc,
    'telephone' => variable_get('cmc_framework_seo_footer_telephone', '+44(0)207 7170 8200'),
    'fax' => variable_get('cmc_framework_seo_footer_fax', '+44(0)207 7170 8499'),
  	'email' => $email,
    'edit' => $edit,
  );
  
  return theme('cmc_seo_footer', array('data' => $data));
}