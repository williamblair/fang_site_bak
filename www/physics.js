        
function startPhysics () {
			var canvas = document.getElementById("myCanvas");
			var ctx    = canvas.getContext('2d');
	
	        /* add the width and height for calculations below */
	        canvas.width = 640;
	        canvas.height = 480;
	
	        /* some physics variables */
	        //var accelGrav = 9.8; // 9.8m/s^2
            var accelGrav = document.getElementById("gravity").value;
	        var ballMass  = 5.0;   // some arbitrary mass
            var ax = 0.0;   // the ball's x and y acceleration
	        var ay = accelGrav;
	        var ballForceY = 0.0;   // for calculating f=ma 
            var ballForceX = 0.0;
	        var timeStep  = 0.07;  // time increment per frame
            var elast     = -1 * document.getElementById("elasiticity").value;  // the 'bounciness' of the ball - negate so it moves back up when it hits the ground
	
			/* coordinates of the circle */
	        var radius = 10;
            var x = canvas.width/2 - radius;
			//var startX = document.getElementById("posX").value;
            var y = radius;
			//var startY = document.getElementById("posY").value;

            //x = startX;
            //y = startY;

            //console.log("start x = " + startX);
            //console.log("start y = " + startY);
	
	        /* variables for the circle */
	        var vx = 0.0; // velocity x and y
	        var vy = 0.0;
			
			function main(){
	
	            /* apply physics */
	            ballForceY = ballMass * ay; // f=ma
	            ay = ballForceY / ballMass; // a=f/m

                ballForceX = ballMass * ax;
                ax = ballForceX / ballMass;
	
                /* apply y acceleration and velocity */
	            vy += ay * timeStep; // apply gravity	
	            y += vy * timeStep; // move the ball

                /* apply x acceleration and velocity */
                vx += ax * timeStep;
                x += vx * timeStep;

	            /* if the ball hits the ground 
                 * (vertical hit detection) */
	            if( y > canvas.height - radius && vy > 0 ) {
                    /* apply the 'elastic' force */
                    vy *= elast;

                    /* move the ball away from the wall a little so it doesn't get stuck */
                    y = canvas.height - radius;
	            }

                /* if the ball hits the left or right wall */
                if( (x > canvas.width - radius || x < 0.0 + radius)&& vx != 0 ){
                    vx *= elast;

                    /* move it away from the left or right wall if necessary */
                    if( x < 0 ) x = radius;
                    else if( x > canvas.width - radius ) x = canvas.width - radius;
                }
	
				/* clear the screen */
				ctx.fillStyle = "#FFFFFF";
				ctx.fillRect(0, 0, canvas.width, canvas.height);
	
				/* draw a circle */
				ctx.fillStyle = "#000000";
	            ctx.beginPath();
				ctx.arc(x, y, radius, 0, 2*Math.PI);
	            ctx.stroke();
		
			    /* run the function again */
		    	requestAnimationFrame(main);
	    	}
		
    		/* start the main loop */
		    main();
        }

        startPhysics(); // call the above function

