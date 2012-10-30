<?php
// Google map iframe
?>
<h3>Location</h3>
<?php // echo $location; ?>

<?php if (count($address)): ?>
<p>
<?php echo implode(", ", $address);?>
</p>
<?php endif; ?>
 
<!-- Google map iframe BEGIN -->
<iframe width="580" height="300" frameborder="0" class="map" scrolling="no" marginheight="0" marginwidth="0"
src="http://maps.google.co.uk/?iwloc=&amp;output=embed&amp;<?php echo $query ?>">
</iframe>
<!-- Google map iframe END -->