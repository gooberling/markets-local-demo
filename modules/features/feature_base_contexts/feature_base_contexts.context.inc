<?php
/**
 * @file
 * feature_base_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_base_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'denamark_base_context';
  $context->description = 'Denmark base context';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'cmc_base_context' => 'cmc_base_context',
      ),
    ),
    'domain' => array(
      'values' => array(
        'de-cmc-distro.com' => 'de-cmc-distro.com',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr-mlt-001' => array(
          'module' => 'apachesolr',
          'delta' => 'mlt-001',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'menu-menu-footer-denmark' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-denmark',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Denmark base context');
  $export['denamark_base_context'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'uk_base_sitewide_context';
  $context->description = '';
  $context->tag = 'UK_Base_context';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'cmc_base_context' => 'cmc_base_context',
      ),
    ),
    'domain' => array(
      'values' => array(
        'uk-cmc-distro.com' => 'uk-cmc-distro.com',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-uk-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-uk-footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('UK_Base_context');
  $export['uk_base_sitewide_context'] = $context;

  return $export;
}
