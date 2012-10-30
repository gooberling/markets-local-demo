<?php if(isset($form['exit'])) {
  $previous = drupal_render($form['exit']);
} else {
  $previous = drupal_render($form['prev']);
}

$next = drupal_render($form['finish']);
?>
<div id= "step-6">
<div class="form-steps grid-2"><?php echo drupal_render($form['steps']); ?></div>
<div class="grid-8 last-col">
	<div class="form-bg">
	   <?php echo drupal_render($form['title']); ?>
           <?php if (isset($messages)) print ($messages); ?>
	   <?php echo drupal_render_children($form); ?>
	</div>
</div>

<div class="buttons grid-8 push-2 last-col">
	<div class="left"><?php echo $previous; ?> </div>
	<div class="right"><?php echo $next; ?> </div>
</div>
</div>