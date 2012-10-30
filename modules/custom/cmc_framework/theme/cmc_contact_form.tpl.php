
<?php echo $form; ?>



  <dl>
    <dt><?php echo t('Address') ?></dt>
      <dd><?php echo implode("<br />\n", $location); ?></dd>
    <dt><?php echo t('Phone') ?></dt>
      <dd><?php echo $telephone ?></dd>
    <dt><?php echo t('Fax') ?></dt>
      <dd><?php echo $fax ?></dd>
    <dt><?php echo t('Email') ?></dt>
      <dd><?php echo '<a href="mailto:' . $email .'">' . $email . '</a>'; ?></dd>
  </dl>
  
