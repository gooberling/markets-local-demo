// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_1024 = {

		attach: function(context) {
			jQuery('html').once('cmc_core_1024', function() {
			//-----------------------------------------------------------------------------------------------
			// set 1024 class for IE to respond on narrowers screens
			//-----------------------------------------------------------------------------------------------
			$(window).bind("resize", fix1024);
			fix1024();

			function fix1024(e) {
				var winWidth = $(window).width();
				if (winWidth >= 966 && winWidth <= 1220) {
					$('body').addClass('resize1024');

				} else {
					$('body').removeClass('resize1024');
				}
			}

			// end script
		});
		}
	};
}(jQuery));
