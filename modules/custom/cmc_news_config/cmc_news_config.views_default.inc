<?php
/**
 * @file
 * cmc_news_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_news_config_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'product_related_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'product-related news';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Products (field_products) */
  $handler->display->display_options['arguments']['field_products_target_id']['id'] = 'field_products_target_id';
  $handler->display->display_options['arguments']['field_products_target_id']['table'] = 'field_data_field_products';
  $handler->display->display_options['arguments']['field_products_target_id']['field'] = 'field_products_target_id';
  $handler->display->display_options['arguments']['field_products_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_products_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_products_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_products_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_products_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_products_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_products_target_id']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_products_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_products_target_id']['validate_options']['types'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['arguments']['field_products_target_id']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['field_products_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_products_target_id']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Latest story */
  $handler = $view->new_display('entity_view', 'Latest story', 'latest_story');
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'product',
  );

  /* Display: Entity content */
  $handler = $view->new_display('entity_view', 'Entity content', 'recent_stories');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'product',
  );
  $translatables['product_related_news'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Latest story'),
    t('Entity content'),
  );
  $export['product_related_news'] = $view;

  return $export;
}
