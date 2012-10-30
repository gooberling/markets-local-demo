// CMC Markets Theme
// name = CMC Markets V4
// description = CMC Markets Base Theme - as of 17/02

(function($) {

	// Store our function as a property of Drupal.behaviors.
	Drupal.behaviors.cmc_core_override = {
		// Overwrites core JS function in autocomplete.js line 165
		customAutoCompleteHidePopup: function(keycode) {

			// Select item if the right key or mousebutton was pressed.
			if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
				this.input.value = $(this.selected).data('autocompleteValue');
			}
			submit = 13 == keycode && $(this.input).hasClass('cmc_auto_submit');
			// Hide popup.
			var popup = this.popup;
			if (popup) {
				this.popup = null;
				$(popup).fadeOut('fast', function() {
					$(popup).remove();
				});
			}
			this.selected = false;
			$(this.ariaLive).empty();

			if (submit) {
				this.input.form.submit();
			}

		},

		// Overwrites core JS function in autocomplete.js line 267
		customAutoCompleteSearch: function(searchString) {
			var db = this;
			this.searchString = searchString;

			// See if this string needs to be searched for anyway.
			searchString = searchString.replace(/^\s+|\s+$/, '');
			if (searchString.length <= 0 || searchString.charAt(searchString.length - 1) == ',') {
				return;
			}

			// See if this key has been searched for before.
			if (this.cache[searchString]) {
				return this.owner.found(this.cache[searchString]);
			}

			// Initiate delayed search.
			if (this.timer) {
				clearTimeout(this.timer);
			}
			this.timer = setTimeout(function() {
				db.owner.setStatus('begin');

				// Ajax GET request for autocompletion.
				$.ajax({
					type: 'GET',
					url: db.uri + '/' + Drupal.encodePath(searchString),
					dataType: 'json',
					success: function(matches) {
						if (typeof matches.status == 'undefined' || matches.status != 0) {
							db.cache[searchString] = matches;
							// Verify if these are still the matches the user wants to see.
							if (db.searchString == searchString) {
								db.owner.found(matches);
							}
							db.owner.setStatus('found');
						}
					},
					error: function(xmlhttp) {
						if (xmlhttp.status != 0) {
							alert(Drupal.ajaxError(xmlhttp, db.uri));
						}
					}
				});
			}, this.delay);
		},

		// Overwrites core JS function in ajax.js line 451
		customAjaxError: function(response, uri) {
			console.log('custom handling');
			if (response.status != 0) {
				alert(Drupal.ajaxError(response, uri));
			}
			// Remove the progress element.
			if (this.progress.element) {
				$(this.progress.element).remove();
			}
			if (this.progress.object) {
				this.progress.object.stopMonitoring();
			}
			// Undo hide.
			$(this.wrapper).show();
			// Re-enable the element.
			$(this.element).removeClass('progress-disabled').removeAttr('disabled');
			// Reattach behaviors, if they were detached in beforeSerialize().
			if (this.form) {
				var settings = response.settings || this.settings || Drupal.settings;
				Drupal.attachBehaviors(this.form, settings);
			}
		},
		
		attach: function(context) {

			if ("ACDB" in Drupal) {
				Drupal.ACDB.delay = 100;
			}

			jQuery('html').once('cmc_core_override', function() {

				if ($(".region-text-search").length > 0) {

					// This sets the custom JS autocomplete.js and ajax.js functions to overwrite the ones in Core
					Drupal.jsAC.prototype.hidePopup = Drupal.behaviors.cmc_core_override.customAutoCompleteHidePopup;
					Drupal.ACDB.prototype.search = Drupal.behaviors.cmc_core_override.customAutoCompleteSearch;

					if (Drupal.ajax) {
						Drupal.ajax.prototype.error = Drupal.behaviors.cmc_core_override.customAjaxError;
					}
					var old_select = Drupal.jsAC.prototype.select;
					Drupal.jsAC.prototype.select = function(node) {
						old_select.apply(this, [node]);
						$('input[type=submit]', this.input.form).click();
					}
				}
			});
			

			
			// end script
		}
	};
}(jQuery));
