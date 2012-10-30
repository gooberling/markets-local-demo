/**
 * js for cmc widgets
 */
Drupal.behaviors.cmc_widget_update = function(context) {

  // get refresh period from settings
  // set this up to refresh periodically - 
  var pricing_refresh_period = 20;  // default is 20secs

  // set up the tables so we assign symbol and updated to each row
  $('.cmc_widget-prices').each(function(i){
    var widget_wrapper = $(this);    
    $('.cmc_widget-product', widget_wrapper).each(function(j){
      var price_container = $(this);
      var rel = price_container.attr('rel');
      price_container.attr('symbol', rel);
    });
  });
  
  pollLatestPrices(pricing_refresh_period);
  
  
  /**
   * Poll for the latest prices of widget products 
   */
  function pollLatestPrices(period) {

    var date = new Date();
    var time = parseInt(date.getTime() / (period*1000));
     
    var symbols = [];
    $('.cmc_widget-product').each(function(i){
      var container = $(this);
      symbols.push(container.attr('symbol'));
    });
    
    var request_url = '/cmc_widget_pricing/' + symbols.join('|') + '?t=' + time;
    
    $.ajax({
      type: "GET",
      url: request_url,
      dataType: "json",
      success: function(data){
        var counter = 0;
        var t = setInterval(function(){
            
            // update the rows
            $('.cmc_widget-product').each(function(j){
              var container = $(this);
              var symbol = container.attr('symbol');
              //console.log(data[symbol][counter]);
              updatePriceData(data[symbol][counter], container);              
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
    
    // update the cells
    setPrice($('.bid', container), data.bid);
    setPrice($('.ask', container), data.ask);
    //$('.movement', container).html(data.movement);
    $('.spread', container).html(data.spread);
    
    // Delay and clear span class
    var t = setTimeout(function(){        
        $('span', container).each(function(i){
          $(this).attr('class', '');
        });
        clearTimeout(t);
      },
      700
    );    
  }

  
  /**
   * Update the price value in a cell
   */
  function setPrice(cell, value) {
    current_value = $('span', cell).html();
    
    var classname = '';
    if (value > current_value) {
      classname = 'up';
    }
    else if (value < current_value) {
      classname = 'down';
    }
    
    var output = '<span class="' + classname + '">' + value + '</span>';
    cell.html(output);
  }
};


