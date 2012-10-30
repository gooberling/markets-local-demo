(function ($) {

  Drupal.behaviors.cmc_tracking_cmc_registration = {
    attach: function (context, settings) {
      var radios = $('#cmc-registration-get-form input[name="already_registered"]');
      
      var already_registered = ''; // stores current value
      // when user clicks on  yes/no to already_registered
      // we want to fire off a pageview
      radios.each(function(i){
        var radio = $(this);
        var radio_value = radio.val();
        
        if (radio.attr('checked') === true) {
          already_registered = radio_value; 
        }
        
        radio.click(function(e){
          if (radio_value != already_registered) {     
            // only fire if user is switching between states
            var track_page = settings.cmc_tracking_cmc_registration.already_registered[radio_value];                    
            window._gaq.push(["_trackPageview", track_page]);            
          }
          // need to store clicked value
          already_registered = radio_value;
        });        
      });
    }
  };  
})(jQuery);
