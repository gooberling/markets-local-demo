<?php

// print_r(array_keys($fields));
//field_platform_desktop
//field_teaser
// nothing
?>

<?php echo $fields['field_teaser']->content ?>

<?php if(isset($fields['field_platform_android'])): echo $fields['field_platform_android']->content; endif; ?>
<?php if(isset($fields['field_platform_ipad'])): echo $fields['field_platform_ipad']->content; endif; ?>
<?php if(isset($fields['field_platform_iphone'])): echo $fields['field_platform_iphone']->content; endif; ?>
<?php if(isset($fields['field_platform_desktop'])): echo $fields['field_platform_desktop']->content; endif; ?>
	


