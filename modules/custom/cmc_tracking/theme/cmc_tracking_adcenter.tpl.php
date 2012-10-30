<?php
// adcenter tracking tags
?>
<!-- adcenter BEGIN -->
<script type="text/javascript">if (!window.mstag) mstag = {loadTag : function(){},time : (new Date()).getTime()};</script>
<script id="mstag_tops" type="text/javascript" src="//flex.atdmt.com/mstag/site/<?php echo $tracking['site_id'] ?>/mstag.js"></script>
<script type="text/javascript"> mstag.loadTag("analytics", {dedup:"1",domainId:"<?php echo $tracking['domain_id'] ?>",type:"1",actionid:"<?php echo $tracking['action_id'] ?>"})</script>
<noscript><iframe src="//flex.atdmt.com/mstag/tag/<?php echo $tracking['site_id'] ?>/analytics.html?dedup=1&domainId=<?php echo $tracking['domain_id'] ?>&type=1&actionid=<?php echo $tracking['action_id'] ?>" frameborder="0" scrolling="no" width="1" height="1" style="visibility:hidden;display:none"> </iframe></noscript>
<!-- adcenter END -->
