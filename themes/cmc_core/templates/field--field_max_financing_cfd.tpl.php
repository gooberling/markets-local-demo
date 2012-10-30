<?php
/**
 * @see template_preprocess_field()
 * @see theme_field()
 */

$margin = (float)$items[0]['#markup'];
$margin_pct = (int)round(100 * $margin);

?>

<h4><?php echo t('CFD Margin'); ?></h4>
<p>0%-<?php echo $margin_pct; ?>%</p>
