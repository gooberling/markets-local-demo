(function($) {
	/**
	 *
	 */
	Drupal.behaviors.cmc_framework = {
		attach: function(context) {
			
			var switcher_block = $('#country-switcher');
			var country_list = $('ul', switcher_block);
			country_list.hide();

			// show/hide the country selector
			$(switcher_block).hover(

			function() {
				$('.switch').addClass("up");

				$(country_list).stop(true, true).animate({
					height: 'toggle',
					queue: false,
					easing: 'easeInQuart'
				}, 200, function() {});
			}, function() {
				$('.switch').removeClass("up");

				$(country_list).stop(true, true).animate({
					height: 'toggle',
					queue: false,
					easing: 'easeInQuart'
				}, 200, function() {});
			});


			// twitter button popup
			var twitter_share = $('#custom-tweet-button');
			if (twitter_share.length > 0) {
				twitter_share.click(function(e) {
					var url = $(this).attr('href');
					window.open(url, 'twitter_share', 'width=480,height=360');
					e.preventDefault();
				});
			}

			// open up the buttons
			var share_block = $('#block-cmc-framework-cmc-follow');
			var buttons = $('#share-this-buttons', share_block);
			buttons.hide();

			// show/hide the social icons
			$(share_block).hover(

			function() {
				$(buttons).stop(true, true).animate({
					height: 'toggle',
					easing: 'easeInQuart'
				}, 250, function() {});
			}, function() {
				$(buttons).stop(true, true).animate({
					height: 'toggle',
					easing: 'easeInQuart'
				}, 250, function() {});
			});
		}
	}
})(jQuery);
