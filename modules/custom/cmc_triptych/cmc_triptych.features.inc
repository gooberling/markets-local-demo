<?php
/**
 * @file
 * cmc_triptych.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_triptych_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cmc_triptych_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_triptych_node_info() {
  $items = array(
    'cmc_triptych' => array(
      'name' => t('CMC Triptych'),
      'base' => 'node_content',
      'description' => t('Landing page with a triptych layout'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
