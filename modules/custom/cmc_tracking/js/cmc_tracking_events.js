(function ($) {

  Drupal.behaviors.cmc_tracking_events= {
    attach: function (context, settings) {
       
      // track pdf
      $('a.registration-pdf,a[href*="/pdf/"]').each(function(i) {
        $(this).bind('click.pageTracker', function(e) {          
          window._gaq.push(['_trackEvent', 'pdf', 'download', 'registration-pdf']);
          //e.preventDefault();
        });
      });     
    }
  };  
})(jQuery);
