<?php
/**
 * @file
 * cmc_instruments_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function cmc_instruments_search_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
