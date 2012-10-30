<div class="platform-header">
	
	<!-- content -->
	<div class="hero-content grid-4">
		<?php if(!empty($node->field_teaser['und'][0])): ?>
			<?php echo $node->field_teaser['und'][0]['safe_value']; ?>
		<?php endif; ?>
	</div>

	<!-- image or video -->
	<div class="hero-image dynamicExtra dynamicWidth">
		
		<canvas id="canvas" class="dynamicExtra IEdynamicWidth" style=""></canvas>
	</div>
	

	<?php
		$fields = array(
			'field_platform_desktop_videos' => 'field_platform_desktop',
			'field_platform_iphone_videos' => 'field_platform_iphone',
			'field_platform_ipad_videos' => 'field_platform_ipad',
			'field_platform_android_videos' => 'field_platform_android',
		);

		$still_only = FALSE;
		if (isset($node->field_still_only['und'])) {
				$still_only = $node->field_still_only['und'][0]['value'] == 1;
		}
	?>
	
	<?php
	$item_number=1;
	foreach ($fields as $field => $image_field): ?>
		<?php
			$i++;
			$videos = array();
			
			if (isset($node->{$field}['und']) && !$still_only) {
				foreach($node->{$field}['und'] as $video) {
					$videos[$video['filemime']] = $video;
				}
			}
			$video_types = array(
				'video/webm' => 'video/webm; codecs="vp8, vorbis"',
				'video/mp4' => 'video/mp4',
				'video/ogg' => 'video/ogg; codecs="theora, vorbis"',
			);
				
			$class = str_replace('field_platform_', '', $image_field);
			if (!empty($node->{$image_field}['und'])) {
				$image = file_create_url($node->{$image_field}['und'][0]['uri']);
			}
		?>
		<?php if (count($videos) > 0): ?>
			<video id="video-<?php echo $class ?>" class="sequence sequence-item-<?php echo $item_number ?> sequence-<?php echo $class ?>" rel="<?php echo $class ?>" poster="<?php echo $image; ?>">
				<?php foreach ($video_types as $key => $video_attributes) : ?>
					<?php if (!empty($videos[$key])): ?>
						<?php $video = $videos[$key]; ?>
						<source src="<?php echo file_create_url($video['uri']); ?>" type='<?php echo $video_attributes; ?>' />
					<?php endif; ?>
				 <?php endforeach; ?>
			</video>

			<!-- still image -->
		<img id="image-<?php echo $class ?>" class="platform-video-image sequence-item-none sequence-image-item-<?php echo $item_number ?>" rel="<?php echo $class; ?>" src="<?php echo $image; ?>"/>

		<?php elseif (!empty($node->{$image_field}['und'])): ?>
	
		<img id="image-<?php echo $class ?>" class="sequence sequence-item-<?php echo $item_number ?> sequence-image-item-<?php echo $item_number ?> sequence-<?php echo $class ?> platform-video-image" rel="<?php echo $class; ?>" src="<?php echo $image; ?>"/>

		<?php endif; ?>

		<?php $item_number++; ?>

	<?php endforeach; ?>
	
	<!-- Mask to cover the line at the edge of the video -->
	<div class="vid-mask dynamicExtra"></div>
</div>

<!-- timer circle -->
<div id="seekbar" ></div>
