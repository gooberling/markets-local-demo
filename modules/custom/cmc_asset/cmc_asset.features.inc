<?php
/**
 * @file
 * cmc_asset.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_asset_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_asset_node_info() {
  $items = array(
    'cmc_asset' => array(
      'name' => t('CMC Asset'),
      'base' => 'node_content',
      'description' => t('Upload images and files to this content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
