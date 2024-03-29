<?php
/**
 * @file
 * cmc_ppc_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cmc_ppc_page_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cmc_ppc_page';
  $strongarm->value = 0;
  $export['comment_anonymous_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cmc_ppc_page';
  $strongarm->value = '1';
  $export['comment_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cmc_ppc_page';
  $strongarm->value = 1;
  $export['comment_default_mode_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cmc_ppc_page';
  $strongarm->value = '50';
  $export['comment_default_per_page_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cmc_ppc_page';
  $strongarm->value = 1;
  $export['comment_form_location_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cmc_ppc_page';
  $strongarm->value = '1';
  $export['comment_preview_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cmc_ppc_page';
  $strongarm->value = 1;
  $export['comment_subject_field_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cmc_ppc_page';
  $strongarm->value = '0';
  $export['language_content_type_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cmc_ppc_page';
  $strongarm->value = array();
  $export['menu_options_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cmc_ppc_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cmc_ppc_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cmc_ppc_page';
  $strongarm->value = '1';
  $export['node_preview_cmc_ppc_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cmc_ppc_page';
  $strongarm->value = 0;
  $export['node_submitted_cmc_ppc_page'] = $strongarm;

  return $export;
}
