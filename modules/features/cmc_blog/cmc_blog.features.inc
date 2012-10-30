<?php
/**
 * @file
 * cmc_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmc_blog_ctools_plugin_api() {
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
function cmc_blog_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function cmc_blog_node_info() {
  $items = array(
    'cmc_blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Blog for CMC markets site. Blogs should be able to be syndicated to different domains'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
