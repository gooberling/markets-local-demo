
<?php $next = drupal_render($form['next']); ?>
<div id= "step-1">
<div class="form-steps grid-2"><?php echo drupal_render($form['steps']); ?></div>
<div class="grid-8 last-col">
	<div class="form-bg">
	   <?php echo drupal_render($form['title']); ?>
          <div class="required"><span>*</span> <?php echo t('Required fields'); ?></div>
           <?php if (!empty($messages)) print ($messages); ?>
	   <?php echo drupal_render($form['account_type']); ?>
	   <?php echo drupal_render($form['account_type_desciption_ia']); ?>
	   <?php echo drupal_render($form['account_type_desciption_ja']); ?>
	   <?php echo drupal_render($form['account_type_desciption_ca']); ?>
	   <?php echo drupal_render($form['account_type_desciption_tai']); ?>
	   <?php echo drupal_render($form['account_type_desciption_tac']); ?>
	   <?php echo drupal_render($form['already_registered']); ?>
	   <div><?php echo drupal_render_children($form); ?></div>
	</div>
</div>

<div class="buttons grid-8 push-2 last-col">
	<div class="right"><?php echo $next; ?> </div> 
</div> 

</div>

