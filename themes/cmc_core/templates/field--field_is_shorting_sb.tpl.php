<?php
/**
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>

<h4><?php echo t('Shorting'); ?></h4>
<p><?php echo $items[0]['#markup'] === '1' ? t('Allowed') : t('Not allowed') ?></p>

