<?php
//$values = cmc_adform_embed_js();
$adform_js_url = variable_get('cmc_adform_javascript_src', '');
$adform_ac_no = variable_get('cmc_adform_account_no', '');
$divider = '|';

if (empty($adform['page_name'])) {
  $adform['page_name'] = cmc_adform_get_page_name();
}

?>
<!-- Adform Tracking Code BEGIN -->
<script type="text/javascript" src="<?php print $adform_js_url ?>"></script>
<script type="text/javascript">
Adform.Tracking.Params.PageName = encodeURIComponent('<?php echo $adform['page_name'] ?>');
Adform.Tracking.Params.Divider = encodeURIComponent('<?php echo $divider ?>');

<?php if (!empty($adform['sale_value'])): ?>
Adform.Tracking.Vars.Sale = '<?php echo $adform['sale_value']; ?>';
Adform.Tracking.Vars.OrderID = '<?php echo (!empty($adform['order_id'])) ? $adform['order_id'] : ''; ?>';
Adform.Tracking.Vars.BasketSize = '1';
<?php endif; ?>

<?php if (!empty($adform['tracking_division'])): ?>
Adform.Tracking.Vars.TD = '<?php echo $adform['tracking_division']; ?>';
<?php endif; ?>

Drupal.behaviors.cmc_tracking.add('external', function() {
  try {
    Adform.Tracking.Track(<?php echo $adform_ac_no; ?>);
  } catch (e) {
    // Do nothing, just catch so that error doesn't prevent normal page behaviour
  }
});

</script>
<noscript>
<p style="margin:0;padding:0;border:0;"><img src="<?php echo $adform_js_url; ?>?pm=<?php print $adform_ac_no ?>&amp;ADFPageName=<?php print $adform['page_name']?>&amp;ADFdivider=<?php echo $divider ?>" width="1" height="1" alt="" /></p>
</noscript>
<!-- Adform Tracking Code END -->
