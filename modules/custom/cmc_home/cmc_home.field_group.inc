<?php
/**
 * @file
 * cmc_home.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmc_home_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner1|node|cmc_home|form';
  $field_group->group_name = 'group_banner1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner 1',
    'weight' => '7',
    'children' => array(
      0 => 'field_home_banner_content1',
      1 => 'field_home_banner_image1',
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
  $export['group_banner1|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner2|node|cmc_home|form';
  $field_group->group_name = 'group_banner2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner 2',
    'weight' => '8',
    'children' => array(
      0 => 'field_home_banner_content2',
      1 => 'field_home_banner_image2',
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
  $export['group_banner2|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner3|node|cmc_home|form';
  $field_group->group_name = 'group_banner3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner 3',
    'weight' => '9',
    'children' => array(
      0 => 'field_home_banner_content3',
      1 => 'field_home_banner_image3',
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
  $export['group_banner3|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner4|node|cmc_home|form';
  $field_group->group_name = 'group_banner4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner 4',
    'weight' => '10',
    'children' => array(
      0 => 'field_home_banner_content4',
      1 => 'field_home_banner_image4',
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
  $export['group_banner4|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero1|node|cmc_home|form';
  $field_group->group_name = 'group_hero1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 1',
    'weight' => '2',
    'children' => array(
      0 => 'field_home_hero_image1',
      1 => 'field_home_hero_content1',
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
  $export['group_hero1|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero2|node|cmc_home|form';
  $field_group->group_name = 'group_hero2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 2',
    'weight' => '3',
    'children' => array(
      0 => 'field_home_hero_image2',
      1 => 'field_home_hero_content2',
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
  $export['group_hero2|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero3|node|cmc_home|form';
  $field_group->group_name = 'group_hero3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 3',
    'weight' => '4',
    'children' => array(
      0 => 'field_home_hero_image3',
      1 => 'field_home_hero_content3',
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
  $export['group_hero3|node|cmc_home|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero4|node|cmc_home|form';
  $field_group->group_name = 'group_hero4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cmc_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero 4',
    'weight' => '5',
    'children' => array(
      0 => 'field_home_hero_image4',
      1 => 'field_home_hero_content4',
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
  $export['group_hero4|node|cmc_home|form'] = $field_group;

  return $export;
}
