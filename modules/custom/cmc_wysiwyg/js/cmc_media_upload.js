(function($) {

  /**
   * 
   */
  Drupal.behaviors.cmc_wysiwyg_media_upload = {
      attach: function (context, settings) {

        var media_upload_form = $('#media-add-upload');
        
        $('#edit-upload').focus(function(e){
        });
        
        $('#edit-upload').blur(function(e){
          // we take a guess at what kind of file it is
          // should be in config
        });
        
        $('#edit-upload').mouseout(function(e){

          var filename = $(this).val();
          if (filename) {
          }
          
        });
      }
    };
  
     
  
})(jQuery);
