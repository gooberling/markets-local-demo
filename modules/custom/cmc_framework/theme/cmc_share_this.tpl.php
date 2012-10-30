
<style type="text/css">
#fb_share {

  }
.FBConnectButton_Simple {
  /*
  Replace the background image with whatever we want
  Might need to be here so it overrides fb css?
  */
  background-image: url('<?php echo $data['module_path']; ?>/img/share-this-facebook.png');
  width:50px;
  height:50px;
  display:block;
}

#custom-tweet-button {
  display: block;
  background-image: url('<?php echo $data['module_path']; ?>/img/share-this-twitter.png');
  width:50px;
  height:50px;
}
</style>
 
<div id="share-this-buttons">
<!-- TWITTER -->
<a id="custom-tweet-button" href="https://twitter.com/share?url=<?php echo urlencode($data['url']); ?>&text=<?php echo urlencode($data['title']) ?>" target="_blank"></a>
<script type="text/javascript">!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>

<!-- FACEBOOK -->
<a id="fb_share" name="fb_share" type="icon"></a>
<script src="http://static.ak.fbcdn.net/connect.php/js/FB.Share"
        type="text/javascript">
</script>
</div>

<span id="share-this-toggle"><?php echo t('Share this page'); ?></span>


