<?php
/**
 * @file
 * cmc_hero.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_hero_ctools_plugin_api() {
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
function cmc_hero_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cmc_hero_node_info() {
  $items = array(
    'cmc_hero' => array(
      'name' => t('CMC Hero'),
      'base' => 'node_content',
      'description' => t('Heroes for cmc pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
