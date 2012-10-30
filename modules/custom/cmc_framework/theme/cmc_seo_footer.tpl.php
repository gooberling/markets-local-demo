

<?php if ($data['edit']): ?>
  <div class="edit-link"><?php echo $data['edit']; ?></div>
<?php endif; ?>

<?php foreach($data['links'] as $i => $section_links): ?>
  <div class="grid-2">
    <?php $heading = $section_links['heading']; ?>
    <h4><?php echo l($heading['link_title'], $heading['link_path']); ?></h4>
    
    <?php if(!empty($section_links['tree'])): ?>
    <ul class="child-links">
      <?php foreach($section_links['tree'] as $id => $child): ?>
        <?php $item = $child['link']; ?>
        <li><?php echo l($item['link_title'], $item['link_path']) ?></li>
      <?php endforeach; ?>
    </ul>
    <?php endif; ?>
  </div>
<?php endforeach; ?>

<div class="grid-2 contact last-col">
  <address>
  <?php echo implode("<br />", $data['location'])?>
  </address>
  
  <ul class="details">
  <?php
  $fields = array(
    'telephone',
    'fax',
    'email',
  );
  foreach($fields as $field): ?>
    <?php if (!empty($data[$field])): ?>
    <li class="<?php echo $field; ?>"><?php echo $data[$field]?></li>
    <?php endif; ?>
  <?php endforeach; ?>
  </ul>
  
</div>
