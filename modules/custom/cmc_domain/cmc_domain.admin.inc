<?php
/**
 * @File
 *
 * @author Ravi Julapalli (r.julapalli@cmcmarkets.com)
 */

/**
 *
 * Enter description here ...
 */
function cmc_domain_add_menu($options) {
  
  $m = menu_load($options['name']);
  
  if (!$m) {
    $menu = array(
      'menu_name' => $options['name'],
      'title' => $options['title'],
      'description' => $options['description'],
    );
    menu_save($menu);
    drupal_set_message('Added menu ' . $options['name']);
  }
  else {
    drupal_set_message('Menu ' . $options['name'] . ' exists', 'error');
  }
}


function cmc_domain_default_menus() {
  $menus = array(
    array(
      'name' => 'main-menu',
      'title' => 'Main menu',
    ),
    array(
      'name' => 'menu-header-menu',
      'title' => 'Header menu',
    ),
    array(
      'name' => 'menu-seo-menu',
      'title' => 'SEO menu',
    ),
    array(
      'name' => 'menu-footer-menu',
      'title' => 'Footer menu',
    ),
  );
  
  return $menus;
}



/**
 * Each domain should have 4 menus
 * Enter description here ...
 */
function cmc_domain_create_menus() {
  
  module_load_include('inc', 'cmc_domain', 'cmc_domain.admin');
  
  $domain = isset($_GET['domain']) ? $_GET['domain'] : '';
  
  // these default menus should be created
  $menus = cmc_domain_default_menus();
  
  if (!isset($_GET['domain'])) {
    drupal_set_message('No Domain set - set domain by ?domain=[something]', 'error');
  }
  else {
    
    foreach ($menus as $i => $m) {
      $menus[$i]['name'] .= '-' . $domain;
      $menus[$i]['title'] .= ' ' . $domain;
    }
  }
  
  foreach ($menus as $menu) {
    cmc_domain_add_menu($menu);
    // link menu to domain!
  }
  
  return __METHOD__;
}


