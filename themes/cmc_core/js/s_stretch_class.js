// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 13/09

(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_stretch = {

		attach: function(context) {
			jQuery('html').once('cmc_core_stretch', function() {
			//-----------------------------------------------------------------------------------------------
			// set odd width that effects header background
			//-----------------------------------------------------------------------------------------------
			$(window).bind("resize", fixHeader);
			fixHeader();
			function fixHeader(e) {
					var winWidth = $(window).width();

					if (winWidth % 2 == 1) {
							$('body').addClass('stretch');
					} else {
							$('body').removeClass('stretch');
					}
			}

			// end script
		});
		}
	};
}(jQuery));
