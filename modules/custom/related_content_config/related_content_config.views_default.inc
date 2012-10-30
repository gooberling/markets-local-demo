<?php
/**
 * @file
 * related_content_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function related_content_config_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'further_reading';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_sitewide';
  $view->human_name = 'further reading';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'further reading';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Contextual filter: Search: More like this */
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['id'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['field'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['fields'] = array(
    'title' => 'title',
    'field_experience' => 'field_experience',
    'field_theme' => 'field_theme',
    'field_trade_type' => 'field_trade_type',
    'field_keywords' => 'field_keywords',
    'body:value' => 'body:value',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmc_blog' => 'cmc_blog',
    'cmc_document_guide' => 'cmc_document_guide',
    'cmc_page' => 'cmc_page',
    'cmc_video' => 'cmc_video',
  );

  /* Display: Further Reading Main */
  $handler = $view->new_display('block', 'Further Reading Main', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Further Reading List */
  $handler = $view->new_display('block', 'Further Reading List', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['block_caching'] = '4';
  $translatables['further_reading'] = array(
    t('Master'),
    t('further reading'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Teaser'),
    t('All'),
    t('Further Reading Main'),
    t('Further Reading List'),
  );
  $export['further_reading'] = $view;

  $view = new view;
  $view->name = 'related_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_sitewide';
  $view->human_name = 'related content';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_teaser']['element_wrapper_class'] = 'teaser';
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_sitewide';
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
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['author']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['author']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Indexed Node: Content type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['type']['validate']['fail'] = 'ignore';
  /* Contextual filter: Indexed Node: Theme */
  $handler->display->display_options['arguments']['field_theme']['id'] = 'field_theme';
  $handler->display->display_options['arguments']['field_theme']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['arguments']['field_theme']['field'] = 'field_theme';
  $handler->display->display_options['arguments']['field_theme']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_theme']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_theme']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_theme']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_theme']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_theme']['validate_options']['vocabularies'] = array(
    'theme' => 'theme',
    'country' => 0,
    'device' => 0,
    'events' => 0,
    'experience' => 0,
    'instrument_type' => 0,
    'keywords' => 0,
    'location' => 0,
    'platform' => 0,
    'region' => 0,
    'sector' => 0,
    'trade_type' => 0,
  );
  $handler->display->display_options['arguments']['field_theme']['validate_options']['type'] = 'tids';
  $handler->display->display_options['arguments']['field_theme']['validate_options']['transform'] = 0;
  /* Contextual filter: Indexed Node: Trade Type */
  $handler->display->display_options['arguments']['field_trade_type']['id'] = 'field_trade_type';
  $handler->display->display_options['arguments']['field_trade_type']['table'] = 'search_api_index_sitewide';
  $handler->display->display_options['arguments']['field_trade_type']['field'] = 'field_trade_type';
  $handler->display->display_options['arguments']['field_trade_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_trade_type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_trade_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_trade_type']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_trade_type']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_trade_type']['validate_options']['vocabularies'] = array(
    'trade_type' => 'trade_type',
    'blog_vocabulary' => 0,
    'country' => 0,
    'device' => 0,
    'events' => 0,
    'experience' => 0,
    'instrument_type' => 0,
    'keywords' => 0,
    'location' => 0,
    'platform' => 0,
    'region' => 0,
    'sector' => 0,
    'theme' => 0,
  );
  $handler->display->display_options['arguments']['field_trade_type']['validate_options']['type'] = 'tids';
  $handler->display->display_options['arguments']['field_trade_type']['validate_options']['transform'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['related_content'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t('All'),
    t('Block'),
  );
  $export['related_content'] = $view;

  return $export;
}
