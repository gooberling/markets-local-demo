
<div class="block-views-cmc-landing-page-hero grid-10 last-col">
<?php foreach ($rows as $i => $row): ?>
  <div class="hero row<?php echo $i; ?>">
	
	<?php if (!empty($row['content'])): ?>
	    <div class="hero-content grid-4"><?php echo $row['content']; ?></div>
	  <?php endif; ?>
  
  <?php if (!empty($row['image'])): ?>
    <div class="hero-image"><?php echo $row['image']; ?></div>
  <?php endif; ?>
  
  
  </div>
<?php endforeach; ?>

  <a class="prev">Prev</a>
  <a class="next">Next</a>

</div>