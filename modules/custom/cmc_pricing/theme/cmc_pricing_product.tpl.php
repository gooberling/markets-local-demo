

<?php cmc_pricing_add_js();?>

<?php

if (empty($truncate)) {
  $title = l($node->title, 'node/' . $node->nid);
}
else {
  $title = truncate_utf8($node->title, 15, FALSE, TRUE, 1);
  $options = array(
    'attributes' => array(
      'title' => $node->title,
    ),
  );
  $title = l($title, 'node/' . $node->nid, $options);
}
?>

<div class="pricing" rel="<?php echo (!empty($pricing['pricing']['symbol'])) ? $pricing['pricing']['symbol'] : ''; ?>">

<h3><?php echo $title; ?></h3>

<div class="prices">
  <ul>
    <li>
      <span class="ask">
        <span class="value"><?php echo (!empty($pricing['price']->ask)) ? $pricing['price']->ask: ''; ?></span>
        <span class="movement"></span>
      </span>
    </li>
    <li>
      <span class="bid">
        <span class="value"><?php echo (!empty($pricing['price']->bid)) ? $pricing['price']->bid: ''; ?></span>
        <span class="movement"></span>
      </span>
    </li>
  </ul>
</div>
<ul class="details">
  <li class="spread-details">Spread <span class="spread"><?php echo (!empty($pricing['price']->spread)) ? $pricing['price']->spread: ''; ?></span></li>
<!--  <li class="open">Open <span><?php echo (!empty($pricing['price']->open)) ? $pricing['price']->open: ''; ?></span></li>-->
  <!-- <li>Change <span>1.5</span></li>-->
</ul>


</div>
