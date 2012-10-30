// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02
// JS file for IE nav filler.
(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_embed = {

		attach: function(context) {
				// some js to replace youtube object tags with iframes 
				// media tokens for videos in body content don't get converted 
				// to iframe tags like they do if we used a video field
				// 
				$('.media-youtube-preview-wrapper').each(function(i) {
					var video_embed = $(this);
					var id = video_embed.attr('id');

					if (Drupal.settings.media_youtube && Drupal.settings.media_youtube[id] != undefined) {
						//console.log('exists');
						return;
					}

					var embed = $('embed', video_embed);
					var src = embed.attr('src').split('?');
					var youtube_url = src[0].split('/');
					var youtube_querystring = src[1];

					// get youtube options
					youtube_querystring = youtube_querystring.split('&');
					var youtube_options = {};
					for (var i = 0; i < youtube_querystring.length; i++) {
						values = youtube_querystring[i].split('=');
						youtube_options[values[0]] = values[1];
					}

					var youtube_id = youtube_url[youtube_url.length - 1];
					var obj = {
						fullscreen: embed.attr('allowfullscreen'),
						height: embed.attr('height'),
						hw: (embed.attr('height') / embed.attr('width')),
						id: id + '_iframe',
						options: {
							rel: youtube_options.rel,
							showinfo: youtube_options.showinfo,
							showsearch: youtube_options.showsearch,
							version: youtube_options.version,
							wmode: embed.attr('wmode')
						},
						video_id: youtube_id,
						width: embed.attr('width')
					};

					if (Drupal.settings['media_youtube'] == undefined) {
						Drupal.settings['media_youtube'] = {};
					}
					Drupal.settings['media_youtube'][id] = obj;
					Drupal.media_youtube.insertEmbed(id);
				});
			
			// end script
		}
	};
}(jQuery));
