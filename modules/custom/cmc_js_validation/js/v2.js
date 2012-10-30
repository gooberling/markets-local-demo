(function($) {
  /**
     Basic principles:

     Elements should provide two things: an array of validator functions, and
     an error handler function.  The validators are responsible for validating
     the state of the element, and return both a validation state and a
     message explaining why the element is invalid (if so).  The error handler
     function is responsible for displaying the error message in some way.

     This means that elements can be validated without any messages being
     displayed, and that different elements might have different error handlers,
     so that they might display errors in different ways.

     Bootstrap process:

     1) Drupal will load this file as a JS library.  The behavior object will
        be globally visible.
     2) Modules which want to make use of validators will set JS settings
        which indicate which validators to apply to which elements.
     3) Other modules may also extend the Drupal.behaviors.cmcValidation.
        validators object to make extra validators available.
     4) On page load, the attach() function is called.  This will attach the
        validators and perform on-load initialisation.


     TODO:

     * Ignoring elements
     * Marking elements visually

  */

  function isValidEmail(emailElement) {
    var emailPattern ;
    // Checking to see if email is of the form abcd@def.com
    emailPattern   = /^[a-zA-Z0-9\.\_\-\+]+@[a-zA-Z0-9\.\-]+\.[a-zA-Z]{2,4}$/;
    //Email address should be between 6-
    if (!emailPattern.test($(emailElement).val())) {
      return false;
    }
    else {
      return true;
    }
  }

  function isValidPass(passElement, compareElement) {
    var passPattern ;

    if (compareElement) {
      if($(passElement).val() === $(compareElement).val()) {
	return false;
      }
    }

    passPattern   = /.*^(?=.{6,15})/;
    if (!passPattern.test($(passElement).val())) {
      return false;
    }

    passPattern   = /.*^(?=.*[0-9]+)(?=.*[a-z])/ ;
    if (!passPattern.test($(passElement).val())) {
      return false;
    }

    passPattern   = /.*^(?=.*[a-z])/ ;
    if (!passPattern.test($(passElement).val())) {
      return false;
    }
    return true;
  }



  Drupal.behaviors.cmcValidation = {
    attach: function(context, settings) {
      init();
    },

    functions: {
      nextDisable: function() {
        var msg = '<div id="required-text">' +Drupal.t("Complete all required fields to continue")  +'</div>';
	if (!this.valid) {
	  $('#edit-next').attr('disabled', 'disabled');
	  $('#edit-next').addClass('form-button-disabled');
          
	  $('div.buttons div.right').prepend($(msg));
	  $('#required-text').show();
	}
      },

      finishDisable: function() {
	if (!this.valid) {
	  $('#edit-finish').attr('disabled', 'disabled');
	  $('#edit-finish').addClass('form-button-disabled');
	}
      },

      submitDisable: function() {
	if (!this.valid) {
	  $('#edit-submit').attr('disabled', 'disabled');
	  $('#edit-submit').addClass('form-button-disabled');
	}
      },

      submitCheck: function(formName) {
	if (this.valid) {
	  $('#edit-submit').attr('disabled', '');
	  $('#edit-submit').removeClass('form-button-disabled');
	} else {
	  $('#edit-submit').attr('disabled', 'disabled');
	  $('#edit-submit').addClass('form-button-disabled');
	}
      },


      nextCheck: function(formName) {
	if (this.valid) {
	  $('#required-text').hide();
	  $('#edit-next').attr('disabled', '');
	  $('#edit-next').removeClass('form-button-disabled');
	} else {
	  if ($('#required-text').length === 0) {
            var tmsg = '<div id="required-text">' +Drupal.t("Complete all required fields to continue")  +'</div>';
	    $('div.buttons div.right').prepend($(tmsg));
	  } else {
	    $('#required-text').show();
	  }
	  $('#edit-next').attr('disabled', 'disabled');
	  $('#edit-next').addClass('form-button-disabled');
	}
      },

      finishCheck: function(formName) {
	if (this.valid) {
	  $('#edit-finish').attr('disabled', '');
	  $('#edit-finish').removeClass('form-button-disabled');
	} else {
	  $('#edit-finish').attr('disabled', 'disabled');
	  $('#edit-finish').addClass('form-button-disabled');
	}
      },

      requiredValidator: function() {
	return {
	  valid: this.val().length > 0,
	  message: Drupal.t("This field is required and must not be empty")
	};
      },

      requiredIfSetValidator: function() {
        var thisElementHasValue = $(this).val().length > 0;
        var otherElementHasValue;

        for (var i = 0; i< arguments.length; i++) {
          otherElementHasValue = $(arguments[i]).val().length > 0;
          var valid = thisElementHasValue ? true : !otherElementHasValue;
          if (valid  == false) {
            // If we know element is invalid break loop
            break;
          }
        }
	
	return {
	  valid: valid,
	  message: Drupal.t("This field is required and must not be empty")
	};
      },

      companyNumberValidator: function(element) {
	return {
	  valid: !isNaN($(element).val()),
	  message: Drupal.t('The company number you have entered is invalid')
	};
      },
      requiredIfDateSetValidator: function(element) {
	var thisElementHasValue = this.val().length > 0;
	var valid;

	if (!thisElementHasValue) {
	  var id = element;

	  var day = $(id + '-day').val();
	  var month = $(id + '-month').val();
	  var year = $(id + '-year').val();

	  valid = day == 0 && month == 0 && year == 0;
	} else {
	  valid = true
	}

	return {
	  valid: valid,
	  message: Drupal.t("This field is required and must not be empty")
	};
      },

      requiredIfNotNullValidator: function(element) {
	return {
	  valid: $(element).val() !== '',
	  message: ''
	};
      },

      checkedValidator: function() {
	return {
	  valid: this.is(':checked'),
	  message: Drupal.t('This field must be checked to continue')
	};
      },

      standardErrorHandler: function(state) {
	var newClass;
	var oldClass;
	//console.log(selector);
	var error_div = this.attr('id') + "-error";

	var msg = state.message;
	var isValid = state.valid;
        var warn = state.warning;

	var parent = this.parent();
        var selectedVal;
	if (parent.hasClass('select-wrapper')) {
	  parent = parent.parent();
	}

	var required = ($('.form-required', parent).length > 0);
        
        // Step 1 check if the object has a warning set to it, if it is then 
        // we show warning before doing anything else
        if(warn && isValid ) {
     
          
          this.removeClass('error');
          this.removeClass('valid');
	  parent.removeClass('error');
          parent.removeClass('valid');
          this.addClass('warn-invalid');
          parent.addClass('warn-invalid');
          parent.append('<div id="'+ error_div +'" class="msgs warn-invalid">'+ msg +'<span></span></div>');
          
          $('.description').hide();
	  $('.form-item.active .msgs').fadeIn('slow');
          
          
        }
        else if (isValid) {
          if ($('input:checked', this).length > 0) {
            selectedVal = $('input:checked', this).val();
          } else {
            selectedVal = this.val();
          }
	  if ((selectedVal.length === 0) && !required) {
	    $('div').remove('#' + error_div);
	    this.removeClass('error');
            this.removeClass('valid');
            this.removeClass('warn-invalid');
	    parent.removeClass('error');
            parent.removeClass('warn-invalid');

	  } else {
	    newClass = 'valid';
	    oldClass= 'error';
	    // $(selector).parent().remove(error_id);
	    this.removeClass('warn-invalid');
            parent.removeClass('warn-invalid');
          
            $('div').remove('#' + error_div);

	    parent.removeClass(oldClass);
	    parent.addClass(newClass);
	    //console.log('add' + newClass);
	    this.addClass(newClass);
	    this.removeClass(oldClass);
	    //console.log('greater than');
	  }
	} else {
	  if ($('#' + error_div).length < 1) {
	    parent.append('<div id="'+ error_div +'" class="msgs error">'+ msg +'<span></span></div>');
	    //console.log('less than');
	    $('.description').hide();
	    $('.form-item.active .msgs').fadeIn('slow');

	    newClass = 'error';
	    oldClass= 'valid';
	    //console.log('add ' + newClass);
	    parent.removeClass(oldClass);
	    parent.addClass(newClass);

	    this.removeClass(oldClass);
	    this.addClass(newClass);
	  }
	}
      },

      dateErrorHandler: function(state) {
	var newClass;
	var oldClass;
	//console.log(selector);
	var error_div = this.attr('id') + "-error";

	var msg = state.message;
	var isValid = state.valid;

	var parent = this.parent();
	if (parent.hasClass('select-wrapper')) {
	  parent = parent.parent();
	}

	var required = ($('.form-required', parent).length > 0);

	if (isValid) {
	  if ((this.val().length === 0) && !required) {
	    $('div').remove('#' + error_div);
	    parent.removeClass('error');
	  } else {
	    newClass = 'valid';
	    oldClass= 'error';

	    $('div').remove('#' + error_div);
	    parent.removeClass(oldClass);
	    parent.addClass(newClass);
	  }
	} else {
	  if ($('#' + error_div).length < 1) {
	    parent.append('<div id="'+ error_div +'" class="msgs error">'+ msg +'<span></span></div>');

	    $('.description').hide();
	    $('.form-item.active .msgs').fadeIn('slow');

	    newClass = 'error';
	    oldClass= 'valid';

	    parent.removeClass(oldClass);
	    parent.addClass(newClass);
	  }
	}
      },

      nullErrorHandler: function(state) {
	// do nothing!
      },

      debugErrorHandler: function(state) {
	console.log( {state: state, element: this });
      },

      ignoreIfChecked: function(element) {
	return $(element).is(':checked');
      },
     
     ignoreIfNotChecked: function(element) {
	return !($(element).is(':checked'));
      },

      ignoreIfVal: function(element, value) {
	return ($(element).val() === value);
      },

      ignoreIfNotVal: function(element, value) {
	return ($(element).val() !== value);
      },

      ignoreIfEmpty: function(element) {
	return ($(element).val().length === 0);
      },

      /** Standard validators **/

      radioValidator: function(validOptions) {
	var valid = (($('input[type=radio]:checked', this).length > 0) &&
		     ($('input[type=radio]:checked', this).val() !== ''));

	return {
	  valid: valid,
	  message: 'Please select an option'
	};
      },

      dateValidator: function() {
	var id = '#' + this.attr('id');

	var day = $(id + '-day', this).val();
	var month = $(id + '-month', this).val();
	var year = $(id + '-year', this).val();

	var empty = day == 0 && month == 0 && year == 0;
	var full = !(day == 0 || month == 0 || year == 0);

	return {
	  valid: empty || full,
	  message: 'Please select a date'
	};
      },

      dateRequiredIfSetValidator: function(element) {
	var otherElementHasValue = $(element).val().length > 0;
	var valid;
	if (otherElementHasValue) {
	  // @todo refactor this and dateValidator
	  var id = '#' + this.attr('id');

	  var day = $(id + '-day', this).val();
	  var month = $(id + '-month', this).val();
	  var year = $(id + '-year', this).val();

	  var empty = day == 0 && month == 0 && year == 0;
	  valid = !(day == 0 || month == 0 || year == 0);
	} else {
	  valid = true;
	}

	return {
	  valid: valid,
	  message: Drupal.t('Please select a date')
	};
      },

      dobValidator: function(minAge) {
	var day = $('#edit-dob-day', this).val();
	var month = $('#edit-dob-month', this).val();
	var year = $('#edit-dob-year', this).val();
        var msg = Drupal.t('You must be at least @minage years old',{'@minage': minAge});
          
	if (day == 0 || month == 0 || year == 0) {
	  return {
	    valid: false,
	    message: msg
	  };
	}

	// moment is a bit weird about months
	var birthdate = moment([year, month - 1, day]);
	var requiredAge = birthdate.add('years', minAge);

	return {
	  // must have reached required age before today or today
	  valid: requiredAge.valueOf() <= moment().valueOf(),
	  message: Drupal.t(msg)
	};
      },

      emailValidator: function() {
	var isValid = isValidEmail(this);
	return {
	  valid: isValid,
	  message: Drupal.t('The email address you entered is an invalid format.')
	};
      },

      emailConfirmValidator: function(other, isPrimary) {
	var primary = isPrimary ? this : $(other);
	var secondary = isPrimary ? $(other) : this;
	var isEqual = primary.val() === secondary.val();
	var primaryIsValid = isValidEmail(primary);
	var secondaryIsBlank = secondary.val() === '';

	var message = '';

	if (!isEqual) {
	  message = Drupal.t('The email addresses do not match.');
	} else if (!primaryIsValid) {
	  message = Drupal.t('The email address you entered is an invalid format.');
	}

	return {
          valid: isEqual && primaryIsValid,
	  message: message
	};
      },
      
       ukEmailConfirmValidator: function(other, isPrimary) {
	var primary = isPrimary ? this : $(other);
	var secondary = isPrimary ? $(other) : this;

	var isEqual = primary.val() === secondary.val();
	var primaryIsValid = isValidEmail(primary);
	var secondaryIsBlank = secondary.val() === '';

	var message = '';

	if (!isEqual) {
	  message = Drupal.t('The email addresses do not match.');
	} else if (!primaryIsValid) {
	  message = Drupal.t("If the 'Email address' field above is green then your Email address do not match.<br><br>If the 'Email  address' field is pink then your original email address is invalid.");
	}

	return {
          valid: isEqual && primaryIsValid,
	  message: message
	};
      },

      passwordValidator: function(emailId) {
	var isValid = isValidPass(this, emailId);

	return {
	  valid: isValid,
	  message: Drupal.t('The password you entered is invalid: <ul><li>Must be between 6 and 15 characters long.</li><li>Must contain at least one lower case character and one number.</li><li>Cannot be the same as your email address.</li></ul>')
	};
      },

      passwordConfirmValidator: function(other, isPrimary, emailId) {
	var primary = isPrimary ? this : $(other);
	var secondary = isPrimary ? $(other) : this;
        
	var isEqual = primary.val() === secondary.val();
	var primaryIsValid = isValidPass(primary, emailId);

	var message = '';

	if (!isEqual) {
	  message = Drupal.t('Passwords do not match.');
	} else if (!primaryIsValid) {
	  message = Drupal.t('The password you entered is invalid: <ul><li>Must be between 6 and 15 characters long.</li><li>Must contain at least one lower case character and one number.</li><li>Cannot be the same as your email address.</li></ul>')
	}

	return {
	  valid: isEqual && primaryIsValid,
	  message: message
	};
      },
      
      ukPasswordConfirmValidator: function(other, isPrimary, emailId) {
	var primary = isPrimary ? this : $(other);
	var secondary = isPrimary ? $(other) : this;

	var isEqual = primary.val() === secondary.val();
	var primaryIsValid = isValidPass(primary, emailId);

	var message = '';

	if (!isEqual) {
	  message = Drupal.t('Passwords do not match.');
	} else if (!primaryIsValid) {
	  message = Drupal.t("If the 'password' field above is green then your passwords do not match.<br><br>If the 'password' field is pink then your original password does not meet the password criteria.");
	}

	return {
	  valid: isEqual && primaryIsValid,
	  message: message
	};
      },
      

      minLengthValidator: function(min) {
	var isValid = this.val().length >= min;
        var msg = Drupal.t('Minimum of @noofchars characters required',{'@noofchars' : min});
        return {
	  valid: isValid,
	  message: msg
	};
      }
    }
  };

  var Form = function() {

    var functions = Drupal.behaviors.cmcValidation.functions;

    function buildFuncArray(funcs) {
      var _funcs = [], f;
      for (f in funcs) {
	var fn = functions[f];
	var args = funcs[f];

	if (fn) {
	  _funcs.push({ "fn": fn, "args": args });
	}
      }

      return _funcs;
    }

    function makeBatchValidator(validators, element) {
      var funcs = buildFuncArray(validators);

      return function() {
	var result = { valid: true, message: '' };
	$.each(funcs, function(key, func) {
	  result = func.fn.apply(element, func.args);
	  if (!result.valid) {
	    return false;
	  }
	});

	return result;
      };
    }

    function makeBatchIgnoreHandler(ignores, element) {
      var funcs = buildFuncArray(ignores);

      return function() {
	var result = false;
	$.each(funcs, function(key, func) {
	  result = func.fn.apply(element, func.args);
	  if (result) {
	    return false;
	  }
	});

	return result;
      };
    }

    function makeEventHandler(validator, errHandler, form, id) {
      var dom = $(id).get(0);
      return function(event) {
	var state = validator(dom);
	form.updateElement(id, state);
      };
    }

    function safe(fn, _this) {
      if (typeof fn === 'function') {
	return function() { fn.apply(_this, arguments); };
      } else {
	return function() {};
      }
    }

    var _form = function(id, settings) {
      this.id = id;
      this.elements = {};
      this.valid = false;

      this.onChange = safe(functions[settings.change], this);

      this.addElements(settings.elements);

      var valid = this.scanElements();
      if (this.valid !== valid) {
	this.updateValidity(valid);
      }

      var self = this;
      $(':input', $(id)).focus(function() {
	var id = '#' + $(this).attr('id');
	if (self.elements[id]) {
	  self.activate(id);
	}
      });

      this.load = safe(functions[settings.load], this);

    };

    _form.prototype.activate = function(until) {
      $.each(this.elements, function(id, el) {
	if (id === until) {
	  return false;
	} else if (!el.ignore()) {
	  var state = el.validator();
	  el.errorHandler(state);
	}
      });
    };

    _form.prototype.addElements = function(elements) {
      var e;
      for (e in elements) {
	var $e = $(e);
	if ($e.length === 0) {
	  continue;
	}

	var eh = elements[e].errorHandler || 'standardErrorHandler';
	var el = {
	  id: e,
	  valid: undefined,
	  activated: false,
	  validator: makeBatchValidator(elements[e].validators, $e),
	  ignore: makeBatchIgnoreHandler(elements[e].ignore, $e),
	  errorHandler: safe(functions[eh], $e)
	};

	var eventHandler = makeEventHandler(el.validator, el.errorHandler,
					    this, el.id);

	var activator = function(_el) {
	  return function() {
	    _el.activated = true;
	  };
	}(el);

	$e.data({ element: el });
	$e.change(activator).blur(activator);

	$e.change(eventHandler).blur(eventHandler).keyup(eventHandler);

	if (elements[e].subscribe && elements[e].subscribe.length) {
	  var form = this;
	  $.each(elements[e].subscribe, function(key, id) {
	    var updater = function(form, toUpdate) {
	      return function() {
		form.elements[toUpdate].activated = true;
		form.revalidateElement(toUpdate);
	      }
	    }(form, e);
	    $(id).change(updater).blur(updater).keyup(updater);
	  });
	}

	this.elements[e] = el;
      }

      var self = this;

      $.each(this.elements, function(key, el) {
	var state = el.validator();
	var $el = $(el.id);
	if (!el.ignore()) {
	  self.updateElement(el.id, state);
	} else {
	  el.valid = state.valid;
	}
      });

    };

    _form.prototype.revalidateElement = function(id) {
      var el = this.elements[id];
      if (el) {
        if(el.ignore()) {
          state = {
            valid: true,
            message: ''
          };
          this.updateElement(id, state);
      } else {
          var state = el.validator();
          this.updateElement(id, state);
        }
      }
    };

    _form.prototype.updateElement = function(id, state) {
      var el = this.elements[id];
      var wasValid = el.valid;
      el.valid = state.valid;
//      el.activated = true;

//      if (state.valid !== wasValid) {
	// change of state handling
	if (el.activated) {
	  el.errorHandler(state);
	}
	this.elementChanged(el, state);
  //    }
    };

    /**
       An element has changed from valid to invalid.
       We need to scan through all elements to see if this results in the whole
       form changing state.
    */
    _form.prototype.elementChanged = function(element, state) {
      if (this.valid === state.valid) {
	// state change has no effect on form validity
	return;
      } else if (state.valid === false) {
	// form validity needs to be false, but currently true
	if (this.valid === true) {
	  this.updateValidity(false);
	}
      } else {
	// element has just become valid
	// scan all elements to see if whole form is valid
	var valid = this.scanElements();

	if (this.valid !== valid) {
	  this.updateValidity(valid);
	}
      }
    };

    _form.prototype.scanElements = function() {
      var valid = true;
      $.each(this.elements, function(id, el) {
	if (el.ignore()) {
	  return true; // continue
	}
	if (!el.valid) {
	  valid = false;
	  return false;
	}
      });

      return valid;
    };

    _form.prototype.updateValidity = function(valid) {
      this.valid = valid;
      this.stateChange(valid);
    };

    _form.prototype.stateChange = function(newState) {
      // @todo enable/disable buttons
      if (this.onChange) {
	// onChange should be a func which does stuff like disable buttons
	this.onChange.apply(this, [newState]);
      }
    };

    return _form;

  }();

  function init() {
    var name, f, forms = {};
    for (name in Drupal.settings.cmcForm) {
      f = new Form(name, Drupal.settings.cmcForm[name]);
      forms[name] = f;
      f.load();
    }
    Drupal.behaviors.cmcValidation.forms = forms;
  }

})(jQuery);
