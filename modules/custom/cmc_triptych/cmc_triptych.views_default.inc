<?php
/**
 * @file
 * cmc_triptych.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmc_triptych_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cmc_triptych';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CMC Triptych';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Header */
  $handler = $view->new_display('block', 'Header', 'header');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div id="triptych1" class="triptych">';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Image 1 */
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['id'] = 'field_cmc_triptych_image1';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['table'] = 'field_data_field_cmc_triptych_image1';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['field'] = 'field_cmc_triptych_image1';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['element_class'] = 'triptych-image';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cmc_triptych_image1']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_6']['id'] = 'nothing_6';
  $handler->display->display_options['fields']['nothing_6']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_6']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_6']['label'] = '';
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
  $handler->display->display_options['fields']['nothing_6']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_6']['element_class'] = 'mask';
  $handler->display->display_options['fields']['nothing_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_6']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_6']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_6']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_6']['hide_alter_empty'] = 0;
  /* Field: Content: Text 1 */
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['id'] = 'field_cmc_triptych_text1';
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['table'] = 'field_data_field_cmc_triptych_text1';
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['field'] = 'field_cmc_triptych_text1';
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['element_class'] = 'triptych-content';
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text1']['field_api_classes'] = 0;
  /* Field: Content: Rollover 1 */
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['id'] = 'field_cmc_triptych_rollover1';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['table'] = 'field_data_field_cmc_triptych_rollover1';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['field'] = 'field_cmc_triptych_rollover1';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['element_class'] = 'triptych-rollover';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover1']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div id="triptych2" class="triptych">';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_2']['hide_alter_empty'] = 0;
  /* Field: Content: Image 2 */
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['id'] = 'field_cmc_triptych_image2';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['table'] = 'field_data_field_cmc_triptych_image2';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['field'] = 'field_cmc_triptych_image2';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['element_class'] = 'triptych-image';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cmc_triptych_image2']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_7']['id'] = 'nothing_7';
  $handler->display->display_options['fields']['nothing_7']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_7']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_7']['label'] = '';
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
  $handler->display->display_options['fields']['nothing_7']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_7']['element_class'] = 'mask';
  $handler->display->display_options['fields']['nothing_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_7']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_7']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_7']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_7']['hide_alter_empty'] = 0;
  /* Field: Content: Text 2 */
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['id'] = 'field_cmc_triptych_text2';
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['table'] = 'field_data_field_cmc_triptych_text2';
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['field'] = 'field_cmc_triptych_text2';
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['element_class'] = 'triptych-content';
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text2']['field_api_classes'] = 0;
  /* Field: Content: Rollover 2 */
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['id'] = 'field_cmc_triptych_rollover2';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['table'] = 'field_data_field_cmc_triptych_rollover2';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['field'] = 'field_cmc_triptych_rollover2';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['element_class'] = 'triptych-rollover';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover2']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_3']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<div id="triptych3" class="triptych">';
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
  $handler->display->display_options['fields']['nothing_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_4']['hide_alter_empty'] = 0;
  /* Field: Content: Image 3 */
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['id'] = 'field_cmc_triptych_image3';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['table'] = 'field_data_field_cmc_triptych_image3';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['field'] = 'field_cmc_triptych_image3';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['element_class'] = 'triptych-image';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cmc_triptych_image3']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_8']['id'] = 'nothing_8';
  $handler->display->display_options['fields']['nothing_8']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_8']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_8']['label'] = '';
  $handler->display->display_options['fields']['nothing_8']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_8']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_8']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_8']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_8']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_8']['element_class'] = 'mask';
  $handler->display->display_options['fields']['nothing_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_8']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing_8']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_8']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_8']['hide_alter_empty'] = 0;
  /* Field: Content: Text 3 */
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['id'] = 'field_cmc_triptych_text3_1';
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['table'] = 'field_data_field_cmc_triptych_text3';
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['field'] = 'field_cmc_triptych_text3';
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['element_class'] = 'triptych-content';
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_text3_1']['field_api_classes'] = 0;
  /* Field: Content: Rollover 3 */
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['id'] = 'field_cmc_triptych_rollover3';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['table'] = 'field_data_field_cmc_triptych_rollover3';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['field'] = 'field_cmc_triptych_rollover3';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['label'] = '';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['element_class'] = 'triptych-rollover';
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cmc_triptych_rollover3']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_5']['id'] = 'nothing_5';
  $handler->display->display_options['fields']['nothing_5']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_5']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_5']['label'] = '';
  $handler->display->display_options['fields']['nothing_5']['alter']['text'] = '</div>';
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
  $handler->display->display_options['fields']['nothing_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_5']['hide_alter_empty'] = 0;
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
  $translatables['cmc_triptych'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Header'),
    t('<div id="triptych1" class="triptych">'),
    t('</div>'),
    t('<div id="triptych2" class="triptych">'),
    t('<div id="triptych3" class="triptych">'),
  );
  $export['cmc_triptych'] = $view;

  return $export;
}
