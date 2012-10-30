<?php

function _twitter_lab_get_connection() {  
  module_load_include('php','twitter_lab', 'twitteroauth/twitteroauth/Oauth');
  module_load_include('php','twitter_lab', 'twitteroauth/twitteroauth/twitteroauth');
  
  $consumer_key = variable_get('twitter_lab_consumer_key');
  $consumer_secret = variable_get('twitter_lab_consumer_secret');
  $oauth_token = variable_get('twitter_lab_auth_token');
  $oauth_secret = variable_get('twitter_lab_auth_secret');
  
  return new TwitterOAuth($consumer_key, $consumer_secret, $oauth_token, $oauth_secret);
}

/**
 *
 * @param type Retrieve set of followers for a given twitter account.  Numeric id
 * @return type 
 * 
 * @Todo Need to investigate if we need to return  full user information if a user id is provided
 * @see
 */
function _twitter_lab_get_follower($id = NULL) {

  $followers = cache_get(TWITTER_LAB_FOLLOWER_CACHES);
  if (!$followers) {
    do {
      if (!empty($followers['next_cursor']) && $followers['next_cursor'] > 0 ) {
        $params['cursor'] = $followers['next_cursor'];
      }
      $connection = _twitter_lab_get_connection();      
      $data = $connection->get("followers/ids", $params);

    } while($followers->next_cursor != 0);
    cache_set(TWITTER_LAB_FOLLOWER_CACHES, $data->ids, 'cache');
    $followers = cache_get(TWITTER_LAB_FOLLOWER_CACHES);  
  }
  
  if (!is_null($id))  {
    return TRUE;
    return in_array($id, $followers->data) ? TRUE : FALSE;
  } 
  return $followers->data;
}


/**
 * Class that encapsulates twitter questions 
 */
class twitter_question extends twitter_servicetags {

  var $question_text;
  var $twitter_user;
  var $is_follower;
  var $hashtags;
  
  function __construct($item) {
    $this->question_text = $item->text;
    $this->twitter_user = $item->user;
    $this->is_follower = _twitter_lab_get_follower($this->twitter_user->id);
    $this->service_tags_get();

    // Check if the user  tweet has any hashtags. Any request for a price etc will 
    // be associated with a hashtag.
   
    $this->hashtags = !empty($item->entities->hashtags)? $item->entities->hashtags : FALSE;
  }
  
  /** 
   * Provide response back based on the service lookup and expected return items
   */
  function response() {
    if (empty($this->hashtags)) return FALSE;
    
    foreach($this->hashtags as $hashtag) {
      
      if (key_exists($hashtag->text, $this->service_tags)) {
     //   print_r($hashtag);
     //   print_r($this->service_tags[$hashtag->text]['call_back']);
        $callback = !empty($this->service_tags[$hashtag->text]['call_back'])? $this->service_tags[$hashtag->text]['call_back'] : $this->callback();
//        print($callback);
        if (function_exists($callback)) {
          $callback($this);
        } else {
          $this->callback($this);
        }
      }
    }
    
    foreach($this->service_tags as $service_tag => $service_item) {
      if (!empty($service_item['call_back']) && function_exists($this->hashtags)) {
        
      }
    }
  }
  
  function callback($item) {
    print('here');
    cmc_products::init();
    $products = cmc_products::get();    
    if($products) {
      $this->buildmessage();
    }
  }
  
  
}


class twitter_servicetags {
  protected $service_tags;
  protected function service_tags_get() {
  
    $this->service_tags = array(); 
    $this->service_tags['price'] = array(
         'call_back' => 'get_price',
         'return' => array('FX', 'COMMODOTIES'),
     );

    foreach (module_implements('twitter_lab_service') as $module) {
      $extra_tags = module_invoke($module, 'twitter_lab_service');
      
      if (!empty($extra_tags)) {
        $this->service_tags += $extra_tags;
      }
    }
   //print_r($this->service_tags);
  }
}


class cmc_products {
  static private $products;
  
  /**
   * Build list of CMC Products
   */
  function init($symbol) {
    static $symbols;
    
    if (!cache_get('product_symbols')) {
      
       drupal_static($symbols);
    }
    if($symbol) {
      $symbols[$symbol];
    } else {
      return $symbols;
    }
    
    self::$products = array(
        '001HK.SPOT.HKD.CMC' => 
        
        'test',
    );
  }
  
  function lookup($symbol){
    
  }
  
  function get() {
    return self::$products;
  }
}