<?php
/**
 * @file
 * cmc_blog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_blog_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|cmc_blog|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '5',
    'children' => array(
      0 => 'field_instrument_type',
      1 => 'field_theme',
      2 => 'field_keywords',
      3 => 'field_trade_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Tags to relate content to each other.
Some vocabularies won\'t be relevant but the better the content is tagged the better the relevant content results should be',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_taxonomy|node|cmc_blog|form'] = $field_group;

  return $export;
}
