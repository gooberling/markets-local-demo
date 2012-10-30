

<?php cmc_pricing_add_js();?>
<?php //echo path_to_theme();
//global $theme;
//print_r($theme);
?>



<!-- <marquee class="pricing-group ticker-container" scrollamount="6">-->
<div class="pricing-group ticker-container">

<ul class="pricing-scroller">

  <?php if(!empty($node->field_pricing_products1)): ?>

      <?php foreach($node->field_pricing_products1['und'] as $product_nid): ?>
      <?php $price = $instruments[$product_nid['nid']];
      //print_r($price);
      ?>
      <li class="pricing" rel="<?php echo $price['pricing']['pricing']['symbol']; ?>">
         <div class="title"><?php echo l($price['product']['title'], 'node/' . $price['product']['nid']); ?></div>
         <div class="bid">
           <span class="value"><?php echo $price['pricing']['price']->bid; ?></span><br />
         </div>
         <div class="ask">
           <span class="value"><?php echo $price['pricing']['price']->ask; ?></span><br />
         </div>

       </li>

      <?php endforeach; ?>
  <?php endif; ?>
</ul>

</div>
<?php if (!empty($edit_link)): ?>
<?php echo $edit_link ?>
<?php endif; ?>
