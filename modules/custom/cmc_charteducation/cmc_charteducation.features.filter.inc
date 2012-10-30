<?php
/**
 * @file
 * cmc_charteducation.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cmc_charteducation_filter_default_formats() {
  $formats = array();

  // Exported format: cmc_charteducation
  $formats['cmc_charteducation'] = array(
    'format' => 'cmc_charteducation',
    'name' => 'cmc_charteducation',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<b> <i> <item> <u>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
