// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_login = {
		
		login_popup_clicked: false,
		attach: function(context) {
			jQuery('html').once('cmc_core_login', function() {
			//-----------------------------------------------------------------------------------------------
			// login layer pop up
			//-----------------------------------------------------------------------------------------------
			// show
			$(".buttons .login").click(function(e) {
				var login_button = $(this);
				login_button.toggleClass("active");

				// only fire once if clicking on login
				// does it make current page referer?
				// To try and keep Wil happy...
				if (window._gaq && Drupal.behaviors.cmc_core_login.login_popup_clicked === false) {
					window._gaq.push(["_trackPageview", '/login-popup']);
					Drupal.behaviors.cmc_core.login_popup_clicked = true;
				}

				var login_layer = $('.login-layer');
				// so it shows above everything
				
				if (login_layer.is(':hidden')) {
					login_layer.fadeIn('fast');
				} else {
					login_button.removeClass("active");
					login_layer.hide();
				}

				// hover state to remove
				// hover seems to be better than mouseover
				login_layer.hover(function(e) {
					// do nothing
				}, function(e) {
					login_layer.hide();
					login_button.removeClass("active");
				});

				e.preventDefault();
			});


			// end script
		});
		}
	};
}(jQuery));
