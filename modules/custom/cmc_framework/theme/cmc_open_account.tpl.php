

<div class="signpost-links">
  <div class="<?php echo $data['class1']; ?>">
  <a href="<?php echo $data['url1']; ?>"><?php echo $data['text1']; ?></a>
  </div>
  <div class="<?php echo $data['class2']; ?>">
  <a href="<?php echo $data['url2']; ?>"><?php echo $data['text2']; ?></a>
  </div>
  
  <footer class="disclaim">
    <?php echo $data['footer']; ?>
    <?php if($data['edit']): ?>
      <p><?php echo $data['edit']; ?></p>
    <?php endif; ?>
  </footer>
</div>
