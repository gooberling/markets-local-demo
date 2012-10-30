<?php

  /**
   * This is the main controller class that builds relevant form based on which region user
   * is on.
   */
class cmc_registration_controller {

  /**
   * @var string
   * product for which user is signing up for. Possible options SB/CFD
   */
  public $product;

  /**
   * @var integer
   * Type of applicaiton, Demo / Live account
   */
  public $form_type;

  /**
   * machine name of the regional site that user is registering for, has default of
   * 'default' representing UK
   * @var type
   */
  public $region;

  /**
   * Holds region info including callback, path to language file etc
   * @var mixed
   */
  public $all_regions_info;

  /**
   * Holds region info including callback, path to language file etc
   * @var mixed
   */
  public $region_info;

  /**
   * All regions that are found in the system
   * @var type
   */
  public $all_regions;

  /**
   * Steps in current application process
   * @var type
   */
  public  $steps;


  /**
   * Create a set of all default steps, this is used when steps are to be overridden
   * by default steps
   * @var type
   */
  public $default_steps;


  /**
   * Steps in current application process
   * @var type
   */
  public  $current_step;


  /**
   * Name of company as used in region
   * @var type
   */
  public $company_name;

  /**
   *
   * @param type $region
   */
  function __construct($form_state, $form_type, $product) {

    // setup all configuration variables
    $this->product = $product;
    $this->form_type = $form_type;

    // Region forms are currently associated with. Default is 'default' which is also for UK
    $this->region = variable_get('cmc_registration_region', 'default');
    $this->form_type = $form_type;


    // Get a list of all regions found within forms
    $this->all_regions = self::cmc_registration_regions();

    // Retrieve information related to each region, although we only need to know
    // current region information, we prepare the list and statically cache info
    $this->all_regions_info = self::cmc_registration_regions_info();

    // Prepare current region info

    $this->region_info = $this->all_regions_info[$this->region];

    // Find list of all steps associated with current region

    $this->default_steps = $this->steps_info(CMC_REGISTRATION_DEFAULT);
    $this->steps = $this->steps_info($this->region);

    if (isset($form_state['step'])) {

      $this->current_step  = $form_state['step'];
      $this->steps[$this->current_step]['active'] = TRUE;
    }

    if ($product == CMC_REGISTRATION_PRODUCT_CFD) {
      $this->company = CMC_REGISTRATION_COMPANY_NAME_CFD;
    } else if ($product == CMC_REGISTRATION_PRODUCT_SB) {
      $this->company = CMC_REGISTRATION_COMPANY_NAME_SB;
    }
  }


  function set_currentstep($step) {
    $this->current_step = $step;
    $this->steps[$this->current_step]['active'] = TRUE;
  }

  /**
   * Returns array of all steps within a given form
   * @return boolean
   */
  private static function cmc_registration_regions() {
    $dir = drupal_get_path('module', 'cmc_registration') ."/forms";
    $mask = "/^[a-zA-Z0-9-_]*_cmc_registration.inc$/";
    $files = file_scan_directory($dir, $mask, array('min_depth' => 1));

    if (!$files) return false;
    // Get all the files that end with cmc_registration.inc
    foreach($files as $file) {
      $hook = cmc_registration_get_region_hook($file->filename);
      $regions[$hook] = array(
        'hook' => $hook,
        'filename' => basename($file->uri),
        'uri' => $file->uri,
        'path' => dirname($file->uri),
      );
    }

    return $regions;
  }



  /***
   * Builds information of all the steps for a given region
   */
  private function steps_info($region = false) {

    $region = ($region) ? $region : $this->region;
    $region_info =  $this->all_regions_info[$region];

    $func = $region_info['form_type'][$this->form_type]['steps'];
    if (function_exists($func)) {
      $step_info = call_user_func($func);
    }
    // Check if any of the steps is set to use default steps, and we only use this step
    // if current region is not default region

    if ($region != CMC_REGISTRATION_DEFAULT) {
      foreach($step_info as $step => $item) {
        if(isset($step) && empty($item['form'])) {

          // Step is set an empty array so use default
          // Also merge if any elements that have been defined for regions with default
          // e.g Region might not define separate form for each step, but could define context
          // for text elements.
          // Language context should always be the current region even if it uses default.
        //  unset($this->default_steps[$step]['language']);
          $step_info[$step] = array_merge($this->default_steps[$step], $step_info[$step] );


          //A part from knowing which region user is currently on, we also
          // need to know if this step is being used from default
          $step_info[$step]['is_default'] = TRUE;
        }
        else {
          $step_info[$step]['is_default'] = FALSE;
        }
      }
    }

    return $step_info;
  }

  /**
   * Return a list of steps for a given region,
   * If region is not provided returns default steps
   */
  public static function cmc_registration_steps($region, $reg_type = CMC_REGISTRATION_DEMO) {
    //statically cache region_info so that it can be used in future. We will need
    // region_info throughout the form process.
    $steps = &drupal_static(__FUNCTION__);

    if(!empty($steps)) return $steps;
    $regions = self::cmc_registration_regions_info();

    $region_info = isset($regions[$region])? $regions[$region] : FALSE;
    if(!$region_info) return FALSE;

    if( isset($region_info['form_type'][$reg_type]['steps'])) {
      $callback = $region_info['form_type'][$reg_type]['steps'];

      if(function_exists($callback)) {
        $steps = call_user_func($callback) ;
      }
    }
    return $steps;
  }


  /**
   * Return a list of regions that are available in the system
   * Each region is recognized by having a file with filename <region>_cmc_registration_region.inc
   *
   * Each distinct region will need to implment _info() hook that tells registration
   * forms
   * of the following informatino
   */
  public static function cmc_registration_regions_info() {

    //statically cache region_info so that it can be used in future. We will need
    // region_info throughout the form process.

    //  $all_regions_info = &drupal_static(__FUNCTION__);
    foreach (self::cmc_registration_regions() as $key => $item ) {
      $hook = $item['hook'];
      $function = "{$hook}_cmc_registration_region_info";

      require_once($item['uri']);
      if (function_exists($function)) {
        $all_regions_info[$hook] = call_user_func($function);
        $all_regions_info[$hook]['base_path'] = $item['path'];
      }
    }
    return $all_regions_info;
  }

  /**
   * This function builds required form elements, what it does not do is setup submit handlers
   * which needs to be done at a later date.
   * @param type $form_id
   * @param type $form_state
   * @return type
   */
  function build_form($form_id, &$form_state) {
    /**
       This is very complicated, either because Form API sucks or because I'm an idiot.
       Basically, if there's a 'token' parameter on the query string, we try to verify this token for session
       transfer.  If this succeeds, we take the user to step 2.
    */
   // register_shutdown_function('cmc_registration_forms_shutdown');

    $form = array();
    if (empty($form_state['step'])) {

      $form_state['step'] = 1;
      $form_state['step_info'] = $this->steps;

      if (!isset($form_state['identity']) && (count($form_state['input']) == 0)) { // no input, so this is the first-time visit
        $key = &drupal_static('cmc_registration_live_identity', FALSE);
        if (isset($_GET['token'])) {
          if ($key = CMCApplication::verifySession($_GET['token'])) {
            // we got an identity, skip step 1
            $form_state['step'] = 2;
            // If step one is being skipped initialize sessions for step2
            cmc_registration_initialize_sessions();
          }
        }

        // if we didn't just get an identity from a session transfer, go to step 1
        if (!$key) {
          if (isset($_GET['token'])) { // forcibly forget the token
            unset($_GET['token']);
            cmc_registration_goto($_GET['q']);
            return;
          }
          $form_state['step'] = 1;
        }
      }
      elseif (isset($_GET['token'])) {
        $form_state['step'] = 2;
      }

      $this->current_step = $form_state['step'];
      $this->steps[$this->current_step]['active'] = TRUE;
    }

    // check if a session exists, if the form is in step 1, start a new session.
    if($form_state['step'] == 1) {
      cmc_registration_initialize_sessions();
    }
    else if (empty($_SESSION['application_id'])) {
      cmc_registration_goto(request_path());
    }

    if (isset($form_state['step_info'][$this->current_step]['stored_values'])) {
      $form_state['values'] = $form_state['step_info'][$this->current_step]['stored_values'];
    }

    //Store step in static variable, we will use this in theming layer
    $form_step = &drupal_static('cmc_registation_form_step', FALSE);
    $form_step = "step-" .$this->current_step;

    $context = array('context' => CMC_REGISTRATION_CONTEXT_GLOBAL);

    $step = &$form_state['step'];
    $this->current_step = $step;
    $this->steps[$this->current_step]['active'] = TRUE;

    if ($this->steps && !empty($this->steps[$this->current_step])) {
      $func = $this->steps[$this->current_step]['form'];

      if ((count($form_state['input']) == 0) && isset($this->steps[$this->current_step]['no_cache'])) {
        drupal_add_http_header('Pragma', 'no-cache');
        drupal_add_http_header('Cache-Control', 's-maxage=0, max-age=0, no-store, no-cache, must-revalidate, post-check=0, pre-check=0');
        drupal_add_http_header('Expires', 'Sun, 19 Nov 1978 05:00:00 GMT');
      }

      // Prepare Language file that has copy text for titles and descriptions
      // of each fields
      $language_text = $this->get_language_text($this->steps[$this->current_step]);

      // If form step is defined in a seperate file, include the file
      if (isset($this->steps[$this->current_step]['file'])) {
        $relative_path = (isset($this->steps[$this->current_step]['is_default']) &&
                         ($this->steps[$this->current_step]['is_default'] ==  TRUE)) ? CMC_REGISTRATION_DEFAULT : $this->region;
        form_load_include($form_state, 'inc', 'cmc_registration', '/forms/' .$relative_path .'/' .$this->steps[$this->current_step]['file']);
      }

      // There are two files that are to be made available to form loader
      // 1. File that holds form elements
      // 2. original <hook>_cmc_registration.inc , This is important as once form is built
      //    form builder extracts form_state directly from form cache and does not go through
      //    all the steps of form builder, what this means is in _validate functions
      //    <hook>_cmc_registrtion.inc is not included  by default thus resulting in
      //    undefined function error
      // 3. If region uses default region then is_default flag is set to true and include default_registration.inc
      //    throughout the form process


      if (isset($this->steps[$this->current_step]['is_default']) && ($this->steps[$this->current_step]['is_default'])) {
        $file =  "default_cmc_registration";
        form_load_include($form_state, 'inc', 'cmc_registration', 'forms/default/' .$file);
      } else {
        $file = $this->region_info['prefix'] ."cmc_registration";
        form_load_include($form_state, 'inc', 'cmc_registration', '/forms/' .$this->region .'/' .$file);
      }


      // Before we call form builder we prepare options array which includes
      // language text, context, produt
      $options = array(
        'language_text' => $language_text,
        'context' => $this->get_context(),
        'product' => $this->product
      );

      $form = call_user_func($func, $form_id, $form_state, $options);

      // Now that we have form with us, lets prepare title of the form and teaser
      // text for the form step
      if (function_exists($this->steps[$this->current_step]['teaser'])) {
        $teaser = call_user_func($this->steps[$this->current_step]['teaser'], $form_state, $options );
      }
      else {
        $teaser = $this->steps[$this->current_step]['teaser'];
      }

      $subheading = t($teaser, array(), $context);
      $form['#prefix'] = theme('cmc_registration_subheading', array('subheading' => $subheading));
    }

    foreach($this->steps as $id => &$step) {
      if (!empty($step['title callback']) && function_exists($step['title callback'])) {
        $title = call_user_func($step['title callback'], $form_state, $options);
        $step['title'] = t($title);
      }

      if(isset($form_state['step_info'][$id]['complete']) && ($id != $this->current_step)) {
        $this->steps[$id]['complete'] = $form_state['step_info'][$id]['complete'];
      }
    }

    $form_elements = $this->prepare_nav();

    $this->prepare_buttons($form, $form_state);
    $form = array_merge($form_elements, $form);
    $form['#prefix'] = theme('cmc_registration_subheading', array('subheading' => $subheading));

    // Allow other systems to hook into registration form. hook_cmc_registration_form_alter
    $t = array('step' => $this->current_step,'context' => $this->steps[$this->current_step]);
    drupal_alter('cmc_registration_form', $form, $form_state, $t);

    // Attach Javascript files
    $js = drupal_get_path('module', 'cmc_registration') . '/js/registration.validator.js';
    drupal_add_js($js);

    $js = drupal_get_path('module', 'cmc_registration') . '/js/registration.misc.js';
    drupal_add_js($js);

    //Hacky needs to be removed at some stage. Basically we are not to allow customers from using
    // Umlaut and other special characters that cannot be encoded correctly when data is transfered
    // between PHP and Java
    drupal_add_js(drupal_get_path('module', 'cmc_registration') . '/js/registration.umlaut.js',
    array(
      'type' => 'file',
      'group' => JS_LIBRARY,
      'every_page' => TRUE
    )
  );

    return $form;
  }

  /**
   * Returns context Id that is to be used with translation
   * @param type $language_element
   * @return type
   */
  private function get_context_id($language_element) {
    if (isset($language_element['context'])) {
      return $this->region .'-' .$language_element['context'];
    }
  }

  /**
   * Gets language text
   */
  private function get_language_text($step) {
    $langauge_text = false;
    $file_path = false;
    $language_text = false;

    if(isset($step['language']['file']) && !empty($step['language']['file']))
      $file_path = drupal_get_path('module', 'cmc_registration') ."/forms/" .$this->region ."/language/" .$step['language']['file'];

    // We are having to do this job second time as we are not sure if
    // the default region does not have a associated language file

    if ( ($file_path) && file_exists($file_path)) {
      $language_text = drupal_parse_info_file($file_path);
    }
    return ($language_text);
  }

  /**
   * prepares Previous & Next buttons for the form. We check to see if there
   * are any associated submit handlers with each of the step.
   *
   * - If a step is not defined as final step and has a submit handler, form gets
   *   multiple submit handlers as below
   *   - submit handler defined in step is attached to form,
   *   - cmc_registration_live_next_submit is attached
   *
   * - If a step does not have associated submit handlers and is not defined as
   *   final step
   *   - cmc_registration_live_next_submit is attached
   *
   * - If a step is defined as final and has submit handler then defined submit
   *   handler is attached to the form
   *
   * - If a step is defined as final and has not submit handler attached then
   *   cmc_registration_live_final_submit
   *
   * @param type $form
   * @param type $form_state
   */
  function prepare_buttons(&$form, &$form_state) {
    $submit_handlers = array();
    $validate_handler = array();

    if ($this->current_step > 1) {
      if (isset($key) && ($key) && ($step == 2) && ($_GET['token'])) {
        if(isset($_SERVER['HTTP_REFERER']) && !empty($_SERVER['HTTP_REFERER'])) {
          l('Previous', $_SERVER['HTTP_REFERER'] .strtoupper($product),
                  array('attributes' => array('class' => 'previous')));
        }
        else {
          $previous = l('Previous',"registration/" .strtoupper($product),
                  array('attributes' => array('class' => 'previous')));
        }

        $form['prev'] = array(
          '#type' => 'markup',
          '#markup' => $previous,
        );
      }
      else {
        $previous = (isset($this->steps[$this->current_step]['previous']) &&
                    ($this->steps[$this->current_step]['previous'] == FALSE))? FALSE : TRUE;

        if ($previous) {
          $form['prev'] = array(
            '#type' => 'submit',
            '#value' => t('Previous'),
            '#name' => 'prev',
            '#submit' => array('cmc_registration_live_previous_submit'),
            '#limit_validation_errors' => array(),
            '#validate' => array('cmc_registration_live_previous_submit')
          );
        } else if (isset($this->steps[$this->current_step]['exit'])) {
          $form['exit'] = array(
            '#type' => 'submit',
            '#value' => t('Exit'),
            '#name' => 'exit',
            '#submit' => array('cmc_registration_live_exit')
          );
        }
      }
    }

    // Include each validation function defined for the different steps.
    if (function_exists($this->steps[$this->current_step]['form'] . '_validate')) {
      $validate_handler[] = $this->steps[$this->current_step]['form'] . '_validate';
    }

    //  // Show the Next button only if there are more steps defined.
    if (array_key_exists($this->current_step + 1, $this->steps)) {
      // The Next button should be included on every step
      $next_label = isset($this->steps[$this->current_step]['next']) ?
      $this->steps[$this->current_step]['next'] : t('Next');

      $form['next'] = array(
        '#type' => 'submit',
        '#value' => $next_label,
        '#name' => 'next',
        '#submit' => array('cmc_registration_live_next_submit'),
      );

      // Include each validation function defined for the different steps.
      $validator = $this->steps[$this->current_step]['form'] . '_validate';
      $validators = array('cmc_registration_live_next_submit');

      if (function_exists($validator)) {
        $validators[] = $validator;
      }

      $form['next']['#validate'] = $validators;

    }
    else {
      // Just in case there are no more steps, we use the default submit handler
      // of the form wizard. Call this button Finish, Submit, or whatever you
      // want to show. When this button is clicked, the
      // cmc_registration_live_form_submit handler will be called.

      // By default this button should be disabled by setting '#disabled' property
      // to TRUE, Setting disable propety to true results in submit handler not being
      // associated with button. This seems to be a bug that needs fixing in core.
      // Hence we use jquery to explictly enable / disable submit button see /js/registration.validator.js

      $submit_handlers[] = (!empty($this->steps[$this->current_step]['submit'])) ?  $this->steps[$this->current_step]['submit'] : 'cmc_registration_live_final_submit';
      $context = array('context' => CMC_REGISTRATION_CONTEXT_STEP5);
      $form['finish'] = array(
        '#type' => 'submit',
        '#value' => t('Finish'),
        '#validate' => !empty($validate_handler) ? $validate_handler : array(), // We submit empty array as FAPI tries to execute false and bombs
        '#submit' => $submit_handlers,
      );
    }
  }

  /**
   * Prepares left navigaton representing steps of the application
   */
  function prepare_nav() {
    $items = array();
    foreach($this->steps as $id => $step) {
      if(!isset($step['nav hide']) || ($id == $this->current_step)) {
        $items[$id] = $step;
      }
    }
    $form_elements = array('steps' => array('#markup' => theme('cmc_registration_steps', array('steps' => $items))),
                     'title' => array('#markup' => '<h2>' . $this->steps[$this->current_step]['title'] . '</h2>')
    );

    return $form_elements;
  }

  function get_context() {
    $context = (!empty($this->steps[$this->current_step]['language'])) ? $this->steps[$this->current_step]['language']['context'] .'-' . $this->product : FALSE;
    return $context;
  }
}
