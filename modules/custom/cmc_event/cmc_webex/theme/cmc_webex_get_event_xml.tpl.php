<?php
// echo it out so php doesn't think it's php short tag
echo '<?xml version="1.0" encoding="UTF-8" ?>' . "\n"; ?>
<serv:message xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
	<header>
		<?php echo theme('cmc_webex_security_context_xml') ?>
	</header>
	<body>
		<bodyContent xsi:type="java:com.webex.service.binding.event.GetEvent">
			<sessionKey><?php echo $webex_event_session ?></sessionKey>
		</bodyContent>
	</body>
</serv:message>