<?php
/**
 * @file
 * cmc_pricing.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cmc_pricing_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmc_pricing_panel';
  $strongarm->value = 0;
  $export['comment_anonymous_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmc_pricing_panel';
  $strongarm->value = '1';
  $export['comment_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmc_pricing_panel';
  $strongarm->value = 1;
  $export['comment_default_mode_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmc_pricing_panel';
  $strongarm->value = '50';
  $export['comment_default_per_page_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmc_pricing_panel';
  $strongarm->value = 1;
  $export['comment_form_location_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmc_pricing_panel';
  $strongarm->value = '1';
  $export['comment_preview_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmc_pricing_panel';
  $strongarm->value = 1;
  $export['comment_subject_field_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cmc_pricing_panel';
  $strongarm->value = '0';
  $export['language_content_type_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cmc_pricing_panel';
  $strongarm->value = array();
  $export['menu_options_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cmc_pricing_panel';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmc_pricing_panel';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cmc_pricing_panel';
  $strongarm->value = '1';
  $export['node_preview_cmc_pricing_panel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cmc_pricing_panel';
  $strongarm->value = 0;
  $export['node_submitted_cmc_pricing_panel'] = $strongarm;

  return $export;
}
