<?php
// This should contain extra or tracking overrides
// otherwise it should pick up the defaults
/**
 * No SB accounts
 * Overrides for completion step
 * CFD google adwords conversions
 */
function cmc_tracking_registration_complete_de() {
  return array(
    'live' => array(
      'CFD' => array(
        'google_conversion' => array(
        	'id' => '1065656044',
        	'language' => 'de',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'hE0kCLSH_AEQ7L2S_AM',
          'value' => '10',
        ),
      ),
    ),
    'demo' => array(
      'CFD' => array(
        'google_conversion' => array(
        	'id' => '1065656044',
        	'language' => 'de',
        	'format' => '2',
        	'color' => 'ffffff',
        	'label' => 'RGxGCLyG_AEQ7L2S_AM',
          'value' => '0',
        ),
      ),
    ),
  );
}