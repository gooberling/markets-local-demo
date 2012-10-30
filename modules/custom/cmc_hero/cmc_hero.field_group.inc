<?php
/**
 * @file
 * cmc_hero.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_hero_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero1|node|cmc_hero|form';
  $field_group->group_name = 'group_hero1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_hero';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_hero_image1',
      1 => 'field_hero_content1',
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
  $export['group_hero1|node|cmc_hero|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero2|node|cmc_hero|form';
  $field_group->group_name = 'group_hero2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_hero';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 2',
    'weight' => '2',
    'children' => array(
      0 => 'field_hero_image2',
      1 => 'field_hero_content2',
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
  $export['group_hero2|node|cmc_hero|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero3|node|cmc_hero|form';
  $field_group->group_name = 'group_hero3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_hero';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 3',
    'weight' => '3',
    'children' => array(
      0 => 'field_hero_image3',
      1 => 'field_hero_content3',
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
  $export['group_hero3|node|cmc_hero|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero4|node|cmc_hero|form';
  $field_group->group_name = 'group_hero4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_hero';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 4',
    'weight' => '7',
    'children' => array(
      0 => 'field_hero_image4',
      1 => 'field_hero_content4',
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
  $export['group_hero4|node|cmc_hero|form'] = $field_group;

  return $export;
}
