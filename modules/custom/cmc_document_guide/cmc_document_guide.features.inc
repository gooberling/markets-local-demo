<?php
/**
 * @file
 * cmc_document_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_document_guide_ctools_plugin_api() {
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
function cmc_document_guide_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_document_guide_node_info() {
  $items = array(
    'cmc_document_guide' => array(
      'name' => t('CMC Document Guide'),
      'base' => 'node_content',
      'description' => t('This will be a pdf document guide that users must fill in a form to download'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
