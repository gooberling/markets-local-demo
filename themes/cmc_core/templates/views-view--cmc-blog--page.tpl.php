<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<!-- <div class="tabbed">
	<div class='slider'></div>
	<ul>
		<li class="active">
   <h2><a href="#"><?php echo t('Latest Market Analysis') ?></a></h2> -->

			<div class="detail">


<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>



  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>


  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>



  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>





</div><?php /* class view */ ?>

   </div><?php /* detail */?>


<!-- </li>
<li>
  <h2><?php echo l(t('News'), 'news'); ?></h2>
</li>
</ul>
  </div> --> <?php /* tabbed */?>
