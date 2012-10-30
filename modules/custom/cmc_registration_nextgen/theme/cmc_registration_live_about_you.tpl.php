
<?php $previous = drupal_render($form['prev']); ?>   
<?php $next = drupal_render($form['next']); ?>
<div id="step-3">
<div class="form-steps grid-2"><?php echo drupal_render($form['steps']); ?></div>
<div class="grid-8 last-col">
	<div class="form-bg">
	   <?php echo drupal_render($form['title']); ?>
           <div class="required"><span>*</span> <?php echo t('Required fields'); ?></div>
           <?php if (!empty($messages)) print ($messages); ?>
	    <?php echo drupal_render_children($form); ?>
	</div>
</div>

<div class="buttons grid-8 push-2 last-col">
	<div class="left"><?php echo $previous; ?> </div> 
	<div class="right"><?php echo $next; ?> </div> 
</div>

</div>