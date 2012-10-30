<?php
// http://code.google.com/apis/analytics/docs/gaJS/gaJSApiBasicConfiguration.html#_gat.GA_Tracker_._trackPageview
// any way to ensure it goes in after the google analytics stuff?
// we want to track a pageview which we set
// if we're in here, make sure we've removed the default _trackPageview() so
// it's not called twice - we use cmc_tracking_js_alter to remove it...
?>
<?php if ($pageview): ?>
<!-- Google Analytics TrackPageView BEGIN -->
<script type="text/javascript">
var gaq = _gaq || [];
Drupal.behaviors.cmc_tracking.add('local', function() {
  _gaq.push(["_trackPageview", "<?php echo $pageview ?>"]);
});
</script>
<!-- Google Analytics TrackPageView END -->
<?php endif; ?>
