<ul>
<?php
      foreach ($steps as $number => $step):
        $classes = array();
        if(isset($step['class'])) {
          $classes [] = $step['class'];
        }
	
	if (isset($step['active'])) {
	  $classes[] = 'active';
	}
	if (isset($step['complete'])) {
	  $classes[] = 'complete';
	}

	$class = implode(' ', $classes);
	?>
	<li class="<?php echo $class; ?>">
         <?php if(!isset($step['final'])) {
           $label = t("Step @number", array('@number' => $number)); 
         } else {
           $label = t($number); 
         }
         
         ?>
		<h3><span><?php echo $label; ?></span>&nbsp;<?php echo $step['title']; ?></h3>
	</li>
	<?php
	endforeach;
	?>
</ul>
