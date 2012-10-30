<?php
/**
 *
 * Default is UK
 */
function cmc_tracking_registration_step1() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_start',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_start',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_START',
          'page_name' => 'SB_LIVE_START',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_start',
          'demo_to_live' => 'cfd/demo_to_live_signup_start',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_START',
          'page_name' => 'CFD_LIVE_START',
        ),
      ),
    ),
    'demo' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/demo_signup_start',
          'demo_to_live' => 'spreadbet/live_to_demo_signup_start',
        ),
        'adform' => array(
          'sale_value' => '50',
          'tracking_division' => 'SB_DEMO_START',
        	'page_name' => 'SB_DEMO_START',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/demo_signup_start',
          'demo_to_live' => 'cfd/live_to_demo_signup_start',
        ),
        'adform' => array(
          'sale_value' => '50',
          'tracking_division' => 'CFD_DEMO_START',
          'page_name' => 'CFD_DEMO_START',
        ),
      ),
    ),
  );
}





/**
 * Understanding the risks
 */
function cmc_tracking_registration_step2() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_risks',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_risks',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_RISKS',
          'page_name' => 'SB_LIVE_RISKS',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_risks',
          'demo_to_live' => 'cfd/demo_to_live_signup_risks',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_RISKS',
          'page_name' => 'CFD_LIVE_RISKS',
        ),
      ),
    ),
  );
}




/**
 * Understanding the risks
 */
function cmc_tracking_registration_step3() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_1_about_you',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_1_about_you',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_ABOUT',
          'page_name' => 'SB_LIVE_ABOUT',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_1_about_you',
          'demo_to_live' => 'cfd/demo_to_live_signup_1_about_you',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_ABOUT',
          'page_name' => 'CFD_LIVE_ABOUT',
        ),
      ),
    ),
  );
}


/**
 * Financial Background
 */
function cmc_tracking_registration_step4() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_2_financial_background',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_2_financial_background',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_FINANCIAL',
          'page_name' => 'SB_LIVE_FINANCIAL',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_2_financial_background',
          'demo_to_live' => 'cfd/demo_to_live_signup_2_financial_background',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_FINANCIAL',
          'page_name' => 'CFD_LIVE_FINANCIAL',
        ),
      ),
    ),
  );
}

/**
 * Agreements
 */
function cmc_tracking_registration_step5() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_3_agreements',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_3_agreements',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_AGREEMENTS',
          'page_name' => 'SB_LIVE_AGREEMENTS',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_3_agreements',
          'demo_to_live' => 'cfd/demo_to_live_signup_3_agreements',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_AGREEMENTS',
          'page_name' => 'CFD_LIVE_AGREEMENTS',
        ),
      ),
    ),
  );
}



/**
 * Acknowledgement
 * Not all regions will have this - Looks like it'll only be AU
 */
function cmc_tracking_registration_step6() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_acknowledge',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_acknowledge',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_ACKNOWLEDGE',
          'page_name' => 'SB_LIVE_ACKNOWLEDGE',
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_acknowledge',
          'demo_to_live' => 'cfd/demo_to_live_signup_acknowledge',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_ACKNOWLEDGE',
          'page_name' => 'CFD_LIVE_ACKNOWLEDGE',
        ),
      ),
    ),
  );
}



/**
 * Reject step!
 */
function cmc_tracking_registration_reject() {
  return array(
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_reject',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_reject',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_REJECT',
          'page_name' => 'SB_LIVE_REJECT',
        ),

      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_reject',
          'demo_to_live' => 'cfd/demo_to_live_signup_reject',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_REJECT',
          'page_name' => 'CFD_LIVE_REJECT',
        ),

      ),
    ),
  );
}


/**
 * Complete
 */
function cmc_tracking_registration_complete() {
  return array(
    'demo' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/demo_signup_complete',
          'demo_to_live' => 'spreadbet/live_to_demo_signup_complete',
        ),
        'adform' => array(
          'sale_value' => '50',
          'tracking_division' => 'SB_DEMO_COMPLETE',
          'page_name' => 'SB_DEMO_COMPLETE',
        ),
        'google_ecommerce' => array(
          'order' => array(
            'id' => '',
            'store_name' => '',
            'price' => '',
            'tax' => '',
            'shipping' => '',
            'city' => '',
            'state' => '',
            'country' => '',
          ),
          'items' => array(
            array(
              'id' => '',
              'sku' => 'DEMO',
              'product_name' => 'nextgen',
              'category' => '',
              'unit_price' => '50.00',
              'quantity' => '1',
            ),
          ),
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/demo_signup_complete',
          'demo_to_live' => 'cfd/live_to_demo_signup_complete',
        ),
        'adform' => array(
          'sale_value' => '50',
          'tracking_division' => 'CFD_DEMO_COMPLETE',
          'page_name' => 'CFD_DEMO_COMPLETE',
        ),
        'google_ecommerce' => array(
          'order' => array(
            'id' => '',
            'store_name' => '',
            'price' => '',
            'tax' => '',
            'shipping' => '',
            'city' => '',
            'state' => '',
            'country' => '',
          ),
          'items' => array(
            array(
              'id' => '',
              'sku' => 'DEMO_CFD',
              'product_name' => 'nextgen',
              'category' => '',
              'unit_price' => '50.00',
              'quantity' => '1',
            ),
          ),
        ),
      ),
    ),
    'live' => array(
      'SB' => array(
        'google_analytics_pageview' => array(
          'live' => 'spreadbet/live_signup_complete',
          'demo_to_live' => 'spreadbet/demo_to_live_signup_complete',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'SB_LIVE_COMPLETE',
          'page_name' => 'SB_LIVE_COMPLETE',
        ),
        'google_ecommerce' => array(
          'order' => array(
            'id' => '',
            'store_name' => '',
            'price' => '',
            'tax' => '',
            'shipping' => '',
            'city' => '',
            'state' => '',
            'country' => '',
          ),
          'items' => array(
            array(
              'id' => '',
              'sku' => 'LIVE',
              'product_name' => 'nextgen',
              'category' => '',
              'unit_price' => '1000.00',
              'quantity' => '1',
            ),
          ),
        ),
      ),
      'CFD' => array(
        'google_analytics_pageview' => array(
          'live' => 'cfd/live_signup_complete',
          'demo_to_live' => 'cfd/demo_to_live_signup_complete',
        ),
        'adform' => array(
          'sale_value' => '1000',
          'tracking_division' => 'CFD_LIVE_COMPLETE',
          'page_name' => 'CFD_LIVE_COMPLETE',
        ),
        'google_ecommerce' => array(
          'order' => array(
            'id' => '',
            'store_name' => '',
            'price' => '',
            'tax' => '',
            'shipping' => '',
            'city' => '',
            'state' => '',
            'country' => '',
          ),
          'items' => array(
            array(
              'id' => '',
              'sku' => 'LIVE_CFD',
              'product_name' => 'nextgen',
              'category' => '',
              'unit_price' => '1000.00',
              'quantity' => '1',
            ),
          ),
        ),
      ),
    ),
  );
}