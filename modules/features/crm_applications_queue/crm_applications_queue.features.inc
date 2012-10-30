<?php
/**
 * @file
 * crm_applications_queue.features.inc
 */

/**
 * Implements hook_views_api().
 */
function crm_applications_queue_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
