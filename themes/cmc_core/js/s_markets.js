// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
(function($) {

	//-----------------------------------------------------------------------------------------------
	// AJAX callback for scripts that need to run after AJAX event
	//-----------------------------------------------------------------------------------------------
	// http://drupal.org/node/491400
	// http://www.jaypan.com/tutorial/calling-function-after-ahah-event-drupal-6-or-ajax-event-drupal-7
	$(document).ajaxComplete(function(e, xhr, settings) {

		//-----------------------------------------------------------------------------------------------
		// faceted search block, blue titles
		//-----------------------------------------------------------------------------------------------
		$('#main-content div.region-filter-block .block-facetapi').each(function(i) {
			block_widget = $(this);

			var active = $('a.facetapi-active', block_widget);
			if (active.length) {
				// has an active facet
				block_widget.addClass('filtered');
			} else {
				// remove class on block widget
				block_widget.removeClass('filtered');
			}
		});

	});

})(jQuery);