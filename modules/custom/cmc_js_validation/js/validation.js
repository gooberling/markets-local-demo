(function($) {


  /**
     Validation Framework

     This JS library contains functions for validating form elements, and some
     framework code for assigning these validators to the correct element.

     The JS object Drupal.cmcForms contains the following objects/functions:

     - isElementValid()
     - rehash()
     - attachHandlers()
     - handlers (an object with various handler methods)

     Drupal.settings.cmcForm is an object which contains various members
     representing forms on the current page.  This object is populated by JSON
     data which is generated server-side depending on the forms being displayed.

     In summary, most of the code below is responsible for reading the values in
     Drupal.settings.cmcForm['FORMNAME'] and using this data to attach handlers
     to events on the form.  Most of these handlers are validators.

     The 'rehash' function is responsible for iterating through all of the form
     elements for the given form, checking to see if they're currently in a
     valid state.  This can then be used to disable/enable 'Next' or 'Submit'
     buttons.
  */

  Drupal.behaviors.validator = {
    attach: function (context) {

      window.setTimeout(function() {

	if (Drupal.settings.cmcForm) {
	  // iterate through forms (bit of future-proofing for multiple forms on one page)
	  for (var i in Drupal.settings.cmcForm) {
	    var form = Drupal.settings.cmcForm[i];

	    // attach validators and click handlers
	    Drupal.cmcForms.attachHandlers(form.elements, i);

	    // do we have an on-load function specified for this form?
	    if (form.load) {
	      var load = Drupal.cmcForms.handlers[form.load];
	      $(document).ready(load);
	    }

	    // check the error state of the form
	    Drupal.cmcForms.rehash(i);

	    // attach an event handler which rehashes the form error state whenever anything changes
	    (function(formId) {
	      $(formId).change(function() {
		// something on this form has changed, let's call the rehash
		// function to check if everything is valid
		Drupal.cmcForms.rehash(formId);
	      });
	    })(i);
	  }
	}
      }, 1);
    }
  }


  Drupal.cmcForms = {

    // Validates a single form element
    isElementValid: function(id) {

      // Utility function to check for the presence of a 'required' label
      function isRequired(el) {
	return ($('span.form-required', el.parent()).length > 0);
      }

      var $el = $(id);
      // do we have an error class, or is the element both non-required and
      // empty?
      //console.log('required? ' + isRequired($el));
      //console.log('val: ' + $el.val());
      var validator = $el.data('validator');

      //console.log('isvalid');
      //console.log(id);
      //console.log(validator);
      var valid = (typeof validator == 'object') ? validator() : true;

      return (!$el.hasClass('error')) &&
	(!(isRequired($el) && ($el.val() == '')));
    },

    /**
       This function is called whenever any form element changes.
       It iterates through the form elements, checking their status.
       If all are valid then Drupal.settings.cmcForm[formName].status
       is set to true.

       At the end, the 'postRehash' handler is called.  This is a
       function which should take some action depending on the form
       status, e.g. enabling/disabling a submit button
    */
    rehash: function(formName) {

      // get the form data
      var form = Drupal.settings.cmcForm[formName];
      // assume everything is valid until proven otherwise
      var status = true;
      for (var id in form.elements) {
	//console.log('checking ' + id);

	var ignore = false;

	// do we have some 'ignore' functions for this element?
	// if so, check if we should be ignoring the element for validation
	// purposes (mostly used for conditionally-visible form elements)
	if (form.elements[id].ignore) {
	  // loop through the ignore handlers
	  for (var ignoreFnName in form.elements[id].ignore) {
	    var ignoreFn = Drupal.cmcForms.handlers[ignoreFnName];
	    //console.log(ignoreFnName);
	    // get the result of the ignore check
	    var ignore = ignoreFn.apply($(id), form.elements[id].ignore[ignoreFnName]);
	    if (ignore) {  // we should be ignoring this element if true
	      ignore = true;
	      //console.log('ignoring ' + id);
	      break;
	    }
	  }
	}

	// if non-ignored and not valid, the form is in invalid state
	if (!ignore && !Drupal.cmcForms.isElementValid(id)) {
	  //console.log(id + ' failed validation');
	  status = false;
	  break;
	}
	//console.log(id + ' is valid');
      }

      Drupal.settings.cmcForm[formName].status = status;

      if (form.postRehash) {
	// call the post-rehash handler
	// normally this is a function to enable/disable buttons
	// the identity of the function to call is configured within
	// the module code
	Drupal.cmcForms.handlers[form.postRehash](formName);
      }
    },

    runValidators: function(formName, until) {
      if (Drupal.cmcForms.runValidatorLock) {
	return;
      }

      Drupal.cmcForms.runValidatorLock = true;

      //console.log('validating all until ' + until);

      var elements = Drupal.settings.cmcForm[formName].elements;

      for (var name in elements) {
	//console.log('validating ' + name);
	if (name == until) {
	  break;
	}



	$(name).change();
      }

      Drupal.cmcForms.runValidatorLock = false;
    },

    checkErrors: function(elements, formName) {
      for (var id in elements) {
	if (!Drupal.cmcForms.isElementValid(id)) {
	  elements[id].invalid = true;
	}
      }
    },


    // loop through form elements and apply validators
    attachHandlers: function(elements, formName) {
      // the index (i) is the id of the element e.g. '#form-email'

      $(':input', $(formName)).focus(
	function() {
	  Drupal.cmcForms.runValidators(formName, '#' + $(this).attr('id'));
	}
      );

      for (var i in elements) {
	var el = elements[i]; // the object containing info about event handlers
	var $el = $(i);  // the jQuery object for this element
	var elDom = $el.get(0); // we only ever have one matching element @todo extend to cope with N
	//console.log(el);
	// do we have any validators for this element?


	if (el.validators) {
	  // iterate through validators

	  var validator = function(validators, dom) {
	    return function() {
	      var result = { valid: true, action: null };
	      for (var name in validators) {
//		//console.log(name);
		var fn = Drupal.cmcForms.handlers[name];

		result = fn.apply(dom, validators[name]);

		if (!result.valid) {
		  break;
		}
	      }

	      return result;
	    }

	  }(el.validators, elDom);

	  //console.log('setting validator for ' + i);
	  //console.log(validator);
	  $el.data('validator', validator);
	  $el.data('changed', false);

	  // @todo validate element on load

	  var eventHandler = function(event) {
	    var eventEl = $(this);
	    var inner = function(event, deferred) {
	      var _validator = eventEl.data('validator');

	      if (_validator) {
		var status = _validator();


		if (eventEl.data('changed') || (status.valid == true)) {
		  status.action(true);
		}

		Drupal.cmcForms.rehash(formName);

	      }

	    }

	    if (event.type == 'change' || event.type == 'blur') {
	      eventEl.data('changed', true);
	      inner(event, $(this), false);
	    } else {
	      window.setTimeout(function() { inner(event,  true); }, 1);
	    }

	  }

	  $el.change(eventHandler).blur(eventHandler)
	    .keypress(eventHandler).click(eventHandler);


	} else {
	  // no validators found, attach a standard 'clear errors on change' validator
	  $el.change(function() {
	    $(this).removeClass('error');
	  });
	}

	if ($el.val() != '') {
	  $el.data('changed', 'true');
	  $el.change();
	}
      }
    },

    /**
     * Toggles the current item and its wrapper based on client side validation rules
     */
    markElement: function(selector, isValid, msg, showMsg) {
   
      var newClass;
      var oldClass;
      //console.log(selector);
      var error_div = $(selector).attr('id') + "-error";

      if(!msg) var msg = '';

      if (isValid) {
	newClass = 'valid';
	oldClass= 'error';
	// $(selector).parent().remove(error_id);
	$('div').remove('#' + error_div);
	$(selector).parent().removeClass(oldClass);
	$(selector).parent().addClass(newClass);
	//console.log('add' + newClass);
	$(selector).addClass(newClass);
	$(selector).removeClass(oldClass);
	//console.log('greater than');
      } else {
	if ($('#' + error_div).length < 1) {
	  $(selector).parent().append('<div id="'+ error_div +'" class="msgs error">'+ msg +'<span></span></div>');
	  //console.log('less than');
	  $('.description').hide();
	  $('.form-item.active .msgs').fadeIn('slow');

	  newClass = 'error';
	  oldClass= 'valid';
	  //console.log('add ' + newClass);
	  $(selector).parent().removeClass(oldClass);
	  $(selector).parent().addClass(newClass);

	  $(selector).removeClass(oldClass);
	  $(selector).addClass(newClass);
	}
      }
    },


    handlers: {
      ////////// Generic ///////////

      'ignoreIfChecked': function(element) {
	return $(element).is(':checked');
      },

      'ignoreIfVal': function(element, value) {
	return ($(element).val() == value);
      },

      'ignoreIfNotVal': function(element, value) {
	return ($(element).val() != value);
      },

      'nextDisable': function() {
	$('#edit-next').attr('disabled', 'disabled');
	$('#edit-next').addClass('form-button-disabled');
      },

      'finishDisable': function() {
	$('#edit-finish').attr('disabled', 'disabled');
	$('#edit-finish').addClass('form-button-disabled');
      },

      'submitDisable': function() {
	$('#edit-submit').attr('disabled', 'disabled');
	$('#edit-submit').addClass('form-button-disabled');
      },

      'submitCheck': function(formName) {
	if (Drupal.settings.cmcForm[formName].status) {
	  $('#edit-submit').attr('disabled', '');
	  $('#edit-submit').removeClass('form-button-disabled');
	} else {

	  $('#edit-submit').attr('disabled', 'disabled');
	  $('#edit-submit').addClass('form-button-disabled');
	}
      },


      'nextCheck': function(formName) {
	if (Drupal.settings.cmcForm[formName].status) {
	  $('#edit-next').attr('disabled', '');
	  $('#edit-next').removeClass('form-button-disabled');
	} else {
	  $('#edit-next').attr('disabled', 'disabled');
	  $('#edit-next').addClass('form-button-disabled');
	}
      },

      'finishCheck': function(formName) {
	if (Drupal.settings.cmcForm[formName].status) {
	  $('#edit-finish').attr('disabled', '');
	  $('#edit-finish').removeClass('form-button-disabled');
	} else {
	  $('#edit-finish').attr('disabled', 'disabled');
	  $('#edit-finish').addClass('form-button-disabled');
	}
      },
    },

    addHandlers: function(obj) {
      for (var prop in obj) {
	if (obj.hasOwnProperty(prop)) {
	  Drupal.cmcForms.handlers[prop] = obj[prop];
	}
      }
    },

  }



}(jQuery));
