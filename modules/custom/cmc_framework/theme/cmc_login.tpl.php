<menu class="buttons">
  <a href="<?php echo url($data['signup']['url']); ?>" class="signup"><?php echo $data['signup']['text']; ?></a>
  <a href="<?php echo url($data['login']['url']); ?>" class="login"><?php echo $data['login']['text']; ?></a>
   
  <div class="login-layer">
    <?php for ($i=1; $i<=4; $i++):
      $url = 'url' . $i;
      $text = 'text' . $i;
      $class = 'class' . $i;
    ?>
      <?php if ($data[$url] && $data[$text]): ?>
        <p class="<?php echo ($data[$class]) ? $data[$class] : '';?>">
          <a href="<?php echo $data[$url]; ?>"><?php echo $data[$text]; ?></a>
        </p>
      <?php endif; ?>
    <?php endfor; ?>
    
    <?php if (!empty($data['promo'])): ?>
      <div class="login-promo">
        <?php if (!empty($data['promo']['image'])): ?>
          <div class="login-promo-image"><?php echo $data['promo']['image']; ?></div>
        <?php endif; ?>
        
        <?php if (!empty($data['promo']['content'])): ?>
          <div class="login-promo-text"><?php echo $data['promo']['content']; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    
    <?php if($data['edit']): ?>
     <div class="edit"><?php echo $data['edit']; ?></div>
    <?php endif; ?>
  </div>

</menu>

