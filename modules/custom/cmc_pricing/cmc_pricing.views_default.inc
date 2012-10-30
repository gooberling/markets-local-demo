<?php
/**
 * @file
 * cmc_pricing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_pricing_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cmc_pricing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CMC Pricing';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Tab 1 Products (field_pricing_products1) */
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['id'] = 'field_pricing_products1_nid';
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['table'] = 'field_data_field_pricing_products1';
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['field'] = 'field_pricing_products1_nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Instrument Code */
  $handler->display->display_options['fields']['field_instrument_code']['id'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['table'] = 'field_data_field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['field'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['label'] = '';
  $handler->display->display_options['fields']['field_instrument_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instrument_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Tab 3 Title */
  $handler->display->display_options['fields']['field_pricing_title3']['id'] = 'field_pricing_title3';
  $handler->display->display_options['fields']['field_pricing_title3']['table'] = 'field_data_field_pricing_title3';
  $handler->display->display_options['fields']['field_pricing_title3']['field'] = 'field_pricing_title3';
  /* Field: Content: Tab 2 Title */
  $handler->display->display_options['fields']['field_pricing_title2']['id'] = 'field_pricing_title2';
  $handler->display->display_options['fields']['field_pricing_title2']['table'] = 'field_data_field_pricing_title2';
  $handler->display->display_options['fields']['field_pricing_title2']['field'] = 'field_pricing_title2';
  /* Field: Content: Tab 4 Title */
  $handler->display->display_options['fields']['field_pricing_title4']['id'] = 'field_pricing_title4';
  $handler->display->display_options['fields']['field_pricing_title4']['table'] = 'field_data_field_pricing_title4';
  $handler->display->display_options['fields']['field_pricing_title4']['field'] = 'field_pricing_title4';
  /* Field: Content: Tab 5 Title */
  $handler->display->display_options['fields']['field_pricing_title5']['id'] = 'field_pricing_title5';
  $handler->display->display_options['fields']['field_pricing_title5']['table'] = 'field_data_field_pricing_title5';
  $handler->display->display_options['fields']['field_pricing_title5']['field'] = 'field_pricing_title5';
  /* Field: Content: Tab 1 Title */
  $handler->display->display_options['fields']['field_pricing_title1']['id'] = 'field_pricing_title1';
  $handler->display->display_options['fields']['field_pricing_title1']['table'] = 'field_data_field_pricing_title1';
  $handler->display->display_options['fields']['field_pricing_title1']['field'] = 'field_pricing_title1';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';

  /* Display: product by name */
  $handler = $view->new_display('block', 'product by name', 'product_by_name');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = 0;
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['title']['break_phrase'] = 0;
  /* Contextual filter: Content: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['arguments']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['arguments']['field_country_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_country_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_country_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_country_tid']['not'] = 0;

  /* Display: Pricing Panel List */
  $handler = $view->new_display('block', 'Pricing Panel List', 'pricing_panel_list');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Instrument Code */
  $handler->display->display_options['fields']['field_instrument_code']['id'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['table'] = 'field_data_field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['field'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['label'] = '';
  $handler->display->display_options['fields']['field_instrument_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instrument_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmc_pricing_panel' => 'cmc_pricing_panel',
  );

  /* Display: Pricing Panels */
  $handler = $view->new_display('block', 'Pricing Panels', 'pricing_panels');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Tab 1 Products (field_pricing_products1) */
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['id'] = 'field_pricing_products1_nid';
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['table'] = 'field_data_field_pricing_products1';
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['field'] = 'field_pricing_products1_nid';
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_pricing_products1_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Instrument Code */
  $handler->display->display_options['fields']['field_instrument_code']['id'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['table'] = 'field_data_field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['field'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['label'] = '';
  $handler->display->display_options['fields']['field_instrument_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instrument_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Tab 1 Title */
  $handler->display->display_options['fields']['field_pricing_title1']['id'] = 'field_pricing_title1';
  $handler->display->display_options['fields']['field_pricing_title1']['table'] = 'field_data_field_pricing_title1';
  $handler->display->display_options['fields']['field_pricing_title1']['field'] = 'field_pricing_title1';
  $handler->display->display_options['fields']['field_pricing_title1']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_title1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_title1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title1']['field_api_classes'] = 0;
  /* Field: Content: Tab 1 Products */
  $handler->display->display_options['fields']['field_pricing_products1']['id'] = 'field_pricing_products1';
  $handler->display->display_options['fields']['field_pricing_products1']['table'] = 'field_data_field_pricing_products1';
  $handler->display->display_options['fields']['field_pricing_products1']['field'] = 'field_pricing_products1';
  $handler->display->display_options['fields']['field_pricing_products1']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_products1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_products1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_pricing_products1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pricing_products1']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_pricing_products1']['field_api_classes'] = 0;
  /* Field: Content: Tab 2 Title */
  $handler->display->display_options['fields']['field_pricing_title2']['id'] = 'field_pricing_title2';
  $handler->display->display_options['fields']['field_pricing_title2']['table'] = 'field_data_field_pricing_title2';
  $handler->display->display_options['fields']['field_pricing_title2']['field'] = 'field_pricing_title2';
  $handler->display->display_options['fields']['field_pricing_title2']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_title2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_title2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title2']['field_api_classes'] = 0;
  /* Field: Content: Tab 2 Products */
  $handler->display->display_options['fields']['field_pricing_products2']['id'] = 'field_pricing_products2';
  $handler->display->display_options['fields']['field_pricing_products2']['table'] = 'field_data_field_pricing_products2';
  $handler->display->display_options['fields']['field_pricing_products2']['field'] = 'field_pricing_products2';
  $handler->display->display_options['fields']['field_pricing_products2']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_products2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_products2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_pricing_products2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pricing_products2']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_pricing_products2']['field_api_classes'] = 0;
  /* Field: Content: Tab 3 Title */
  $handler->display->display_options['fields']['field_pricing_title3']['id'] = 'field_pricing_title3';
  $handler->display->display_options['fields']['field_pricing_title3']['table'] = 'field_data_field_pricing_title3';
  $handler->display->display_options['fields']['field_pricing_title3']['field'] = 'field_pricing_title3';
  $handler->display->display_options['fields']['field_pricing_title3']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_title3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_title3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title3']['field_api_classes'] = 0;
  /* Field: Content: Tab 3 Products */
  $handler->display->display_options['fields']['field_pricing_products3']['id'] = 'field_pricing_products3';
  $handler->display->display_options['fields']['field_pricing_products3']['table'] = 'field_data_field_pricing_products3';
  $handler->display->display_options['fields']['field_pricing_products3']['field'] = 'field_pricing_products3';
  $handler->display->display_options['fields']['field_pricing_products3']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_products3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_products3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_pricing_products3']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pricing_products3']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_pricing_products3']['field_api_classes'] = 0;
  /* Field: Content: Tab 4 Title */
  $handler->display->display_options['fields']['field_pricing_title4']['id'] = 'field_pricing_title4';
  $handler->display->display_options['fields']['field_pricing_title4']['table'] = 'field_data_field_pricing_title4';
  $handler->display->display_options['fields']['field_pricing_title4']['field'] = 'field_pricing_title4';
  $handler->display->display_options['fields']['field_pricing_title4']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_title4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_title4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title4']['field_api_classes'] = 0;
  /* Field: Content: Tab 4 Products */
  $handler->display->display_options['fields']['field_pricing_products4']['id'] = 'field_pricing_products4';
  $handler->display->display_options['fields']['field_pricing_products4']['table'] = 'field_data_field_pricing_products4';
  $handler->display->display_options['fields']['field_pricing_products4']['field'] = 'field_pricing_products4';
  $handler->display->display_options['fields']['field_pricing_products4']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_products4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_products4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_pricing_products4']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pricing_products4']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_pricing_products4']['field_api_classes'] = 0;
  /* Field: Content: Tab 5 Title */
  $handler->display->display_options['fields']['field_pricing_title5']['id'] = 'field_pricing_title5';
  $handler->display->display_options['fields']['field_pricing_title5']['table'] = 'field_data_field_pricing_title5';
  $handler->display->display_options['fields']['field_pricing_title5']['field'] = 'field_pricing_title5';
  $handler->display->display_options['fields']['field_pricing_title5']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_title5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_title5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_title5']['field_api_classes'] = 0;
  /* Field: Content: Tab 5 Products */
  $handler->display->display_options['fields']['field_pricing_products5']['id'] = 'field_pricing_products5';
  $handler->display->display_options['fields']['field_pricing_products5']['table'] = 'field_data_field_pricing_products5';
  $handler->display->display_options['fields']['field_pricing_products5']['field'] = 'field_pricing_products5';
  $handler->display->display_options['fields']['field_pricing_products5']['label'] = '';
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pricing_products5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pricing_products5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_pricing_products5']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pricing_products5']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_pricing_products5']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Instrument Codes */
  $handler = $view->new_display('block', 'Instrument Codes', 'instrument_codes');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Instrument Code */
  $handler->display->display_options['fields']['field_instrument_code']['id'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['table'] = 'field_data_field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['field'] = 'field_instrument_code';
  $handler->display->display_options['fields']['field_instrument_code']['label'] = '';
  $handler->display->display_options['fields']['field_instrument_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instrument_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instrument_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_instrument_code']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $translatables['cmc_pricing'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_pricing_products1'),
    t('Nid'),
    t('Tab 3 Title'),
    t('Tab 2 Title'),
    t('Tab 4 Title'),
    t('Tab 5 Title'),
    t('Tab 1 Title'),
    t('All'),
    t('product by name'),
    t('Pricing Panel List'),
    t('Pricing Panels'),
    t('Instrument Codes'),
  );
  $export['cmc_pricing'] = $view;

  return $export;
}
