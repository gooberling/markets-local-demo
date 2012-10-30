<?php


/**
 *
 * Enter description here ...
 * @param unknown_type $form
 * @param unknown_type $form_state
 * @param unknown_type $pid
 */
function cmc_pricing_admin_edit($form, &$form_state, $pid) {
  
  
  $pricing = cmc_pricing_load($pid);
  
  $markup = array();
  foreach($pricing as $k => $v) {
    $markup[] = $k . ': ' . $v;
  }
  
  $form['markup'] = array(
    '#markup' => theme('item_list', array('items' => $markup)),
  );
  
  
  $form['pid'] = array(
    '#type' => 'hidden',
    '#value' =>  $pricing['pid'],
  );
  
  
  $form['instrument_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Instrument Code'),
    '#description' => t('This should be the code od the product the pricing value should be surfaced against'),
    '#default_value' =>  $pricing['instrument_code'],
  );
  
  $form['submit'] = array(
  	'#type' => 'submit',
  	'#value' => t('Update'),
  );
  
  $form['delete'] = array(
    '#markup' => l('DELETE', 'admin/config/cmc/pricing/delete/' . $pricing['pid']),
  );
  
  return $form;
}



function cmc_pricing_admin_edit_submit($form, &$form_state) {
  //print_r($form_state);
  $form_values = $form_state['values'];
  
  $pricing = cmc_pricing_load($form_values['pid']);
  $pricing['instrument_code'] = $form_values['instrument_code'];
  
  $res = cmc_pricing_save($pricing);
  if ($res) {
    drupal_set_message('Saved pricing');
  }
  else {
    drupal_set_message('Error saving pricing', 'error');
  }
  //exit;
}

function cmc_pricing_admin_delete_confirm(&$form_state, $pid) {
  $form['pid'] = array(
		'#type' => 'value',
		'#value' => $pid,
	);
 
	return confirm_form($form,
    	t('Are you sure you want to delete this product pricing?'),
    	isset($_GET['destination']) ? $_GET['destination'] : "admin/config/cmc/pricing/list",
    	t('This action cannot be undone.'),
    	t('Delete'),
    	t('Cancel'));
}


function cmc_pricing_admin_delete_confirm_submit($form, &$form_state) {
	$form_values = $form_state['values'];
 
	if ($form_state['values']['confirm']) {
		$pid = $form_state['values']['pid'];
		cmc_pricing_delete($pid);
		drupal_set_message(t('Pricing Product has been deleted successfully.'));
  }
 
	drupal_goto('admin/config/cmc/pricing/list');
}


/**
 */
function cmc_pricing_admin_list() {

  $header = array(
    array('data' => 'Edit'),
    array('data' => 'Instrument Code', 'field' => 'instrument_code'),
    array('data' => 'Name', 'field' => 'name', 'sort' => 'asc'),
    array('data' => 'Symbol', 'field' => 'symbol'),
    array('data' => 'Type', 'field' => 'type'),
    array('data' => 'Subtype', 'field' => 'subtype'),
    array('data' => 'Country', 'field' => 'country'),
    array('data' => 'Region', 'field' => 'region'),
    array('data' => 'created', 'field' => 'created'),
    array('data' => 'updated', 'field' => 'updated'),
  );
  
    

  $query = db_select('cmc_pricing', 'cmc_pricing')
          ->extend('PagerDefault')     //Pager Extender
          ->limit(50)              //10 results per page
          ->extend('TableSort')        //Sorting Extender
          ->orderByHeader($header)//Field to sort on is picked from $header
          ->fields ('cmc_pricing', array (
              'pid',
              'instrument_code',
              'name',
              'symbol',
              'type',
              'subtype',
              'country',
              'region',
              'created',
              'updated',
          ));
    
  
  $results = $query->execute();
  $rows = array();
  foreach ($results as $node) {
    
    $edit_options = array(
      'query' => array('destination' => $_GET['q'])
    );
    $rows[] = array(
      'data' => array(
        l('Edit', 'admin/config/cmc/pricing/edit/' . $node->pid, $edit_options),
        $node->instrument_code,
        $node->name,
        $node->symbol,
        $node->type,
        $node->subtype,
        $node->country,
        $node->region,
        $node->created,
        $node->updated,
      )
    );
  }
            
  $html = theme('table',
    array(
        'header' => $header,
        'rows'=>$rows,
        'caption' => 'Creating Drupal 7 style tables',   //Optional Caption for the table
        'sticky' => TRUE,                        //Optional to indicate whether the table headers should be sticky
        'empty' => 'No nodes created...',        //Optional empty text for the table if resultset is empty
    )
  );
            
        
  $html .= theme('pager', array(
      'tags' => array(),
    )
  );

  return $html;
        
}











/**
 * List the pricing blocks
 * Enter description here ...
 */
function cmc_pricing_admin_panel_list() {
  $result = db_select('cmc_pricing_block', 'cpb')
  ->fields('cpb', array('pbid', 'title', 'created'))
  ->execute();

  $rows = array();
  while ($record = $result->fetchAssoc()) {
    $row = array(
      $record->pbid,
      $record->title,
      $record->created,
    );

    $rows[] = $row;
  }

  $data = array(
    'header' => array(
      'data' => array('pbid', 'title', 'created'),
    ),
    'rows' => array(
      'data' => $rows,
    ),
  );
  
  $output = l('Add new pricing panel', 'admin/content/cmc_pricing_block/save') . '  fsa';
  $output .= theme('table', $data);
  return $output;
}


