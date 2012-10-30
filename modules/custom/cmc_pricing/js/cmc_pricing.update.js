(function($){
/**
 * 
 */
Drupal.behaviors.cmc_pricing = {
  attach: function(context) {
   
    // tabbed stuff goes here
    pricingTabsInit()
    
    // default is 20secs
    var pricing_refresh_period = Drupal.settings.cmc_pricing.refresh_period;    
    pollLatestPrices(pricing_refresh_period);
    
    var scrollers = $('.ticker-container .pricing-scroller');
    if (scrollers.length) {
      scrollers.each(function(i){
        $(this).wonksticker({tickerBuffer:30});
      });
    }
    
    /**
     * Set up the panel tabs
     */
    function pricingTabsInit() {
      
      $('.tab-panel').each(function(i){
        var panel_group = $(this);
        var panels = $('.pricing-panel-tabbed', panel_group);
        var headings = $('.pricing-panel-tabbed h3', panel_group);       
        var nav = '';
        
        for (var i=0; i<panels.length; i++) {                 
          var panel = $(panels[i]);
          var heading = $('h3', panels[i]);
          
          if (heading.length) {
            var heading_text = heading.html();
            
            var table = $('table', panels[i]);
            table.attr('rel', heading_text);
            
            nav += '<li><a href="#" rel="' + heading_text + '">' + heading_text + '</a></li>';
          }
        }
        
        if (nav) {
          nav = '<ul class="panel-nav">' + nav + '</ul>';
        }
        
        $('h2', panel_group).after(nav);
        $('h3', panel_group).hide();
        var tables = $('table', panel_group);
        tables.hide();
        $(tables[0]).fadeIn('slow');
        
        var panel_nav_links = $('ul.panel-nav a', panel_group);
        $(panel_nav_links[0]).addClass('active');
        
        // add click handlers
        panel_nav_links.click(function(e){
          $('table', panel_group).hide();
          $('ul.panel-nav a', panel_group).removeClass('active');
          
          var a = $(this);
          a.addClass('active');
          $('table[rel="' + a.attr('rel') + '"]', panel_group).fadeIn('slow');
          
          e.preventDefault();
        });
        
      });
      
    }
    
    
    /**
     * Poll for the latest prices of products 
     */
    function pollLatestPrices(period) {

      var date = new Date();
      var time = parseInt(date.getTime() / (period*1000));
       
      var symbols = [];
      $('.pricing').each(function(i){
        var container = $(this);
        symbols.push(container.attr('rel'));
      });
      
      var request_url = '/cmc_pricing/' + symbols.join('|') + '?t=' + time;
      
      $.ajax({
        type: "GET",
        url: request_url,
        dataType: "json",
        success: function(data){
          var counter = 0;

          var t = setInterval(function(){
              
              // update the rows
              $('.pricing').each(function(j){
                var container = $(this);
                var symbol = container.attr('rel');
                if (data[symbol] !== undefined) {
                  updatePriceData(data[symbol][counter]['price'], container);              
                }
              });
              
              counter++;        
                    
              if (counter >= period) {
                // make another ajax call
                clearInterval(t);
                pollLatestPrices(period);
              }              
            },
            1000
          );
          // end interval
        } 
      });          
    }
    
    /**
     * Update the price table row
     */
    function updatePriceData(data, container) {    
      if (data == null) {
        return;
      }
      
      setPrice($('.bid', container), data.bid, data.bid_change);
      setPrice($('.ask', container), data.ask, data.ask_change);
      setSpread($('.spread', container), data.spread);
      
      /*           
      // Delay and clear span class
      var t = setTimeout(function(){        
          $('span', container).each(function(i){
            $(this).attr('class', '');
          });
          clearTimeout(t);
        },
        700
      );    
      */
    }

    function setSpread(cell, spread) {
      cell.html(spread);
    }
    
    /**
     * Update the price value in a cell
     */
    function setPrice(cell, value, movement) {
      
      cell.removeClass('up down'); // reset
      var classname = '';
      var current_value = $('.value', cell).html();
      
      
      if (typeof value != 'undefined') {
        // Calculate movement client side rather than server side
        // when we make a new ajax request, the movement isn't calculated 
        // correctly
        var m = value - current_value;      
        if (m > 0) {
          cell.addClass('up');
        }
        else if (m < 0) {        
          cell.addClass('down');        
        }
  /*      else {
          movement = '';        
        }
        
        var v = value.toString();        
        // get movement to match up with value decimal places
        var decimals = v.toString().length - (v.toString().indexOf('.')+1);      
        var power = Math.pow(10,decimals);
        m = Math.round(m*power)/power;
        
        if (m == 0) {
          m = '';
        }
    */    
        //var string_m = m.toString();
        // might need a sprintf function
//        $('.movement', cell).html(m);            
        $('.value', cell).html(value);
        
      }
      
      
    }
  }

}
})(jQuery);
