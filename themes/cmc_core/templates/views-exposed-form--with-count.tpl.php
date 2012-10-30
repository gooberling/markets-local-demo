<div>
<?php
$view_path = substr($form['#action'], 1);

$total = cmc_search_total_results($view_path);
$count = cmc_search_results_count();
$view_all_link =  l(t('View all'), $view_path);

if ($count === NULL) {
  $count = $total;
}

?>
    <?php foreach ($widgets as $id => $widget): ?>
      <div id="<?php print $widget->id; ?>-wrapper" class="views-exposed-widget views-widget-<?php print $id; ?>">
        <?php if (!empty($widget->label)): ?>
          <label for="<?php print $widget->id; ?>">
            <?php print $widget->label; ?>
          </label>
        <?php endif; ?>
        <?php if (!empty($widget->operator)): ?>
          <div class="views-operator">
            <?php print $widget->operator; ?>
          </div>
        <?php endif; ?>
        <div class="views-widget">
          <?php print $widget->widget; ?>
        </div>
      </div>
    <?php endforeach; ?>
<?php /* seems to need this else ajax.js breaks */ ?>
    <div class="views-exposed-widget views-submit-button">
      <?php print $button; ?>
    </div>
    <div class="view-all">
      <span class="results-count"><?php echo $count; ?></span>
      <span class="total-results-count"><span>/</span> <?php print $total; ?></span>
      <span class="link"><?php print $view_all_link; ?></span>
    </div>
</div>
