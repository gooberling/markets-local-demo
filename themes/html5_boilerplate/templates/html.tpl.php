<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
  <head>
    <?php
    /**
     * @see html5_boilerplate_html_head_alter()
     */
    ?>
	<meta http-equiv="X-UA-Compatible" content="IE=9">
	<!-- forces IE to standards mode-->
    <!--[if IE 8]>
    	<meta http-equiv="X-UA-Compatible" content="IE=8" />
    <![endif]-->

   <!-- for android browsers and to prevent zoom -->
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=1" />
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <?php print $scripts; ?>
	
    <?php
    /**
     * Pull the HTML5shiv script from Googlecode to support IE6/7/8
     */
    ?>
    <!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
  </head>
  <body class="<?php print $classes; ?>"<?php print $attributes;?>>
    <div id="skip-link">
      <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
    </div>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  </body>
</html>
