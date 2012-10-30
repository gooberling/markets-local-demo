<?php
/**
 * @file
 * related_content_config.features.inc
 */

/**
 * Implements hook_views_api().
 */
function related_content_config_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
