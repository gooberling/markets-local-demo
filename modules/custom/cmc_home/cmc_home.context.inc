<?php
/**
 * @file
 * cmc_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmc_home_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmc_home';
  $context->description = 'CMC Homepage context';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmc_home' => 'cmc_home',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~node/3685' => '~node/3685',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cmc_home-cmc_home_heroes' => array(
          'module' => 'cmc_home',
          'delta' => 'cmc_home_heroes',
          'region' => 'landing_page',
          'weight' => '-10',
        ),
        'cmc_home-cmc_home_banners' => array(
          'module' => 'cmc_home',
          'delta' => 'cmc_home_banners',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'region' => array(
      'cmc_core' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'landing_page' => 0,
          'text_search' => 0,
          'filter_block' => 0,
          'content' => 0,
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
  t('CMC Homepage context');
  $export['cmc_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmc_sign_up';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmc_home' => 'cmc_home',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/3685' => 'node/3685',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cmc_home-cmc_home_signup' => array(
          'module' => 'cmc_home',
          'delta' => 'cmc_home_signup',
          'region' => 'content',
          'weight' => '-50',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-49',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['cmc_sign_up'] = $context;

  return $export;
}
