<?php
/**
 * @file
 * cmc_pricing.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_pricing_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab1|node|cmc_pricing_panel|form';
  $field_group->group_name = 'group_tab1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_pricing_panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab1',
    'weight' => '3',
    'children' => array(
      0 => 'field_pricing_products1',
      1 => 'field_pricing_title1',
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
  $export['group_tab1|node|cmc_pricing_panel|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab2|node|cmc_pricing_panel|form';
  $field_group->group_name = 'group_tab2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_pricing_panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab2',
    'weight' => '4',
    'children' => array(
      0 => 'field_pricing_title2',
      1 => 'field_pricing_products2',
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
  $export['group_tab2|node|cmc_pricing_panel|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab3|node|cmc_pricing_panel|form';
  $field_group->group_name = 'group_tab3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_pricing_panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab3',
    'weight' => '5',
    'children' => array(
      0 => 'field_pricing_title3',
      1 => 'field_pricing_products3',
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
  $export['group_tab3|node|cmc_pricing_panel|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab4|node|cmc_pricing_panel|form';
  $field_group->group_name = 'group_tab4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_pricing_panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab 4',
    'weight' => '6',
    'children' => array(
      0 => 'field_pricing_title4',
      1 => 'field_pricing_products4',
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
  $export['group_tab4|node|cmc_pricing_panel|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab5|node|cmc_pricing_panel|form';
  $field_group->group_name = 'group_tab5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_pricing_panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab 5',
    'weight' => '7',
    'children' => array(
      0 => 'field_pricing_title5',
      1 => 'field_pricing_products5',
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
  $export['group_tab5|node|cmc_pricing_panel|form'] = $field_group;

  return $export;
}
