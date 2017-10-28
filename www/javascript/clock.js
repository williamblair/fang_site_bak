/* a digital clock for fun 
 * code taken from  (and slightly modified)
 * https://bocoup.com/weblog/javascript-arduino-digital-clock-johnny-five 
 * */
function startTime() {
	var date = new Date();           // full date format
	var AMPM = (date.getHours() <= 12) ? "AM" : "PM"; // determine to end with AM or PM
	var h    = date.getHours() % 12; // hours in AM/PM format
	var m    = date.getMinutes();
	var s    = date.getSeconds();

	/* change 0 hrs to 12 if necessary */
	if( h == 0 ) { 
		h = 12;
	}
	
	/* add preceding zero if necessary */
	if(m < 10){
		m = "0" + m;
	}
	if(s < 10){
		s = "0" + s;
	}
	
	document.getElementById('timer').innerHTML = "Time: " + h + ":" + m + ":" + s + " " + AMPM;
	var t = setTimeout(function(){startTime()}, 500);
}
startTime(); // call and start it up

