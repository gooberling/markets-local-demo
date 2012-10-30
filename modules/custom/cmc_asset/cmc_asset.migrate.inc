<?php

/**
 *
 */
abstract class AssetMigration extends Migration {
  
	/**
   * Node has been saved, now do some more things to the node
   * @param unknown_type $entity
   * @param unknown_type $source_row
   */
  public function complete(&$entity, $source_row) {
    
    $files_dir = variable_get('file_public_path', '');
    $downloaded = array();
    
    if ($source_row->images) {
      
      $images = explode("\n", $source_row->images);
      
      foreach ($images as $i => $image) {
        if (!$image) {
          continue;
        }
        
        $src = 'http://www.cmcmarkets.co.uk/' . $image;
        // download the file and put it into filesystem
        // as we need to preserve the filepath
        $this->downloadFile($src, $image);
        $downloaded[] = $src;
        
        // add the filepath to the body so we have a record of it
        $entity->body['und'][0]['value'] .= $src . "\n";
      }
    }
    
    if ($source_row->files) {
      
      $files = explode("\n", $source_row->files);
      
      foreach ($files as $i => $file) {
        if (!$file) {
          continue;
        }
        
        $src = 'http://www.cmcmarkets.co.uk/' . $file;
        // download the file and put it into filesystem
        // as we need to preserve the filepath
        $this->downloadFile($src, $file);
        $downloaded[] = $src;
        
        // add the filepath to the body so we have a record of it
        $entity->body['und'][0]['value'] .= $src . "\n";
      }
    }
    
    //exit;
    if ($entity->nid) {
      node_save($entity);
    }
  }
  
  private function addToFilesTable() {
    
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




class CmcEmailImageMigration extends AssetMigration {
  
	/**
   * Class Constructor
   */
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Migrate CMC Email Images');
    
    $query = db_select('cmcmarkets.email_images', 'email_images')
      ->fields('email_images',
            array('nid', 'domain', 'created', 'title',
            'images', 'published', 'target')
            );
      //->orderBy('nid', 'DESC');
    
    $this->source = new MigrateSourceSQL($query, array());
    $this->destination = new MigrateDestinationNode('cmc_asset');
    
        
    $this->map = new MigrateSQLMap($this->machineName,
       array(
         'nid' => array(
           'type' => 'int',
           'length' => 11,
           'not null' => TRUE,
         ),
       ),
       MigrateDestinationNode::getKeySchema()
    );

    
    $mappings = array(
      'title' => 'title',
	    'created' => 'created',
	    'body' => 'body',
      'published' => 'published',
	  );

    foreach ($mappings as $dest => $source) {
      $this->addFieldMapping($dest, $source);
    }
  }
}



class CmcAssetMigration extends AssetMigration {
  
	/**
   * Class Constructor
   */
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Migrate CMC Asset');
    
    $query = db_select('cmcmarkets.assets', 'assets')
      ->fields('assets',
            array('nid', 'domain', 'created', 'title',
            'images', 'files', 'published', 'target')
            );
      //->orderBy('nid', 'DESC');
    
    $this->source = new MigrateSourceSQL($query, array());
    $this->destination = new MigrateDestinationNode('cmc_asset');
    
        
    $this->map = new MigrateSQLMap($this->machineName,
       array(
         'nid' => array(
           'type' => 'int',
           'length' => 11,
           'not null' => TRUE,
         ),
       ),
       MigrateDestinationNode::getKeySchema()
    );

    
    $mappings = array(
      'title' => 'title',
	    'created' => 'created',
	    'body' => 'body',
      'published' => 'published',
	  );

    foreach ($mappings as $dest => $source) {
      $this->addFieldMapping($dest, $source);
    }
  }
}
       