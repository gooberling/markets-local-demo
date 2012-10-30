<?php
// This should contain extra or tracking overrides
// otherwise it should pick up the defaults
// AU HAS NO SB ACCOUNTS
/**
 * Creating your login
 * put in overrides
 */
function cmc_tracking_registration_step1_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174705',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'f9t7COTGwAIQrLiG_wM',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174713',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'SNiqCPTEwAIQrLiG_wM',
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step2_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174706',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'peooCNzHwAIQrLiG_wM',
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step3_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174707',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'jg3jCNTIwAIQrLiG_wM',
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step4_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174708',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'vxIICMzJwAIQrLiG_wM',
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step5_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174709',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'Y2U4CMTKwAIQrLiG_wM',
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step6_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174710',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'i3iqCLzLwAIQrLiG_wM',
        ),
      ),
    ),
  );
}

/**
 * Reject step!
 */
function cmc_tracking_registration_reject_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=178153',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'gFKcCISUxAIQrLiG_wM',
          'value' => '0',
        ),
      ),
    ),
  );
}



/**
 * No SB accounts
 * Overrides for completion step
 */
function cmc_tracking_registration_complete_au() {
  return array(
    'live' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174711',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'V-LMCOzFwAIQrLiG_wM',
          'value' => '10',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'eyeblaster' => array(
          'activity' => 'ActivityID=174704',
        ),
        'google_conversion' => array(
        	'id' => '1071750188',
        	'language' => 'en',
        	'format' => '3',
        	'color' => 'ffffff',
        	'label' => 'Gu60CPzDwAIQrLiG_wM',
          'value' => '10',
        ),
      ),
    ),
  );
}