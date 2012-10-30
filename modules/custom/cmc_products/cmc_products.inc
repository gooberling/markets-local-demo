<?php


class ProductMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('cmc_products'));

    //  $this->systemOfRecord = Migration::DESTINATION;

    $query = Database::getConnection('default', 'pmdata')
      ->select('pmdata_processed', 'p')
      ->fields('p', array('InstrumentCode', 'LanguageId', 'NameShort', 'InstrumentDescription',
          'Background', 'InfluencingFactors', 'InstrumentCountry', 'Currency', 'Region', 'Subtype',
          'InstrumentType', 'MaxOrdersizeCFDAUD', 'MaxOrdersizeCFDEUR', 'MaxOrdersizeCFDGBP',
          'MaxOrdersizeCFDSGD', 'MaxOrdersizeCFDUnit', 'MaxOrdersizeSBEUR', 'MaxOrdersizeSBGBP',
          'MaxFinancingCFD', 'MaxFinancingCFDSG', 'MaxFinancingSB', 'IsShortingCFD', 'IsShortingSB',
          'IsTradableSB', 'IsTradableCFD', 'PointMultiplier'
        ))
      ->condition('LanguageId', 1, '=');

    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationNode('product');

    $this->map = new MigrateSQLMap($this->machineName,
                 array(
                   'instrumentcode' => array(
                     'type' => 'varchar',
                     'length' => 25,
                     'not null' => TRUE,
                   ),
                   'languageid' => array(
                     'type' => 'int',
                     'size' => 'normal',
                     'not null' => TRUE,
                   ),
                 ),
                 MigrateDestinationNode::getKeySchema()
    );

    $mappings =
      array(
	    'title' => 'nameshort',
	    'body' => 'instrumentdescription',
	    'field_instrument_code' => 'instrumentcode',
	    'field_background' => 'background',
	    'field_influencing_factors' => 'influencingfactors',
	    'field_currency' => 'currency',
	    'field_country' => 'instrumentcountry',
	    'field_region' => 'region',
	    'field_sector' => 'subtype',
	    'field_instrument_type' => 'instrumenttype',
            'field_max_order_size_cfd_aud' => 'maxordersizecfdaud',
            'field_max_order_size_cfd_eur' => 'maxordersizecfdeur',
            'field_max_order_size_cfd_gbp' => 'maxordersizecfdgbp',
            'field_max_order_size_cfd_sgd' => 'maxordersizecfdsgd',
            'field_max_order_size_cfd_unit' => 'maxordersizecfdunit',
            'field_max_order_size_sb_eur' => 'maxordersizesbeur',
            'field_max_order_size_sb_gbp' => 'maxordersizesbgbp',
            'field_max_financing_cfd' => 'maxfinancingcfd',
            'field_max_financing_cfd_sg' => 'maxfinancingcfdsg',
            'field_max_financing_sb' => 'maxfinancingsb',
            'field_is_shorting_cfd' => 'isshortingcfd',
            'field_is_shorting_sb' => 'isshortingsb',
            'field_is_tradable_sb' => 'istradablesb',
            'field_is_tradable_cfd' => 'istradablecfd',
            'field_trading_hours' => 'tradinghours',
            'field_point_multiplier' => 'pointmultiplier'
	    );

    foreach ($mappings as $dest => $source) {
      $this->addFieldMapping($dest, $source);
    }

  }

  /*  public function prepareRow($row) {
        $query = Database::getConnection('default', 'sourcecontent')
      ->select('markettradingdetails', 'm')
      ->fields('m', array(
          'StartDay', 'StartTime', 'EndDay', 'EndTime', 'StartDate', 'EndDate', 'TimeZone'
        ))
      //      ->condition('ValidFrom', 'NOW()', '>')
      //      ->condition('ValidTo', 'NOW()', '<')
      ->condition('InstrumentCode', $row->instrumentcode, '=')
      //  ->condition('TimeZoneCode', 'UTC', '=')
      ->orderBy('StartDate', 'ASC')
      ->orderBy('StartTime', 'ASC');

    $result = $query->execute();

    $times = array();
    foreach ($result->fetchAll() as $time) {
      if ($time->startday != $time->endday) {
        $time_copy = clone $time;
        $time_copy->endtime = '00:00:00';
        $times[$time->timezone][$time->startdate][] = $time_copy;

        $time->startdate = $time->enddate;
        $time->startday = $time->endday;
        $time->starttime = '00:00:00';

        $times[$time->timezone][$time->startdate][] = $time;
      } else {
        $times[$time->timezone][$time->startdate][] = $time;
      }
    }

    $value = json_encode($times);

    $row->tradinghours = $value;
    return $row;
  }
  */
}

abstract class ProductTermMigration extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('cmc_products'));

    $query = Database::getConnection('default', 'pmdata')
      ->select('pmdata_processed', 'p')
      ->fields('p', array($this->termField, 'LanguageId'))
      ->condition('LanguageId', $this->languageId, '=')
      ->distinct();

    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationTerm($this->vocabName);

    $term_field_lower = strtolower($this->termField);

    $this->map = new MigrateSQLMap($this->machineName,
                 array(
                   $term_field_lower => array(
                     'type' => 'varchar',
                     'length' => 100,
                     'not null' => TRUE,
                   ),
                   'languageid' => array(
                     'type' => 'int',
                     'size' => 'normal',
                     'not null' => TRUE,
                   ),
                 ),
                 MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('name', $term_field_lower);
  }
}

class EnCountryTermMigration extends ProductTermMigration {
  var $termField = 'InstrumentCountry';
  var $languageId = '1';
  var $vocabName = 'country';
}

class EnRegionTermMigration extends ProductTermMigration {
  var $termField = 'Region';
  var $languageId = '1';
  var $vocabName = 'region';
}

class EnTypeTermMigration extends ProductTermMigration {
  var $termField = 'InstrumentType';
  var $languageId = '1';
  var $vocabName = 'instrument_type';
}

class EnSectorTermMigration extends ProductTermMigration {
  var $termField = 'Subtype';
  var $languageId = '1';
  var $vocabName = 'sector';
}
