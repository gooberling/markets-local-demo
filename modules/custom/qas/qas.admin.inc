<?php

/**
 * Settings form from QAS
 */
function qas_settings() {
  $form = array();

  $form['qas_username'] = array(
    '#type' => 'textfield',
    '#title' => t('QAS username'),
    '#description' => 'Username provide by  QAS, this can be found in your account area on qas website',
    '#required' => FALSE,
    '#size' => 30,
    '#maxlength' => 32,
    '#default_value' => vaiable_get('qas_username'),
  );

  $form['qas_password'] = array(
    '#type' => 'textfield',
    '#title' => t('QAS Password'),
    '#description' => 'Password provide by  QAS, this can be found in your account area on qas website',
    '#required' => FALSE,
    '#size' => 30,
    '#maxlength' => 32,
    '#default_value' => vaiable_get('qas_password'),
  );

  $form['description_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Description'),
    '#default_value' => !empty($search_page->description)  ? TRUE : FALSE
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Provide description'),
    '#title_display' => 'invisible',
    '#size' => 64,
    '#default_value' => !empty($search_page->description) ? $search_page->description : '',
    '#dependency' => array(
      'edit-description-enable' => array(1),
    ),
  );

  $form['info'] = array(
    '#title' => t('Search Page Information'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#prefix' => '<div id="dynamic-search-page">',
    '#suffix' => '</div>',
  );
}
