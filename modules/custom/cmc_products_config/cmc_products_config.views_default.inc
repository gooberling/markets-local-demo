<?php
/**
 * @file
 * cmc_products_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_products_config_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'browse_markets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_sitewide';
  $view->human_name = 'browse markets';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'browse markets';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Instrument Type */
  $handler->display->display_options['fields']['field_instrument_type']['id'] = 'field_instrument_type';
  $handler->display->display_options['fields']['field_instrument_type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_instrument_type']['field'] = 'field_instrument_type';
  $handler->display->display_options['fields']['field_instrument_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_instrument_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instrument_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_instrument_type']['view_mode'] = 'full';
  /* Field: Indexed Node: Max Financing CFD */
  $handler->display->display_options['fields']['field_max_financing_cfd']['id'] = 'field_max_financing_cfd';
  $handler->display->display_options['fields']['field_max_financing_cfd']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_max_financing_cfd']['field'] = 'field_max_financing_cfd';
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_max_financing_cfd']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_max_financing_cfd']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_max_financing_cfd']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_max_financing_cfd']['field_api_classes'] = 0;
  /* Field: Indexed Node: Max Financing SB */
  $handler->display->display_options['fields']['field_max_financing_sb']['id'] = 'field_max_financing_sb';
  $handler->display->display_options['fields']['field_max_financing_sb']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_max_financing_sb']['field'] = 'field_max_financing_sb';
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_max_financing_sb']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_max_financing_sb']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_max_financing_sb']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_max_financing_sb']['field_api_classes'] = 0;
  /* Field: Indexed Node: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_country']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_country']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_country']['view_mode'] = 'full';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'markets/browse';
  $translatables['browse_markets'] = array(
    t('Master'),
    t('browse markets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Title'),
    t('Instrument Type'),
    t('Max Financing CFD'),
    t('Max Financing SB'),
    t('Country'),
    t('Page'),
  );
  $export['browse_markets'] = $view;

  return $export;
}
