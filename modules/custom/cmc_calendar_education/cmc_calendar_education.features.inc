<?php
/**
 * @file
 * cmc_calendar_education.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_calendar_education_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cmc_calendar_education_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_calendar_education_node_info() {
  $items = array(
    'cmc_calendar_education' => array(
      'name' => t('CMC Calendar Education'),
      'base' => 'node_content',
      'description' => t('CMC Calendar Education'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
