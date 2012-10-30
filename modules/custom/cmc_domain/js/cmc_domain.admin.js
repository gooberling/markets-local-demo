(function ($) {

  Drupal.behaviors.cmc_domain_admin = {
    attach: function (context, settings) {
       return;
      // domain access domain
      var fieldset_domain = $('#edit-domain');
      
      // we hide the 'send to all affilliates' checkbox
      $('#edit-domain-site', fieldset_domain).parent().hide();
      
      $('#edit-domains input').click(function(e){
        showDomainPathTextfields();
      });
      showDomainPathTextfields();
      
      // hide the url alias field we don't want to use this field
      $('#edit-path .form-item-path-alias').hide();
      
      var pathauto_checkbox = $('#edit-path-pathauto'); 
      pathauto_checkbox.click(function(e){  
        showPathautoMessage($(this));        
      });
      
      showPathautoMessage(pathauto_checkbox);
      
      // we want to hide the url path settings
      // it's not really relevant with domain access
      // can we do this with permissions?
      
      // put in a js alert for the domain paths
      $('#edit-submit, #edit-preview').click(function(e){
        
        if ($('#edit-path-pathauto').attr('checked')) {          
          return;
        }
        
        var domains_checked = $('#edit-domains input:checked');
        var domain_missing = new Array();
        
        domains_checked.each(function(e){          
          var path_field = $('#edit-domain-path-' + $(this).val());          
          if (path_field.val() == '') {            
            var label = path_field.prev('label');
            domain_missing.push(label.text());
          }
        });
        
        if (domain_missing.length) {
          e.preventDefault();          
          alert(Drupal.t('Domain Paths missing! Please fill them in') + "\n" + domain_missing.join("\n"));
        }
      });
      
      
      
      // add/remove pathauto message
      function showPathautoMessage(checkbox) {
        if (checkbox.attr('checked')) {
          $('#edit-path-pathauto').before('<div id="pathauto-message"' 
              + 'style="border:2px solid red; padding:10px; margin:0 0 10px 0;">'
              + Drupal.t('Please Clear the domain urls for this to take effect, otherwise it will be whatever these are set to.')
              + '</div>');
        }
        else {
          $('#pathauto-message').remove();
        }
      }
      
      // helper function to show domain path textfields 
      function showDomainPathTextfields() {
        var checked = $('#edit-domains input:checked');
        
        // get the domain path fieldset and hide all the domain paths
        // unless the domain has been checked
        var fieldset_domainpath = $('#edit-domain-path');        
        $('.form-type-textfield', fieldset_domainpath).hide();
        
        $('.form-type-textfield', fieldset_domainpath).each(function(e){
          var input = $('input', this);
          if (input.val()) {
            input.attr('rel', input.val());
          }
          input.val('') // empty the value
        });
        
        checked.each(function(i){
          var wrapper = $('.form-item-domain-path-' + $(this).val(), fieldset_domainpath);
          wrapper.show();
          
          var input = $('input', wrapper);         
          if (input.attr('rel') != '') {
            input.val(input.attr('rel'));
          }
        });
      }
      
    }
  };  
})(jQuery);