<?php
/**
 * @file
 * feature_cmc_seo_sitemap.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_cmc_seo_sitemap_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}