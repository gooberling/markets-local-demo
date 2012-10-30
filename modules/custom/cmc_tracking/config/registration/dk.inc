<?php
// This should contain extra or tracking overrides
// otherwise it should pick up the defaults
/**
 * Creating your login
 * put in overrides
 */
function cmc_tracking_registration_step1_dk() {
  return array(
    'live' => array(
      'CFD' => array(
        'google_conversion' => array(
          'id' => 'DK1056833164',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'google_conversion' => array(
          'id' => 'DK1056833164',
        ),
      ),
    ),
  );
}
