// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_showHide = {

		attach: function(context) {
			//-----------------------------------------------------------------------------------------------
			// Education Landing Page - Show More
			//-----------------------------------------------------------------------------------------------
			$('div.pager-actions a.show-more').click(function(e) {
				e.preventDefault();

				var box_height = $(this).parent().parent().find('div.view-content').height();

				var item_count = $(this).parent().parent().find('div.view-content div.landing-list ul li').size();

				var max_size = (Math.ceil(item_count / 5)) * 230;

				if (box_height + 230 == max_size) {

					$(this).css('display', 'none');
					$(this).parent().find('a.show-all').css('display', 'inline');
				}

				$(this).parent().find('a.show-less').css('display', 'inline');

				$(this).parent().parent().find('div.view-content').animate({
					height: box_height + 230
				}, 400, 'easeOutCirc', function() {
					// Animation complete.
				});


			});

			//-----------------------------------------------------------------------------------------------
			// Education Landing Page - Show Less
			//-----------------------------------------------------------------------------------------------
			$('div.pager-actions a.show-less').click(function(e) {
				e.preventDefault();

				var box_height = $(this).parent().parent().find('div.view-content').height();

				$(this).parent().find('a.show-more').css('display', 'inline');
				$(this).parent().find('a.show-all').css('display', 'none');

				if (box_height == 460) {

					$(this).css('display', 'none');

				}

				$(this).parent().parent().find('div.view-content').animate({
					height: box_height - 230
				}, 400, 'easeOutCirc', function() {
					// Animation complete.
				});
			});
		}
	};

	// end script


}(jQuery));
