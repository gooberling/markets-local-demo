
<?php //print_r($data); ?>
<?php foreach ($data['blocks'] as $k => $v): ?>

  <div class="signup <?php echo $v['class']; ?>">
    <?php echo t($v['content']); ?>
  </div>

<?php endforeach; ?>

<?php echo $data['edit']?>
