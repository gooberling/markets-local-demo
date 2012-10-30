<?php
// webex credentials
// settings in module now
$settings = cmc_webex_connection_settings(variable_get('cmc_webex_connection', ''));
$webex_id = trim($settings['user']);
$webex_password = trim($settings['password']);

$webex_site_id = trim(variable_get('cmc_webex_site_id', '298174'));
$webex_site_name = trim(variable_get('cmc_webex_site_name', 'cmc-markets'));
$webex_partner_id = trim(variable_get('cmc_webex_partner_id', '298cm')); // what is this?
$webex_email = trim(variable_get('cmc_webex_email', ''));
?>
<securityContext>
	<webExID><?php echo $webex_id ?></webExID>
	<password><?php echo $webex_password ?></password>
	<siteID><?php echo $webex_site_id ?></siteID>
	<partnerID><?php echo $webex_partner_id ?></partnerID>
</securityContext>
