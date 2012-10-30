<?php 
$firstname = $result['first_name'];
$surname = $result['surname'];
$name = $firstname . ' ' . $surname;
$email = $result['email_address'];
$phone = $result['phone'];

$phone_country_code = variable_get('cmc_webex_phone_code', '');
$phone = $phone_country_code . ',' . $phone;
//$phone = '12345678901';

$country = $result['location_country'];
?>
<person>
  <?php echo theme('cmc_webex_xml_cell', 'firstName', $firstname); ?>
  <?php echo theme('cmc_webex_xml_cell', 'lastName', $surname); ?>
  <?php echo theme('cmc_webex_xml_cell', 'name', $name); ?>
  <address>
  	<addressType>PERSONAL</addressType>
  	<?php echo theme('cmc_webex_xml_cell', 'country', $country); ?>
  </address>  
  <phones>
  	<?php echo theme('cmc_webex_xml_cell', 'phone', $phone); ?>  	
  </phones>  
  <?php echo theme('cmc_webex_xml_cell', 'email', $email); ?>  
    
  <type>VISITOR</type>
</person>
<role>ATTENDEE</role>
<?php echo theme('cmc_webex_xml_cell', 'language', $language); ?>
<?php echo theme('cmc_webex_xml_cell', 'locale', $locale); ?>
<?php //echo theme('cmc_webex_xml_cell', 'timeZoneID', $country['timeZoneID']); ?>
<sessionKey><?php echo $webex_event_session; ?></sessionKey>
