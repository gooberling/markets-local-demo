<?php
// This should contain extra or tracking overrides
// otherwise it should pick up the defaults
/**
 * No SB accounts
 * Overrides for completion step
 * CFD google adwords conversions
 */
function cmc_tracking_registration_complete_at() {
  return array(
    'live' => array(
      'CFD' => array(
        'google_conversion' => array(
        	'id' => '1060326479',
        	'language' => 'de',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'HHToCMmdiAIQz5jN-QM',
          'value' => '0',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'google_conversion' => array(
        	'id' => '1060326479',
        	'language' => 'de',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'S5BHCNGciAIQz5jN-QM',
          'value' => '0',
        ),
      ),
    ),
  );
}