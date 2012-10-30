<?php
/**
 * @File
 *
 * @author Ravi Julapalli (r.julapalli@cmcmarkets.com)
 */


function cmc_admin_node_exists($params) {
  $node = node_load($params);
  if ($node->nid) {
    drupal_set_message($variable . ' node exists');
    return true;
  }
  return false;
}

/**
 * Copied from devel_generate_content_add_node()
 */
function cmc_admin_prepare_dummy_node($type) {
  
  // prepare node for new data
  $node = new StdClass();

  module_load_include('inc', 'node', 'node.pages');
  $node->type = $type;
  node_object_prepare($node);

  global $user;
  $node->uid = $user->uid;

  $node->filter = variable_get('filter_default_format', 1);
  //$node->format = FILTER_FORMAT_DEFAULT;
  $node->created = time();
  $node->comment = 0;

  return $node;
}


/**
 */
function cmc_admin_lorem_ipsum($paragraphs=3, $num_chars=null) {
  $lorem_ipsum = array(
  	'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce eu urna eu augue mollis imperdiet molestie in ipsum. Donec eu tortor vel justo viverra aliquet. Donec accumsan nulla a eros bibendum porta. Sed ipsum lectus, laoreet volutpat molestie a, rhoncus vel quam. Nunc non pharetra urna. Vivamus feugiat mauris sed ante egestas ornare. Nam et nulla vitae neque facilisis dignissim.',
    'Curabitur tincidunt sem vel arcu facilisis id volutpat enim feugiat. Fusce ipsum elit, ultricies ac vehicula ut, convallis sed tortor. Sed mauris erat, pellentesque in aliquam sed, luctus non felis. Morbi in lorem in metus vestibulum scelerisque ac in neque. Duis in lorem nec elit molestie egestas. Vivamus eget varius urna. Suspendisse laoreet, orci eget fermentum tristique, ligula velit venenatis urna, ac egestas sem tellus ut ante. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Ut neque mauris, aliquam non eleifend eget, fermentum dignissim arcu. Ut vulputate faucibus lacus ac pretium. Donec tempor ullamcorper leo, non consectetur lectus aliquet et. Morbi tempus consectetur arcu, volutpat tristique nisl lacinia at. Sed dolor justo, adipiscing quis malesuada vel, tempus id est.',
    'In arcu sapien, mattis in iaculis ut, molestie vel augue. Pellentesque iaculis metus vitae arcu sodales vitae viverra elit adipiscing. Aliquam erat volutpat. Vestibulum ut odio ante, vel dictum libero. Etiam vel enim a ipsum blandit dapibus sed non sem. Maecenas dignissim libero et sem porttitor eu faucibus nisi commodo. Curabitur quis nisl faucibus nulla elementum sagittis et id arcu. Quisque non sollicitudin velit. Morbi nec nibh a lacus placerat cursus sit amet nec ipsum. Aliquam porttitor malesuada libero, sit amet rutrum elit pretium quis. Etiam ut elit vitae massa ultrices facilisis eu tempor libero. Nunc rutrum libero aliquet tellus fermentum at vestibulum ipsum accumsan. Proin euismod tristique sem. Aliquam commodo nisl magna. Vestibulum aliquam blandit metus.',
    'Maecenas posuere tristique nulla nec condimentum. Suspendisse potenti. Quisque interdum libero non risus ultricies eu adipiscing dui rutrum. Sed purus sem, suscipit rhoncus bibendum at, euismod sit amet lectus. Praesent a sem ut dolor condimentum blandit. Praesent ac mauris a mauris pulvinar elementum non sit amet orci. Pellentesque mollis viverra sodales. Ut nec pellentesque quam. Mauris vehicula ipsum in libero dictum quis viverra metus mattis. Maecenas interdum elit id enim gravida venenatis. Curabitur augue massa, laoreet vel facilisis at, porttitor vestibulum sem.',
    'Aliquam euismod viverra purus non scelerisque. Suspendisse at lorem eu tortor semper pellentesque sed nec risus. Donec enim nunc, elementum eu tincidunt in, ornare non leo. Duis rutrum eleifend nunc sed porttitor. Nullam venenatis, nisi vitae ullamcorper faucibus, turpis leo faucibus ante, eget facilisis est arcu at enim. Curabitur eu libero velit. Duis convallis sapien in quam dictum elementum. In aliquet dignissim ante, in scelerisque enim hendrerit ac.',
    'Quisque euismod, neque ac varius semper, lorem mi adipiscing sapien, vel pulvinar eros lorem sed libero. Praesent sollicitudin, tortor eget adipiscing dignissim, ligula ipsum varius neque, ut vulputate lectus ligula id elit. Cras a magna non nisi congue vulputate. Nunc elementum varius sapien, ultricies elementum ante sodales eget. Integer vestibulum luctus tellus a sagittis. Nam non mi et leo ultrices tempor sed sit amet nunc. Aenean eget nunc et ante pharetra rutrum. Nam posuere tempus pulvinar. Quisque gravida aliquam sodales. Donec varius, orci ut luctus aliquam, purus lectus pellentesque ipsum, sit amet auctor orci nulla id sapien. In hac habitasse platea dictumst. Phasellus laoreet pulvinar sodales. Nullam eget euismod lacus. Suspendisse adipiscing, enim quis accumsan tristique, leo tellus rhoncus mi, in condimentum nisi neque in justo.',
  );
  
  
  if (!is_null($num_chars)) {
    $rand = mt_rand(0, count($lorem_ipsum)-1);
    $line = $lorem_ipsum[$rand];
    $line = substr($line, strlen($line)-$num_chars, $num_chars);
    return ucfirst($line);
  }
  else {
    $ret = array();
    for ($i=0; $i<$paragraphs; $i++) {
      $rand = mt_rand(0, count($lorem_ipsum)-1);
      $ret[] = $lorem_ipsum[$rand];
    }
    
    return implode("\n\n", $ret);
  }

  return $node;
}


function cmc_admin_add_menu_link($menu_name='main-menu', $options=array()) {
  $item = array();
  $item['link_title'] = $options['link_title'];
  $item['link_path'] = $options['link_path'];
  $item['menu_name'] = $menu_name;
  
  if (isset($options['parent_path'])) {
    $params =array(
    	':link_path' => $options['parent_path'],
      ':menu_name' => $menu_name,
    );
    $result = db_query("SELECT mlid FROM {menu_links} WHERE link_path = :link_path AND menu_name= :menu_name", $params);
    foreach ($result as $res) {
      $item['plid'] = $res->mlid;
    }
    
    //print_r($mlid);
    //$item['plid'] = $mlid;
  }
  menu_link_save($item);
  drupal_set_message('Added menu item ' . $item['link_title']);
  
}


/**
 *
 * Enter description here ...
 */
function cmc_admin_add_menu($options) {
  
  $m = menu_load($options['name']);
  
  if (!$m) {
    $menu = array(
      'menu_name' => $options['name'],
      'title' => $options['title'],
      'description' => $options['description'],
    );
    menu_save($menu);
    drupal_set_message('Added menu ' . $options['name']);
  }
  else {
    drupal_set_message('Menu ' . $options['name'] . ' exists', 'error');
  }
}



