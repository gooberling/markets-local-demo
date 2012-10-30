// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_facets = {

		attach: function(context) {
			jQuery('html').once('cmc_core_facets', function() {
			//-----------------------------------------------------------------------------------------------
			// faceted search block
			//-----------------------------------------------------------------------------------------------


			// markets section only
			$('.markets-section #main-content div.region-filter-block .block-facetapi.two').addClass('active');
			$('.markets-section #main-content div.region-filter-block').each(function(i) {
				block_widget = $(this);
				var blocks = $('.block-facetapi', block_widget);
				// loop thru the tabs
				blocks.each(function(j) {
					var tab = $(this);
					var tab_title = $('h2', tab);
					//var tab_content = $('div.item-list', tab);
					var link_active = $('a', tab);
					// check if a value has been filtered and add marker to H2
					if (link_active.hasClass('facetapi-active')) {
						tab_title.append('<span class="filtered"></span>');
					} else {
						tab_title.remove('.filtered');
					}
					//	show hide the blocks
					tab_title.click(function(e) {
						e.preventDefault();

						if (!tab.hasClass('active')) {
							// clicked on different tab so close all and show clicked
							blocks.removeClass('active');
							tab.addClass('active');
							$('div.item-list', blocks).hide();

							// set slider position
							$('div.item-list', tab).fadeIn('slow');
						}
					});

				});
			});

			//-----------------------------------------------------------------------------------------------
			// show hide faceted search
			//-----------------------------------------------------------------------------------------------



			function filterslide(e) {
				var moveto = $('.region-text-search').offset().top;
				e.preventDefault();
				var txt = $(".region-filter-block").is(':visible') ? Drupal.t('Show filters') : Drupal.t('Hide filters');
				$(".filter-actions .reveal").text(txt);
				$('.region-filter-block').slideToggle('slow', function() {

					$('body,html').animate({
						scrollTop: moveto,
						easing: 'easeInQuart'
					}, 600, function() {

						// Animation complete.
					});
				});
				$(this).parent().toggleClass('open');

			}

			function focusslide(e) {
				var moveto = $('.region-text-search').offset().top;
				$('body,html').animate({
					scrollTop: moveto,
					easing: 'easeInQuart'
				}, 600, function() {

					$(".filter-actions .reveal").text(Drupal.t('Hide filters'));
					$('.region-filter-block').slideDown('slow', function() {});
					$('.filter-actions').addClass('open');
				});

			}

			// move on focus
			$('.region-text-search .form-text').focus(focusslide);

			$('.filter-actions .reveal').click(filterslide);
			
			
			// end script
		});
		}
	};
}(jQuery));
