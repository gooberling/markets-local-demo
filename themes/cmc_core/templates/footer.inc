
	<footer id="footer" role="contentinfo">
		
		<?php print render($page['risk']); ?>
		
		<!-- the nav is output here so that we can position it at the bottom in the mobile version -->
		<a name='mobile-nav'></a>
			<div class="inner grid-10 mobile-navigation">
					<a href="#top" class="mobile-menu">Back to top</a>
				 	<?php print render($page['main_nav']); ?>
			</div>
		
		<?php print render($page['footer']); ?>
    <?php print render($page['ppc_footer']); ?>
  
	  <?php print render($page['bottom_page']); ?>
		
	</footer>
	
	<?php print render($page['cookies_uk']); ?>

<?php if (isset($cmc_adform)):
		print $cmc_adform;
	endif;
?>