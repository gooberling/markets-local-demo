
<!-- <div class="block-views-cmc-landing-page-hero-bottom"> -->

<?php if ($edit) : ?>
<div class="edit" style="float:right; position:absolute; top:20px; right:0; padding:5px; z-index:999; background-color:#EC009C;"><?php echo $edit ?></div>
<?php endif; ?>

<?php foreach ($rows as $i => $row): ?>
  <?php $odd_even = ($i%2 == 0) ? 'odd' : 'even'; ?>

  <div class="banner row<?php echo $i; ?> <?php echo $odd_even; ?> <?php echo (!empty($row['class'])) ? $row['class'] : ''; ?>">
	  <div class="inner grid-10 last-col">

	  <?php if (!empty($row['content'])): ?>
	    <div class="grid-5"><?php echo $row['content']; ?></div>
	  <?php endif; ?>

	  <?php if (!empty($row['image'])): ?>
	    <div class="grid-5 last-col"><?php echo $row['image']; ?></div>
	  <?php endif; ?>
	  </div>
  </div>

<?php endforeach; ?>
<!-- </div> -->
