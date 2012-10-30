  <script type="text/javascript">
		
		function campaignPrevious() {
		
			var scrollAmount = Math.ceil((jQuery(document).scrollTop() - jQuery(window).height()) / jQuery(window).height()) * jQuery(window).height();
			
			jQuery('html, body').animate({scrollTop: scrollAmount}, 500);
		
		}
		
		function campaignNext() {
			
			var scrollAmount = Math.floor((jQuery(document).scrollTop() + jQuery(window).height()) / jQuery(window).height()) * jQuery(window).height();
			
			jQuery('html, body').animate({scrollTop: scrollAmount}, 500);

		}
		
		jQuery(document).scroll(function () {
			
			var total_campaigns = (Math.ceil(jQuery(document).height() / jQuery(window).height()) - 1);
			
			var campaign_end = jQuery(window).height() * (total_campaigns-1);
			
			var scrollAmount = Math.floor((jQuery(document).scrollTop() + jQuery(window).height()) / jQuery(window).height()) * jQuery(window).height();
			
			var current_campaign = (scrollAmount / jQuery(window).height());
			
			if (jQuery(document).scrollTop() > 0 && jQuery(document).scrollTop() <= campaign_end) {
				jQuery('input.prev').css('display','inline');
			} else {
				jQuery('input.prev').css('display','none');
			}
			
			if (jQuery(document).scrollTop() >= campaign_end) {
				 jQuery('input.next').css('display','none');
			} else {
				jQuery('input.next').css('display','inline');
			}
			
			// Add active states on scroll
			jQuery('li.campaign-nav a').removeClass('active');
			var current_campaign_li = 'li#campaign-' + current_campaign + ' a';
			jQuery(current_campaign_li).addClass('active');
			
		});
		
  </script>
  
  <header class="campaign-header">
	<ul>
	
	<?php 
	
	$query = new EntityFieldQuery();
	$entities = $query->entityCondition('entity_type', 'node')
                    ->propertyCondition('status', 1)
					->propertyCondition('type', array('cmc_campaign_page'))
                    ->propertyOrderBy('created', 'DESC')
                    ->execute();

	$nodes = node_load_multiple(array_keys($entities['node']));
	
	// Set the promo item to the top
	$i = 0;
	foreach($nodes as $node):
		
		$campaign_menu[$i]['menu_title'] = $node->field_campaign_menu_title['und'][0]['safe_value'];
		$campaign_menu[$i]['anchor'] = $node->field_campaign_anchor_link['und'][0]['safe_value'];
		
		if ((isset($_GET['promo'])) && ($_GET['promo'] == $node->field_campaign_anchor_link['und'][0]['safe_value'])):
			$promo_item = $i;
		endif;
		
		$i++;
	endforeach;
	
	if (isset($promo_item)):
		$promo[] = $campaign_menu[$promo_item];
		unset($campaign_menu[$promo_item]);
		$campaign_menu = array_merge($promo, $campaign_menu);
	endif;
		
		//Reverse array as menu is actually displayed backwards
		$campaign_menu = array_reverse($campaign_menu);
		
		$node_count = count($campaign_menu);
		$i=$node_count;
		foreach ($campaign_menu as $campaign_item):
		
		if ($i == 1):
				print "<li class='campaign-nav' id='campaign-" . $i . "'><a class='active' href='#" . $campaign_item['anchor'] . "'>" . $campaign_item['menu_title'] . "</a></li>";
			else:
				print "<li class='campaign-nav' id='campaign-" . $i . "'><a href='#" . $campaign_item['anchor'] . "'>" . $campaign_item['menu_title'] . "</a></li>";
			endif;
			$i--;
		endforeach;
	?>
	
	</ul>

  </header>

	
<div class="campaign-carousel">
	<!--nav arrows -->
	<div class="campaign-arrows">
		
		<?php 
		$i = 1;
		foreach ($nodes as $node):
			$campaign[$i]['anchor_link'] = $node->field_campaign_anchor_link['und'][0]['safe_value'];
			$i++;
		endforeach;
		?>
		
		<?php if ($i > 2): ?>
		<input type="button" onclick="campaignPrevious();" value="Previous" class="prev" />
		<input type="button" onclick="campaignNext();" value="Next" class="next" />
		<?php endif; ?>
		
	</div>	
	<!-- /nav arrows -->
	
							
				<?php print render($page['content']); ?>
			  
</div>
	
	
	<!-- footer -->
  <footer class="footer">
	<div class="risk">
	<?php 
	print render($page['campaign_footer']); ?>
	</div>

  </footer>