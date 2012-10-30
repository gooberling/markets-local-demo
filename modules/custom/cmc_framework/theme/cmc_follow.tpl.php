
<style type="text/css">
#block-cmc-framework-cmc-follow .twitter {
  background-image: url('<?php echo $data['module_path']; ?>/img/share-this-twitter.png');
}
#block-cmc-framework-cmc-follow .facebook {
  background-image: url('<?php echo $data['module_path']; ?>/img/share-this-facebook.png');
}
#block-cmc-framework-cmc-follow .youtube {
  background-image: url('<?php echo $data['module_path']; ?>/img/share-this-youtube.png');
}

</style>
<div id="share-this-buttons">
<?php foreach ($data['links'] as $k => $v): ?>
 <a class="<?php echo $k;?>" href="<?php echo $v; ?>" target="_blank"></a>
<?php endforeach; ?>
</div>

<span id="share-this-toggle"><?php echo t($data['text']); ?></span>


