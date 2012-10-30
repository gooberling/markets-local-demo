(function($) {
	/**
	 *
	 */
	Drupal.behaviors.cmc_hero = {
		attach: function(context) {

			var block_id = '#hero-transition';
			var heroes = $('.hero.row1');

			var transition_speed = Drupal.settings.cmc_hero.transition_speed;

			if (heroes.length) {
				if ($.browser.msie && $.browser.version <= 8.0) {
					// for IE 7 & 8 do slide
					$(block_id).cycle({
						fx: 'fade',
						speedIn: 800,
						speedOut: 800,
						easeIn: 'linear',
						easeOut: 'linear',
						delay: -6000,
						cleartype: true,
						cleartypeNoBg: true,
						//pager : '#hero-nav',
						slideExpr: 'div.hero',
						next: '.region-landing-page .next',
						prev: '.region-landing-page .prev',
						something: '',
						timeout: transition_speed,
						cssBefore: {
								//marginLeft: 300,
								opacity: 0
								
							},
						animIn: {
							//marginLeft: 0,
							opacity: 1
						},
						animOut: {
							//marginLeft: 300,
							opacity: 0
						}
					});
				} else {
					// for everything else do the fade
					$(block_id).cycle({
						fx: 'fade',
						speedIn: 800,
						speedOut: 600,
						easeIn: 'easeInCubic',
						easeOut: 'easeOutCubic',
						delay: -6000,
						cleartype: true,
						cleartypeNoBg: true,
						//pager : '#hero-nav',
						slideExpr: 'div.hero',
						next: '.region-landing-page .next',
						prev: '.region-landing-page .prev',
						something: '',
						timeout: transition_speed
						
					});

				}

				$('.region-landing-page .next').show();
				$('.region-landing-page .prev').show();
			} else {
				// hide the pager
				$('.region-landing-page .next').hide();
				$('.region-landing-page .prev').hide();
			}

		}

	}


})(jQuery);
