<?php

class ChartEducationMigration extends Migration {
  
	/**
   * Class Constructor
   */
  public function __construct() {
    parent::__construct();
    
    // http://drupal.org/node/1117454
    // so only mapped fields are updated!
    $this->systemOfRecord = Migration::DESTINATION;
    
    
    $this->description = t('Migrate CMC Chart Education');
    
    $query = db_select('cmcmarkets.cmc_charteducation', 'cmc_charteducation')
      ->fields('cmc_charteducation',
            array('nid', 'language', 'domain_src', 'path', 'created',
            'title', 'body', 'image', 'chart_id', 'published', 'domain_dest')
            )
      ->orderBy('language', 'DESC');
    
    $this->source = new MigrateSourceSQL($query, array());
    
    $node_options = MigrateDestinationNode::options('en', 'cmc_charteducation');
    $this->destination = new MigrateDestinationNode('cmc_charteducation', $node_options);
    
        
    $this->map = new MigrateSQLMap($this->machineName,
                 array(
                   'nid' => array(
                     'type' => 'int',
                     'length' => 11,
                     'not null' => TRUE,
                   ),
                   'language' => array(
                     'type' => 'varchar',
                     'length' => 255,
                     'not null' => TRUE,
                   ),
                 ),
                 MigrateDestinationNode::getKeySchema()
    );

    
    $mappings = array(
      'title' => 'title',
	    'created' => 'created',
	    'body' => 'body',
      'field_chart_education_id' => 'chart_id',
	    'language' => 'language',
      'status' => 'published',
	    );

    foreach ($mappings as $dest => $source) {
      $this->addFieldMapping($dest, $source);
    }
  }
  
  
	/**
   * Add any additional data / clean up data for the current row / node that will be added/updated.
   */
  public function prepareRow(&$current_row) {
  }
  
	/**
   * Hack to link up the translations
   * @param unknown_type $entity
   * @param unknown_type $source_row
   */
  public function complete(&$entity, $source_row) {
    
    if ($source_row->language == 'en') {
      $entity->tnid = $entity->nid;
    }
    else if ($source_row->language == 'de') {
      //'find one'
      $view = views_get_view('cmc_charteducation');
      $view->preview('source_node', array($source_row->chart_id));
      $results = $view->result;
      if (count($results)) {
        $entity->tnid = $results[0]->nid;
      }
    }
    
    
    if ($source_row->image) {
      $files_dir = variable_get('file_public_path', '');
      $downloaded = array();
      $images = explode("\n", $source_row->image);
      
      foreach ($images as $i => $image) {
        if (!$image) {
          continue;
        }
        
        $src = 'http://www.cmcmarkets.co.uk/' . $image;
        // download the file and put it into filesystem
        // as we need to preserve the filepath
        $this->downloadFile($src, $image);
        $downloaded[] = $src;
      }
    }
    
    
    
    if ($entity->nid) {
      node_save($entity);
    }
  }
  
  
  
/**
   * Download a file using phpcurl
   * @param unknown_type $src
   * @param unknown_type $dest
   */
  private function downloadFile($src, $dest) {
    
    $pathinfo = pathinfo($dest);
    $dest_dir = $pathinfo['dirname'];
    $d = $_SERVER['DOCUMENT_ROOT'] . '/' . $dest_dir;

    // create directory if it doesn't exist on filesystem
    if (!file_exists($d)) {
      mkdir($d,0777,TRUE);
    }
    
    $dest = $pathinfo['dirname'] . '/' . $pathinfo['basename'];
    
    $ch = curl_init($src);
    $fp = fopen($dest, 'wb');
    
    if ($fp !== false) {
      curl_setopt($ch, CURLOPT_FILE, $fp);
      curl_setopt($ch, CURLOPT_HEADER, 0);
      curl_exec($ch);
      curl_close($ch);
      fclose($fp);
    }
    else {
      watchdog('cmc_asset.migrate', $src . ' could not be downloaded');
    }
  }
  
}
