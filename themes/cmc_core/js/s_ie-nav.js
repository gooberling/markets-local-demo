// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_ienav = {

		attach: function(context) {
			jQuery('html').once('cmc_core_ienav', function() {
			//-----------------------------------------------------------------------------------------------
			// this fills in the blank space left by the see-through nav items
			//-----------------------------------------------------------------------------------------------
			if ($.browser.msie) {
				$("tr:odd").addClass('even');


				var li_width = 0;
				// get width of all the navigation 'li's
				$('#header ul.menu li').each(function(i) {
					li_width += $(this).outerWidth();
				});
				var navwidth = $("#header ul.menu").outerWidth();
				// add the extra li
				if ($('#header ul.menu .filler').length < 1) {
					$("#header ul.menu").append('<li class="filler"></li>');
				}
				var filler_width = ((navwidth - li_width) / navwidth) * 100 + '%';
				//						 // set its width to fill the space
				// if ($.browser.version == 9.0) {
				//				$('#header ul.menu li.filler').css('width', (filler_width-1));
				//			} else {
				$('#header ul.menu li.filler').css('width', filler_width);
				//}
			}

			// remove class after JS has loaded.	Just added to make appearence better for page load
			$('#header').removeClass('loading');

			// end script
		});
		}
	};
}(jQuery));
