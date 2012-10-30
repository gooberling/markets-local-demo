

<?php cmc_pricing_add_js();?>

<div class="pricing" rel="<?php echo (!empty($pricing['pricing']['symbol'])) ? $pricing['pricing']['symbol'] : ''; ?>">
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
</div>
