<?php
/**
 * @file
 * cmc_wysiwyg.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_wysiwyg_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|file|default|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'default';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '4',
    'children' => array(
      0 => 'field_domain',
      1 => 'field_instrument_type',
      2 => 'field_trade_type',
      3 => 'field_experience',
      4 => 'field_platform',
      5 => 'field_device',
      6 => 'field_theme',
      7 => 'field_keywords',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Taxonomy tags to aid finding a file',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_taxonomy|file|default|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|file|image|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '4',
    'children' => array(
      0 => 'field_keywords',
      1 => 'field_trade_type',
      2 => 'field_experience',
      3 => 'field_instrument_type',
      4 => 'field_platform',
      5 => 'field_device',
      6 => 'field_theme',
      7 => 'field_event_type',
      8 => 'field_domain',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Taxonomy tags to aid finding a file',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_taxonomy|file|image|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|file|video|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '4',
    'children' => array(
      0 => 'field_domain',
      1 => 'field_instrument_type',
      2 => 'field_trade_type',
      3 => 'field_experience',
      4 => 'field_platform',
      5 => 'field_device',
      6 => 'field_theme',
      7 => 'field_keywords',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Taxonomy tags to aid finding a file',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_taxonomy|file|video|form'] = $field_group;

  return $export;
}
