<?php
/**
 * @file
 * cmc_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_event_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|cmc_event|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '7',
    'children' => array(
      0 => 'field_instrument_type',
      1 => 'field_trade_type',
      2 => 'field_experience',
      3 => 'field_event_type',
      4 => 'field_theme',
      5 => 'field_keywords',
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
  $export['group_taxonomy|node|cmc_event|form'] = $field_group;

  return $export;
}
