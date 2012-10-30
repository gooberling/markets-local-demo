<?php
/**
 * @file
 * cmc_instruments_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_instruments_search_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'instruments_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_sitewide';
  $view->human_name = 'instruments_search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'instruments_search';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Result summary */
  $handler->display->display_options['empty']['result']['id'] = 'result';
  $handler->display->display_options['empty']['result']['table'] = 'views';
  $handler->display->display_options['empty']['result']['field'] = 'result';
  $handler->display->display_options['empty']['result']['empty'] = FALSE;
  $handler->display->display_options['empty']['result']['content'] = 'No results found';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Indexed Content: Instrument Code */
  $handler->display->display_options['fields']['field_instrument_code']['id'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_instrument_code']['field'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['field_api_classes'] = 0;
  /* Field: Indexed Content: Title Search */
  $handler->display->display_options['fields']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['fields']['search_api_aggregation_1']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['search_api_aggregation_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['search_api_aggregation_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['search_api_aggregation_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['search_api_aggregation_1']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_background' => 'field_background',
    'field_currency' => 'field_currency',
    'field_influencing_factors' => 'field_influencing_factors',
    'field_instrument_code' => 'field_instrument_code',
    'search_api_aggregation_1' => 'search_api_aggregation_1',
    'author:mail' => 'author:mail',
    'body:value' => 'body:value',
    'body:summary' => 'body:summary',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'instruments-search';
  $translatables['instruments_search'] = array(
    t('Master'),
    t('instruments_search'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No results found'),
    t('Title'),
    t('Instrument Code'),
    t('Title Search'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['instruments_search'] = $view;

  return $export;
}
