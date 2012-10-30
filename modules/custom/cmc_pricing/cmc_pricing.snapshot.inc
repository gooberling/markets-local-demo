<?php

/**
 * We receive the last 30 updates for a given product in the price feed
 *
 * This isn't really what we want as we want as the lsat 30 update time period can
 * vary between different products
 * We want to be able to cycle through and update the price if there has been a
 * every second or so. We want values to be precalculated before we feed back
 * to the browser
 *
 * So the javascript is just set to cycle through a json array updating a DOM
 * element each second, don't really want to muck up with calculations.
 * Also this ajax call can be cached periodically, say 20 seconds or so?
 *
 * This measn the price isn;t up to date and out by around 20 seconds
 * But this is just to fake it
 *
 * @param unknown_type $price_snapshot
 */
function cmc_pricing_snapshot($args) {

  $args = explode(',', $args);

  $prices = array();
  $now = time();
  //echo $now;
  //echo "\n\n";
  //$now = strtotime('2012-05-25T20:00:00.489Z');
  //echo "\n\n";


  $args = explode('|', $args[0]);

  foreach ($args as $i => $symbol) {
    //echo $symbol, 'fafas';
    $price = cmc_pricing_get_current_price($symbol);

    if (!empty($price->prices->price)) {
      $movements = cmc_pricing_snapshot_movements($price->prices->price, $now);
      $prices[$symbol] = $movements;
    }
    else {

      $data = array(
        'title' => $price->product,
        'nid' => '',
        'instrument_code' => '',
      );
      cmc_pricing_log_product_pricing_warning($data);
      //watchdog('Could not get price for: ' . $price->product);
    }
  }
//print_r($prices);

  drupal_add_http_header('Content-type', 'application/json');

  echo json_encode($prices);
  exit;
  //print_r($prices);
  //return __METHOD__;
}



/**
 * We want to format it so we have 20 seconds worth of prices..
 * This probably needs tweaking, but seems to be one off, think it will be good
 * enough for teh time being. Not time critical and is suposed to be indicative
 * @param unknown_type $price_snapshot
 */
function cmc_pricing_snapshot_movements($prices, $current_time) {

  $default_time_zone = date_default_timezone_get();
  //echo $default_time_zone;
  date_default_timezone_set('UTC');
  $js_cache_time = variable_get('cmc_pricing_js_cache_time', '20');
  $time = $current_time - $js_cache_time;

  //echo $time, '::', date('Y-m-d H:i:s', $current_time), "\n\n";
  //echo date('Y-m-d H:i:s', $time), '::', date('Y-m-d H:i:s', $current_time);

  // figure out where we should start
  $start_index = 0;

  for ($i=0; $i<30; $i++) {
    if (date('U', strtotime($prices[$i]->timestamp)) > $time) {
      $start_index = $i;
      break;
    }
  }

  //print_r($prices);
  //echo '@', $start_index, '@';
  if ($start_index) {
    $prices = array_slice($prices, $start_index-1);
  }

  $movements = array();
  foreach ($prices as $price) {
    $d = date('Y-m-d H:i:s', strtotime($price->timestamp));
    //$d = date('U', strtotime($price->timestamp));
    $movements[$d] = $price;
  }

  $prices = array_values($movements);
  $current_price = (object) array_shift($prices);
  $next_price_change_time = date('U', strtotime($prices[0]->timestamp));
  $snapshot = array();

  for ($time; $time < $current_time; $time++) {

    if ($next_price_change_time < $time) {
      $bid = isset($current_price->bid) ? $current_price->bid : 0;
      $ask = isset($current_price->ask) ? $current_price->ask : 0;

      $current_price = array_shift($prices);
      if (empty($current_price)) {
        $current_price = new StdClass();
      }

      if (isset($prices[0]->timestamp)) {
        $next_price_change_time = date('U', strtotime($prices[0]->timestamp));
      }
    }

    // store in snapshot
    // clone $current_price otherwise it will reference it
    // and values get fucked up
    $snapshot[] = array(
        'time' => date('Y-m-d H:i:s', $time),
        'price' => clone $current_price,
    );

    //print_r($current_price);

  }

  date_default_timezone_set($default_time_zone);

  return $snapshot;
}
