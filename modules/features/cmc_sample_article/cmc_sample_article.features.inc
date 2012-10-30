<?php
/**
 * @file
 * cmc_sample_article.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cmc_sample_article_node_info() {
  $items = array(
    'cmc_sample_article' => array(
      'name' => t('cmc_sample_article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
