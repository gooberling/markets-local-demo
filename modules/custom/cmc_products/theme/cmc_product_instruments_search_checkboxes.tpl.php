<div id ="<?php echo drupal_html_id("product-search-instruments"); ?>" class ="form-checkboxes <?php echo drupal_html_class("product-search-instruments"); ?> "> 
  <?php foreach ($result as $id => $item): ?>
    <?php //print($item["title"]); ?>
  <input class="form-item form-type-checkbox" type ="checkbox" name ="instruments" value ="<?php print ($item["field_instrument_code"]); ?>"/> <?php print $item["title"]; ?> 
  <?php endforeach; ?>
</div>


