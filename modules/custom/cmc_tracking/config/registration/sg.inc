<?php
// This should contain extra or tracking overrides
// otherwise it should pick up the defaults
// SINGAPORE HAS NO SB ACCOUNTS
// Storm should be throughout the registration process

/**
 * No SB accounts
 * Overrides for completion step
 */
function cmc_tracking_registration_complete_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
          'order_id' => '',
          'email_address' => '',
        ),
        's2d6' => array(
          'page_type' => 'Live Account CFD',
          'identity' => '',
          'email_address' => '',
        ),
        'google_conversion' => array(
        	'id' => '1021045250',
        	'language' => 'en',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'Z4z5CJas8QIQgtTv5gM',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
        's2d6' => array(
          'page_type' => 'Demo Account CFD',
          'identity' => '',
          'email_address' => '',
        ),
        'google_conversion' => array(
        	'id' => '1021045250',
        	'language' => 'en',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'GxgWCJ6r8QIQgtTv5gM',
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step1_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step2_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step3_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step4_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step5_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_step6_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

/**
 */
function cmc_tracking_registration_reject_sg() {
  return array(
    'live' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Live Account CFD',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'storm' => array(
          'type' => 'Demo Account CFD'
        ),
      ),
    ),
  );
}

