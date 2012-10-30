// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_signupLink = {

		attach: function(context) {
			jQuery('html').once('cmc_core_signupLink', function() {
			//-----------------------------------------------------------------------------------------------
			// check that this isnt IE8 and duplicate signup link
			//-----------------------------------------------------------------------------------------------
			if ($.browser.msie && $.browser.version <= 8.0) {
				// do nothing
			} else {

				// there might be more than one signpost link here so loop thru
				$('.signpost1 a').each(function(i) {

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
					if ($('body,html').hasClass('is-front')) {
						var toppos = '-45px';
					} else {
						var toppos = '-33px';
					}

					parent.mouseover(function() {
						$('a:nth-child(n)', parent).animate({
							top: toppos
						}, {
							duration: 500,
							queue: false,
							easing: 'easeOutQuint'
						});
						return false;
					});

					// move them back down
					parent.mouseout(function() {
						$('a:nth-child(n)', parent).animate({
							top: '0'
						}, {
							duration: 500,
							queue: false,
							easing: 'easeOutQuint'
						});
						return false;
					});
				});


			}


			// end script
		});
		}
	};
}(jQuery));
