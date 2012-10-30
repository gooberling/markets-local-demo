<?php

/**
 * Returns revisions of a translated string 
 * @param int $lid
 *  Id of the translated string
 * 
 * @return Revisions of a given string themed in table format 
 */
function _locale_revisions_by_lid($lid) {
  $rows = array();
  $header = array(
    'title' => array('data' => t('Revision'), 'field' => 'lr.rid', 'sort' => 'desc'),
    'author' => array('data' => t('Author'), 'field' => 'lr.uid'),
    'changed' => array('data' => t('Updated'), 'field' => 'lr.updated', 'sort' => 'desc'),
    'status' => array('data' => t('Status')),
    'operations' => array('data' => t('Operations'))
  );
  
  $result = db_select('locales_revisions_index', 'lr') 
    ->fields('lr', array('rid', 'uid', 'updated','status', 'current'))
    ->condition('lid', $lid, '=')
    ->extend('PagerDefault')->extend('TableSort')
    ->limit(LOCALE_REVISIONS_PAGE_LIMIT)
    ->orderByHeader($header)
    ->execute();
  
  while($record = $result->fetchAssoc()) {
    $rid = $record['rid'];
    $rows[] = array(
      'rid' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $rid,
          '#href' => 'admin/config/regional/locale_revisions/revert/' .$rid, 
          '#suffix' => ' ',
        ),
      ),
      'author' => theme('username', array('account' => user_load($record['uid']))),
      'changed' => format_date($record['updated'], 'short'),
      'status' => ($record['status'] == LOCALE_REVISIONS_PUBLISHED) ? t('Published') : t('Draft'),
      'operations' => array(
        'data' => _locale_revisions_operations($record),
      ),
    );
  }
 
  $data = theme('table', array(
  'header' => $header,
  'rows' => $rows,
  'attributes' => array('class' => array('mytable'))
  ));
 
 $pager = theme('pager');
 return ($data .$pager);
}


/**
 * Returns revision of a given translations in all languages along with the 
 * original source string
 * @param type $rid
 * @return type 
 */
function _locale_revisions_get_revision($rid) {
  // Don't understand why Join queries donot work like other queries and we have 
  // to explicitly write the query in seperate lines.
  $query = db_select('locales_revisions_index', 'i');
  $query->join('locales_source', 's', 'i.lid = s.lid'); // JOIN users with users_roles
  $query->fields('s'); // SELECT the fields from users
  $query->condition('i.rid', $rid,'='); // WHERE role is 3
  
  $source = $query->execute()
               -> fetchAssoc();
  
  $result = db_select('locales_revisions', 'lr')
    ->fields('lr')
    ->condition('lr.rid', $rid, '=')
    ->execute();
    
  while($record = $result->fetchAssoc()) {
    $rows[] = array($record['language'], $record['translation']);
  }
  
  return array(
   'original' => $source,
   'translated' => $rows,
  );
}


/**
 * Returns strings by status. If status is draft, returns all the strings that are set to Draft
 * Information of strings that are in draft is available in locale_revisions_index table.
 * Strings that are published is available in locales_target (Provided by core)
 * strings that
 * 
 * @param tinyint $status 
 *   Status of translated strings
 * @return mixed
 *   themed as table list of all strings that match the filter criteria
 */
function _locale_strings($filter = FALSE) {
  $rows = array();
  
  $header = array(
    'revision' => array('data' => t('Revision'), 'field' => 'i.rid', 'sort' => 'desc'),
    'textgroup' => array('data' => t('textgroup'),),
    'location' => array('data' => t('Location'),),
    'source' => array('data' => t('Original String'),),
    'context' => array('data' => t('Context'), 'field' => 's.context', 'sort' => 'desc' ),
    'author' => array('data' => t('Last updated by'), 'field' => 'i.uid'),
    'changed' => array('data' => t('Updated'), 'field' => 'i.updated', 'sort' => 'desc'),
    'status' => array('data' => t('Status')),
    'operations' => array('data' => t('Operations'))
  );
  
  $query = db_select('locales_revisions_index', 'i');
  $query->join('locales_source', 's', 'i.lid = s.lid'); // JOIN users with users_roles
  $query->fields('s');
  $query->fields('i',array('rid', 'updated', 'uid','status' ));
  
  if($filter) {
    $query->condition('status', $filter, '=');
  }
  
  // When querying for published strings, Only bring up 
  // the strings that have a current revision in place
  if ($filter == LOCALE_REVISIONS_PUBLISHED) {
    $query->condition('current', LOCALE_REVISIONS_PUBLISHED, '=');
  }
  
  $result = $query->extend('PagerDefault')->extend('TableSort')
          ->limit(LOCALE_REVISIONS_PAGE_LIMIT)
          ->orderByHeader($header)
          ->execute();
  
  while($item = $result->fetchAssoc()) {
    $rows[] = array(
      'rid' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $item['rid'],
          '#href' => 'admin/config/regional/locale_revisions/revert/' .$item['rid'], 
          '#suffix' => ' ',
        ),
      ),
      'textgroup' => $item['textgroup'],
      'location' => $item['location'],  
      'source' => $item['source'],
      'context' => $item['context'],
      'author' => theme('username', array('account' => user_load($item['uid']))),
      'changed' => format_date($item['updated'], 'short'),
      'status' => ($item['status'] == LOCALE_REVISIONS_PUBLISHED) ? t('Published') : t('Draft'),
      'operations' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('View'),
          '#href' => 'admin/config/regional/translate/edit/' .$item['lid'], 
          '#suffix' => ' ',
        ),
      ),
    );
  }
  
  
  $data = theme('table', array(
  'header' => $header,
  'rows' => $rows,
  'attributes' => array('class' => array('mytable'))
  ));
 
 $pager = theme('pager');
 return ($data .$pager);
} 

/**
 * Cancel the revert form
 * @param type $form
 * @param type $form_state 
 */
function locale_revisions_goto_lid($lid) {
  drupal_goto("admin/config/regional/translate/edit/". $lid);
}
