<?php
/**
 * @file
 * cmc_platform_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_platform_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cmc_platform_page_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_platform_page_node_info() {
  $items = array(
    'cmc_platform_page' => array(
      'name' => t('CMC Platform Page'),
      'base' => 'node_content',
      'description' => t('CMC Platform Page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
