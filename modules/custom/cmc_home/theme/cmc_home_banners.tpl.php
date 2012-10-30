
<?php foreach ($rows as $i => $row): ?>
  <?php $odd_even = ($i%2 == 0) ? 'odd' : 'even'; ?>
    
  <div class="banner row<?php echo $i; ?> <?php echo $odd_even; ?> grid-10 last-col">
	
  
	  <?php if (!empty($row['content'])): ?>
	    <div class="grid-5"><?php echo $row['content']; ?></div>
	  <?php endif; ?>
	
	  <?php if (!empty($row['image'])): ?>
	    <div class="grid-5 last-col"><?php echo $row['image']; ?></div>
	  <?php endif; ?>
	
  

  </div>

<?php endforeach; ?>
