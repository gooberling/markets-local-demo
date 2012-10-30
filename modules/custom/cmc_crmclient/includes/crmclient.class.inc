<?php
/**
 * Contains all helper functions required by cmc_crmclient module
 * 
 **/

/*
 * Name of queue that shall be used as store for unprocessed applications
 */
define('LIVE_APPLICATION_QUEUE', 'cmc_live_applications');

class CrmSoapClient   {
  public $connection;
  
  public function __construct() {
    return ;
  }
  
  /**
   * Submit application to backend queue 
   */
  public function submitApplication() {
    if(1==2 ) {
    } 
    else {
      $this->addToQueue(LIVE_APPLICATION_QUEUE, $application);
    }
  }
  
  /**
   * Process pending queue 
   */
  public function processQueue() {
    
  }
  
  public function setClassMap($mappings) {
    $this->classmap  = $mappings;
  }

  /**
   * Establish connection to Pega CRM 
   */
  public function connect () {
    ini_set("soap.wsdl_cache_enabled", "0");
    
    $soapOptions = array(
      'soap_version'=>SOAP_1_2, 
      'trace' => 1,
      'keep_alive' => true,
      'cache_wsdl' => WSDL_CACHE_NONE,
      'login' => 'OnboardingService',
      'password' => 'rules',
      'classmap' => array(
          'ApplicationForm' => 'CrmApplicationForm',
          'RequestType' => 'RequestType',
          'PersonalDetails' => 'PersonalDetails',
          'Address' => 'Address',
          'BankDetails' => 'BankDetails',
          'IdentificationDetails' => 'IdentificationDetails',
          'FinancialDetails' => 'FinancialDetails',
          'CodeValuePair' => 'CodeValuePair',
          'TradingRelevantExperience' => 'TradingRelevantExperience',
          'UnderstandingOfTheFeaturesAndRisks' => 'UnderstandingOfTheFeaturesAndRisks',
          'LegalAgreement' => 'LegalAgreement',
          'Identity' => 'Identity',
      ),
    );
   
    try {
      $this->connection = new SoapClient(drupal_get_path('module', 'cmc_crmclient') ."/includes/ProcessApplication.wsdl", $soapOptions); 
     // print_r($this->connection->__getTypes());
    } 
    catch (Exception $e) {
      print_r($e);
 
     // print_r($e);
      die();
    }
  }
  
    
  /**
   * Add an item to queue to be processed later
   * @param type $queue_name
   * @param type $data
   * @return type 
   */
  function addToQueue($queue_name, $data) {
    $queue = DrupalQueue::get($queue_name);
    $queue->createQueue(); // no harm in trying to recreate existing queue, Will queue if it exists or create a new one

    $queue->createItem($data);
    $count = $queue->numberOfItems();
    return("Current Application Queue has {$count} applications waiting to be processed");
  }
}