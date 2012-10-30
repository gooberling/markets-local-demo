<?php
/**
 * @file
 * cmc_platform_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_platform_page_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_android|node|cmc_platform_page|form';
  $field_group->group_name = 'group_android';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_platform_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Android',
    'weight' => '3',
    'children' => array(
      0 => 'field_platform_android',
      1 => 'field_platform_android_videos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_android|node|cmc_platform_page|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_desktop|node|cmc_platform_page|form';
  $field_group->group_name = 'group_desktop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_platform_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Desktop',
    'weight' => '4',
    'children' => array(
      0 => 'field_platform_desktop',
      1 => 'field_platform_desktop_videos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_desktop|node|cmc_platform_page|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ipad|node|cmc_platform_page|form';
  $field_group->group_name = 'group_ipad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_platform_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'iPad',
    'weight' => '5',
    'children' => array(
      0 => 'field_platform_ipad',
      1 => 'field_platform_ipad_videos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ipad|node|cmc_platform_page|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_iphone|node|cmc_platform_page|form';
  $field_group->group_name = 'group_iphone';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_platform_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'iPhone',
    'weight' => '2',
    'children' => array(
      0 => 'field_platform_iphone',
      1 => 'field_platform_iphone_videos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_iphone|node|cmc_platform_page|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_navigation|node|cmc_platform_page|form';
  $field_group->group_name = 'group_navigation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_platform_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Navigation',
    'weight' => '6',
    'children' => array(
      0 => 'field_platform_nav_image',
      1 => 'field_platform_nav_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_navigation|node|cmc_platform_page|form'] = $field_group;

  return $export;
}
