<?php
/**
 * @file
 * feature_cmc_master.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_cmc_master_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmc_base_context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['cmc_base_context'] = $context;

  return $export;
}
