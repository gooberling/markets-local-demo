<?php
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */
?>
<?php 

if (isset($row->nid)):
	$node_link = url(drupal_get_path_alias('node/' . $row->nid));
else:
	$node_link = '';
endif;

if (isset($row->field_field_platform_nav_text[0]['raw']['value'])):
	$link_text = $row->field_field_platform_nav_text[0]['raw']['value'];
else:
	$link_text = '';
endif;

if (isset($row->field_field_platform_nav_image[0]['rendered']['#item']['uri'])):
	$image_url = file_create_url($row->field_field_platform_nav_image[0]['rendered']['#item']['uri']);
else:
	$image_url = '';
endif;

print '<div class="nav-content">    
          <a title="' . $node_link . '" href="' . $node_link . '">
          <img width="80" height="50" src="' . $image_url . '" typeof="foaf:Image">    
          <p>' . $link_text . '</p></a></div>';

?>