<?php echo '<?xml version="1.0" encoding="UTF-8" ?>' . "\n"; ?>
<serv:message xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
	<header>
		<?php echo theme('cmc_webex_security_context_xml'); ?>
	</header>
	<body>
		<bodyContent xsi:type="java:com.webex.service.binding.event.LstsummaryEvent">
			<listControl>
        <startFrom>1</startFrom>
        <maximumNum><?php echo variable_get('cmc_webex_num_events', '15'); ?></maximumNum>
        <listMethod>OR</listMethod>
			</listControl>
			<order>
        <orderBy>STARTTIME</orderBy>
        <orderAD>ASC</orderAD>
      </order>
      <dateScope>
      	<startDateStart><?php echo $from_date; // US Date format!  ?></startDateStart>
      </dateScope>
		</bodyContent>
	</body>
</serv:message>
