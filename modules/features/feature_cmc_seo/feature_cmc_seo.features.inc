<?php
/**
 * @file
 * feature_cmc_seo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_cmc_seo_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
