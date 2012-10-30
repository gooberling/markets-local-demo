
<div id="hero-transition" class="block-views-cmc-landing-page-hero grid-10 last-col">
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

  

<?php if ($edit) : ?>
<div class="edit" style="position:absolute; top:120px; right:0; padding:5px; z-index:999; background-color:#EC009C;"><?php echo $edit ?></div>
<?php endif; ?>


<?php
// want the open an account to always be embedded into a hero
$block = module_invoke('cmc_framework', 'block_view', 'cmc_open_account');
echo render($block['content']);
?>

</div>

<a class="prev">Prev</a>
<a class="next">Next</a>




