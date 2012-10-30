<?php
echo '<?xml version="1.0" encoding="utf-8"?>';
?>
<charteducation>
  <node>
    <language><?php echo $data['language']; ?></language>
    <id><?php echo $data['chart_id']; ?></id>
    <title><?php echo $data['title']; ?></title>
    <body>
      <?php echo $data['body']; ?>
    </body>
  </node>
</charteducation>