<?php

function cmc_products_instruments_search($args) { 
  // Get search content
  $content = $_POST["search_api_views_fulltext"];
  
  // Perform Solr Search
  $search_result = _cmc_products_get_instruments_solr_content($content);
  
  // FOrmat Results
  $results = _cmc_products_prepare_result_solr_content($search_result);
    
  echo(json_encode($results));
  exit();
}

/**
 * Convert Solr result into a renderable array that can be passed back JSON encoded easily
 * @param type $result
 * @return type 
 */
function _cmc_products_prepare_result_solr_content($result) {
  $rows = array();
  foreach($result['results'] as $id => $item) {
    $rows[$id]['title'] = $item['fields']['title'];
    $rows[$id]['field_instrument_code'] = strip_tags($item['fields']['field_instrument_code'],'<strong>');
  }
 return $rows;
}

/**
 * Performs Solr Search on a provided text content
 * Uses search api server, Only basic settings are provided, advanced settings such as 
 * Connectivity, fq and facets etc are detalt by search_api_solr
 * @param type $content
 * @return type 
 */
function _cmc_products_get_instruments_solr_content($content) {
  $indx = "sitewide";
  $conditions = $conditions = array('class' => 'search_api_solr_service', 'enabled' => TRUE);

  // Set server  
  $index = search_api_index_load_multiple(array($indx));
  foreach (search_api_server_load_multiple(FALSE, $conditions) as $server) {
     $server->getSolrConnection()->optimize(FALSE, FALSE);
  }
  $solrServer = new SearchApiSolrService($server);
  $query = new SearchApiQuery($index[$indx]);
  $search_fields  = array(

    'title' => 'title',
    'field_currency' => 'field_currency',
  );
  $query->fields($search_fields);
  
  // Run the query object through search api query alter to add any Node Access related permissions
 // search_api_search_api_query_alter($query);
  $filter = new SearchApiQueryFilter;
  $filter->condition('type', 'product', '=');
  $query->filter($filter);
  $query->keys($content);
  $results = $solrServer->search($query);
 return $results;
}