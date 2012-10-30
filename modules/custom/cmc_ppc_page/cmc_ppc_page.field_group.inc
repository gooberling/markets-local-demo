<?php
/**
 * @file
 * cmc_ppc_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_ppc_page_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero|node|cmc_ppc_page|form';
  $field_group->group_name = 'group_hero';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_ppc_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
      1 => 'field_hero_content',
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
  $export['group_hero|node|cmc_ppc_page|form'] = $field_group;

  return $export;
}
