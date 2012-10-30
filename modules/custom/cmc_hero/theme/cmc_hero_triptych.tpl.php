
<?php //print_r($node); ?>
<?php //echo $content;

$num_triptychs = 3;

$image_url = file_create_url($node->field_image['und'][0]['uri']);
$image = theme('image', array('path' => $image_url));

//echo $image;
$bg_color = $node->field_triptych_bg['und'][0]['value'];
$panel_class = $node->field_triptych_panel_class['und'][0]['value'];
$triptych_class = $node->field_triptych_class['und'][0]['value'];
?>


<div class="block-views-cmc-landing-page-hero triptych grid-10 last-col">
   
  <div class="hero-content grid-4 <?php echo $triptych_class ?>"><?php echo $node->body['und'][0]['safe_value']; ?></div>
  
  <div class="triptych-panels">
  <?php for ($i=1; $i <= $num_triptychs; $i++): ?>
      <div class="triptych-content <?php echo $panel_class ?>">
        <?php echo $node->{'field_cmc_triptych_text' . $i}['und'][0]['safe_value'] ?>
     </div>
    <?php endfor; ?>
  </div>
  

  <?php if ($edit) : ?>
  <div class="edit" style="position:absolute; top:120px; right:0; padding:5px; z-index:999; background-color:#EC009C;"><?php echo $edit ?></div>
  <?php endif; ?>


  <?php
  // want the open an account to always be embedded into a hero
  $block = module_invoke('cmc_framework', 'block_view', 'cmc_open_account');
  echo render($block['content']);
  ?>

</div>

<?php if ($image): ?>
  
  <div class="hero-image-triptych" style="background-color:<?php echo $bg_color; ?>; background-image: url(<?php echo $image_url; ?>);"></div>
<?php endif; ?>



