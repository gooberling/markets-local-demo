<?php
/**
 * @file
 * cmc_products_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_products_config_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_price_info|node|product|form';
  $field_group->group_name = 'group_price_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Price Info',
    'weight' => '13',
    'children' => array(
      0 => 'field_max_order_size_cfd_aud',
      1 => 'field_max_order_size_cfd_eur',
      2 => 'field_max_order_size_cfd_gbp',
      3 => 'field_max_order_size_cfd_sgd',
      4 => 'field_max_order_size_cfd_unit',
      5 => 'field_max_order_size_sb_eur',
      6 => 'field_max_order_size_sb_gbp',
      7 => 'field_max_financing_cfd',
      8 => 'field_max_financing_cfd_sg',
      9 => 'field_max_financing_sb',
      10 => 'field_is_shorting_cfd',
      11 => 'field_is_shorting_sb',
      12 => 'field_is_tradable_sb',
      13 => 'field_is_tradable_cfd',
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
  $export['group_price_info|node|product|form'] = $field_group;

  return $export;
}
