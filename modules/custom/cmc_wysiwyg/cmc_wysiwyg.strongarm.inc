<?php
/**
 * @file
 * cmc_wysiwyg.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cmc_wysiwyg_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ckeditor_link_autocomplete_node_types';
  $strongarm->value = array(
    'cmc_page' => 'cmc_page',
    '- any -' => 0,
    'cmc_blog' => 0,
    'cmc_document_guide' => 0,
    'cmc_event' => 0,
    'cmc_location' => 0,
    'cmc_video' => 0,
    'product' => 0,
    'cmc_sample_article' => 0,
  );
  $export['ckeditor_link_autocomplete_node_types'] = $strongarm;

  return $export;
}
