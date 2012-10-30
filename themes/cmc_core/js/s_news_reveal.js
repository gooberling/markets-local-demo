// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_reveal = {

		attach: function(context) {
			//-----------------------------------------------------------------------------------------------
			// news stories reveal
			//-----------------------------------------------------------------------------------------------
			$('.page-news .tabbed .view-content li, .markets-section .tabbed .view-content li').each(function(i) {
				return_height = ($('.view-third-party-news ul:first > li').outerHeight() * $('.view-third-party-news ul:first > li').length) + 220;

				var el = $(this);
				var el_height = el.height();

				el.attr('height', el_height);
				el.css('height', 125);

				var news_tab_height = return_height + parseInt(el.attr('height'));

				if (el.attr('height') > 125) {
					$(this).addClass('long');
				}

				$('a.show, h3', el).click(function(e) {
					e.preventDefault();

					// if it is a short block do nothing
					if (el.attr('height') <= 125) {

						return;
					}

					var h, t;

					$(this).parent().toggleClass('long-hover');
					if (parseInt(el.css('height')) <= 125) {
						h = el_height;
						t = news_tab_height - 125;
					} else {
						h = 125;
						t = return_height;
					}

					$(el).animate({
						height: h
					}, 400, 'easeOutCirc', function() {
						el.siblings().animate({
							height: 125
						}, 200, 'easeOutCirc');
					});
					$('.tabbed').animate({
						height: t
					}, 400, 'easeOutCirc', function() {
					});
				});
			});

			// end script
		}
	};
}(jQuery));
