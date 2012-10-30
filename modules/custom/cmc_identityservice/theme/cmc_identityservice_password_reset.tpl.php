
<div class="grid-10 last-col">
	<div class="form-bg forgot">
		<div class="required"><span>*</span> <?php echo t('Required fields'); ?></div>
		<h2><?php  print t('Please enter your new password below'); ?></h2>
  		<div class="form-item active">   
			 	<?php print drupal_render($form['pass1']); ?>
			    <?php print drupal_render($form['pass2']); ?>
    
  			   <div class="spacer"><?php echo drupal_render_children($form); ?></div>
   		</div>
	</div>
</div>

