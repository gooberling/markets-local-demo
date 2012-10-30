<?php
/**
 * @file
 * crm_applications_queue.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_applications_queue_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'application_queue';
  $view->description = 'Displays list of items in Applications Queue';
  $view->tag = 'default';
  $view->base_table = 'queue';
  $view->human_name = 'Pending Applications Queue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Applications Queue';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: SystemQueue: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'queue';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: SystemQueue: Data */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'queue';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  $handler->display->display_options['fields']['data']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['data']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['data']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['data']['alter']['external'] = 0;
  $handler->display->display_options['fields']['data']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['data']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['data']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['data']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['data']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['data']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['data']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['data']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['data']['alter']['html'] = 0;
  $handler->display->display_options['fields']['data']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['data']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['data']['hide_empty'] = 0;
  $handler->display->display_options['fields']['data']['empty_zero'] = 0;
  $handler->display->display_options['fields']['data']['hide_alter_empty'] = 1;
  /* Field: SystemQueue: Expire */
  $handler->display->display_options['fields']['expire']['id'] = 'expire';
  $handler->display->display_options['fields']['expire']['table'] = 'queue';
  $handler->display->display_options['fields']['expire']['field'] = 'expire';
  $handler->display->display_options['fields']['expire']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['external'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['expire']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['expire']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['expire']['alter']['html'] = 0;
  $handler->display->display_options['fields']['expire']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['expire']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['expire']['hide_empty'] = 0;
  $handler->display->display_options['fields']['expire']['empty_zero'] = 0;
  $handler->display->display_options['fields']['expire']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['expire']['date_format'] = 'long';
  /* Sort criterion: SystemQueue: Creation */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'queue';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: SystemQueue: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'queue';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = 'cmc_live_applications';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'applications_queue';
  $translatables['application_queue'] = array(
    t('Master'),
    t('Applications Queue'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Item ID'),
    t('Data'),
    t('Expire'),
    t('Page'),
  );
  $export['application_queue'] = $view;

  return $export;
}
