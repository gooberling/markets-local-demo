<div id="country-switcher">
  <ul>
    <?php
    $i=0;
    foreach($data['countries'] as $country => $url){
      $class = ($i==0) ? ' class="first"': '';
      $i++;
      echo '<li' . $class . '>' . l(t($country), $url). '</li>';
    }
    ?>
    <?php if($data['edit']): ?>
      <li><?php echo $data['edit']; ?></li>
    <?php endif; ?>
  </ul>
  <a class="switch"><?php echo $data['switch']; ?></a>
</div>

