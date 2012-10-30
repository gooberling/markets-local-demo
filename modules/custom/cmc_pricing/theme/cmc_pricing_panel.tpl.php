

<?php
///print_r($node);
//print_r($instruments);
$num_panels_per_node = 5;
$display_type = $node->field_pricing_display['und']['0']['value'];
cmc_pricing_add_js();

?>

<div class="pricing-group <?php echo $display_type ?>">

<?php if(!empty($node->field_pricing_display_title['und'][0]['value'])): ?>
 <h2><?php echo $node->field_pricing_display_title['und'][0]['value']?></h2>
<?php endif; ?>

<?php if (!empty($edit_link)): ?>
<?php echo $edit_link ?>
<?php endif; ?>
<!--
<ul>
    <li>1</li>
    <li>2</li>
    <li>3</li>
    </ul>
-->
<?php for ($i=1; $i<=$num_panels_per_node; $i++) : ?>
  <?php if(!empty($node->{'field_pricing_products' . $i})): ?>

    <?php if($display_type == 'default'): ?>
      <div class="pricing-panel">
        <?php if (!empty($node->{'field_pricing_title' . $i}['und'][0]['value'])): ?>
          <h3><?php echo $node->{'field_pricing_title' . $i}['und'][0]['value']?></h3>
        <?php endif; ?>

        <?php foreach($node->{'field_pricing_products' . $i}['und'] as $product_nid): ?>
          <?php
          if (!empty($instruments[$product_nid['nid']])) {
            $price = $instruments[$product_nid['nid']];

            $data = array(
              'node' => (object)$price['product'],
              'pricing' => $price['pricing'],
              'truncate' => 1,
            );

            echo theme('cmc_pricing_product', $data);
          }

          ?>

        <?php endforeach; ?>

       </div>
    <?php else : ?>

      <div class="pricing-panel pricing-panel-tabbed">
       <?php if (!empty($node->{'field_pricing_title' . $i}['und'][0]['value'])) : ?>
         <h3><?php echo $node->{'field_pricing_title' . $i}['und'][0]['value']?></h3>
       <?php endif; ?>

       <table>
        <tr class="th-shadow">
         <th class="th-instrument">Instrument</th>
         <th class="th-spread">Spread</th>
         <th class="th-sell">Sell</th>
         <th class="th-buy">Buy</th>
         <!-- <th class="th-open">+/- Change<br />Open</th> -->
        </tr>
        <?php foreach($node->{'field_pricing_products' . $i}['und'] as $product_nid): ?>

        <?php if (!empty($instruments[$product_nid['nid']])) : ?>
          <?php $price = $instruments[$product_nid['nid']]; ?>
          <tr class="pricing" rel="<?php echo $price['pricing']['pricing']['symbol']; ?>">
           <td class="title"><?php echo l($price['product']['title'], 'node/' . $price['product']['nid']); ?></td>
           <td class="spread"><?php echo (!empty($price['pricing']['price']->spread)) ? $price['pricing']['price']->spread: ''; ?></td>
           <td class="bid">
             <span class="value"><?php echo (!empty($price['pricing']['price']->bid)) ?  $price['pricing']['price']->bid: ''; ?></span>
             <span class="movement"></span>
           </td>
           <td class="ask">
             <span class="value"><?php echo (!empty($price['pricing']['price']->ask)) ? $price['pricing']['price']->ask: ''; ?></span>
             <span class="movement"></span>
           </td>
           <!-- <th><?php echo (!empty($price['pricing']['price']->open)) ? $price['pricing']['price']->open: ''; ?></th> -->
          </tr>
        <?php endif; ?>
        <?php endforeach; ?>

       </table>
      </div>
    <?php endif; ?>

  <?php endif; ?>

<?php endfor; ?>

</div>
