<?php
  /**
   * Set the gradient div for all pages
   */
  ?>

<header class="gradient">
<a name='top'></a>
  <div id="header" class="clearfix loading" role="banner">
	<!-- this adds the blue bars to the left and right to allow for the see through nav links -->
	<div class="top-fill-left"><div class="insert"></div></div>
	<div class="inner grid-10">
		<div id="logo">
	      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" >
	       	  <?php /** <img src="<?php print $path; ?>images/cmc-logo.png" alt="CMC Markets" />  * have in the page. */?>
	      </a>
		</div>
	   
		<?php
	    // main header section
		print render($page['header']);
		  ?>

	    <!-- <?php print render($page['menu_bar']); ?> -->
	</div>
		<!-- this adds the blue bars to the left and right to allow for the see through nav links -->
 		 <div class="top-fill-right"><div class="insert"></div></div>
 </div>

	<?php
	    // landing page area for full width headers
		print render($page['landing_page']);
?>
  
 
 
	<!-- hidden from desktop version -->
	<a href="#mobile-nav" class="mobile-menu">Main Menu</a>
	
		<?php
			// the free text filter block
			print render($page['text_search']);
		?>
	
<?php /** End gradient div */ ?>
</header>

<?php
/**
 * Print a conditional wrapper to contain these page elements.
 */
?>
<?php if (isset($messages) || isset($page['help']) || isset($page['highlighted']) || isset($breadcrumb)): ?>
 
    
    <?php print render($page['help']);  ?>

    <?php
    /**
     * Most regions don't need any additional markup, we can do everything we
     * need with region.tpl.php output. In my fantasy D8 world $breadcrumb no
     * longer exists and is now a block, but we'll print it for posterity.
     */
    ?>
    <?php if ($highlighted = render($page['highlighted'])): print $highlighted; endif; ?>
	
	
	
<div id="crumbtrail" class="clearfix">
	
	<div class="inner grid-10">
	
	      <?php print $breadcrumb; ?>
	
	 </div>
	
 </div>
	<!-- <?php if ($messages): ?>
			<div class="inner grid-10"><?php print $messages; ?></div>
		<?php endif; ?> -->
	
<?php endif; ?>