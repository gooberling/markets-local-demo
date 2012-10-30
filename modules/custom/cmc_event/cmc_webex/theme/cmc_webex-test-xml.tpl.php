<?php // Test to get the user tp make sure the XML API works

// echo it out so php doesn't think it's php short tag
echo '<?xml version="1.0" encoding="UTF-8" ?>' . "\n"; ?>
<serv:message xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
  <header>
    <securityContext>
      <?php echo theme('cmc_webex_security_context_xml') ?>
    </securityContext>
  </header>
  <body>
    <bodyContent xsi:type="java:com.webex.service.binding.user.GetUser">
    	<webExId><?php echo $data['webex_id'] ?></webExId>
    </bodyContent>
  </body>
</serv:message>
