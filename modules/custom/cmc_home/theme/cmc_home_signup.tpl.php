

<?php foreach ($rows as $i => $row): ?>
  <?php $odd_even = ($i%2 == 0) ? 'odd' : 'even'; ?>
    
  <div class="signup row<?php echo $i; ?> <?php echo $odd_even; ?>">
  
  <?php if (!empty($row['image'])): ?>
    <div class="image"><?php echo $row['image']; ?></div>
  <?php endif; ?>
  
  <?php if (!empty($row['content'])): ?>
    <div class="content"><?php echo $row['content']; ?></div>
  <?php endif; ?>
  </div>

<?php endforeach; ?>
