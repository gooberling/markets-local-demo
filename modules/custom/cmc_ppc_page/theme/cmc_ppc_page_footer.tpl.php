
<address>
  <span><?php echo implode("</span><span>", $location)?></span>
</address>

<ul class="details">
<?php
$fields = array(
  'telephone' => $telephone,
  'fax' => $fax,
  'email' => $email,
);
foreach($fields as $k => $v): ?>
  <?php if (!empty($v)): ?>
  <li class="<?php echo $k; ?>"><strong><?php echo ucfirst(t($k)) ?>:</strong> <?php echo $v; ?></li>
  <?php endif; ?>
<?php endforeach; ?>
</ul>