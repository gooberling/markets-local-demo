<a name='top'></a>
<?php 
 $image = file_create_url($node->field_image['und'][0]['uri']);
?>
  <header id="header" class="clearfix" role="banner"  style="background-image:url('<?php echo $image; ?>');" >
	<!-- this adds the blue bars to the left and right to allow for the see through nav links -->

	<div class="inner grid-10">
		<div id="logo">
	      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" >
	       	  <?php /** <img src="<?php print $path; ?>images/cmc-logo.png" alt="CMC Markets" />  * have in the page. */?>
	      </a>
		</div>
	   
		<?php
	    // main header section
		print render($page['ppc_header']);
		  ?>

	</div>
		<!-- this adds the blue bars to the left and right to allow for the see through nav links -->
		<?php
		  // landing page area for full width headers
		  print render($page['landing_page']);
		?>
 		 
 </header>


  
 
 
	<!--	<a href="#mobile-nav" class="mobile-menu">Main Menu</a> -->


<?php if ($messages): ?>
  <div class="inner grid-10"><?php print $messages; ?></div>
<?php endif; ?>
