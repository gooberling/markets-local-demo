<?php
/**
 * @file
 * cmc_platform_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_platform_page_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cmc_platform';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CMC Platform';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'platform-header dynamicHeight';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'platform-header-hero';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
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
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
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
  $handler->display->display_options['fields']['field_teaser']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser']['element_class'] = 'hero-content grid-4';
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  /* Field: Content: Platform Android */
  $handler->display->display_options['fields']['field_platform_android']['id'] = 'field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['table'] = 'field_data_field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['field'] = 'field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['label'] = '';
  $handler->display->display_options['fields']['field_platform_android']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['element_class'] = 'dynamicWidth';
  $handler->display->display_options['fields']['field_platform_android']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_android']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_android']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_android']['field_api_classes'] = 0;
  /* Field: Content: Platform Desktop */
  $handler->display->display_options['fields']['field_platform_desktop']['id'] = 'field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['table'] = 'field_data_field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['field'] = 'field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['label'] = '';
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_platform_desktop']['element_class'] = 'hero-image dynamicExtra dynamicWidth';
  $handler->display->display_options['fields']['field_platform_desktop']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_desktop']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_desktop']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_desktop']['field_api_classes'] = 0;
  /* Field: Content: Platform iPad */
  $handler->display->display_options['fields']['field_platform_ipad']['id'] = 'field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['table'] = 'field_data_field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['field'] = 'field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['label'] = '';
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_ipad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_ipad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_ipad']['field_api_classes'] = 0;
  /* Field: Content: Platform iPhone */
  $handler->display->display_options['fields']['field_platform_iphone']['id'] = 'field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['table'] = 'field_data_field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['field'] = 'field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['label'] = '';
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_iphone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_iphone']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_iphone']['field_api_classes'] = 0;
  /* Field: Content: Platform Navigation Image */
  $handler->display->display_options['fields']['field_platform_nav_image']['id'] = 'field_platform_nav_image';
  $handler->display->display_options['fields']['field_platform_nav_image']['table'] = 'field_data_field_platform_nav_image';
  $handler->display->display_options['fields']['field_platform_nav_image']['field'] = 'field_platform_nav_image';
  /* Field: Content: Platform Navigation Text */
  $handler->display->display_options['fields']['field_platform_nav_text']['id'] = 'field_platform_nav_text';
  $handler->display->display_options['fields']['field_platform_nav_text']['table'] = 'field_data_field_platform_nav_text';
  $handler->display->display_options['fields']['field_platform_nav_text']['field'] = 'field_platform_nav_text';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'cmc_platform_page' => 'cmc_platform_page',
  );

  /* Display: Header Desktop */
  $handler = $view->new_display('block', 'Header Desktop', 'header_desktop');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Platform Desktop */
  $handler->display->display_options['fields']['field_platform_desktop']['id'] = 'field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['table'] = 'field_data_field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['field'] = 'field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['label'] = '';
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_platform_desktop']['element_class'] = 'hero-image dynamicExtra dynamicWidth';
  $handler->display->display_options['fields']['field_platform_desktop']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_desktop']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_desktop']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_desktop']['field_api_classes'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
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
  $handler->display->display_options['fields']['field_teaser']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser']['element_class'] = 'hero-content grid-4';
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Navigation */
  $handler = $view->new_display('block', 'Navigation', 'navigation');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'platform-nav';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '5';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<div class="nav-links"><div class="nav-links-pos">';
  $handler->display->display_options['fields']['nothing_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_4']['hide_alter_empty'] = 0;
  /* Field: Content: Platform Desktop */
  $handler->display->display_options['fields']['field_platform_desktop']['id'] = 'field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['table'] = 'field_data_field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['field'] = 'field_platform_desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['label'] = '';
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['text'] = 'Desktop -';
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['path'] = 'node/[nid]?platform=desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['link_class'] = 'desktop';
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_desktop']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_desktop']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_desktop']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_desktop']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_desktop']['field_api_classes'] = 0;
  /* Field: Content: Platform iPad */
  $handler->display->display_options['fields']['field_platform_ipad']['id'] = 'field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['table'] = 'field_data_field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['field'] = 'field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['label'] = '';
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['text'] = 'iPad -';
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['path'] = 'node/[nid]?platform=ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['link_class'] = 'ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_ipad']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_ipad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_ipad']['field_api_classes'] = 0;
  /* Field: Content: Platform iPhone */
  $handler->display->display_options['fields']['field_platform_iphone']['id'] = 'field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['table'] = 'field_data_field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['field'] = 'field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['label'] = '';
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['text'] = 'iPhone';
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['path'] = 'node/[nid]?platform=iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['link_class'] = 'iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_iphone']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_iphone']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_iphone']['field_api_classes'] = 0;
  /* Field: Content: Platform Android */
  $handler->display->display_options['fields']['field_platform_android']['id'] = 'field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['table'] = 'field_data_field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['field'] = 'field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['label'] = '';
  $handler->display->display_options['fields']['field_platform_android']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['text'] = 'Android -';
  $handler->display->display_options['fields']['field_platform_android']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['path'] = 'node/[nid]?platform=android';
  $handler->display->display_options['fields']['field_platform_android']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['link_class'] = 'android';
  $handler->display->display_options['fields']['field_platform_android']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_android']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_android']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_android']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_5']['id'] = 'nothing_5';
  $handler->display->display_options['fields']['nothing_5']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_5']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_5']['label'] = '';
  $handler->display->display_options['fields']['nothing_5']['alter']['text'] = '</div></div>';
  $handler->display->display_options['fields']['nothing_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_5']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_5']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_6']['id'] = 'nothing_6';
  $handler->display->display_options['fields']['nothing_6']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_6']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_6']['label'] = '';
  $handler->display->display_options['fields']['nothing_6']['alter']['text'] = '<div class="nav-content">';
  $handler->display->display_options['fields']['nothing_6']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_6']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_6']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_6']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_6']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_6']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_6']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_6']['hide_alter_empty'] = 0;
  /* Field: Content: Platform Navigation Image */
  $handler->display->display_options['fields']['field_platform_nav_image']['id'] = 'field_platform_nav_image';
  $handler->display->display_options['fields']['field_platform_nav_image']['table'] = 'field_data_field_platform_nav_image';
  $handler->display->display_options['fields']['field_platform_nav_image']['field'] = 'field_platform_nav_image';
  $handler->display->display_options['fields']['field_platform_nav_image']['label'] = '';
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_nav_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_nav_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_nav_image']['field_api_classes'] = 0;
  /* Field: Content: Platform Navigation Text */
  $handler->display->display_options['fields']['field_platform_nav_text']['id'] = 'field_platform_nav_text';
  $handler->display->display_options['fields']['field_platform_nav_text']['table'] = 'field_data_field_platform_nav_text';
  $handler->display->display_options['fields']['field_platform_nav_text']['field'] = 'field_platform_nav_text';
  $handler->display->display_options['fields']['field_platform_nav_text']['label'] = '';
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_nav_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_platform_nav_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_nav_text']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_7']['id'] = 'nothing_7';
  $handler->display->display_options['fields']['nothing_7']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_7']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_7']['label'] = '';
  $handler->display->display_options['fields']['nothing_7']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_7']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_7']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_7']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_7']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_7']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_7']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_7']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_7']['hide_alter_empty'] = 0;

  /* Display: Header iPad */
  $handler = $view->new_display('block', 'Header iPad', 'header_ipad');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Platform iPad */
  $handler->display->display_options['fields']['field_platform_ipad']['id'] = 'field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['table'] = 'field_data_field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['field'] = 'field_platform_ipad';
  $handler->display->display_options['fields']['field_platform_ipad']['label'] = '';
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_platform_ipad']['element_class'] = 'hero-image dynamicExtra dynamicWidth';
  $handler->display->display_options['fields']['field_platform_ipad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_ipad']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_ipad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_ipad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_ipad']['field_api_classes'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
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
  $handler->display->display_options['fields']['field_teaser']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser']['element_class'] = 'hero-content grid-4';
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="read-more"><a href="#">Read More</a></div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '#';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'read-more';
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Header iPhone */
  $handler = $view->new_display('block', 'Header iPhone', 'header_iphone');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Platform iPhone */
  $handler->display->display_options['fields']['field_platform_iphone']['id'] = 'field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['table'] = 'field_data_field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['field'] = 'field_platform_iphone';
  $handler->display->display_options['fields']['field_platform_iphone']['label'] = '';
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_platform_iphone']['element_class'] = 'hero-image dynamicExtra dynamicWidth';
  $handler->display->display_options['fields']['field_platform_iphone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_iphone']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_iphone']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_iphone']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_iphone']['field_api_classes'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
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
  $handler->display->display_options['fields']['field_teaser']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser']['element_class'] = 'hero-content grid-4';
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="read-more"><a href="#">Read More</a></div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '#';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'read-more';
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Header Android */
  $handler = $view->new_display('block', 'Header Android', 'header_android');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Platform Android */
  $handler->display->display_options['fields']['field_platform_android']['id'] = 'field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['table'] = 'field_data_field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['field'] = 'field_platform_android';
  $handler->display->display_options['fields']['field_platform_android']['label'] = '';
  $handler->display->display_options['fields']['field_platform_android']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_platform_android']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_platform_android']['element_class'] = 'hero-image dynamicExtra dynamicWidth';
  $handler->display->display_options['fields']['field_platform_android']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_platform_android']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_platform_android']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_platform_android']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_platform_android']['field_api_classes'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
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
  $handler->display->display_options['fields']['field_teaser']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser']['element_class'] = 'hero-content grid-4';
  $handler->display->display_options['fields']['field_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_teaser']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="read-more"><a href="#">Read More</a></div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '#';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'read-more';
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $translatables['cmc_platform'] = array(
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
    t('Platform Navigation Image'),
    t('Platform Navigation Text'),
    t('Custom text'),
    t('Header Desktop'),
    t('All'),
    t('Navigation'),
    t('<div class="nav-links"><div class="nav-links-pos">'),
    t('Desktop -'),
    t('node/[nid]?platform=desktop'),
    t('iPad -'),
    t('node/[nid]?platform=ipad'),
    t('iPhone'),
    t('node/[nid]?platform=iphone'),
    t('Android -'),
    t('node/[nid]?platform=android'),
    t('</div></div>'),
    t('<div class="nav-content">'),
    t('</div>'),
    t('Header iPad'),
    t('<div class="read-more"><a href="#">Read More</a></div>'),
    t('#'),
    t('Header iPhone'),
    t('Header Android'),
  );
  $export['cmc_platform'] = $view;

  return $export;
}
