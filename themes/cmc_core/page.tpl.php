<!-- <div id="page"> -->
<?php
	// header include
  if (!empty($node) &&  $node->type == 'cmc_ppc_page') {
    include('templates/header-ppc.inc');
  }
  else {
	  include('templates/header.inc');
  }
?>

	<div id="main-wrapper" class="clearfix">

	 	<div class="inner grid-10">
	    	<section id="main-content" class="<?php print $main_content_layout ?> region-content" role="main">



		      <?php print render($title_prefix); ?>
		      <?php if ($title  && (isset($node) && $node->type != 'product')): ?>
		        <h1 id="page-title"><?php print $title; ?></h1>
		      <?php endif; ?>
		      <?php print render($title_suffix); ?>

		      <?php if ($tabs = render($tabs)): ?>
		        <div class="tabs"><?php print $tabs; ?></div>
		      <?php endif; ?>

		      <?php if ($action_links = render($action_links)): ?>
		        <ul class="action-links"><?php print $action_links; ?></ul>
		      <?php endif; ?>

			
			
				  <?php if ($filter_block = render($page['filter_block'])): ?>
            <?php if (cmc_core_filter_block_has_facet_filters($page['filter_block'])): ?>
					 
              <div class="filter-actions"><a href="#" class="reveal"><?php echo t('Show filters') ?></a>
			        <?php print $filter_block; ?>
			</div>
           
            <?php else: ?>
			        <?php print $filter_block; ?>
            <?php endif; ?>
            
          <?php endif; ?>
				
			<!-- Original Market analysis page -->	
		 <!-- <?php // if ($_GET['q'] == 'market-analysis'): ?>
								<div class="tabbed"><div class='slider'></div><ul><li class="active"><h2><a href="#"><?php // echo t('Latest Market Analysis') ?></a></h2><div class="detail">
							<?php // elseif ($_GET['q'] == 'news/dow-jones'): ?>
								<div class="tabbed"><div class='slider'></div> <ul> <li> <h2><?php // echo l(t('Latest Market Analysis'), 'market-analysis') ?></h2> </li> <li class="active"> <h2><a href="#"><?php // echo t('Dow Jones News') ?></a></h2> <div class="detail">
							<?php // endif; ?>
								
								<?php // print render($page['content']); ?>
							  
							<?php // if ($_GET['q'] == 'market-analysis'): ?>
								</div></li><li><h2><?php // echo l(t('Dow Jones News'), 'news/dow-jones'); ?></h2></li></ul></div>
							<?php // elseif ($_GET['q'] == 'news/dow-jones'): ?>
								</div></li></ul></div>
							<?php // endif; ?>  -->
			<!-- End Original Market analysis page -->	
			
			
			<!-- Temp page with no news -->
			
			<?php if ($_GET['q'] == 'market-analysis'): ?>
			
				<div class="detail">
			<?php endif; ?>
				
				<?php print render($page['content']); ?>
			  
			<?php if ($_GET['q'] == 'market-analysis'): ?>
				</div>
			<?php endif; ?>
			  
		      <?php print $feed_icons; ?>

		    </section>
			
			<?php if ($sidebar_first = render($page['sidebar_first'])): print $sidebar_first; endif; ?>
			<?php if ($sidebar_second = render($page['sidebar_second'])): print $sidebar_second; endif; ?>
			
			<?php print render($page['content_related']); ?>

		</div>
		<?php print render($page['content_home']); ?>
	</div>


<?php
	// footer include
	include('templates/footer.inc');
?>

<!-- </div> -->

