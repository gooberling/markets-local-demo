<?php
/**
 * @file
 * cmc_triptych.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_triptych_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_triptych1|node|cmc_triptych|form';
  $field_group->group_name = 'group_triptych1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_triptych';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Triptych 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_cmc_triptych_image1',
      1 => 'field_cmc_triptych_rollover1',
      2 => 'field_cmc_triptych_text1',
      3 => 'field_cmc_triptych_video1',
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
  $export['group_triptych1|node|cmc_triptych|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_triptych2|node|cmc_triptych|form';
  $field_group->group_name = 'group_triptych2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_triptych';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Triptych2',
    'weight' => '2',
    'children' => array(
      0 => 'field_cmc_triptych_image2',
      1 => 'field_cmc_triptych_rollover2',
      2 => 'field_cmc_triptych_text2',
      3 => 'field_cmc_triptych_video2',
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
  $export['group_triptych2|node|cmc_triptych|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_triptych3|node|cmc_triptych|form';
  $field_group->group_name = 'group_triptych3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_triptych';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Triptych3',
    'weight' => '3',
    'children' => array(
      0 => 'field_cmc_triptych_image3',
      1 => 'field_cmc_triptych_rollover3',
      2 => 'field_cmc_triptych_text3',
      3 => 'field_cmc_triptych_video3',
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
  $export['group_triptych3|node|cmc_triptych|form'] = $field_group;

  return $export;
}
