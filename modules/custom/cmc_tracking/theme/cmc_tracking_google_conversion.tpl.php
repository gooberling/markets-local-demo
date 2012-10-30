<?php
// http://support.google.com/adwords/bin/answer.py?hl=en&answer=1722054
?>
<!-- Google Conversion BEGIN -->
<script type="text/javascript">
/* <![CDATA[ */
var google_conversion_id = "<?php echo $conversion['id'] ?>";
var google_conversion_language = "<?php echo $conversion['language'] ?>";
var google_conversion_format = "<?php echo $conversion['format'] ?>";
var google_conversion_color = "<?php echo $conversion['color'] ?>";
var google_conversion_label = "<?php echo $conversion['label'] ?>";
var google_conversion_value = <?php echo $conversion['value'] ?>;
/* ]]> */
</script>
<script type="text/javascript" src="<?php echo cmc_tracking_protocol() ?>www.googleadservices.com/pagead/conversion.js"></script>
<noscript>
<img height="1" width="1" border="0"
src="<?php echo cmc_tracking_protocol() ?>www.googleadservices.com/pagead/conversion/<?php echo $conversion['id'] ?>/?value=<?php echo $conversion['value'] ?>&label=<?php echo $conversion['label'] ?>&amp;guid=ON&amp;script=0">
</noscript>
<!-- Google Conversion END -->
