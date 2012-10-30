// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for use on the Trading Platforms page
(function($) {
	
Drupal.behaviors.cmc_core = {

// Set global variables
current_video: '',
intervalID: '',
timeoutID: '',

	
attach: function(context) {

jQuery('html').once('cmc_core', function() {

// Function to get the platform name from the URL
function getParameterByName(name) {
	name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
	var regexS = "[\\?&]" + name + "=([^&#]*)";
	var regex = new RegExp(regexS);
	var results = regex.exec(window.location.search);
	if (results == null) return "desktop";
	else return decodeURIComponent(results[1].replace(/\+/g, " "));
}

$(".block-cmc-platform-page").css('visibility', 'visible');

// Function to check if using mobile
function isMobile() {
	var ismobile = navigator.userAgent.match(/(iPad)|(iPhone)|(iPod)|(android)|(webOS)/i);
	return ismobile;

}

// Function to check if using IE 8 or below
function isIE() {
	if ($.browser.msie && $.browser.version <= 8.0) {
		return true;
	}
	if (getParameterByName('testimage') == 1) {
		return true;
	}
	return false;
}

// Play video on canvas
function canvasPlayVideo(el, video) {
	/// store what currently playing video is
	Drupal.behaviors.cmc_core.current_video = $(video).attr('rel');
	var canvas = document.getElementById('canvas');

	var cw = canvas.clientWidth;
	var ch = canvas.clientHeight;
	canvas.width = cw;
	canvas.height = ch;

	var context = canvas.getContext('2d');
	draw(el, context, cw, ch);
}

// Draw the video onto the canvas
function draw(v, c, w, h) {
	if (v.paused || v.ended) return false;
	c.drawImage(v, 0, 0, w, h);
	// not sure how setTimeout worked in non IE browsers
	//setTimeout(draw,20,v,c,w,h);
	setTimeout(function() {
		draw(v, c, w, h);
	}, 20);
}

// Timer
function myTimer() {
    var sec = 2
    var timer = setInterval(function() { 
    if (sec == -1) {
      clearInterval(timer);
     } 
    }   , 1000);
}

// Transition called a number of times throughout the script
function itemTransition(current_media, next_media) {
	
	if (!isIE() && !isMobile() && current_media.is('video')) {
		current_media.get(0).pause();
	}

	var winHeight = $(window).height();

	// transition animation
	$('.hero-image').animate({
		top: (winHeight - 150),
		easing: 'easeOutCubic'
	}, 600, function() {

	var active_item = next_media.attr('id').replace('image-','');
	var active_item = active_item.replace('video-','');
	
	// Image or IE 8 and below
	if (isIE() || isMobile() || next_media.is('img')) {

		$('#canvas').hide();
		$('img.platform-video-image').hide();
		next_media.show();

		$('.hero-image').append(next_media);

		// Set the global variable that logs the media currently playing
		Drupal.behaviors.cmc_core.current_video = next_media.attr('id').replace('image-','');

		if (isIE() || isMobile()) {

			var current_item = parseInt(next_media.attr("class").split(" ")[2].replace('sequence-image-item-',''));
			var next_item = current_item + 1;

			// The call to to this function is normally based on a listener event for when a video has ended but as
			// we are now showing a we call the imageAdvance function which call this function again after 15 secs
			if ($('.sequence-image-item-' + next_item).length) {
				imageAdvance($('.sequence-image-item-' + current_item), $('.sequence-image-item-' + next_item));
			} else {
				imageAdvance($('.sequence-image-item-' + current_item), $('.sequence-image-item-1'));
			}

		} else {

			var current_item = parseInt(next_media.attr("class").split(" ")[1].replace('sequence-item-',''));
			var next_item = current_item + 1;

			// Same as above but we may use a video
			if ($('.sequence-item-' + next_item).length) {
				imageAdvance($('.sequence-item-' + current_item), $('.sequence-item-' + next_item));
			} else {
				imageAdvance($('.sequence-item-' + current_item), $('.sequence-item-1'));
			}

		}

		// We know that the image will be shown for 15 seconds so we just set the seekbar values manually
		var seekbarPosition = -1;
		Drupal.behaviors.cmc_core.intervalID = setInterval(function(){
			if (seekbarPosition >= -32) {
				$('#seekbar').css('background-position', (seekbarPosition * 17) + 'px 0');
				seekbarPosition--;
			}
		}, 469); 
	}

	// Video in desktop broswers that support HTML5
	else {

		// If the previous item was an image then hide this
		if (current_media.is('img')) {
			$('img.platform-video-image').hide();
		}

		$('#canvas').show();

		next_media.get(0).currentTime = 0;
		
		// Rewind to start
		next_media.get(0).play();

	}
	
	$('.nav-links-pos a').removeClass('playing');
	$('.nav-links-pos a.active.' + active_item).addClass('playing');


	$('.hero-image').animate({
		top: -145,
		easing: 'easeOutCubic'
	}, 600);
	
	});
	// end item transition
}


// Runs the transition function after 15 seconds
function imageAdvance(current_media, next_media) {
	Drupal.behaviors.cmc_core.timeoutID = setTimeout(function() { itemTransition(current_media, next_media) }, 15000);
}


// If the Platform Header div exists then do this stuff....
if ($(".platform-header").length) {
	
	var videos = $('.sequence');
	
	videos.each(function(i) {
		var video = $(this).get(0);

		$(video).bind("play", function() {
			canvasPlayVideo(this, video);
		});

		// Event listener that runs when a video has finished playing
		$(video).bind("ended", function() {
			
			var current_item = parseInt($(this).attr("class").split(" ")[1].replace('sequence-item-',''));
			var next_item = current_item + 1;
			
			if (!(current_item == 1)) {
				
				if ($('.sequence-item-' + next_item).length) {
					itemTransition($('.sequence-item-' + current_item), $('.sequence-item-' + next_item));
				} else {
					itemTransition($('.sequence-item-' + current_item), $('.sequence-item-1'));
				}
			
			} else {
				video.pause();
				
			}

		});
	});
	
	
	// Runs on page load then not again
	if (videos.length > 0) {
		videos.hide();
		$('img.platform-video-image').hide();

		// Finds out from the querystring whether the video we should play first
		var platform = getParameterByName('platform');

		$('.nav-links-pos a.active.' + platform).addClass('playing');
		
		// If first item is a image or we are viewing in IE8 or below
		if (isIE() || isMobile() || $('.sequence-' + platform).is('img')) {

			$('#canvas').hide();

			var images = $('img.platform-video-image');
			images.each(function(i) {
				var img = $(this);
				img.remove();
				$('.hero-image').append(img);
				img.hide();
			});

			// Show the image we want to load first
			$('#image-' + platform).show();

			// We know that the image will be shown for 15 seconds so we just set the seekbar values manually
			var seekbarPosition = -1;
			Drupal.behaviors.cmc_core.intervalID = setInterval(function(){ 
				if (seekbarPosition >= -32) {
					$('#seekbar').css('background-position', (seekbarPosition * 17) + 'px 0');
					seekbarPosition--;
				}
			}, 469); 

			if (isIE() || isMobile()) {

				var current_item = parseInt($('.sequence-' + platform).attr("class").split(" ")[2].replace('sequence-image-item-',''));
				var next_item = current_item + 1;

				// Images only for IE8 and below.. The call to to this function is normally based on a listener event 
				// for when a video has ended but as we are now showing a we call the imageAdvance function which call
				// this function again after 15 secs
				if (!(current_item == 1)) {
					if ($('.sequence-image-item-' + next_item).length) {
						imageAdvance($('.sequence-image-item-' + current_item), $('.sequence-image-item-' + next_item));
					} else {
						imageAdvance($('.sequence-image-item-' + current_item), $('.sequence-image-item-1'));
					
					}
				} else {
					$('#seekbar').hide();
				}

			} else {

				var current_item = parseInt($('.sequence-' + platform).attr("class").split(" ")[1].replace('sequence-item-',''));
				var next_item = current_item + 1;
				
				
				if (!(current_item == 1)) {
						// Same as above but pulls through video if one is avaialble
						if ($('.sequence-item-' + next_item).length) {
							imageAdvance($('.sequence-item-' + current_item), $('.sequence-item-' + next_item));
				
						}	else {
							imageAdvance($('.sequence-item-' + current_item), $('.sequence-item-1'));
					
						}
					}	else {
							$('#seekbar').hide();
					}

			}

		}

		// If first item is a video
		else {
			
			var current_item = parseInt($('.sequence-' + platform).attr("class").split(" ")[1].replace('sequence-item-',''));
			
			image_url = '';
			if ($('#video-' + platform).length) {
				$('#video-' + platform).get(0).play();
				image_url = $('#video-' + platform).attr('poster');
				Drupal.behaviors.cmc_core.current_video = platform;
				
				}	else {
					image_url = $(videos[0]).attr('poster');
					
			}
		}

		var winHeight = $(window).height();
		var winWidth = $(window).width();

		// only if platform header exists
		var container = $(".platform-header").position();
		var imageLeft = $(".hero-image").position();
		var navHeight = $(".platform-nav").height();

		var posAdjust = container.left + imageLeft.left;
		var playerWidth = winWidth - posAdjust;


		// Navigation links
		$('.nav-links a').click(function(e) {

			clearInterval(Drupal.behaviors.cmc_core.intervalID);
			clearTimeout(Drupal.behaviors.cmc_core.timeoutID);

			var link = $(this);
			
			if (isIE() || isMobile()) {

				if (link.hasClass('active')) {
					e.preventDefault();
					
					if (isIE() || isMobile() || link.hasClass('ipad')) {
						var current_video = $('#image-' + Drupal.behaviors.cmc_core.current_video);
					}
					else {
						var current_video = $('#image-' + Drupal.behaviors.cmc_core.current_video);
					}

					var next_video = $('#image-' + link.attr('rel'));
					itemTransition(current_video, next_video);
				}

			} else if (link.hasClass('active')) {
				e.preventDefault();
				// Don't want to restart if current video
				if (Drupal.behaviors.cmc_core.current_video != link.attr('rel')) {
					var next_video = $('.sequence-' + link.attr('rel'));
					var current_video = $('.sequence-' + Drupal.behaviors.cmc_core.current_video);
					
					itemTransition(current_video, next_video);
				}
			} else {
				var current_video = Drupal.behaviors.cmc_core.current_video;
				var video = $('#video-' + current_video).get(0);
				video.pause();
			}
		});

		// Pause playing when clicking on canvas
		$('canvas').click(function() {
			$('.hero-image').css('background-image', 'none');
			var current_video = Drupal.behaviors.cmc_core.current_video;

			if (!current_video) {
				// no video so grab the first one
				current_video = $(videos[0]).attr('rel');
			}

			var video = $('#video-' + current_video).get(0);
			if (video.paused == false) {
				video.pause();

			} else {
				video.play();
			}
		});

	} else {

		// no videos
		var platform = getParameterByName('platform');
		$('#canvas').hide();

		var images = $('img.platform-video-image');
		images.each(function(i) {
			var img = $(this);
			img.remove();
			$('.hero-image').append(img);
			img.hide();
		});

		if ($('#image-' + platform).length) {
			$('#image-' + platform).show();
		} else {
			$(images[0]).show();
		}

		$('.nav-links a').click(function(e) {
			var link = $(this);
			if (link.hasClass('active')) {
				e.preventDefault();

				var target = link.attr('rel');
				var winHeight = $(window).height();
				$('.hero-image').animate({
					top: (winHeight - 150),
					easing: 'easeOutCubic'
				}, 600, function() {
					images.hide();
					$('#image-' + target).show();
					$('.hero-image').animate({
						top: -145,
						easing: 'easeOutCubic'
					}, 600);
				});

			}

		});


	}
}



// Platform Resizing
$(window).bind("resize", platformsLanding);
platformsLanding();

// Set height and position of hero elements
function platformsLanding(e) {

	if ($(".platform-header").length < 1) {
		return;
	}

	var winHeight = $(window).height();
	var winWidth = $(window).width();
	var container = $(".platform-header").offset();
	var imageLeft = $(".hero-image").position();
	var navHeight = $(".platform-nav").height();
	var IE9width = (winHeight - 90) * 1.77777777777778;

	var posAdjust = container.left + imageLeft.left;
	var playerWidth = winWidth - posAdjust;

	$(".block-cmc-platform-page").css('height', winHeight - container.top);

	// adjust the nave for logged in view
	$(".logged-in .block-cmc-platform-page").css('height', winHeight - (container.top + 210));

	// set the height and width of main image container
	$(".dynamicExtra").css('height', winHeight - 90);
	$(".dynamicWidth").css('width', playerWidth);

	// for IE( we have t o set the width explicitly)
	if ($.browser.msie && $.browser.version == 9.0) {
		$(".IEdynamicWidth").css('width', IE9width);

	}

	// video seekbar, here as have to readjust depending on window size
	if ($('#seekbar').length) {

		$("video").bind("timeupdate", function() {

			var steps = 1 / 32;
			var seekBg = parseInt(this.currentTime, 10) / parseInt(this.duration, 10);
			var step = parseInt(seekBg / steps, 10);

			$('#seekbar').css('background-position', (step * -17) + 'px 0');
		});
	}
}





// add active class to hghlight page you are on
$('.nav-links a.active').parent().parent().parent().addClass('active');

// get current li attributes
var currentLi = $('.nav-links a.active').parent().parent().parent().attr('jcarouselindex');

// hover
$(".view-cmc-platform li:not(.active)").hover(
  function () {
    $(this).children('.nav-links').fadeIn('fast');
  }, 
  function () {
    $(this).children('.nav-links').fadeOut('fast');
  }
);


// scroll down to the breadcrumb so user can read the content
var block_id = '#block-cmc-platform-page-cmc-platform-page-header'
$(block_id + ' a.more').click(function(e) {
	e.preventDefault();

	var pos = $('.platform-nav').offset().top + 70;
	var toolbar = $('#toolbar');
	// check to see if we have toolbar here
	if (toolbar.length) {
		pos -= toolbar.height();
	}

	// scroll down
	$('body,html').animate({
		scrollTop: pos,
		easing: 'easeOutQuart'
	}, 600);
});

// create back to top div
var back_text = Drupal.t('View video');  
$('.node-type-cmc-platform-page #main-content').append('<div class="backUp">' + back_text + '</div>')

// scroll back up on sub nav
$('.backUp').click(function(e) {
	// e.preventDefault();
	$('body,html').animate({
		scrollTop: 0,
		easing: 'easeOutQuart'
	}, 600);
});

// add back to top link






				
});

}
};

})(jQuery);

