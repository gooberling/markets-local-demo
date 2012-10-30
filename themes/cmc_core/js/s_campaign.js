// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_campaign = {

		attach: function(context) {
			jQuery('html').once('cmc_core_campaign', function() {
				//-----------------------------------------------------------------------------------------------
				// Campaign Pages
				//-----------------------------------------------------------------------------------------------
				$(window).bind("resize", function() {
					campaignLanding()
				});
				campaignLanding();

				function campaignLanding() {
					var winHeight = $(window).height();
					$(".campaign").css('height', winHeight);
				}


				if ($.browser.msie && $.browser.version <= 8.0) {
					// do nothing
				} else {

					// there might be more than one signpost link here so loop thru
					$('.campaign-signpost1 a').each(function(i) {

						var link = $(this);
						var parent = $(link.parent());

						// duplicate signpost link to be able to do pop up
						// true parameter so we also copy events and data handlers
						link.clone(true).appendTo(parent);

						// change style of duplicate
						$('a:nth-child(2)', parent).css({
							color: 'white',
							background: 'black'
						});

						// move both links up together
						var toppos = '-45px';


						parent.mouseover(function() {
							$('a:nth-child(n)', parent).animate({
								top: toppos
							}, {
								duration: 500,
								queue: false
							});
							return false;
						});


						// move them back down
						parent.mouseout(function() {
							$('a:nth-child(n)', parent).animate({
								top: '0'
							}, {
								duration: 500,
								queue: false
							});
							return false;
						});
					});

					// remove up arrow on load
					$('body.campaign-page input.prev').css('display', 'none');
				}

				$('body.campaign-page li.campaign-nav a').click(function() {
					$('body.campaign-page li.campaign-nav a').removeClass('active');
					$(this).addClass('active');
				});





				// end script
			});
		}
	};
}(jQuery));
