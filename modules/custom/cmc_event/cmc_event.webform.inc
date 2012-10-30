<?php


/**
 * hook_webform_select_options_info
 */
function cmc_event_webform_select_options_info() {
  $items = array();
  $items['cmc_event_dates'] = array(
    'title' => t('Event Node Dates'),
    'options callback' => '_cmc_event_webform_dates',
  );
  
  return $items;
}


/**
 * Return the valid dates for an event webform
 */
function _cmc_event_webform_dates() {
  
  if (arg(0) != 'node' || !is_numeric(arg(1))) {
    return;
  }
  // assume we're on the right node
  $nid = arg(1);
  $event_node = node_load($nid);

  // get the event datas from a view
  $view = views_get_view('cmc_events');
  $view->preview('event_dates', array($nid));
  $dates = array();
  //print_r($view->result);
  foreach ($view->result as $res) {
    $event_date = $res->field_data_field_date_field_date_value;
    $dates[format_date($event_date, 'custom', 'Y-m-d H:i')] = format_date($event_date);
  }
  return $dates;
}


/**
 * Implementation of hook_cmc_webform_thanks_alter
 * @param unknown_type $confirmation
 * @param unknown_type $values
 */
function cmc_event_cmc_webform_thanks_alter(&$confirmation, $values) {
  
  $submitted_values = $values['submitted_tree'];
  
  if (empty($submitted_values['cmc_event_nid'])) {
    return;
  }
  
  $event_title = $submitted_values['cmc_event_title'];
  $event_nid = $submitted_values['cmc_event_nid'];
  
  $confirmation .= '<p>' . t('Back to ') . l($event_title, 'node/' . $event_nid) . '</p>';
  
  // add tracking code
  $event_node = node_load($event_nid);
  if (!empty($event_node->field_webform_tracking['und'][0]['value'])) {
    $confirmation .= $event_node->field_webform_tracking['und'][0]['value'];
  }
  
  
  // do some string replacements with submitted values
  //$output[] = t('Back to') . l($event_title, 'node/' . $event_nid);
  
}

/**
 *
 * Enter description here ...
 * @param unknown_type $node
 */
function cmc_event_webform_export($node) {
  
  $log_results = _cmc_event_webform_log_get_summary($node);
  //print_r($log_results);
  $header = array('Number', 'Event nid', 'Event Title', 'Date', '', '');
  
  $rows = array();
  foreach ($log_results as $res) {
    $row = array();
    $row[] = $res->num;
    $row[] = $res->event_nid;
    $row[] = $res->event_title;
    $row[] = format_date($res->event_date);
    
    $download_url =  'node/' . $res->event_nid . '/cmc_event_webform/download/' . $res->event_date;
    $row[] = l('Download CSV', $download_url);
    $row[] = 'WEBEX';
    
    $rows[] = $row;
  }
  
  return theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 *
 * Enter description here ...
 * @param unknown_type $node
 */
function _cmc_event_webform_log_get_summary($node) {
  //cmc_event_webform_log
  
  $result = db_query('SELECT COUNT(*) AS num, event_nid, event_title, event_date
FROM cmc_event_webform_log
WHERE event_nid=:nid
GROUP BY event_date DESC', array(':nid' => $node->nid));
  
  $results = array();
  foreach ($result as $record) {
    $results[] = $record;
  }
  
  return $results;
}

/**
 *
 * Enter description here ...
 * @param unknown_type $node
 */
function _cmc_event_webform_log_get_sids($node, $timestamp) {
  //cmc_event_webform_log
  
  $result = db_query('SELECT sid
FROM cmc_event_webform_log
WHERE event_nid=:nid AND event_date=:event_date
ORDER BY sid DESC', array(':nid' => $node->nid, ':event_date' => $timestamp));
  
  $results = array();
  foreach ($result as $record) {
    $results[] = $record->sid;
  }
  
  return $results;
}


/**
 *
 */
function cmc_event_webform_download($node, $timestamp) {
  
  $webform_node = node_load($node->field_webform['und'][0]['nid']);
  $sids = _cmc_event_webform_log_get_sids($node, $timestamp);
  cmc_webform_download($webform_node, $sids);
}


/**
 * Respond to a Webform submission being inserted.
 * implementation of hook_webform_submission_insert
 * @param $node
 *   The Webform node on which this submission was made.
 * @param $submission
 *   The Webform submission that was just inserted into the database.
 */
function cmc_event_webform_submission_insert($node, $submission) {

  $component_values = _cmc_event_webform_submission_component_values($node, $submission);
  
  if ($component_values['cmc_event_nid']) {
    // Insert a record into a 3rd-party module table when a submission is added.
    db_insert('cmc_event_webform_log')
      ->fields(array(
        'nid' => $node->nid,
        'sid' => $submission->sid,
        'event_nid' => $component_values['cmc_event_nid'],
        'event_title' => $component_values['cmc_event_title'],
        'event_date' => strtotime($component_values['event_date']),
        'created' => date('U'),
      ))
      ->execute();
  }
}


/**
 *
 * @param unknown_type $node
 * @param unknown_type $submission
 */
function _cmc_event_webform_submission_component_values($node, $submission) {
  $component_values = array(
    'cmc_event_nid' => '',
    'cmc_event_title' => '',
    'event_date' => '',
  );
  $component_keys = array_keys($component_values);
  
  $components = $node->webform['components'];
  
  foreach ($components as $comp) {
    $form_key = $comp['form_key'];
    if (in_array($form_key, $component_keys)) {
      $cid = $comp['cid'];
      $component_values[$form_key] = $submission->data[$cid]['value'][0];
    }
  }
  
  return $component_values;
}


/**
 * implementation of hook_webform_submission_update
 * @param unknown_type $node
 * @param unknown_type $submission
 */
function cmc_event_webform_submission_update($node, $submission) {
  
  $component_values = _cmc_event_webform_submission_component_values($node, $submission);
  
  if ($component_values['cmc_event_nid']) {
    // Update a record in a 3rd-party module table when a submission is updated.
    db_update('cmc_event_webform_log')
      ->fields(array(
        'event_nid' => $component_values['cmc_event_nid'],
        'event_title' => $component_values['cmc_event_title'],
        'event_date' => strtotime($component_values['event_date']),
      ))
      ->condition('nid', $node->nid)
      ->condition('sid', $submission->sid)
      ->execute();
  }
}
