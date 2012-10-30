<?php
if (!empty($results[0])) {
  $first = array_shift($results);
}
else {
  // only one
  $first = $results;
  unset($results);  
}

// echo it out so php doesn't think it's php short tag
echo '<?xml version="1.0" encoding="UTF-8" ?>' . "\n"; ?>
<serv:message xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
	<header> 
		<?php echo theme('cmc_webex_security_context_xml') ?>
	</header>
	<body>
		<bodyContent xsi:type="java:com.webex.service.binding.attendee.CreateMeetingAttendee">
			<?php
			echo theme('cmc_webex_meeting_attendee_xml', $first, $webex_event_session, $language, $locale);

			if (is_array($results) && count($results)) {			  
			  foreach ($results as $r) {
			    echo "<attendees>\n";
			    echo theme('cmc_webex_meeting_attendee_xml', $r, $webex_event_session);
			    echo "</attendees>\n";
			  }
			}
			?> </bodyContent>
	</body>
</serv:message>
