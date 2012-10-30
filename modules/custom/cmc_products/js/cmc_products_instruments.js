/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) { 
  var instruments = [];
  $(document).ready(function() {
    var searchtype;
    
    // If this is the first time page is being loaded then we prepoluate instruments 
    // array with values from select box
  
    if (instruments.length === 0) {
      $("#selected_results option").each(function(){
        instruments.push($(this).val());
      });
    }
      
    $('#edit-get-instruments').click(function(event) {
      var querystring = "";
        // check what kind of search has been selected by editor
      if ($('#edit-search-type-content-search').attr('checked')) {
        querystring = $("#edit-body-und-0-value").val();
        searchtype = "content";
      }
      
      if ($('#edit-search-type-keywords-search').attr('checked')) {
         querystring = $("#edit-search-keywords").val();
          searchtype = "keywords";
       }
      var instrument_lookup_url = Drupal.settings.basePath + 'instruments_lookup';
      $.post(instrument_lookup_url,
        {search_api_views_fulltext: querystring,searchtype:searchtype},
        function(data) {
          markup = set_instruments_data(data);
        }
      );
    });
    
//    
//
//    $("input:checkbox[name='instruments']").live("click","",function(){
//      instruments = "";
//      instruments_list = $('input[name=instruments]:checked');  
//      $(instruments_list).each(function(){
//        if (instruments == "") {
//          instruments = $(this).val();
//        } else {
//          instruments = instruments + ',' +$(this).val();
//        }
//      });
//      
//      $('#edit-field-instruments-und-0-value').val(instruments);      
//    });

    function set_instruments_data(data) {
      var products = $.parseJSON(data);
      var markup;
      if (data.length < 3 ){
        $("#results-status").text(Drupal.t("No results found"));
      } 
      else {
        $("#results-status").empty();
        $("select[name='search_results'] option").remove();
        $.each(products, function(index, element) {
          $("select[name='search_results']")
          $("select[name='search_results']").append('<option value="'+ element.field_instrument_code +'">' + Drupal.t(element.title) + '</option>');
        });
      } 
    }
    
    /**
     * Function that moves selected options between fields
     */
    $("#MoveRight,#MoveLeft").click(function(event) {
      var id = $(event.target).attr("id");
      var selectFrom = id == "MoveRight" ? "#search_results" : "#selected_results";
      var moveTo = id == "MoveRight" ? "#selected_results" : "#search_results";
      var selectedItems = $(selectFrom + " option:selected");
      var output = [];

      $.each(selectedItems, function(key, e) {   
        output.push('<option value="' + e.value + '">' + e.text + '</option>');
        if (id == "MoveRight") {
          instruments.push(e.value);
        } 
      
        if(id == "MoveLeft") {
          if (instruments.length ===0) {
            $("#selected_results option").each(function(){
              instruments.push($(this).val());
            });
          }
          
           instruments = $.grep(instruments, function(value) {
           return value != e.value;
            
          });
        }
      });
      $(moveTo).append(output.join(""));               
      selectedItems.remove();
      reset_instruments_list(instruments);
      
    });
    
    function reset_instruments_list(keys) {
      var instruments_list ="";
      $(keys).each(function(index, val){
        if (instruments_list == "") {
          instruments_list = val;
        } else {
          instruments_list = instruments_list + ',' +val;
        }
      });
       $('#edit-field-instruments-und-0-value').val(instruments_list);     
     }
  });
} (jQuery));

