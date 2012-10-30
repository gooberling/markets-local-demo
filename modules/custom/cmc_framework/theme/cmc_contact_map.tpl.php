
<?php //print_r($address); ?>
<script type="text/javascript"
  src="http://maps.googleapis.com/maps/api/js?key=<?php echo $gmap_key; ?>&sensor=false">
</script>
<script type="text/javascript">
  function gmap_initialize() {
    var location = new google.maps.LatLng(<?php echo $location['latitude']; ?>, <?php echo $location['longitude']; ?>);
    
    var myOptions = {
      center: location,
      zoom: <?php echo $gmap_zoom ?>,
      mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    var map = new google.maps.Map(document.getElementById("map_canvas"),
        myOptions);

    var contentString = '<div id="map_canvas_info" style="padding:5px; text-align:left;">'+
    '<?php echo implode('<br />', $address) ?>' +
    '</div>';
    
    var infowindow = new google.maps.InfoWindow({
        content: contentString
    });
    
    var marker = new google.maps.Marker({
      map:map,
      draggable:true,
      animation: google.maps.Animation.DROP,
      position: location
    });
    //google.maps.event.addListener(marker, 'click', toggleBounce);

    google.maps.event.addListener(marker, 'click', function() {
      infowindow.open(map,marker);
    });
  }

  
  
  google.maps.event.addDomListener(window, 'load', gmap_initialize);
</script>

<div id="map_canvas" style="height:400px;"></div>

