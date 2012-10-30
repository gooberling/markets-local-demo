<?php
// http://code.google.com/apis/analytics/docs/tracking/gaTrackingEcommerce.html#General
?>
<!-- Google Analytics eCommerce BEGIN -->
<script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_addTrans',
    '<?php echo $tracking['order']['id'] ?>', // order ID - required
    '<?php echo $tracking['order']['store_name'] ?>', // affiliation or store name
    '<?php echo $tracking['order']['total'] ?>', // total - required
    '<?php echo $tracking['order']['tax'] ?>', // tax
    '<?php echo $tracking['order']['shipping'] ?>', // shipping
    '<?php echo $tracking['order']['city'] ?>', // city
    '<?php echo $tracking['order']['state'] ?>', // state or province
    '<?php echo $tracking['order']['country'] ?>' // country
  ]);

  // add item might be called for every item in the shopping cart
  <?php foreach($tracking['items'] as $item) : ?>
  _gaq.push(['_addItem',
    '<?php echo $item['id'] ?>', // order ID - required
    '<?php echo $item['sku'] ?>', // SKU/code - required
    '<?php echo $item['product_name'] ?>', // product name
    '<?php echo $item['category'] ?>',   // category or variation
    '<?php echo $item['unit_price'] ?>', // unit price - required
    '<?php echo $item['quantity'] ?>' // quantity - required
  ]);
  <?php endforeach; ?>
  _gaq.push(['_trackTrans']); //submits transaction to the Analytics servers
</script>
<!-- Google Analytics eCommerce END -->