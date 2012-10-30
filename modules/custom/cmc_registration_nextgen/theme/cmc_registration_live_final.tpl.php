<div id= "live-final">
<div class="form-steps grid-2"><?php echo $steps; ?></div>
<div class="grid-8 last-col">
	<div class="form-bg">
	   <h2><?php echo $data['title']; ?></h2>
            <?php if (!empty($messages)) print ($messages); ?>
           <?php echo $data['body_text']; ?>
	 
	</div>
</div>
</div>