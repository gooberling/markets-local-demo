function trackS2D6(pageType,emailAddress, identity) {
	var currentTime = new Date();
	var month = currentTime.getMonth() + 1;
	var day = currentTime.getDate();
	var year = currentTime.getFullYear();
	var hours = currentTime.getHours();
	var minutes = currentTime.getMinutes();
	var seconds = currentTime.getSeconds();
	if(minutes < 10){
		minutes = "0" + minutes;
	}
	if(seconds < 10){
		seconds = "0" + seconds;
	}
	var dateTime = year + month + day + hours + minutes + seconds;

	var s2d6TrackPixel = document.getElementById("s2D6TrackPixel");
	s2d6TrackPixel.setAttribute("src", document.location.protocol + "//www.s2d6.com/x/?x=sp&h=60780&o=" + identity + "&g=" + pageType + "&s=1.00&q=1&e1=" + emailAddress);
}