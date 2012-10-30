

<div class="tabbed">
<div class="slider"></div>

  <ul>
  <?php foreach($tabs as $tab): ?>
  
  <li>
  <h2><a href="#"><?php echo t($tab['title']); ?></a></h2>
  
    <div class="detail" style="width:100%; overflow:hidden;">
            
      <div class="price-col-left" >
       	<?php echo $tab['edit_link']; ?>
	      <?php echo t($tab['content']); ?>
      </div>
            
      <div class="price-col-right">
		 <?php
	        // show pricing panel if one is selected
	        // otherwise show the image if one is uploaded
	        if (!empty($tab['pricing'])) {
	          echo $tab['pricing'];
	        }
	        else if (!empty($tab['image'])) {
	          echo $tab['image'];
	        }
	        ?>
      
      
      </div>
      
    </div>
  
  </li>
  
  <?php endforeach; ?>
  </ul>
</div>