<?php
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>			<?php 

			$url = url('node/' . $fields['nid']->content);

			if ($fields['type']->content == "CMC Video"): ?>
				<a href="<?php print $url; ?>" class="cmc_video img-block"><?php print $fields['field_video']->content;?></a>
			 <?php elseif ($fields['type']->content == "CMC Event"): ?>
				<a href="<?php print $url; ?>" class="cmc_event img-block"><?php if (!empty($fields['field_image']->content)) { print $fields['field_image']->content; }?></a>
			 <?php elseif ($fields['type']->content == "CMC Document Guide"): ?>
				<a href="<?php print $url; ?>" class="cmc_document_guide img-block"><?php if (!empty($fields['field_image']->content)) { print $fields['field_image']->content; }?></a>
			 <?php else: ?>
				<a href="<?php print $url; ?>" class="img-block"><?php if (!empty($fields['field_image']->content)) { print $fields['field_image']->content; }?></a>
			 <?php endif; ?>
			 
			 <?php print $fields['title']->content;?>
			<?php print $fields['field_teaser']->content;?>
			
			<?php
			if ($fields['type']->content == "cmc_event"):
				print $fields['field_date']->content;
			else:
				print $fields['created']->content;
			endif;
			?>