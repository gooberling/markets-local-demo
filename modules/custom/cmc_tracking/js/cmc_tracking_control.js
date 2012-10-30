(function($) {

  var COOKIE_CONSENT_NONE = '0';
  var COOKIE_CONSENT_LOCAL = '1';
  var COOKIE_CONSENT_EXTERNAL = '2';

  var handlers = {
    // Javascript really sucks sometimes
    '1': { applied: false, functions:[] },
    '2': { applied: false, functions:[] }
  };

  function edit_consent() {
    $('.block-cmc-tracking').css('display', 'block');    
    $('#cmc-tracking-consent-form-step1').css('display', 'none');
    $('#cmc-tracking-consent-form-step2').
      css('left', ($(window).width() - $('#cmc-tracking-consent-form-step2').width()) / 2).
      css('top', ($(window).height() - $('#cmc-tracking-consent-form-step2').height()) / 2).
      css('visibility', 'visible');

    var external_cookie_consent = !(get_consent() == COOKIE_CONSENT_LOCAL);
    $('.form-item-other-cookie-options #edit-other-cookie-options-1').attr('checked', external_cookie_consent);
    $('#cmc-tracking-consent-form-step2 #edit-save').click(function(e) {
      e.preventDefault();
      var external = $('.form-item-other-cookie-options #edit-other-cookie-options-1').is(':checked');
      var consent_given = external ?
        COOKIE_CONSENT_EXTERNAL: COOKIE_CONSENT_LOCAL;

      store_consent(consent_given);
      $('#cmc-tracking-consent-form-step2').css('visibility', 'hidden');
      $('.block-cmc-tracking').css('display', 'none');
      return false;
    });

    var change_options = function() {
      var chk = $('.form-item-other-cookie-options #edit-other-cookie-options-1');
      if (chk.is(':checked')) {
	$('.other').addClass('selected');
      } else {
	$('.other').removeClass('selected');
      }
    }

    // fade other cookies div on tracking page
    $('.form-item-other-cookie-options').unbind('click').click(change_options);

    change_options();
  }

  function get_consent() {
    var mobile = $(window).width(); 
    
    if (mobile >=980) {
      if ($('#cmc-tracking-consent-form-step1').length == 0) {
	// if the consent block is turned off, assume consent for everything
	return COOKIE_CONSENT_EXTERNAL;
      } else if (!Drupal.settings.cmc_tracking.consent) {
	return COOKIE_CONSENT_EXTERNAL;
      } else if ($('body').hasClass('mobile') || $('body').hasClass('ipad') || $('body').hasClass('android'))   {
	return COOKIE_CONSENT_EXTERNAL;
      } else {
	var cookie = $.cookie('cmc_cookie_consent');
	var consentValid =
	  (cookie == COOKIE_CONSENT_LOCAL ||
	   cookie == COOKIE_CONSENT_EXTERNAL);

	return consentValid ? cookie : COOKIE_CONSENT_NONE;
      }
    }
  }

  function bake(level) {
    if (!handlers[level].applied) {
      $.each(handlers[level].functions, function(index, fn) {
	fn.apply();
      });
    }

    handlers[level].applied = true;
  }

  function store_consent(level) {

    var options = {
      expires: 365,
      path: '/'
    };

    if (Drupal.settings.cmc_tracking.consent_domain) {
      options.domain = Drupal.settings.cmc_tracking.consent_domain;
    }

    if (level == COOKIE_CONSENT_LOCAL) {
      options.expires = 90;
    }

    $.cookie('cmc_cookie_consent', level, options);
    process_consent(level);
  }

  function request_consent() {

    $('.block-cmc-tracking').css('display', 'block');

    $('#cmc-tracking-consent-form-step1').
      css('left', ($(window).width() - $('#cmc-tracking-consent-form-step1').width()) / 2).
      css('top', ($(window).height() - $('#cmc-tracking-consent-form-step1').height()) / 2);

    $('a.cookie-accept').click(function(e) {
      e.preventDefault();
      store_consent(COOKIE_CONSENT_EXTERNAL);
      $('.block-cmc-tracking').css('display', 'none');
      return false;
    });

    $('a.cookie-update').click(function(e) {
      e.preventDefault();
      edit_consent();

      return false;
    });


    $('#cmc-tracking-consent-form-step2 #edit-save').click(function(e) {
      e.preventDefault();



      return false;
    });

    // fade other cookies div on tracking page
	$('#cmc-tracking-consent-form-step2 .form-radios input').click(function(){
	    var chk = $(this);
		if (chk.val() == 1) {
			$('.other').addClass('selected');				
		}
		else {
			$('.other').removeClass('selected');				
		}
	    

	})

  }

  function attach_menu_link() {
    var mobile = $(window).width();
    if (mobile >=980) {
      $('#block-cmc-framework-cmc-bottom ul.menu').
        append('<li class="cookie-pref"><a href="#">Change cookie settings</a></li>');

      $('.cookie-pref a').click(function(e) {
        e.preventDefault();
        edit_consent();
      });
    }
  }  

  function process_consent(consent) {
    switch (consent) {
    case COOKIE_CONSENT_EXTERNAL:
      bake(COOKIE_CONSENT_EXTERNAL);
      // deliberate fall-through
    case COOKIE_CONSENT_LOCAL:
      bake(COOKIE_CONSENT_LOCAL);
      break;
    case COOKIE_CONSENT_NONE:
      request_consent();
    } 
 }

  function add_handler(level, handler) {
    handlers[level].functions.push(handler);
  }

  Drupal.behaviors.cmc_tracking = {
    add: function(type, handler) {
      if (type == 'local') {
	add_handler(COOKIE_CONSENT_LOCAL, handler);
      } else if (type == 'external') {
	add_handler(COOKIE_CONSENT_EXTERNAL, handler);
      }
    },
    attach: function(context, settings) {
      var consent = get_consent();
      if (settings.cmc_tracking.consent) {
	attach_menu_link();
      }

      process_consent(consent);
    }
  }
})(jQuery);
