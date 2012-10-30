<?php
/**
 * @file
 * cmc_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cmc_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: ckeditor
  $formats['ckeditor'] = array(
    'format' => 'ckeditor',
    'name' => 'ckeditor',
    'cache' => '1',
    'status' => '1',
    'weight' => '-9',
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'media_filter' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: cmc editor
  $formats['cmc_editor'] = array(
    'format' => 'cmc_editor',
    'name' => 'cmc editor',
    'cache' => '1',
    'status' => '1',
    'weight' => '-10',
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'media_filter' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-47',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <table> <tr><th> <td> <div> <p> <h2> <h1> <h3> <h4> <h5> <span> <img> <footer> <section>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
