<?php
/**
 * This imports the pricing feed into a db table that we can use
 */
function cmc_pricing_product_import() {

  // check for table if not there create it
  if (!db_table_exists('cmc_pricing')) {
    drupal_set_message('cmc_pricing table does not exist');

    module_load_include('install', 'cmc_pricing', 'cmc_pricing');
    cmc_pricing_install_create_table();
  }


  // grab the feed now, assume it will be json encoded
  $feed = variable_get('cmc_pricing_products_feed_url', 'http://londhdev3l03:20025/pricefeed/rest/v2/products/en.json');

  // for testing as actuall feed seems flakey and not sure if this is the current one
  //$feed = 'http://localhost.d7-uk-cmcmarkets-dev.cmc.local/profiles/cmc_installer/modules/custom/cmc_pricing/data/products.json';
  //echo $feed;
  $response = drupal_http_request($feed);

  if ($response->code != 200) {
    echo "FAIL!!!! \n\n";
    //print_r($response);
    return;
  }

  // response is in json
  $data = json_decode($response->data);
  
  foreach ($data->products->product as $i => $product) {

    $result = db_select('cmc_pricing', 'cp')
      ->fields('cp', array('instrument_code', 'symbol'))
      ->condition('symbol', $product->symbol, '=')
      ->execute()
      ->fetchAssoc();


    if (empty($result)) {
      $result = db_insert('cmc_pricing')
        ->fields(array(
          'symbol' => $product->symbol,
          //'instrument_code' => $node->field_instrument_code['und'][0]['value'],
          'name' => $product->name,
          'type' => $product->type,
          'subtype' => $product->subtype,
          'country' => $product->country,
          'region' => $product->region,
          'created' => REQUEST_TIME,
        	'updated' => REQUEST_TIME,
        ))
        ->execute();
    }
    else {
      $result = db_update('cmc_pricing')
        ->fields(array(
          'symbol' => $product->symbol,
          //'instrument_code' => $node->field_instrument_code['und'][0]['value'],
          'name' => $product->name,
          'type' => $product->type,
          'subtype' => $product->subtype,
          'country' => $product->country,
          'region' => $product->region,
          'updated' => REQUEST_TIME,
        ))
        ->condition('symbol', $product->symbol, '=')
        ->execute();
    }
  }

  return __METHOD__;
}


/**
 * We need to match the products to the price symbols so we can get the feeds
 * Better way of doing this? Such as making it part of the Migrate procedure
 * A product node should have symbol as a field
 */
function cmc_pricing_product_match_codes() {

  $result = db_select('cmc_pricing', 'cp')
    ->fields('cp', array('instrument_code', 'symbol', 'country', 'type', 'name'))
    ->isNull('instrument_code')
    //->range(0,10)
    ->execute();

  $codes = array();
  $i=0;
  while ($record = $result->fetchAssoc()) {

    $record = (object) $record;

    $node = cmc_pricing_get_product_matching_node($record);
    
    if (isset($node->field_instrument_code['und'][0]['value'])) {
      $codes[] = array(
      	'instrument_code' => $node->field_instrument_code['und'][0]['value'],
        'symbol' => $record->symbol,
      );
    }
    unset($node);
    //print_r($node);
    //break;

  }
 

  foreach ($codes as $i => $res) {

    $result = db_update('cmc_pricing')
        ->fields(array(
          'instrument_code' => $res['instrument_code'],
        ))
        ->condition('symbol', $res['symbol'], '=')
        ->execute();
     //print_r($res);
  }
  return __METHOD__;
}

/**
 * return the node that matches this product
 * @param unknown_type $product
 */
function cmc_pricing_get_product_matching_node($product) {

  $country_vocab = array_shift(taxonomy_vocabulary_load_multiple(array(), array('name' => 'Country')));
  $country = array_shift(taxonomy_get_term_by_name($product->country, array('vid'=>$country_vocab->vid)));

  $instrument_type_vocab = array_shift(taxonomy_vocabulary_load_multiple(array(), array('name' => 'Instrument Type')));
  $instrument_type = array_shift(taxonomy_get_term_by_name($product->type, array('vid'=>$instrument_type_vocab->vid)));
  
  $view = views_get_view('cmc_pricing');
  $args = array($product->name, $country->tid);
  $view->preview('product_by_name', $args);

  if (isset($view->result[0])) {
    $result = $view->result[0];
    unset($view);
    // should save it to the node
    return $result->_field_data['nid']['entity'];
  }
  else {
    return new StdClass();
  }
}


