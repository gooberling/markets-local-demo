<?php
// This should contain extra or tracking overrides
// otherwise it should pick up the defaults
/**
 * No SB accounts
 * Overrides for completion step
 * Spreadbet and CFD google adwords conversions use the same tag
 */
function cmc_tracking_registration_complete_uk() {
  return array(
    'live' => array(
      'CFD' => array(
        'adcenter' => array(
          'site_id' => '15c3f909-95a4-4b5c-8c9d-69dc8bdbb347',
          'domain_id' => '1306957',
          'action_id' => '48704',
        ),
      	'google_conversion' => array(
          array( // SB live account conversion
          	'id' => '1056833164',
          	'language' => 'en',
          	'format' => '2',
          	'color' => 'ffffff',
          	'label' => 'z7S0COzn0wEQjP339wM',
          ),
          array( // live account conversion
          	'id' => '1017053788',
          	'language' => 'en',
          	'format' => '2',
          	'color' => 'ffffff',
          	'label' => 'AntmCJTmsAIQ3IT85AM',
            'value' => '1',
          ),
          array( // mobile conversion
          	'id' => '991494912',
          	'language' => 'en',
          	'format' => '2',
          	'color' => 'ffffff',
          	'label' => 'Spl2CIiI5AMQgIbk2AM',
          ),
        ),
      ),
      'SB' => array(
        'adcenter' => array(
          'site_id' => '15c3f909-95a4-4b5c-8c9d-69dc8bdbb347',
          'domain_id' => '1306957',
          'action_id' => '48704',
        ),
      	'google_conversion' => array(
          array( // SB live account conversion
          	'id' => '1056833164',
          	'language' => 'en',
          	'format' => '2',
          	'color' => 'ffffff',
          	'label' => 'z7S0COzn0wEQjP339wM',
          ),
          array( // live account conversion
          	'id' => '1017053788',
          	'language' => 'en',
          	'format' => '2',
          	'color' => 'ffffff',
          	'label' => 'AntmCJTmsAIQ3IT85AM',
            'value' => '1',
          ),
          array( // mobile conversion
          	'id' => '991494912',
          	'language' => 'en',
          	'format' => '2',
          	'color' => 'ffffff',
          	'label' => 'Spl2CIiI5AMQgIbk2AM',
          ),
        ),
      ),
    ),
  );
}