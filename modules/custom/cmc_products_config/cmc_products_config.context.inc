<?php
/**
 * @file
 * cmc_products_config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmc_products_config_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'browse_markets';
  $context->description = '';
  $context->tag = 'markets';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'browse_markets:page' => 'browse_markets:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-UxUiBXFSW94FcTcHkpVJQ5FoB21EId6r' => array(
          'module' => 'facetapi',
          'delta' => 'UxUiBXFSW94FcTcHkpVJQ5FoB21EId6r',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-LXrXVKOQiR1LmzYh1YgCjKIsTEtGAGWz' => array(
          'module' => 'facetapi',
          'delta' => 'LXrXVKOQiR1LmzYh1YgCjKIsTEtGAGWz',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-mNB_162rGRPZeqAIOH3cG1-o1zYDFP_J' => array(
          'module' => 'facetapi',
          'delta' => 'mNB_162rGRPZeqAIOH3cG1-o1zYDFP_J',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-69MW23PBtoPVlqmC-TC4bP-eoZsSJPTX' => array(
          'module' => 'facetapi',
          'delta' => '69MW23PBtoPVlqmC-TC4bP-eoZsSJPTX',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-_-e233k_6uXddM85FjSCRPLWEcdzGomX' => array(
          'module' => 'facetapi',
          'delta' => '_-e233k_6uXddM85FjSCRPLWEcdzGomX',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('markets');
  $export['browse_markets'] = $context;

  return $export;
}
