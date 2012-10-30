<?php
// http://code.google.com/apis/analytics/docs/tracking/eventTrackerGuide.html
?>
<!-- Google trackEvent BEGIN -->
<script type="text/javascript">
var gaq = _gaq || [];
<?php foreach($tracking as $t): ?>
<?php
  $event = array();
  $event[] = $t['category'];
  $event[] = $t['action'];
  
  $params = array(
    'opt_label',
    'opt_value',
   	'opt_noninteraction',
  );
  
  foreach ($params as $param) {
    if ((!empty($t[$param]))) {
      $event[] = $t[$param];
    }
  }
?>
_gaq.push(['_trackEvent', '<?php echo implode("','", $event)?>']);
<?php endforeach; ?>
</script>
<!-- Google trackEvent END -->
