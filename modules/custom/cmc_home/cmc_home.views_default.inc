<?php
/**
 * @file
 * cmc_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_home_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cmc_home';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CMC Home';
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
  /* Field: Content: Banner 1 content */
  $handler->display->display_options['fields']['field_home_banner_content1']['id'] = 'field_home_banner_content1';
  $handler->display->display_options['fields']['field_home_banner_content1']['table'] = 'field_data_field_home_banner_content1';
  $handler->display->display_options['fields']['field_home_banner_content1']['field'] = 'field_home_banner_content1';
  $handler->display->display_options['fields']['field_home_banner_content1']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_content1']['element_class'] = 'content';
  $handler->display->display_options['fields']['field_home_banner_content1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_content1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['field_api_classes'] = 0;
  /* Field: Content: Banner 1 image */
  $handler->display->display_options['fields']['field_home_banner_image1']['id'] = 'field_home_banner_image1';
  $handler->display->display_options['fields']['field_home_banner_image1']['table'] = 'field_data_field_home_banner_image1';
  $handler->display->display_options['fields']['field_home_banner_image1']['field'] = 'field_home_banner_image1';
  $handler->display->display_options['fields']['field_home_banner_image1']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_image1']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_home_banner_image1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_image1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_banner_image1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_banner_image1']['field_api_classes'] = 0;
  /* Field: Content: Banner 2 content */
  $handler->display->display_options['fields']['field_home_banner_content2']['id'] = 'field_home_banner_content2';
  $handler->display->display_options['fields']['field_home_banner_content2']['table'] = 'field_data_field_home_banner_content2';
  $handler->display->display_options['fields']['field_home_banner_content2']['field'] = 'field_home_banner_content2';
  /* Field: Content: Banner 2 image */
  $handler->display->display_options['fields']['field_home_banner_image2']['id'] = 'field_home_banner_image2';
  $handler->display->display_options['fields']['field_home_banner_image2']['table'] = 'field_data_field_home_banner_image2';
  $handler->display->display_options['fields']['field_home_banner_image2']['field'] = 'field_home_banner_image2';
  /* Field: Content: Banner 3 content */
  $handler->display->display_options['fields']['field_home_banner_content3']['id'] = 'field_home_banner_content3';
  $handler->display->display_options['fields']['field_home_banner_content3']['table'] = 'field_data_field_home_banner_content3';
  $handler->display->display_options['fields']['field_home_banner_content3']['field'] = 'field_home_banner_content3';
  /* Field: Content: Banner 3 image */
  $handler->display->display_options['fields']['field_home_banner_image3']['id'] = 'field_home_banner_image3';
  $handler->display->display_options['fields']['field_home_banner_image3']['table'] = 'field_data_field_home_banner_image3';
  $handler->display->display_options['fields']['field_home_banner_image3']['field'] = 'field_home_banner_image3';
  /* Field: Content: Banner 4 content */
  $handler->display->display_options['fields']['field_home_banner_content4']['id'] = 'field_home_banner_content4';
  $handler->display->display_options['fields']['field_home_banner_content4']['table'] = 'field_data_field_home_banner_content4';
  $handler->display->display_options['fields']['field_home_banner_content4']['field'] = 'field_home_banner_content4';
  /* Field: Content: Banner 4 image */
  $handler->display->display_options['fields']['field_home_banner_image4']['id'] = 'field_home_banner_image4';
  $handler->display->display_options['fields']['field_home_banner_image4']['table'] = 'field_data_field_home_banner_image4';
  $handler->display->display_options['fields']['field_home_banner_image4']['field'] = 'field_home_banner_image4';
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

  /* Display: Banners */
  $handler = $view->new_display('block', 'Banners', 'banners');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'banner';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Banner 1 image */
  $handler->display->display_options['fields']['field_home_banner_image1']['id'] = 'field_home_banner_image1';
  $handler->display->display_options['fields']['field_home_banner_image1']['table'] = 'field_data_field_home_banner_image1';
  $handler->display->display_options['fields']['field_home_banner_image1']['field'] = 'field_home_banner_image1';
  $handler->display->display_options['fields']['field_home_banner_image1']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_image1']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_home_banner_image1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_image1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_banner_image1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_banner_image1']['field_api_classes'] = 0;
  /* Field: Content: Banner 1 content */
  $handler->display->display_options['fields']['field_home_banner_content1']['id'] = 'field_home_banner_content1';
  $handler->display->display_options['fields']['field_home_banner_content1']['table'] = 'field_data_field_home_banner_content1';
  $handler->display->display_options['fields']['field_home_banner_content1']['field'] = 'field_home_banner_content1';
  $handler->display->display_options['fields']['field_home_banner_content1']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_content1']['element_class'] = 'content';
  $handler->display->display_options['fields']['field_home_banner_content1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_content1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content1']['field_api_classes'] = 0;
  /* Field: Content: Banner 2 image */
  $handler->display->display_options['fields']['field_home_banner_image2']['id'] = 'field_home_banner_image2';
  $handler->display->display_options['fields']['field_home_banner_image2']['table'] = 'field_data_field_home_banner_image2';
  $handler->display->display_options['fields']['field_home_banner_image2']['field'] = 'field_home_banner_image2';
  $handler->display->display_options['fields']['field_home_banner_image2']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_image2']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_home_banner_image2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_image2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_banner_image2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_banner_image2']['field_api_classes'] = 0;
  /* Field: Content: Banner 2 content */
  $handler->display->display_options['fields']['field_home_banner_content2']['id'] = 'field_home_banner_content2';
  $handler->display->display_options['fields']['field_home_banner_content2']['table'] = 'field_data_field_home_banner_content2';
  $handler->display->display_options['fields']['field_home_banner_content2']['field'] = 'field_home_banner_content2';
  $handler->display->display_options['fields']['field_home_banner_content2']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_content2']['element_class'] = 'content';
  $handler->display->display_options['fields']['field_home_banner_content2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_content2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content2']['field_api_classes'] = 0;
  /* Field: Content: Banner 3 image */
  $handler->display->display_options['fields']['field_home_banner_image3']['id'] = 'field_home_banner_image3';
  $handler->display->display_options['fields']['field_home_banner_image3']['table'] = 'field_data_field_home_banner_image3';
  $handler->display->display_options['fields']['field_home_banner_image3']['field'] = 'field_home_banner_image3';
  $handler->display->display_options['fields']['field_home_banner_image3']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_image3']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_home_banner_image3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_image3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_banner_image3']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_banner_image3']['field_api_classes'] = 0;
  /* Field: Content: Banner 3 content */
  $handler->display->display_options['fields']['field_home_banner_content3']['id'] = 'field_home_banner_content3';
  $handler->display->display_options['fields']['field_home_banner_content3']['table'] = 'field_data_field_home_banner_content3';
  $handler->display->display_options['fields']['field_home_banner_content3']['field'] = 'field_home_banner_content3';
  $handler->display->display_options['fields']['field_home_banner_content3']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_content3']['element_class'] = 'content';
  $handler->display->display_options['fields']['field_home_banner_content3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_content3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content3']['field_api_classes'] = 0;
  /* Field: Content: Banner 4 image */
  $handler->display->display_options['fields']['field_home_banner_image4']['id'] = 'field_home_banner_image4';
  $handler->display->display_options['fields']['field_home_banner_image4']['table'] = 'field_data_field_home_banner_image4';
  $handler->display->display_options['fields']['field_home_banner_image4']['field'] = 'field_home_banner_image4';
  $handler->display->display_options['fields']['field_home_banner_image4']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_image4']['element_class'] = 'image';
  $handler->display->display_options['fields']['field_home_banner_image4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_image4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_image4']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_banner_image4']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_banner_image4']['field_api_classes'] = 0;
  /* Field: Content: Banner 4 content */
  $handler->display->display_options['fields']['field_home_banner_content4']['id'] = 'field_home_banner_content4';
  $handler->display->display_options['fields']['field_home_banner_content4']['table'] = 'field_data_field_home_banner_content4';
  $handler->display->display_options['fields']['field_home_banner_content4']['field'] = 'field_home_banner_content4';
  $handler->display->display_options['fields']['field_home_banner_content4']['label'] = '';
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_home_banner_content4']['element_class'] = 'content';
  $handler->display->display_options['fields']['field_home_banner_content4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_banner_content4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_banner_content4']['field_api_classes'] = 0;
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

  /* Display: Heroes */
  $handler = $view->new_display('block', 'Heroes', 'heroes');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Hero Image 1 */
  $handler->display->display_options['fields']['field_home_hero_image1']['id'] = 'field_home_hero_image1';
  $handler->display->display_options['fields']['field_home_hero_image1']['table'] = 'field_data_field_home_hero_image1';
  $handler->display->display_options['fields']['field_home_hero_image1']['field'] = 'field_home_hero_image1';
  $handler->display->display_options['fields']['field_home_hero_image1']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image1']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 1 */
  $handler->display->display_options['fields']['field_home_hero_content1']['id'] = 'field_home_hero_content1';
  $handler->display->display_options['fields']['field_home_hero_content1']['table'] = 'field_data_field_home_hero_content1';
  $handler->display->display_options['fields']['field_home_hero_content1']['field'] = 'field_home_hero_content1';
  $handler->display->display_options['fields']['field_home_hero_content1']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['field_api_classes'] = 0;
  /* Field: Content: Hero Image 2 */
  $handler->display->display_options['fields']['field_home_hero_image2']['id'] = 'field_home_hero_image2';
  $handler->display->display_options['fields']['field_home_hero_image2']['table'] = 'field_data_field_home_hero_image2';
  $handler->display->display_options['fields']['field_home_hero_image2']['field'] = 'field_home_hero_image2';
  $handler->display->display_options['fields']['field_home_hero_image2']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image2']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 2 */
  $handler->display->display_options['fields']['field_home_hero_content2']['id'] = 'field_home_hero_content2';
  $handler->display->display_options['fields']['field_home_hero_content2']['table'] = 'field_data_field_home_hero_content2';
  $handler->display->display_options['fields']['field_home_hero_content2']['field'] = 'field_home_hero_content2';
  $handler->display->display_options['fields']['field_home_hero_content2']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['field_api_classes'] = 0;
  /* Field: Content: Hero Image 3 */
  $handler->display->display_options['fields']['field_home_hero_image3']['id'] = 'field_home_hero_image3';
  $handler->display->display_options['fields']['field_home_hero_image3']['table'] = 'field_data_field_home_hero_image3';
  $handler->display->display_options['fields']['field_home_hero_image3']['field'] = 'field_home_hero_image3';
  $handler->display->display_options['fields']['field_home_hero_image3']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image3']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image3']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 3 */
  $handler->display->display_options['fields']['field_home_hero_content3']['id'] = 'field_home_hero_content3';
  $handler->display->display_options['fields']['field_home_hero_content3']['table'] = 'field_data_field_home_hero_content3';
  $handler->display->display_options['fields']['field_home_hero_content3']['field'] = 'field_home_hero_content3';
  $handler->display->display_options['fields']['field_home_hero_content3']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['field_api_classes'] = 0;
  /* Field: Content: Hero Image 4 */
  $handler->display->display_options['fields']['field_home_hero_image4']['id'] = 'field_home_hero_image4';
  $handler->display->display_options['fields']['field_home_hero_image4']['table'] = 'field_data_field_home_hero_image4';
  $handler->display->display_options['fields']['field_home_hero_image4']['field'] = 'field_home_hero_image4';
  $handler->display->display_options['fields']['field_home_hero_image4']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image4']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image4']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 4 */
  $handler->display->display_options['fields']['field_home_hero_content4']['id'] = 'field_home_hero_content4';
  $handler->display->display_options['fields']['field_home_hero_content4']['table'] = 'field_data_field_home_hero_content4';
  $handler->display->display_options['fields']['field_home_hero_content4']['field'] = 'field_home_hero_content4';
  $handler->display->display_options['fields']['field_home_hero_content4']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['field_api_classes'] = 0;
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

  /* Display: Signup */
  $handler = $view->new_display('block', 'Signup', 'signup');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Hero Image 1 */
  $handler->display->display_options['fields']['field_home_hero_image1']['id'] = 'field_home_hero_image1';
  $handler->display->display_options['fields']['field_home_hero_image1']['table'] = 'field_data_field_home_hero_image1';
  $handler->display->display_options['fields']['field_home_hero_image1']['field'] = 'field_home_hero_image1';
  $handler->display->display_options['fields']['field_home_hero_image1']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image1']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 1 */
  $handler->display->display_options['fields']['field_home_hero_content1']['id'] = 'field_home_hero_content1';
  $handler->display->display_options['fields']['field_home_hero_content1']['table'] = 'field_data_field_home_hero_content1';
  $handler->display->display_options['fields']['field_home_hero_content1']['field'] = 'field_home_hero_content1';
  $handler->display->display_options['fields']['field_home_hero_content1']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content1']['field_api_classes'] = 0;
  /* Field: Content: Hero Image 2 */
  $handler->display->display_options['fields']['field_home_hero_image2']['id'] = 'field_home_hero_image2';
  $handler->display->display_options['fields']['field_home_hero_image2']['table'] = 'field_data_field_home_hero_image2';
  $handler->display->display_options['fields']['field_home_hero_image2']['field'] = 'field_home_hero_image2';
  $handler->display->display_options['fields']['field_home_hero_image2']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image2']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 2 */
  $handler->display->display_options['fields']['field_home_hero_content2']['id'] = 'field_home_hero_content2';
  $handler->display->display_options['fields']['field_home_hero_content2']['table'] = 'field_data_field_home_hero_content2';
  $handler->display->display_options['fields']['field_home_hero_content2']['field'] = 'field_home_hero_content2';
  $handler->display->display_options['fields']['field_home_hero_content2']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content2']['field_api_classes'] = 0;
  /* Field: Content: Hero Image 3 */
  $handler->display->display_options['fields']['field_home_hero_image3']['id'] = 'field_home_hero_image3';
  $handler->display->display_options['fields']['field_home_hero_image3']['table'] = 'field_data_field_home_hero_image3';
  $handler->display->display_options['fields']['field_home_hero_image3']['field'] = 'field_home_hero_image3';
  $handler->display->display_options['fields']['field_home_hero_image3']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image3']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image3']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 3 */
  $handler->display->display_options['fields']['field_home_hero_content3']['id'] = 'field_home_hero_content3';
  $handler->display->display_options['fields']['field_home_hero_content3']['table'] = 'field_data_field_home_hero_content3';
  $handler->display->display_options['fields']['field_home_hero_content3']['field'] = 'field_home_hero_content3';
  $handler->display->display_options['fields']['field_home_hero_content3']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content3']['field_api_classes'] = 0;
  /* Field: Content: Hero Image 4 */
  $handler->display->display_options['fields']['field_home_hero_image4']['id'] = 'field_home_hero_image4';
  $handler->display->display_options['fields']['field_home_hero_image4']['table'] = 'field_data_field_home_hero_image4';
  $handler->display->display_options['fields']['field_home_hero_image4']['field'] = 'field_home_hero_image4';
  $handler->display->display_options['fields']['field_home_hero_image4']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_image4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_image4']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_hero_image4']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_home_hero_image4']['field_api_classes'] = 0;
  /* Field: Content: Hero Content 4 */
  $handler->display->display_options['fields']['field_home_hero_content4']['id'] = 'field_home_hero_content4';
  $handler->display->display_options['fields']['field_home_hero_content4']['table'] = 'field_data_field_home_hero_content4';
  $handler->display->display_options['fields']['field_home_hero_content4']['field'] = 'field_home_hero_content4';
  $handler->display->display_options['fields']['field_home_hero_content4']['label'] = '';
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_home_hero_content4']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_home_hero_content4']['field_api_classes'] = 0;
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
  $translatables['cmc_home'] = array(
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
    t('Banner 2 content'),
    t('Banner 2 image'),
    t('Banner 3 content'),
    t('Banner 3 image'),
    t('Banner 4 content'),
    t('Banner 4 image'),
    t('All'),
    t('Banners'),
    t('Heroes'),
    t('Signup'),
  );
  $export['cmc_home'] = $view;

  return $export;
}
