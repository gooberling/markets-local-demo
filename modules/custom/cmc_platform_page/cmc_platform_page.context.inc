<?php
/**
 * @file
 * cmc_platform_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmc_platform_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmc_platform_landing';
  $context->description = 'CMC Platform Landing Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/8' => 'node/8',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-3712bdd76c261261b5e8d7883e8cb292' => array(
          'module' => 'views',
          'delta' => '3712bdd76c261261b5e8d7883e8cb292',
          'region' => 'header',
          'weight' => '-10',
        ),
        'views-cmc_platform-navigation' => array(
          'module' => 'views',
          'delta' => 'cmc_platform-navigation',
          'region' => 'header',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CMC Platform Landing Page');
  $export['cmc_platform_landing'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmc_platform_page';
  $context->description = 'CMC Platform Page context';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmc_platform_page' => 'cmc_platform_page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/8' => 'node/8',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cmc_platform_page-cmc_platform_page_header' => array(
          'module' => 'cmc_platform_page',
          'delta' => 'cmc_platform_page_header',
          'region' => 'landing_page',
          'weight' => '-10',
        ),
        'cmc_framework-cmc_share_this' => array(
          'module' => 'cmc_framework',
          'delta' => 'cmc_share_this',
          'region' => 'content_related',
          'weight' => '-10',
        ),
        'views-further_reading-block' => array(
          'module' => 'views',
          'delta' => 'further_reading-block',
          'region' => 'content_related',
          'weight' => '-10',
        ),
        'views-further_reading-block_1' => array(
          'module' => 'views',
          'delta' => 'further_reading-block_1',
          'region' => 'content_related',
          'weight' => '-10',
        ),
        'cmc_framework-cmc_open_account' => array(
          'module' => 'cmc_framework',
          'delta' => 'cmc_open_account',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CMC Platform Page context');
  $export['cmc_platform_page'] = $context;

  return $export;
}
