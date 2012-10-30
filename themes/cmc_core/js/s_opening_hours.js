// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02

(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_hours = {

		attach: function(context) {
			jQuery('html').once('cmc_core_hours', function() {
			//-----------------------------------------------------------------------------------------------
			// Opening Times Show Hide
			//-----------------------------------------------------------------------------------------------
			$('.hours ul a').click(function(e) {
					e.preventDefault();

					if ($(this).parent().hasClass('active')) {
							return false;
					} else {
							$(this).parent().addClass('active');
							$(this).parent().siblings().removeClass('active');
							$('.hours li span.opening-times').hide();
							$('.hours li.active span.opening-times').fadeIn('slow');

					}
			});


			// end script
		});
		}
	};
}(jQuery));
