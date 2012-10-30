(function($) {

/**
 * Attach this editor to a target element.
 */
Drupal.wysiwyg.editor.attach.markitup = function(context, params, settings) {
  
  // anchor links
  if (settings.markupSet.link) {
    settings.markupSet.link['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.link();      
    }
  }
  
  // bullet lists
  if (settings.markupSet.list_bullet) {
    settings.markupSet.list_bullet['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.list_bullet('ul');
    }
  }
  
  // numbered lists
  if (settings.markupSet.list_numeric) {
    settings.markupSet.list_numeric['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.list_bullet('ol');      
    }
  }
  
  //numbered lists
  if (settings.markupSet.list_tabbed) {
    settings.markupSet.list_tabbed['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.list_tabbed();      
    }
  }
  
  // ajax preview
  if (settings.markupSet.ajaxpreview) {
    settings.markupSet.ajaxpreview['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.ajaxpreview(params);      
    }
  }
  
  // HTML table
  if (settings.markupSet.table) {
    settings.markupSet.table['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.table();      
    }
  }
  
  // Accordion
  if (settings.markupSet.accordion) {
    settings.markupSet.accordion['call'] = function() {
      Drupal.wysiwyg.editor.attach.markitup.accordion();      
    }
  }

  
  // media browser
  if (settings.markupSet.media) {    
    settings.markupSet.media['call'] = function(markItUp) {
      Drupal.wysiwyg.editor.attach.markitup.media(params);      
    }
  }
  
  //
  $('#' + params.field, context).markItUp(settings);

  // Adjust CSS for editor buttons.
  $.each(settings.markupSet, function (button) {
    $('.' + settings.nameSpace + ' .' + this.className + ' a')
      .css({ backgroundImage: 'url(' + settings.root + 'sets/default/images/' + button + '.png' + ')' })
      .parents('li').css({ backgroundImage: 'none' });
  });
  
};

/**
 * Detach a single or all editors.
 */
Drupal.wysiwyg.editor.detach.markitup = function(context, params) {
  if (typeof params != 'undefined') {
    $('#' + params.field, context).markItUpRemove();
  }
  else {
    $('.markItUpEditor', context).markItUpRemove();
  }
};




var functions = {
  //
  selectOptions : function(optionValues){
    var str = '';
    for (var i=0; i<optionValues.length; i++) {
      str += '<option value="' + optionValues[i]['value'] + '">' + optionValues[i]['label'] + '</option>';
    }  
    return str;
  },
  //
  getFormValues : function(form){
    var values = {};
    $.map(form.serializeArray(), function(n, i){
      values[n['name']] = n['value'];
    });
    return values;
  },
  
  openModalWindow : function(content) {
    // set the styles now the overlay is there
    $.modal(content);
    $('#simplemodal-overlay').addClass('ui-widget-overlay');    
  }
};

/**
 * 
 */
Drupal.wysiwyg.editor.attach.markitup.link = function() {
  
  var class_options = functions.selectOptions([
    {label:'Default', value:''},
    {label:'More', value:'more'},
    {label:'Arrow', value:'arrow'},
    {label:'Button Blue', value:'button blue'},
    {label:'Button Yellow', value:'button yellow'},
    {label:'Button Pink', value:'button pink'}
  ]);
  
  var target_options = functions.selectOptions([
    {label:'Same Window', value:''},
    {label:'New Window', value:'_blank'}
  ]);
  
  functions.openModalWindow('<div><h1>Link</h1><form>' +    
    '<div class="form-item"><label for="classname">Class</label><select id="classname" name="classname">' + class_options + '</select></div>' +
    '<div class="form-item"><label for="url">URL (include http:// if external url) <a id="internal-url" href="#">[Internal URL popup?]</a></label><input type="text" id="url" name="url" /></div>' +
    '<div class="form-item"><label for="text">text (leave empty if you have text highlighted)</label><input type="text" id="text" name="text" /></div>' +
    '<div class="form-item"><label for="classname">Window</label><select id="target" name="target">' + target_options + '</select></div>' +
    '<div class="form-item"><label for="title">Mouseover text</label><input type="text" id="title" name="title" /></div>' +
    '<div class="form-item"><input type="submit" name="submit" value="submit" /></div>' +
    '</form></div>');
  
  $('#simplemodal-container #internal-url').click(function(e){

    var link = $(this);
    
    //cmc_wysiwyg/list_internal_nodes
    $.ajax({
      type: 'GET',
      dataType: 'text',
      //data: 'data=' + encodeURIComponent($(field).val()),
      url: '/cmc_wysiwyg/list_internal_nodes',
      success: function(data) {          
        link.parent().after(data);        
        $('#internal-link-chooser-close').click(function(e){
          e.preventDefault();
          $('#internal-link-chooser').remove();          
        });
                
        // on click of menu, should auto fill the fields
        $('#internal-link-chooser li a').click(function(e){
          e.preventDefault();          
          var link = $(this);
          
          $.ajax({
            type: 'GET',
            dataType: 'text',
            data: 'url=' + link.attr('href'),
            url: '/cmc_wysiwyg/get_internal_url',
            success: function(data) {
              $('#simplemodal-data #url').val('/' + data);          
              $('#simplemodal-data #text').val(link.text());              
              $('#internal-link-chooser').remove();          
            },
            error: function() {
              alert('Error on internal url lookup');
            }
          });
        });      
        
        
        // add the open/collapse of menus
        $('ul li').each(function(i){
          // add in the open/collapse
          var li = $(this);
          var ul = $('ul', li);
          if (ul.length) {            
            ul.hide();
            $('a:first', li).after(' <a class="toggler" href="#">[Toggle]</a>');
            
            $('a.toggler', li).click(function(e){
              e.preventDefault();
              ul.toggle();
            });
          }
        });
      },
      error: function() {
        alert('Error on listing menus');
      }
    });
    
    // ajax call to get the menu!
    // view should have a page, limit to domain
    return false;
  });
  
  var form = $('#simplemodal-container form');
  form.submit(function(e){
    e.preventDefault();
    
    var form_values = functions.getFormValues(form);
    $.modal.close();
        
    var openHtml = '<a href="' + form_values.url + '"';
    if (form_values.classname) {openHtml += ' class="' + form_values.classname + '"';}
    if (form_values.target) {openHtml += ' target="' + form_values.target + '"';}
    if (form_values.title) {openHtml += ' title="' + form_values.title + '"';}
    openHtml += '>';    
    if (form_values.text) {openHtml += form_values.text;}
    
    var closeHtml = '</a>';
    
    $.markItUp({ openWith: openHtml, closeWith: closeHtml} );
  });
};


/**
 * 
 */
Drupal.wysiwyg.editor.attach.markitup.list_bullet = function(list_type) {
  
  var class_options;
  var title_list_type = '';
  
  if (list_type == 'ol') {
    class_options = functions.selectOptions([
       {label:'Default', value:''},
       {label:'link class 1', value:'class1'}
     ]);
    title_list_type = 'Numbered ';
  }
  else {
    class_options = functions.selectOptions([
       {label:'Default', value:''},
       {label:'Ticks', value:'tick'},
       {label:'Icons List', value:'iconlist'},
       {label:'Icons List 2-col', value:'iconlist col-2'}
     ]);
    
  }
  
  var num_items = new Array();
  for (var i=1; i<=20; i++) {    
    num_items.push({label:i,value:i});
  }
  num_items = functions.selectOptions(num_items);
    
  functions.openModalWindow('<div><h1>'  + title_list_type + 'List</h1><form>' +    
    '<div class="form-item"><label for="classname">Type</label><select id="classname" name="classname">' + class_options + '</select></div>' +
    '<div class="form-item"><label for="num_items">Number of Items in list</label><select id="num_items" name="num_items">' + num_items + '</select></div>' +
    '<div class="form-item"><input type="submit" name="submit" value="submit" /></div>' +
    '</form></div>');
  
  var form = $('#simplemodal-container form');
  form.submit(function(e){
    e.preventDefault();
    
    var form_values = functions.getFormValues(form);
    $.modal.close();
    
    var openHtml = '<' + list_type;
    if (form_values.classname) {openHtml += ' class="' + form_values.classname + '"';}
    openHtml += '>' + "\n";
    for (var i=0; i<form_values.num_items; i++) {
      if (form_values.classname == 'iconlist' || form_values.classname == 'iconlist col-2') {
        openHtml += "<li> Insert Image here followed by some text. Only one image per list item\n</li>\n\n";
      }
      else {
        openHtml += "<li> list item " + (i+1) + "</li>\n";
      }
    }
    
    openHtml += '</' + list_type + '>' +  "\n";
    
    $.markItUp({ openWith: openHtml} );
  });
};

/**
 * 
 */
Drupal.wysiwyg.editor.attach.markitup.ajaxpreview = function(params) {
  
  var field = $('#' + params.field);
  var iframe = $('iframe', field.parent());
  
  if (!iframe.length) {        
    field.parent().append('<iframe id="ajaxPreview" width="100%" height="600px" class="markItUpAjaxPreview"></iframe>');       
  }
 
  // make an ajax call to render what we've got in the text area 
  $.ajax({
    type: 'POST',
    dataType: 'text',
    data: 'data=' + encodeURIComponent($(field).val()),
    url: '/wysiwyg_preview',
    success: function(data) {          
      
      var ifrm = $('iframe', field.parent()).get(0);
      ifrm = (ifrm.contentWindow) ? ifrm.contentWindow : (ifrm.contentDocument.document) ? ifrm.contentDocument.document : ifrm.contentDocument;
      
      ifrm.document.open();
      ifrm.document.write(data);
      ifrm.document.close();
    }
  });
};


/**
 * Modal dialog for creating a table 
 */
Drupal.wysiwyg.editor.attach.markitup.table = function() {

  var class_options = functions.selectOptions([
    {label:'Default (full width)', value:''},
    {label:'Half width Left', value:'grid-3 left'},
    {label:'Half width Right', value:'grid-3 right'}    
  ]);
   
  var num_items = new Array();
  for (var i=1; i<=20; i++) {    
    num_items.push({label:i,value:i});
  }
  num_items = functions.selectOptions(num_items);
  
  // might have to deal with headings!
   
  functions.openModalWindow('<div><h1>Table</h1><form>' +    
    '<div class="form-item"><label for="classname">Class</label><select id="classname" name="classname">' + class_options + '</select></div>' +
    '<div class="form-item"><label for="rows">Rows</label><select id="rows" name="rows">' + num_items + '</select></div>' +
    '<div class="form-item"><label for="cols">Columns</label><select id="cols" name="cols">' + num_items + '</select></div>' +
    '<div class="form-item"><input type="submit" name="submit" value="submit" /></div>' +
    '</form></div>');
  
  
  var form = $('#simplemodal-container form');
  
  //add listeners for column widths
  $('#cols', form).change(function(e){
    
    var selectbox = $(this);
    var num_cols = selectbox.val()
    var col_width = Math.round(100 / num_cols, 0);
    
    var col_width_elements = $('#col-width-elements');
    if (col_width_elements.length) {
      col_width_elements.remove();
    }
    
    // add in the column widths
    // We set it explictly to equal widths!
    // otherwise use can set the widths themselves
    col_width_elements = '<div id="col-width-elements" style="margin:10px 0;">';
    col_width_elements += '<p>Enter in the column widths, defaults to % but can be px.<br />';
    col_width_elements += 'Entering heading values will add a row of headings into the table, leave blank for no headings.<br />';
    col_width_elements += 'Table colspans and rowspans can be added by editing the HTML directly.</p>';
    
     
    var align_options = '<option value="">left</option>';
    align_options += '<option value="center">center</option>';
    align_options += '<option value="right">right</option>';
    
    for (var i=1; i<=num_cols; i++) {      
      var col_width_element_id = 'col' + i;
      col_width_elements += 'Column ' + (i) + ' width: ';
      col_width_elements += '<input type="text" id="' + col_width_element_id + '" name="' + col_width_element_id + '" value="' + col_width + '%" />';
      col_width_elements += ' Align: ';
      col_width_elements += '<select name="' + col_width_element_id  + '_align" id="' + col_width_element_id + '_align">' + align_options + '</select>';
      col_width_elements += ' Heading: <input type="text" id="' + col_width_element_id + '_heading" name="' + col_width_element_id + '_heading" value="" />';
      col_width_elements += '<br />';
    }
    
    col_width_elements += "<div>\n"; 
    
    selectbox.after(col_width_elements);
    
  });
  
  
  // add submit handler
  form.submit(function(e){
    e.preventDefault();
     
    var form_values = functions.getFormValues(form);
    $.modal.close();
    
    var openHtml = '<div class="table-wrap"><!-- table wrap for mobile -->' + "\n";
    openHtml += '<table';
    if (form_values.classname) {openHtml += ' class="' + form_values.classname + '"';}    
    openHtml += '>' + "\n";
    
    // check if we have headings
    var has_heading = false;
    for (var i=1; i<=form_values.cols; i++) {
      if (form_values['col' + i + '_heading']) {
        has_heading = true;
        break;
      }
    }
    
    if (has_heading === true) {
      openHtml += "<tr>\n";
      for (var i=1; i<=form_values.cols; i++) {
        openHtml += '<th> ' + form_values['col' + i + '_heading'] + ' </th>' + "\n";
      }
      openHtml += "</tr>\n";
    }
    
    
    
    
    for (var i=1; i<=form_values.rows; i++) {      
      openHtml += "<tr>\n";
      
      for (var j=1; j<=form_values.cols; j++) {
        var align = $('#col' + j + '_align', form).val()
        var td_class = '';
        var col_width = '';
        if (i == 1 && form_values.cols > 1) {
          col_width = ' width="' + $('#col' + j, form).val() + '"';
        }
        if (align) {
          td_class = ' class="' + align + '"';
        }
        openHtml += '<td' + col_width + td_class+ '> {row ' + i + ' cell ' + j + '} </td>' + "\n";
      }
      
      openHtml += "</tr>\n";
    }
     
    openHtml += '</table>' + "\n";
    openHtml += '</div>' + "\n";
    
    $.markItUp({ openWith: openHtml} );
  });  
  
};




/**
 * Modal dialog for creating a tabbed list 
 */
Drupal.wysiwyg.editor.attach.markitup.list_tabbed = function() {
  
  // max of 4 tabs
  var num_items = new Array();
  for (var i=1; i<=4; i++) {    
    num_items.push({label:i,value:i});
  }
  num_items = functions.selectOptions(num_items);
    
  functions.openModalWindow('<div><h1>Tabbed List</h1><form>' +
    '<div class="form-item"><label for="num_items">Number of Tabs</label><select id="num_items" name="num_items">' + num_items + '</select></div>' +
    '<div class="form-item"><input type="submit" name="submit" value="submit" /></div>' +
    '</form></div>');
  
  var form = $('#simplemodal-container form');
  
  
  
//add listeners for column widths
  $('#num_items', form).change(function(e){

    var selectbox = $(this);
    var num_items = selectbox.val()
    
    var tab_headers = $('#tab-headers');
    if (tab_headers.length) {
      tab_headers.remove();
    }
    
    // Add tab headers
    tab_headers = '<div id="tab-headers" style="margin:10px 0;">';
    tab_headers += '<p>Enter in headings for the tabs</p>';
    
    for (var i=1; i<=num_items; i++) {      
      var item_id = 'tab_header' + i;
      tab_headers += 'Tab ' + (i) + ' Header: ';
      tab_headers += '<input type="text" id="' + item_id + '" name="' + item_id + '" value="Tab ' + i + '" />';
      tab_headers += '<br />';
    }
    
    tab_headers += "<div>\n";     
    selectbox.after(tab_headers);    
  });  
  
  // submit the form
  form.submit(function(e){
    e.preventDefault();
    
    var form_values = functions.getFormValues(form);
    $.modal.close();
    
    // add the tabbed html
    var openHtml = '<div class="tabbed">' + "\n" + '<div class="slider"></div>' + '<ul>' + "\n";
    var active_class;
    
    for (var i=1; i<=form_values.num_items; i++) {
      
      var tab_header = $('#tab_header' + i, form).val()      
      active_class = (i==1) ? ' class="active"': '';
      
      openHtml += "<li>";
      openHtml += '<h2><a href="#">' + tab_header + '</a></h2>' + "\n";
      openHtml += '<div class="detail">' + "\n";
      openHtml += "Tabbed Content item " + (i); 
      openHtml += "</div>";
      openHtml += "</li>\n\n";      
    }
    
    openHtml += '</ul>' + "\n" + '</div>' +  "\n";
    
    $.markItUp({ openWith: openHtml} );
  });
};



/**
 * Modal dialog for creating an accordion
 */
Drupal.wysiwyg.editor.attach.markitup.accordion = function() {
  
  functions.openModalWindow('<div><h1>Accordion</h1><form>' +    
    '<div class="form-item"><label for="url">Title: </label><input type="text" id="title" name="title" /></div>' +    
    '<div class="form-item"><input type="submit" name="submit" value="submit" /></div>' +
    '</form></div>');
  
  var form = $('#simplemodal-container form');
  
  // submit the form
  form.submit(function(e){
    e.preventDefault();
    
    var form_values = functions.getFormValues(form);
    $.modal.close();
    
    // add the tabbed html
    var openHtml = '<div class="accordion">' + "\n";
    openHtml += '<h2 class="title">' + form_values.title + '</h2>' + "\n";    
    openHtml += '<div class="detail">' + "\n\n";
    openHtml += "Accordion content\n";
    openHtml += "</div>\n";
    openHtml += "</div>\n";    
    
    $.markItUp({ openWith: openHtml} );
  });
};



/**
 * 
 */
Drupal.wysiwyg.editor.attach.markitup.media = function(params) {

  var instanceId = params.field;
  var data = {
    content:'',
    format: 'html',
    node: null
  };
  
  var media_settings = {
    global : {
      id: 'media_wysiwyg',
      types: ['audio', 'image', 'video']
    },
    path : '/sites/all/modules/contrib/media/wysiwyg_plugins/media'
  }

  Drupal.wysiwyg.plugins.cmcmedia.invoke(data, media_settings, instanceId);
  //data, settings, instanceId
  
};



})(jQuery);
