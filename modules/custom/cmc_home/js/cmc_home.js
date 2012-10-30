(function($){
/**
 * 
 */
Drupal.behaviors.cmc_home = {
  attach: function(context) {
   
    var block_id = '#block-cmc-home-cmc-home-heroes';
    var heroes = $(block_id + ' .hero');
    
    if (heroes.length) {
      $(block_id).cycle({
        fx : 'fade',
        timeout : 2000,
        speedIn: 400,
        speedOut: 200,
        pause : 1,
        //pager : '#hero-nav',
        slideExpr : 'div.hero',
        next: '#block-cmc-home-cmc-home-heroes .next', 
        prev: '#block-cmc-home-cmc-home-heroes .prev',
        something: ''
      });  
    }
    else {
      // hide the pager
      $('#block-cmc-home-cmc-home-heroes .next').hide();
	$('#block-cmc-home-cmc-home-heroes .prev').hide();
    }
    
  }
}
})(jQuery);