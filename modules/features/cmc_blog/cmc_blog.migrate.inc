<?php

abstract class CmcBlogMigration extends Migration {
  
  protected function migrationSetup($table_name) {
    $query = db_select('cmcmarkets.' . $table_name, 'blog')
      ->fields('blog',
            array('nid', 'title', 'created', 'body_section', 'teaser',
            'taxonomy', 'path', 'language', 'domain_src', 'domain_dest', 'uid')
            );
    
    $this->source = new MigrateSourceSQL($query, array());
    
    $node_options = MigrateDestinationNode::options('en', 'cmc_editor');
    $this->destination = new MigrateDestinationNode('cmc_blog', $node_options);
    
        
    $this->map = new MigrateSQLMap($this->machineName,
                 array(
                   'nid' => array(
                     'type' => 'int',
                     'length' => 11,
                     'not null' => TRUE,
                   ),
                   'domain_src' => array(
                     'type' => 'varchar',
                     'length' => 255,
                     'not null' => TRUE,
                   ),
                 ),
                 MigrateDestinationNode::getKeySchema()
    );

    
    $mappings = array(
	    //'path' => 'path',
      'title' => 'title',
	    'created' => 'created',
	    'body' => 'body_section',
	    'field_teaser' => 'teaser',
      'field_theme' => 'taxonomy',
      'uid' => 'uid',
	    );

    foreach ($mappings as $dest => $source) {
      $this->addFieldMapping($dest, $source);
    }
    
    $formats = filter_formats();
    $filter_name = 'cmc_blog_migrate_teaser';
    if (!isset($formats[$filter_name])) {
      drupal_set_message($filter_name . ' does not exist. Please create the filter.');
    }
  }
  
  /**
   *
   */
  private function getAllDomains() {
    
    $domains = array();
    $query = db_select('domain', 'd')
      ->fields('d', array('domain_id', 'sitename', 'subdomain', 'scheme', 'valid', 'weight', 'is_default')
      );
    // Get the domains.
    $result = $query->execute();
    foreach ($result as $data) {
      $domains[] = $data;
    }
    
    $result = array();
    foreach ($domains as $i => $d) {
      $result[$d->subdomain] = $d->domain_id;
    }
    
    return $result;
  }
   
  /**
   * Hack to get the domains to be set
   * Enter description here ...
   * @param unknown_type $entity
   * @param unknown_type $source_row
   */
  public function complete(&$entity, $source_row) {
    
    $all_domains = $this->getAllDomains();
    
    $domain_dest = $all_domains[$source_row->domain_dest];
    $entity->domains = array(
     $domain_dest => $domain_dest
    );
    
    $entity->path['pathauto'] = 1;
    $entity->language = $source_row->language;
    
    $entity->domain_site = 0;
    
    $entity->uid = $source_row->uid;
    
    if ($entity->nid) {
      node_save($entity);
    }
  }
  
  
  /**
   * Add any additional data / clean up data for the current row / node that will be added/updated.
   */
  public function prepareRow(&$current_row) {
    //...
    $taxonomy_translations = array(
      'Markte' => 'Markets',
      'Unsere Produkte' => 'CMC Products',
      'Videos' => 'Videos',
      'Wirtschaft' => 'Economy',
      'Wahrung' => 'Currency',
    );
    
    if ($current_row->language == 'de' && !empty($taxonomy_translations[$current_row->taxonomy])) {
      $current_row->taxonomy = $taxonomy_translations[$current_row->taxonomy];
    }
    
    
    // strip html from the teasers here
    // assumed that we have a filter called cmc_blog_migrate_teaser
    // if not create one and set the allowed HTML filters and remove all tags
    $formats = filter_formats();
    $filter_name = 'cmc_blog_migrate_teaser';
    if (isset($formats[$filter_name])) {
      $current_row->teaser = check_markup($current_row->teaser, $filter_name);
    }
  }
}

class CmcUkBlogMigration extends CmcBlogMigration {
	/**
   * Class Constructor
   */
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Migrate CMC D6 Blog UK');
    $this->migrationSetup('blog_uk');
    
  }
}


class CmcDeBlogMigration extends CmcBlogMigration {
	/**
   * Class Constructor
   */
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Migrate CMC D6 Blog DE');
    $this->migrationSetup('blog_de');
    
  }
}

class CmcAtBlogMigration extends CmcBlogMigration {
	/**
   * Class Constructor
   */
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Migrate CMC D6 Blog AT');
    $this->migrationSetup('blog_at');
    
  }
}