<?php
/**
 * @file
 * cmc_wysiwyg.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function cmc_wysiwyg_file_default_displays() {
  $export = array();

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__default__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['default__default__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_link__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_link__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_link__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_link__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_link__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__media_link__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_link__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_link__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_link__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['default__media_link__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['default__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['default__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'default__media_original__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['default__media_original__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__default__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_large__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_large__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
  );
  $export['image__media_medium__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_border__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_border__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_border__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_border__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_border__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_border__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_border__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_border__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_border__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
  );
  $export['image__media_medium_border__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
  );
  $export['image__media_medium_right__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right_border__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right_border__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right_border__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right_border__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right_border__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right_border__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right_border__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_medium_right_border__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_medium_right_border__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
  );
  $export['image__media_medium_right_border__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'small',
  );
  $export['image__media_small__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_border__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_border__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_border__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_border__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_border__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_border__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_border__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_border__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_border__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'small',
  );
  $export['image__media_small_border__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_left__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_left__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_left__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_left__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_left__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_left__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_left__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_left__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_left__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'small',
  );
  $export['image__media_small_left__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'small',
  );
  $export['image__media_small_right__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right_border__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right_border__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right_border__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right_border__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right_border__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right_border__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right_border__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_small_right_border__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'image__media_small_right_border__file_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'small',
  );
  $export['image__media_small_right_border__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__default__file_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__media_youtube_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__default__media_youtube_image'] = $file_display;

  $file_display = new stdClass;
  $file_display->api_version = 1;
  $file_display->name = 'video__default__media_youtube_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'version' => '3',
    'theme' => 'dark',
    'width' => '560',
    'height' => '340',
    'fullscreen' => 1,
    'autoplay' => 0,
    'related' => 1,
    'hd' => 0,
    'showsearch' => 1,
    'modestbranding' => 0,
    'showinfo' => 1,
    'chromeless' => 0,
  );
  $export['video__default__media_youtube_video'] = $file_display;

  return $export;
}
