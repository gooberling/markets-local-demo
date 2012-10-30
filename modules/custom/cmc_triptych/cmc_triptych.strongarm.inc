<?php
/**
 * @file
 * cmc_triptych.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cmc_triptych_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmc_triptych';
  $strongarm->value = 0;
  $export['comment_anonymous_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmc_triptych';
  $strongarm->value = '1';
  $export['comment_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmc_triptych';
  $strongarm->value = 1;
  $export['comment_default_mode_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmc_triptych';
  $strongarm->value = '50';
  $export['comment_default_per_page_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmc_triptych';
  $strongarm->value = 1;
  $export['comment_form_location_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmc_triptych';
  $strongarm->value = '1';
  $export['comment_preview_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmc_triptych';
  $strongarm->value = 1;
  $export['comment_subject_field_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_cmc_triptych';
  $strongarm->value = 1;
  $export['i18n_node_extended_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_cmc_triptych';
  $strongarm->value = array();
  $export['i18n_node_options_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cmc_triptych';
  $strongarm->value = '2';
  $export['language_content_type_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cmc_triptych';
  $strongarm->value = array(
    0 => 'menu-de-main-menu',
    1 => 'menu-uk-main-menu',
  );
  $export['menu_options_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cmc_triptych';
  $strongarm->value = 'menu-uk-main-menu:0';
  $export['menu_parent_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmc_triptych';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cmc_triptych';
  $strongarm->value = '1';
  $export['node_preview_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cmc_triptych';
  $strongarm->value = 0;
  $export['node_submitted_cmc_triptych'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cmc_triptych_pattern';
  $strongarm->value = '[node:menu-link:parents:join:/]/[node:title]';
  $export['pathauto_node_cmc_triptych_pattern'] = $strongarm;

  return $export;
}
