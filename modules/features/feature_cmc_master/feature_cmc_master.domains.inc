<?php
/**
 * @file
 * feature_cmc_master.domains.inc
 */

/**
 * Implements hook_domain_default_domains().
 */
function feature_cmc_master_domain_default_domains() {
$domains = array();
  $domains['de_1_d7_cmc_local'] = array(
  'subdomain' => 'de-1-d7.cmc.local',
  'sitename' => 'Denmark CMC Website',
  'scheme' => 'http',
  'valid' => '1',
  'weight' => '1',
  'is_default' => '0',
  'machine_name' => 'de_1_d7_cmc_local',
);
  $domains['uk_1_d7_cmc_local'] = array(
  'subdomain' => 'uk-1-d7.cmc.local',
  'sitename' => 'UK CMC d7 TEST',
  'scheme' => 'http',
  'valid' => '1',
  'weight' => '-1',
  'is_default' => '1',
  'machine_name' => 'uk_1_d7_cmc_local',
);

return $domains;
}

/**
 * Implements hook_domain_conf_default_variables().
 */
function feature_cmc_master_domain_conf_default_variables() {
$domain_variables = array();
  $domain_variables['de_1_d7_cmc_local'] = array();
  $domain_variables['uk_1_d7_cmc_local'] = array();

return $domain_variables;
}

/**
 * Implements hook_domain_theme_default_themes().
 */
function feature_cmc_master_domain_theme_default_themes() {
$domain_themes = array();
  $domain_themes['de_1_d7_cmc_local'] = array(
  'de_1_d7_cmc_local' => array(
    'seven' => array(
      'theme' => 'seven',
      'settings' => NULL,
      'status' => '1',
      'filepath' => '',
    ),
  ),
);
  $domain_themes['uk_1_d7_cmc_local'] = array();

return $domain_themes;
}
