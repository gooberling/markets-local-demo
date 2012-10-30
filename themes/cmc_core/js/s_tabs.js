// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_tabs = {

		attach: function(context) {
			jQuery('html').once('cmc_core_tabs', function() {
			//-----------------------------------------------------------------------------------------------
			// tab widget, might have more than one
			//-----------------------------------------------------------------------------------------------
			$('#main-content div.tabbed').each(function(i) {
				$(this).show();
				tab_widget = $(this);
				var tabs = $('ul:first > li', tab_widget);

				var tab_width = 100 / tabs.length + '%';
				//set slider width
				$(".slider").css('width', tab_width);
				var active_tab = $('li.active', tab_widget);
				// no active tab so default first one
				if (!active_tab.length) {
					$('li:first', tab_widget).addClass('active');
				}

				// this added to cope with news page height reveal
				if ($('body').hasClass('page-news')) {

					var news_height = ($('.view-third-party-news ul:first > li').outerHeight() * $('.view-third-party-news ul:first > li').length) + 220;
					tab_widget.height(news_height);
				} else {
					// set parent element height
					var tabbed_height = $('li.active div.detail', tab_widget).outerHeight() + $('li.active a', tab_widget).outerHeight();
					tab_widget.height(tabbed_height);
				}

				// loop thru the tabs
				tabs.each(function(j) {
					var tab = $(this);
					tab.css('width', tab_width);
					// set the tab width
					var tab_title = $('h2 a', tab);
					var tab_content = $('div.detail', tab);
					var tab_height = $('div.detail', tab).outerHeight() + $('h2', tab).outerHeight();
					tab_title.click(function(e) {
						if ($(this).attr('href') == '#') {
							e.preventDefault();

							if (!tab.hasClass('active')) {
								// clicked on different tab so close all and show clicked
								tabs.removeClass('active');

								$('div.detail', tabs).hide();
								tab.addClass('active');
								// set slider position
								posMoveto = $(this).parent().parent().position().left;
								//console.log(posMoveto);
								$(".slider").animate({
									left: posMoveto
									}, 400, 'easeOutExpo');
								if ($('body').hasClass('page-news')) {
									// animate height of div containing content
									$(".tabbed").animate({
										height: news_height
									}, 200, 'easeOutCirc', function() {
										tab_content.fadeIn('slow');
									});
								} else {

									//
									$(".tabbed").animate({
										height: tab_height
									}, 200, 'easeOutCirc', function() {
										tab_content.fadeIn('slow');
									});
									//
								}
							}
						}
					});
				});

				if ($('.slider').length) {
					$('.slider').css('left', $('.tabbed li.active').position().left);
				}
			});


			// end script
		});
		}
	};
}(jQuery));
