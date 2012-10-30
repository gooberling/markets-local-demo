<?php
/**
 * Nodes are articles, as in "article of something", not as in "news article".
 * We use the new <article> element to wrap nodes, with an ID and class, and
 * the WAI ARIA role "article". Roles could be added via $attributes, so really
 * we need to add more $attributes in more places so we can do this everywhere,
 * and not just sometimes, which is why I have chosen to hard code them in the
 * templates all the time, to be consistant.
 */


$spread = '';
$node_pricing = '';
if (module_exists('cmc_pricing')) {
  $node_pricing = cmc_pricing_node_pricing($node); // returns HTML

  // temp fix to show spread value from the pricing data
  $data = cmc_pricing_display_data($node);
  if (!empty($data['pricing']['price']->spread)) {
    // assumed to be static on this page
    // of it changes, then we need to use js
    $spread = $data['pricing']['price']->spread;
  }

  $pm = (int)$node->field_point_multiplier['und'][0]['value'];
  $spread = $spread * $pm;

}
?>
<article id="article-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix" role="article"<?php print $attributes; ?>>

  <?php
  /**
   * We can resue the <header> element to wrap our node header content, for now
   * thats just the title in an <h1>, but we could have other stuff here. Using
   * <h1> is pefectly fine in HTML5, you can have as many as you like.
   */
  ?>
  <?php if ($title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
         <?php print $title; ?>
			<span class="product-type-info">
<?php print render($content['field_instrument_type']); ?>,
<?php print render($content['field_sector']); ?>
		  </span>
        </h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php echo $node_pricing; ?>
    </header>
  <?php endif; ?>

  <?php
  /**
   * <footer> is not for marking up the thing at the bottom of the page, its for
   * wrapping meta data that pertains to the entity or page. There is a possible
   * use case for role="contentinfo" here, but we should be mindful not to over-
   * load Assistive Technology with too many roles and the spec clearly states
   * we should not use contentinfo more than once on the page, we'll see how
   * that plays out in real life...
   */
  ?>

	<!-- Commented out but can be put back if necessary -->
  <!-- <div<?php print $content_attributes; ?>> -->
  <!-- left-hand side block of product data -->




<!-- <div class="tabbed">
	<div class='slider'></div>
	<ul>
		<li class="active">
			<h2><a href="#">Overview</a></h2> -->

			<div class="detail">
				<div class="table-wrap">
					<table class="product-data">
						<tr>
							<td class="shorting"><?php print render($content['field_is_shorting_cfd']); ?></td>
							<td class="country"><?php print render($content['field_country']); ?></td>
							<td class="max"><?php print render($content['field_max_order_size_cfd_gbp']); ?></td>
							<td class="margin"><?php print render($content['field_max_financing_cfd']); ?></td>
						</tr>
						<tr>
							<td class="spread"><h4>Spread</h4><p><?php echo $spread ?></p></td>
							<td class="currency"><?php print render($content['field_currency']); ?></td>
							<td class="max"> <?php print render($content['field_max_order_size_sb_gbp']); ?></td>
							<td class="margin"> <?php print render($content['field_max_financing_sb']); ?></td>
						</tr>
<?php if ($commission != ''): ?>
                                                <tr>
							<td colspan="4" class="commission">
                                                          <h4>Commission</h4>
                                                          <?php print $commission; ?>
							</td>
                                                </tr>
<?php endif; ?>
					</table>
				</div>

	    		<h3><?php print t('Background')?></h3>
			    <?php print render($content['body']); ?>

				<h3><?php print t('Influencing Factors')?></h3>
			    <?php print render($content['field_influencing_factors']); ?>
			</div>
		<!-- </li>

			<li>
				<h2><a href="#">News</a></h2>
					<div class="detail">
<div class="latest-story">
<?php // echo render($content['product_related_news_latest_story']); ?>
</div>
<div class="recent-stories">
<?php // echo render($content['product_related_news_recent_stories']); ?>
</div>
					</div>

			</li>


	</ul>

  </div> -->


  <!-- </div> -->
  <?php
  /**
   * We're wrapping links in <menu> element, which is probalby a bit
   * controversial because <menu> is really meant for building toolbars and
   * contextual menus, however <menu> takes a type attribute with 3 possible
   * values - context, toolbar and list (default is list). Links are a list, and
   * I think a little bit like a context menu, meaning links are contextual to
   * the node or comment you are viewing, however they are not true contextual
   * links because you do not have to click anything to make them appear.
   */
  ?>
  <?php if ($links = render($content['links'])): ?>
    <menu class="node-links clearfix"><?php print $links; ?></menu>
  <?php endif; ?>



</article>
