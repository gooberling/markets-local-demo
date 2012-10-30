<?php
/**
 * @file
 * cmc_charteducation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_charteducation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cmc_charteducation_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_charteducation_node_info() {
  $items = array(
    'cmc_charteducation' => array(
      'name' => t('CMC Chart Education'),
      'base' => 'node_content',
      'description' => t('CMC Chart Education'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
