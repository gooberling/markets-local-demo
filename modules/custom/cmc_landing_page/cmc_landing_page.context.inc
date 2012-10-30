<?php
/**
 * @file
 * cmc_landing_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmc_landing_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmc_landing_page';
  $context->description = '';
  $context->tag = 'landing page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmc_landing_page' => 'cmc_landing_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmc_landing_page-hero' => array(
          'module' => 'views',
          'delta' => 'cmc_landing_page-hero',
          'region' => 'landing_page',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('landing page');
  $export['cmc_landing_page'] = $context;

  return $export;
}
