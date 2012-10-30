<?php
/**
 * @file
 * cmc_calendar_education.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cmc_calendar_education_filter_default_formats() {
  $formats = array();

  // Exported format: cmc_calendar_education
  $formats['cmc_calendar_education'] = array(
    'format' => 'cmc_calendar_education',
    'name' => 'cmc_calendar_education',
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
