<?php

// styling and html override output for the breadcrumb links
function cmc_core_breadcrumb($variables) {

	if (count($variables['breadcrumb']) > 0) {

	if (arg(0) == 'node' && is_numeric(arg(1))) {
		$current_nid = arg(1);
		$current_node = node_load($current_nid);
	}

	// If viewing a instrument add 'markets' to the breadcrumb
	if (isset($current_node) && $current_node->type == "product") {
		$variables['breadcrumb'][] = "<a href='/markets'>Markets</a>";
	}

	 // Add the title of the current page to the breadcrumb
	if (end($variables['breadcrumb']) != drupal_get_title()) {
		$variables['breadcrumb'][] = drupal_get_title();
	}

    $lastitem = sizeof($variables['breadcrumb']);
    $title = drupal_get_title();
    $crumbs = '<ul class="breadcrumbs">';
    $a=1;
    foreach($variables['breadcrumb'] as $value) {
      if ($a!=$lastitem){
        $crumbs .= '<li class="breadcrumb-'.$a.'">'. $value . ' ' . '</li>';
        $a++;
      }
      else {
        $crumbs .= '<li class="breadcrumb-last">'.$value.'</li>';
      }
    }
    $crumbs .= '</ul>';

	// Custom handling for search results page
	if(strstr($_GET['q'], 'search/node')) {
		$crumbs = str_replace('<li class="breadcrumb-2"><a href="/search">Search</a> </li><li class="breadcrumb-3"><a href="/search/node">Content</a> </li>', '', $crumbs);
	}

	return $crumbs;
  }
  else {
    return t("Home");
  }
}


function cmc_core_preprocess_page(&$vars) {
  $page = $vars['page'];
  if ($page['sidebar_first'] && $page['sidebar_second']) {
    $vars['main_content_layout'] = 'grid-6 push-2';
  }
  else if ($page['sidebar_first'] && empty($page['sidebar_second'])) {
    $vars['main_content_layout'] = 'grid-8 push-2 last-col';
  }
  else if (empty($page['sidebar_first']) && ($page['sidebar_second'])) {
    $vars['main_content_layout'] = 'grid-8 last-col';
  }
  else {
    $vars['main_content_layout'] = 'grid-10 last-col';
  }
}

function cmc_core_preprocess_html(&$vars) {
	// Add 'page-education' class to the Education landing page
	if (in_array('education', $vars['classes_array'])):
		$vars['classes_array'][] = 'page-education';
	endif;

	// Add 'page-education' class to the Education landing page
	if ($_GET['q'] == 'campaign'):
		$vars['classes_array'][] = 'campaign-page';
	endif;

}

function cmc_core_block_view_alter(&$data, $block) {
	if (isset($block->context) && isset($block->region)) {
		if ($block->context == 'education_landing' && $block->region == 'content') {
			$record_count = substr_count($data['content']['#markup'], 'li class="views-row');
			if (isset($data['subject'])) {
				$data['subject'] .= ' <span class="record_count">(' . $record_count . ')</span>';
			}
		}
	}
}


function cmc_core_set_header_image($image_field) {
  $result = FALSE;

  if (count($image_field)) {
    $url = (file_create_url($image_field['und'][0]['uri']));
    drupal_add_css('.markets-section.node-type-product .gradient  { background-image:url(' . $url . ') !important; }',
      array(
        'type' => 'inline',
        'every_page' => FALSE
      )
    );
    $result = TRUE;
  }

  return $result;
}

function cmc_core_preprocess_node(&$vars) {
  if ($vars['node']->type == 'product') {
    $node_image_field = $vars['node']->field_product_image;
    $type_image_field = $vars['node']->field_instrument_type['und'][0]['taxonomy_term']->field_product_image;
    $sector_image_field = $vars['node']->field_sector['und'][0]['taxonomy_term']->field_product_image;
    $country_image_field = $vars['node']->field_country['und'][0]['taxonomy_term']->field_product_image;

    cmc_core_set_header_image($node_image_field) ||
      cmc_core_set_header_image($type_image_field) ||
      cmc_core_set_header_image($sector_image_field) ||
      cmc_core_set_header_image($country_image_field);

    $vars['openinghours'] = cmc_core_trading_hours($vars['node']);

    $vars['commission'] = cmc_core_commission($vars['node']);

  }


  // Is a 'Display Name' for an author is set alter the node meta data to use this instead of username
  if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {

	$user_data = user_load($vars['uid']);

	if (isset($user_data->field_display_name['und'][0]['value'])) {
	$vars['submitted'] = t('Submitted by !username on !datetime',
      array(
        '!username' => $user_data->field_display_name['und'][0]['value'],
        '!datetime' => '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . $vars['date'] . '</time>',
      )
    );

	}
  }


}

function cmc_core_trading_hours($node) {
  if (count($node->field_trading_hours)) {
    $timezone = 'Europe/London';

    $data = json_decode($node->field_trading_hours['und'][0]['value']);

    $times = (array)($data->$timezone);
    $result = array();

    foreach($times as $time) {

      $detail = array();
      foreach ($time as $t) {
        $detail[] = $t->starttime . '-' . $t->endtime;
      }

      $result[]  = array(
        'day' => date('D', strtotime($time[0]->startdate)),
        'times' => implode(', ', $detail)
      );
    }
  } else {
    $result = array();
  }

  return $result;
  //   $vars['openinghours'] = theme('table', array('header' => $headers, 'rows' =>  array($details)));
}

function cmc_core_commission($node) {
  $commission = '';
  if ($node->field_commission_charged['und'][0]['value'] == 1) {
    $type = $node->field_commission_type['und'][0]['value'];
    $currency = $node->field_currency['und'][0]['value'];
    if ($type == 'BASISPOINTS') {
      $bips = $node->field_bips['und'][0]['value'];
      $bips_minimum = $node->field_bips_minimum_amount['und'][0]['value'];
      $bips_threshold = $node->field_bips_threshold_amount['und'][0]['value'];
      $bips_percent = $bips / 100;

      if ($bips_threshold > 0) {
        $commission = t("@min @curr up to the first @threshold @curr of the transaction, @percent% levied on the remaining portion", array('@min' => $bips_minimum, '@curr' => $currency, '@threshold' => $bips_threshold, '@percent' => $bips_percent));
      } else {
        $commission = t("@percent% (@min @curr min)", array('@min' => $bips_minimum, '@curr' => $currency, '@percent' => $bips_percent));
      }
    } else if ($type == 'AMOUNTPERUNIT') {
      $amount_minimum = $node->field_amount_per_unit_minimum['und']['0']['value'];
      $amount = $node->field_amount_per_unit['und'][0]['value'];
      $commission = t('@amount @curr per CFD (@min @curr min)', array('@amount' => $amount, '@min' => $amount_minimum, '@curr' => $currency));
    }
  }
  return $commission;
}

function cmc_core_preprocess_field(&$vars, $hook) {
  switch($vars['element']['#field_name']) {
    case 'field_max_financing_cfd':
    case 'field_max_financing_cfd_sg':
      // set suggestions
      $vars['theme_hook_suggestions'] = array(
        'field__field_max_financing_cfd',
      );
      break;
    case 'field_max_order_size_cfd_aud':
    case 'field_max_order_size_cfd_eur':
    case 'field_max_order_size_cfd_gbp':
    case 'field_max_order_size_cfd_sgd':
    case 'field_max_order_size_cfd_unit':
      $vars['theme_hook_suggestions'] = array(
        'field__field_max_order_size_cfd'
      );
      break;
    case 'field_max_order_size_sb_eur':
    case 'field_max_order_size_sb_gbp':
      $vars['theme_hook_suggestions'] = array(
        'field__field_max_order_size_sb',
      );
      break;
  }
}

function cmc_core_filter_block_has_facet_filters($block) {
  $keys = array_keys($block);
  $views_count = 0;

  foreach ($keys as $key) {
  	if (strpos($key, 'facetapi') > -1) {
      return true;
    }
	if (strpos($key, 'views') > -1) {
      $views_count++;
    }
  }

  // If this region contains four Views we assume this is the four Facet Views blocks
  if ($views_count == 4) {
      return true;
  }

  return false;
}


function cmc_core_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
	if (isset($form['search_api_views_fulltext'])) {
		$form['search_api_views_fulltext']['#attributes']['class'] = array('cmc_auto_submit');
	}
}


/**
 * See template_preprocess_menu_block_wrapper(&$variables)
 * menu_block.module
 *
 * Add the number of items in menu top level as a class
 */
function cmc_core_preprocess_menu_block_wrapper(&$vars) {
//  print_r($variables);
  $num = 0;
  foreach ($vars['content'] as $k => $v) {
    if (is_numeric($k)) {
      $num++;
    }
  }
  if ($num) {
    $vars['classes_array'][] = 'nav-items-' . $num;
  }
}


function cmc_core_preprocess_views_exposed_form(&$vars) {
  if ($vars['form']['#action'] == '/markets/browse') {
    $vars['theme_hook_suggestions'][] = 'views_exposed_form__with_count';
  }
}
