(function($) {
	/**
	 *
	 */
	Drupal.behaviors.cmc_triptych = {
		attach: function(context) {
			// tryptich landing page layout just for desktop
			$(window).bind("resize", function() {
				tryptychLanding()
			});
			tryptychLanding();

			function tryptychLanding() {

				var block = $('.triptych');
				var winHeight = $(window).height();
				var colHeight = winHeight - ($("#header").outerHeight() + 15);

				block.css('height', colHeight);
				$(".hero-image-triptych").css('height', winHeight);


			}
		}
	}
})(jQuery);
