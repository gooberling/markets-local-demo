(function($) {
  
  Drupal.behaviors.ajax_facets = {
    attach: function(context, settings) {
      if (Drupal.settings && Drupal.settings.views && Drupal.settings.views.ajaxViews) {
	var ajax_path = Drupal.settings.views.ajax_path;
	$.each(Drupal.settings.views.ajaxViews, function(i, view_settings)  {
	  var facet_view = '.facet-wrapper';
	  var facet_settings = {
	    url: ajax_path,
	    submit: view_settings,
	    setClick: true,
	    event: 'click',
	    selector: facet_view,
	    progress: { type:'throbber' }
	  };
	  $(facet_view).filter(':not(.views-processed)').each(function() {
	    var target = this;
	    $(this)
	      .addClass('views-processed')
	      .find('a')
	      .each(function() {
		var view_data = {};
		$.extend(
		  view_data,
		  view_settings,
		  Drupal.Views.parseQueryString($(this).attr('href')),
		  Drupal.Views.parseViewArgs($(this).attr('href'), view_settings.view_base_path)
		);
		
		$.extend(
		  view_data, 
		  Drupal.Views.parseViewArgs($(this).attr('href'), view_settings.view_base_path)
		);

		facet_settings.submit = view_data;
		var facet_ajax = new Drupal.ajax(false, this, facet_settings);
	      });
	  });
	});
      }
    }
  }

} (jQuery));
