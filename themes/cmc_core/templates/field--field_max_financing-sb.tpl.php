<?php
/**
 * @see template_preprocess_field()
 * @see theme_field()
 */

$margin = (float)$items[0]['#markup'];
$margin_pct = (int)round(100 * $margin);

?>

<h4><?php echo t('SB Margin'); ?></h4>
<p><?php echo 100 - $margin_pct; ?>%</p>
