<?php

/**
 * Abstract base class that provides all base methods required to build CMC Application Forms 
 */


interface AppFormInterface {
  
  /**
   * Implements settings form
   */
  function getSettingsForm($feature, AppFormConfig $AppFormConfig);
  
  /**
   * Implements settings form
   */
  function getApplicationForm($feature, AppFormConfig $AppFormConfig) ;
  
  /**
   * Preprocess function that is executed before form is displayed 
   */
  function preprocess() ;
  
  /**
   * Return Mappings that will map against fields when form is submitted 
   */
  function getMappings();
      
}

/**
 * This class shall abstract all Forms related configurations into a single object
 * that can be passed to different modules that extend AppForms for Live and Demo Account
 *  
 */
class AppFormConfig {
  
  /**
   * Contains an array of configurations for a given region
   * Multidimensional array of configurations of form
   * 
   * product1 [e.g CFD]
   * --variable1
   * --variable2
   * --variable3 
   * product2 [e.g SB]
   * --variable1
   * --variable2
   * --variable3 
   * 
   * @var type mixed
   */
  public $config;
  
  /**
   * Id of config as stored in database
   * @var type 
   */
  protected $config_id;
  
  /**
   * Machine name of the
   * @var type String 
   * @todo Do we need to store country name ? 
   */
  protected $country_name;
  
  /**
   * Machine name of the country
   * @var type String 
   */
  protected $country_machine_name;
  
  /**
   * Name of the product
   * @var type String 
   * @todo Should we also store product name ? 
   */
  protected $product_name;
  
  /**
   * Product id of the product
   * @var type 
   */
  protected $product_id;
  
  /**
   * Type of application 
   *   e.g liveRegistration, demoRegistration etc
   * @var type String
   */
  protected $application_type;
  /**
   * Constructor
   * @param null $country
   * @param null $product 
   */
  public function __construct($country_machine_name, $product_id, $application_type = CMC_APPFORMS_LIVE_REG) {
    $this->country_machine_name = $country_machine_name;
    $this->product_id = $product_id;
    $this->application_type = $application_type;      
    $this->loadAppformConfig($country_machine_name, $product_id, $application_type);
  }
  
  public function setAppFormConfig($config) {
    $this->config = $config;
  }
  
  public function getAppFormConfig() {
    return $this->config;
  }
  
  public function setCountry($country) {
    $this->country = $country;
  }
  
  public function getCountry() {
    return $this->country;
  }
  
  public function setProduct_Id($product_id) {
    $this->product_id = $product_id;
  }
  
  public function getProduct_Id() {
    return $this->product_id;
  }
  
  public function setapplication_typed($application_type) {
    $this->application_type = $application_type;
  }
  
  public function getapplication_type() {
    return $this->application_type;
  }
  
  public function setConfig($config) {
    $this->config = $config;
  }
  
  public function getConfig() {
    return $this->config;
  }
  

  /**
   * Saves current application form config to database
   * @param type $region
   * @param type $product 
   */
  public function save() {
    if (!empty($this->config_id) && (is_numeric($this->config_id))) {
      db_update('cmc_appforms_country_config')
      ->fields(array('data' => serialize($this->config)))
      ->condition('country_machine_name', $this->country_machine_name)
      ->condition('application_type', $this->application_type)
      ->condition('product', $this->product_id
      )
      ->execute();
    } 
    else {
      // Insert a new config
      db_insert('cmc_appforms_country_config')
      ->fields(array(
        'application_type' => $this->application_type,
        'country_machine_name' => $this->country_machine_name,
        'product' => $this->product_id,
        'data' => serialize($this->config),
      ))
    ->execute();
    }
  }
  
  /**
   * Load Application form config from database
   * @param type $region
   * @param type $product 
   */
  private function loadAppFormConfig($country_machine_name, $product_id, $application_type) {
    $product = $product_id;
    $config = db_select('cmc_appforms_country_config', 'afc')
          ->fields('afc')
          ->condition('country_machine_name', $country_machine_name)
          ->condition('application_type', $application_type)
          ->condition('product', $product)
          ->execute()
          ->fetchAssoc();

     if ($config) {
       $this->config_id = $config['config_id'];
       $this->config = unserialize($config['data']);      
     }
  }
}


abstract class AppForm {
  /**
   * Register a new Application Form object , Regsitred classes are used to retrieve Application Form elements when final 
   * form is built
   * @param type $className
   * @param type $arguments 
   */

  static public function registerApplicationForm($class_name, $machine_name = NULL, $arguments = array()) {
    if (!$machine_name) {
      $machine_name = self::machineFromClass($class_name);
    } 

    db_merge('cmc_application_form')
      ->key(array('machine_name' => $machine_name))
      ->fields(array(
          'class_name' => $class_name,
          'arguments' => serialize($arguments),
       ))
      ->execute();
  }
  
  /**
   * Unregister a Application Form class, mostly  used when a module is being un installed
   * @param type $machineName 
   */
  static public function unregisterApplicationForm($machine_name) {
    $deleted = db_delete('cmc_application_form')
                ->condition('machine_name', $machine_name, '=')
                ->execute();
  }
  
  /**
   * Prepare machine name for class from a given class  name
   * @param type $class_name
   * @return type 
   */
  static public function machineFromClass($class_name) {
    
    if (preg_match('/AppForm/', $class_name) && ($class_name != 'AppForm')) {
      $machine_name = substr($class_name, 0, strlen($class_name) - strlen('AppForm'));
    }
    else {
      $machine_name = $class_name;
    }
    return $machine_name;
  }  
  
 
  static public function getInstance($machine_name, $class_name = NULL, array $arguments = array()) {
    $appForms = &drupal_static(__FUNCTION__, array());
    // Otherwise might miss cache hit on case difference
    $machine_name_key = strtolower($machine_name);
    if (!isset($appForms[$machine_name_key])) {
      // Skip the query if our caller already made it
      if (!$class_name) {
        // See if we know about this migration
        $row = db_select('cmc_application_form', 'ca')
                 ->fields('ca', array('class_name', 'arguments'))
                 ->condition('machine_name', $machine_name)
                 ->execute()
                 ->fetchObject();
        if ($row) {
          $class_name = $row->class_name;
          $arguments = unserialize($row->arguments);
        }
        else {
           continue;
        }
      }
      $appForms[$machine_name_key] = new $class_name($arguments);
    }
    return $appForms[$machine_name_key];
  }
}


?>
