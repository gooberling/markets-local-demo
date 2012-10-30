 <div class="campaign" id="<?php print $anchor_link; ?>">
		<div class="campaign-inner">
			
			<?php $node = node_load($nid); ?>
			
			<div class="campaign-logo"><a href="/"><img src="/profiles/cmc_installer/themes/cmc_core/images/logo-reg.png" width="80" height="46" alt="Logo Reg"></a></div>
			<div class="copy">
				<h1><?php print $title; ?></h1>
				<div class="img-mobile" style="background-image:url('<?php print image_style_url('campaign_mobile_image', $node->field_campaign_mobile_bg['und'][0]['uri']); ?>')"></div>
				<?php print $body; ?>
				<p><a href="<?php print $fom_link; ?>" onClick="<?php print $fom_tracking_code; ?>"><?php print $fom_link_text; ?></a></p>
			</div>
			<div class="cta">
				<div class="campaign-signpost-links">
				  <div class="campaign-signpost1">
					<a href="/sign-up" onClick="<?php print $tracking_code; ?>">Open an account</a>
				  </div>
				 <footer class="disclaim">
				    <p>Losses can exceed your initial deposit, so ensure you understand the risks</p>
				 </footer>
				</div>

				</div>
			</div>
						
			<div class="img-desktop" style="background-image:url('<?php print image_style_url('campaign_desktop_image', $node->field_campaign_desktop_bg['und'][0]['uri']); ?>')"></div>
			
		</div>