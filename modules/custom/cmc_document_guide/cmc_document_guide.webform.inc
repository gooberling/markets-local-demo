<?php
/**
 * Implementation of hook_cmc_webform_thanks_alter
 * @param unknown_type $confirmation
 * @param unknown_type $values
 */
function cmc_document_guide_cmc_webform_thanks_alter(&$confirmation, $values) {
  
  $submitted_values = $values['submitted_tree'];
  
  if (empty($submitted_values['cmc_document_guide_nid'])) {
    return;
  }
  
  $title = $submitted_values['cmc_document_guide_title'];
  $nid = $submitted_values['cmc_document_guide_nid'];
  
  // confirmation page content
  $confirmation .= '<p>' . t('Back to ') . l($title, 'node/' . $nid) . '</p>';
  
  // get the pdf link
  $document_download = node_load($nid);
  if (isset($document_download->field_pdf['und'][0]['uri'])) {
    $pdf_file = file_create_url($document_download->field_pdf['und'][0]['uri']);
    
    $confirmation .= '<p>' . l(t('Download PDF'), $pdf_file) . '</p>';
  }
  else {
    $msg = t('No pdf associated with this document download!');
    drupal_set_message($msg, 'error');
  }
  
  // do some string replacements with submitted values?
  
  
  // add tracking code
  $document_node = node_load($nid);
  if (!empty($document_node->field_webform_tracking['und'][0]['value'])) {
    $confirmation .= $document_node->field_webform_tracking['und'][0]['value'];
  }
}

/**
 *
 * Enter description here ...
 * @param unknown_type $node
 */
function cmc_document_guide_webform_export($node) {
  
  $log_results = _cmc_document_guide_webform_log_get_summary($node);
  //print_r($log_results);
  $header = array('Number', 'Document Guide nid', 'Document Guide Title', '');
  
  $rows = array();
  foreach ($log_results as $res) {
    $row = array();
    $row[] = $res->num;
    $row[] = $res->document_guide_nid;
    $row[] = $res->document_guide_title;
    
    $download_url =  'node/' . $res->document_guide_nid . '/cmc_document_guide_webform/download';
    $row[] = l('Download CSV', $download_url);
    
    $rows[] = $row;
  }
  
  return theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 *
 * Enter description here ...
 * @param unknown_type $node
 */
function _cmc_document_guide_webform_log_get_summary($node) {
  //cmc_document_guide_webform_log
  
  $result = db_query('SELECT COUNT(*) AS num, document_guide_nid, document_guide_title
FROM cmc_document_guide_webform_log
WHERE document_guide_nid=:nid
GROUP BY document_guide_nid DESC', array(':nid' => $node->nid));
  
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
function _cmc_document_guide_webform_log_get_sids($node) {
  //cmc_document_guide_webform_log
  
  $result = db_query('SELECT sid
FROM cmc_document_guide_webform_log
WHERE document_guide_nid=:nid
ORDER BY sid DESC', array(':nid' => $node->nid));
  
  $results = array();
  foreach ($result as $record) {
    $results[] = $record->sid;
  }
  
  return $results;
}


/**
 *
 */
function cmc_document_guide_webform_download($node) {
  
  $webform_node = node_load($node->field_webform['und'][0]['nid']);
  $sids = _cmc_document_guide_webform_log_get_sids($node);
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
function cmc_document_guide_webform_submission_insert($node, $submission) {

  $component_values = _cmc_document_guide_webform_submission_component_values($node, $submission);
  
  if ($component_values['cmc_document_guide_nid']) {
    
    // Insert a record into a 3rd-party module table when a submission is added.
    db_insert('cmc_document_guide_webform_log')
      ->fields(array(
        'nid' => $node->nid,
        'sid' => $submission->sid,
        'document_guide_nid' => $component_values['cmc_document_guide_nid'],
        'document_guide_title' => $component_values['cmc_document_guide_title'],
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
function _cmc_document_guide_webform_submission_component_values($node, $submission) {
  $component_values = array(
    'cmc_document_guide_nid' => '',
    'cmc_document_guide_title' => '',
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
function cmc_document_guide_webform_submission_update($node, $submission) {
  
  $component_values = _cmc_document_guide_webform_submission_component_values($node, $submission);
  
  if ($component_values['cmc_document_guide_nid']) {
    // Update a record in a 3rd-party module table when a submission is updated.
    db_update('cmc_document_guide_webform_log')
      ->fields(array(
        'document_guide_nid' => $component_values['cmc_document_guide_nid'],
        'document_guide_title' => $component_values['cmc_document_guide_title'],
      ))
      ->condition('nid', $node->nid)
      ->condition('sid', $submission->sid)
      ->execute();
  }
}
