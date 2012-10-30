<?php
/**
 * @file
 * cmc_ppc_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmc_ppc_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ppc_node';
  $context->description = '';
  $context->tag = 'nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmc_ppc_page' => 'cmc_ppc_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmc_ppc-block_1' => array(
          'module' => 'views',
          'delta' => 'cmc_ppc-block_1',
          'region' => 'landing_page',
          'weight' => '-10',
        ),
        'cmc_framework-cmc_risk_warning' => array(
          'module' => 'cmc_framework',
          'delta' => 'cmc_risk_warning',
          'region' => 'risk',
          'weight' => '-10',
        ),
        'cmc_ppc_page-cmc_ppc_page_footer' => array(
          'module' => 'cmc_ppc_page',
          'delta' => 'cmc_ppc_page_footer',
          'region' => 'footer',
          'weight' => '-72',
        ),
      ),
    ),
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'cmc_core' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'landing_page' => 0,
          'text_search' => 0,
          'filter_block' => 0,
          'content' => 0,
          'content_home' => 0,
          'content_related' => 0,
          'risk' => 0,
          'footer' => 0,
          'main_nav' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'cmc_regform' => array(
        'disable' => array(
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'content' => 0,
          'header' => 0,
          'footer' => 0,
          'highlighted' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'html5_boilerplate' => array(
        'disable' => array(
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'content' => 0,
          'header' => 0,
          'menu_bar' => 0,
          'highlighted' => 0,
          'footer' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('nodes');
  $export['ppc_node'] = $context;

  return $export;
}
