<?php
/**
 * @file
 * cmc_ppc_page.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cmc_ppc_page_filter_default_formats() {
  $formats = array();

  // Exported format: cmc_styles_tracking
  $formats['cmc_styles_tracking'] = array(
    'format' => 'cmc_styles_tracking',
    'name' => 'cmc_styles_tracking',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<img> <script> <style>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
