(function ($) {

  Drupal.behaviors.cmc_tracking_cross_domain = {
    attach: function (context, settings) {
      
      /** **** Google Analytics Cross Domain Tracker ***** */
      // Want anything link to mycmc.[tld] or cfd.markets.com to cross domain GA pageTracker
      // http://code.google.com/apis/analytics/docs/tracking/gaTrackingSite.html#trackingIFrames
      // use .bind(click.namspace) rather than adding it as attribute or click().
      // IE doesn't like it if adding as onclick attribute
      // Use bind so we can remove the namespaced click event later
      // selectors passed in by the Drupal.settings
      var ga_selectors = Drupal.settings.cmc_tracking.cross_domain_selectors;

      $(ga_selectors).each(function(i) {
        $(this).bind('click.pageTracker', function(e) {          
          e.preventDefault();
          var href = this.href;          
          _gaq.push(function() {            
            var pageTracker = _gat._getTrackerByName();
            window.open(pageTracker._getLinkerUrl(href, false), '_blank');
          });
        });
        $(this).attr('pagetracker', 1);
      });        
    }
  };  
})(jQuery);
