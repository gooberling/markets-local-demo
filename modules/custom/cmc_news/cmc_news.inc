<?php

class NewsMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('cmc_news'));

    $this->source = new ContentServicesNewsSource(100);

    $options = MigrateDestinationNode::options('en', 'html');
    $this->destination = new MigrateDestinationNode('news', $options);

    $this->map = new MigrateSQLMap($this->machineName,
                 array(
                   'ContentID' => array(
                     'type' => 'varchar',
                     'length' => 255,
                     'not null' => TRUE,
                   ),
                   'Language' => array(
                     'type' => 'varchar',
                     'length' => 10,
                     'not null' => TRUE,
                   ),
                 ),
                 MigrateDestinationNode::getKeySchema()
    );

    $mappings =
      array(
        'title' => 'Headline',
        'body' => 'Body',
        'field_publish_date' => 'PublishDate'
      );

    foreach ($mappings as $dest => $source) {
      $this->addFieldMapping($dest, $source);
    }

    $this->addFieldMapping('field_products', 'Products')->separator(',');
  }
}

class ContentServicesNewsSource extends MigrateSource {

  protected $maxRows;
  protected $currentId;
  protected $data;

  public function __construct($max_rows = 100, $options = array()) {
    parent::__construct($options);
    $this->maxRows = $max_rows;
    $this->currentId = 0;
    $this->data = null;
  }

  public function fields() {
    return array(
      'PublishDate' => t('Publish Date'),
      'ContentID' => t('Content ID'),
      'Products' => t('Product Nids'),
      'StoryCategories' => t('Story Categories'),
      'Language' => t('Language'),
      'Headline' => t('Headline'),
      'ContentBody' => t('Body')
    );
  }

  public function performRewind() {
    if (is_array($this->data)) {
      reset($this->data);
    }
  }

  public function getNextRow() {
    if (!is_array($this->data)) {
      $this->getData();
      reset($this->data);
    }

    $val = current($this->data);
    next($this->data);
    return $val ? $this->prepareObject($val) : NULL;
  }

  protected function prepareObject($story) {
    $result = array(
      'Headline' => $story['Headline']['NewsHeadline'],
      'ContentID'=> $story['ContentID'],
      'Language' => $story['ContentMetaData']['Language'],
      'Body' => $story['Body'],
      'Products' => $story['Products'],
      'PublishDate' => $story['PublishDate'] / 1000
    );
    //    var_dump($result);
    return (object)$result;
  }

  protected function getData() {
    if (empty($this->data)) {
      $this->data = $this->getNews();
    }
    //    var_dump($this->data);
    return $this->data;
  }

  protected function getStartTime() {
    $default = strtotime('-7 days') * 1000;
    return $default;
    return variable_get('cmc_news_latest', $default);
  }

  protected function getStories() {
    $request = new GetContentRequest();
    $filter = new ContentFilter();
    $filter
      ->setSourceTypes("DOWJONES")
      ->setContentTypes("NEWS")
      ->setNumberOfItems($this->maxRows)
      ->setContentStart($this->getStartTime())
      ->setLanguage('en-US');
    $request->setContentFilter($filter);

    $stories = array();

    try {
      $response = nextgen_call($request);
      $stories = $response->getContentsList();
      variable_set('cmc_news_latest', time() * 1000);
    } catch (NextgenException $e) {
      //      drupal_set_message(var_export($e, TRUE));
    }

    return $stories;
  }

  protected function enrichStories($stories) {
    $enrichedStories = array();
    foreach ($stories as $story) {
      $enrichedStories[$story->getContentID()] = $story->toData();
    }

    $request = new GetContentItemRequest();
    $request->setContentIDsList(array_keys($enrichedStories));

    try {
      $response = nextgen_call($request);

      foreach ($response->getContentBodiesList() as $body) {
        $enrichedStories[$body->getContentID()]['Body'] = $body->getContentBody();
      }

    }
    catch (NextgenException $e) {
      //      drupal_set_message(var_export($e, TRUE));
    }

    foreach ($enrichedStories as &$story) {
      $keys = array();
      foreach ($story['ContentMetaData']['ProductKeysList'] as $key) {
        if ($key['InstrumentCode']) {
          $keys[] = $key['InstrumentCode'];
        }
      }

      if (count($keys)) {
        $story['Products'] = implode(',', $this->productNids($keys));
      } else {
        $story['Products'] = NULL;
      }
    }


    return $enrichedStories;
  }

  protected function productNids($titles) {
    $query = Database::getConnection('default', 'default')
      ->select('field_data_field_instrument_code', 'f')
      ->fields('f', array('entity_id'))
      ->condition('field_instrument_code_value', $titles, 'IN')
      ->condition('bundle', 'product', '=');

    $result = $query->execute()->fetchAll();

    $ids = array();

    foreach ($result as $r) {
      $ids[] = $r->entity_id;
    }

    return $ids;
  }

  protected function getNews() {
    $stories = $this->enrichStories($this->getStories());
    //    drupal_set_message(var_export($stories, TRUE));
    return $stories;
  }

  public function computeCount() {
    return count($this->getStories());
  }

  public function __toString() {
    return 'cmc-news-migration';
  }
}
