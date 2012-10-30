<?php
/**
 * @file
 * feature_uk_registration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_uk_registration_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_identityservice_cfdlogin_path';
  $strongarm->value = 'https://www1-hdev3-cfd-uk-cmcdigitals.com/Main.html';
  $export['cmc_identityservice_cfdlogin_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_identityservice_sblogin_path';
  $strongarm->value = 'https://www1-hdev3.cmcdigitals.com/Main.html';
  $export['cmc_identityservice_sblogin_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_appropriateness_CFD';
  $strongarm->value = 'Based on your knowledge and experience CFD';
  $export['cmc_registration_appropriateness_CFD'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_appropriateness_SB';
  $strongarm->value = 'Based on your knowledge and experience SB Based on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SBSBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SBSBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
SBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SBSBBased on your knowledge and experience SB  Based on your knowledge and experience SB Based on your knowledge and experience SB
';
  $export['cmc_registration_appropriateness_SB'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_country_code';
  $strongarm->value = 'GBR';
  $export['cmc_registration_country_code'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_currency';
  $strongarm->value = 'GBP';
  $export['cmc_registration_currency'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_cfd_thankyou';
  $strongarm->value = '4';
  $export['cmc_registration_demo_cfd_thankyou'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_sb_thankyou';
  $strongarm->value = '3';
  $export['cmc_registration_demo_sb_thankyou'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thanks';
  $strongarm->value = '';
  $export['cmc_registration_demo_thanks'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou';
  $strongarm->value = '2';
  $export['cmc_registration_demo_thankyou'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_cfd';
  $strongarm->value = '3';
  $export['cmc_registration_demo_thankyou_cfd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_desktop';
  $strongarm->value = 'https://www1-hdev3.cmcdigitals.com/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_desktop'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_desktop_cfd';
  $strongarm->value = 'https://www1-hdev3-cfd-uk-cmcdigitals.com/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_desktop_cfd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_desktop_sb';
  $strongarm->value = 'https://www1-hdev3.cmcdigitals.com/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_desktop_sb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_ios';
  $strongarm->value = 'http://message/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_ios'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_ios_cfd';
  $strongarm->value = 'http://message/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_ios_cfd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_ios_sb';
  $strongarm->value = 'http://message/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_ios_sb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_mobile';
  $strongarm->value = 'https://www1-hdev3.cmcdigitals.com/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_mobile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_mobile_cfd';
  $strongarm->value = 'https://www1-hdev3-cfd-uk-cmcdigitals.com/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_mobile_cfd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_mobile_sb';
  $strongarm->value = 'https://www1-hdev3.cmcdigitals.com/?token=!token&username=!username';
  $export['cmc_registration_demo_thankyou_mobile_sb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_demo_thankyou_sb';
  $strongarm->value = '2';
  $export['cmc_registration_demo_thankyou_sb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_live_confirmation';
  $strongarm->value = '1';
  $export['cmc_registration_live_confirmation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_live_thankyou';
  $strongarm->value = '1';
  $export['cmc_registration_live_thankyou'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_live_thankyou_cfd';
  $strongarm->value = '5';
  $export['cmc_registration_live_thankyou_cfd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_live_thankyou_sb';
  $strongarm->value = '4';
  $export['cmc_registration_live_thankyou_sb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_pdfdeclaration_CFD';
  $strongarm->value = '<ol>
<li>The information I have provided to CMC Markets about myself is accurate and not misleading in any material respect.  In addition, I will notify CMC Markets immediately if any of that information materially changes or ceases to be true and correct.
</li>
 <li>I understand and accept that CMC Markets will provide services to me on the terms of the <a href ="http://www.cmcmarkets.co.uk/sites/default/files/cmc_tracker_terms_of_business.pdf" target="_blank">CFD Terms of Business</a> and that for my own benefit and protection I should read that document and the <a href="http://www.cmcmarkets.co.uk/how-tos/opening-account/tracker-cfd-terms" target="_blank">Risk Warning Notice for CFD </a></li>

<li>I understand that transactions in contracts for differences (CFDs) are leveraged products and that it is possible to lose more than my deposit.</li>

<li>I understand and accept that my orders will be executed in accordance with CMC Markets\'  <a href ="http://www.cmcmarkets.co.uk/sites/default/files/cmc_tracker_order_execution.pdf" target="_blank">Order Execution Policy Summary for CFDs</a> ;</li>

<li>I understand and accept that all information regarding my CFD account, including all information about my transaction activity, will be provided to me through the online CFD platform and via email and not on paper.</li>
</ol>';
  $export['cmc_registration_pdfdeclaration_CFD'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_pdfdeclaration_SB';
  $strongarm->value = '<ol>
<li>The details provided by me during the on-line and full application process are complete and accurate and I will promptly notify you in writing if any of the representations contained herein shall materially change or cease to be true and correct.</li>

<li>I understand that you will provide the services on the terms of the <a href ="http://www.cmcmarkets.co.uk/content/documents/sb/SPREADBET-TERMS-OF-BUSINESS.pdf" target="_blank"><b>Financial Betting Terms of Business</b></a> and that for my own benefit and protection I should read this document together with the <a href="http://www.cmcmarkets.co.uk/legal/risk-warning-notice" target="_blank"><b>Risk Warning Notice For Financial Betting</b></a>. 
</li>

<li>I understand the nature of margined transactions and can bear the financial risk associated with this kind of product. </li>

<li>I consent to my orders being executed in accordance with the <a href= "http://www.cmcmarkets.co.uk/content/documents/sb/execution-policy.pdf" target="_blank"><b>Order Execution Policy</b></a>. </li>
</ol>';
  $export['cmc_registration_pdfdeclaration_SB'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_pdf_body';
  $strongarm->value = '';
  $export['cmc_registration_pdf_body'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_pdf_footer';
  $strongarm->value = '';
  $export['cmc_registration_pdf_footer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_region';
  $strongarm->value = 'aus';
  $export['cmc_registration_region'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_region_form';
  $strongarm->value = 'default';
  $export['cmc_registration_region_form'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_risk_warning_CFD';
  $strongarm->value = 'its about financial warning all the way CFD';
  $export['cmc_registration_risk_warning_CFD'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_risk_warning_SB';
  $strongarm->value = 'It is about financial warning all the way';
  $export['cmc_registration_risk_warning_SB'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_risk_warning_title_CFD';
  $strongarm->value = 'Risk Warning Notice for CFD';
  $export['cmc_registration_risk_warning_title_CFD'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_risk_warning_title_SB';
  $strongarm->value = 'Risk Warning Notice for Financial betting';
  $export['cmc_registration_risk_warning_title_SB'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_tenant_template_code_cfd';
  $strongarm->value = 'CMC-CFDUK-R';
  $export['cmc_registration_tenant_template_code_cfd'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_tenant_template_code_sb';
  $strongarm->value = 'CMC-SBUK-R';
  $export['cmc_registration_tenant_template_code_sb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_terms_conditions';
  $strongarm->value = 'Terms & Conditions Body Text Terms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body TextTerms & Conditions Body Text';
  $export['cmc_registration_terms_conditions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_terms_conditions_CFD';
  $strongarm->value = 'Agreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFDAgreements  CFD';
  $export['cmc_registration_terms_conditions_CFD'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_terms_conditions_SB';
  $strongarm->value = 'Agreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial bettingAgreements Financial betting';
  $export['cmc_registration_terms_conditions_SB'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_terms_conditions_title';
  $strongarm->value = 'Terms & Conditions';
  $export['cmc_registration_terms_conditions_title'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_terms_conditions_title_CFD';
  $strongarm->value = 'Agreements  CFD';
  $export['cmc_registration_terms_conditions_title_CFD'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cmc_registration_terms_conditions_title_SB';
  $strongarm->value = 'Agreements Financial betting';
  $export['cmc_registration_terms_conditions_title_SB'] = $strongarm;

  return $export;
}
