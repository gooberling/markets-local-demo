<?php
echo '<?xml version="1.0" encoding="utf-8"?>';
?>
<nodes>
  <?php foreach ($data as $row): ?>
    <node>
      <language><?php echo $row['language']; ?></language>
      <id><?php echo $row['chart_id']; ?></id>
      <title><?php echo $row['title']; ?></title>
    </node>
  <?php endforeach; ?>
</nodes>