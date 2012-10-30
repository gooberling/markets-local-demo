// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for blue line.


// Using the closure to map jQuery to $.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_generic = {

		attach: function(context) {
			jQuery('html').once('cmc_core_generic', function() {
				
				//-----------------------------------------------------------------------------------------------
				// iPad slide subnav
				//-----------------------------------------------------------------------------------------------
				$("a.menu-reveal").click(function() {
					$("#main-wrapper").toggleClass('slide');
					$(this).toggleClass('slide');
				});


				//-----------------------------------------------------------------------------------------------
				// ACCORDION
				//-----------------------------------------------------------------------------------------------
				$('div.accordion').each(function(i) {
					var accordion = $(this);
					var accordion_title = $('.title', accordion);
					var accordion_content = $('div.detail', accordion);
					accordion_content.hide();

					accordion_title.prepend('<span> </span>');
					accordion_title.hover(function(e) {
						$(this).css('cursor', 'pointer');
					}, function(e) {
						$(this).css('cursor', 'default');
					});
					// hide the content
					// toggle the content
					accordion_title.click(function(e) {
						e.preventDefault();
						accordion_content.slideToggle('slow');
						$(this).toggleClass('open');
					});
				});

				//-----------------------------------------------------------------------------------------------
				// Placeholder fix for non HTML5 browsers
				//-----------------------------------------------------------------------------------------------
				if (typeof document.createElement("input").placeholder == 'undefined') {

					$('[placeholder]').focus(function() {
						var input = $(this);
						if (input.attr('placeholder').match(input.val())) {
							input.val('');
							input.removeClass('manual_placeholder');
						}
					})

					.blur(function() {
						var input = $(this);
						if (input.val() == '' || input.attr('placeholder').match(input.val())) {
							input.addClass('manual_placeholder');
							input.val(input.attr('placeholder'));
						}
					})

					.blur().parents('form').submit(function() {
						$(this).find('[placeholder]').each(function() {
							var input = $(this);
							if (input.attr('placeholder').match(input.val())) {
								input.val('');
							}
						})
					});
				}


			// end script
			});
		}
	};
}(jQuery));

