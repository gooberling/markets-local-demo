(function ($) {

  Drupal.behaviors.cmc_wysiwyg = {
    attach: function (context, settings) {
	
	//-----------------------------------------------------------------------------------------------
	// Image Library
	//-----------------------------------------------------------------------------------------------	
	
	// When the 'Enter' key is pressed when focus is on the filename field replicate the behaviour of using the 'Filter' button
	jQuery('div.media-browser-tab #edit-filename').keydown(function(e) {
		if (e.keyCode == 13){
		jQuery('a.exposed-button').click();
		e.preventDefault();
		}
	});
      
    }
  };  
})(jQuery);
