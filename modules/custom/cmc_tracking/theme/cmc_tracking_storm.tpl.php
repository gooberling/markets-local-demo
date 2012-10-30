<?php
$path = drupal_get_path('module', 'cmc_tracking');
?>
<!-- Storm BEGIN -->
<script type="text/javascript">
var __stormJs = 'intelligence.dgmsearchlab.com/dcv4/jslib/2785_9AD6483A_2349_4AF0_AE04_95D5A2BB731F.js';
</script>
<script type="text/javascript" src="<?php echo url($path . '/js/storm.js') ?>"></script>

<?php if (!empty($tracking['order_id'])): ?>
<script type="text/javascript">
saleTrack.addSaleItem(1, 1.00, '<?php echo $tracking['type'] ?>', '<?php echo $tracking['email_address'] ?>');
saleTrack.orderid = '<?php echo $tracking['order_id'] ?>';
saleTrack.logSale(1);
</script>
<?php endif; ?>
<!-- Storm END -->
