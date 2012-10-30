<?php
/**
 * Menu blocks are best served up a <nav>. Most of the time menus really are
 * menus and HTML5 gives us the <nav> element to mark them up. Drupal gives us
 * template suggestions so I am using one here to target menu blocks. Note
 * however that not all menus are Menu module menus, we need some preprocessing
 * to make sure the Main menu and others use this template.
 * @see html5_boilerplate_preprocess_block()
 */

?>



<nav id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?> <?php print $content_attributes; ?>>
	<div class="inner grid-10">
	<?php print $content ?>
	</div>
</nav>

