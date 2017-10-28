/* intro.js for FFVI html */

var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");

// set size of canvas
canvas.width = 640;
canvas.height = 480;

// set z position of canvas so we can add other elements on top of it
canvas.style.zIndex = "-1"; // -1 is lowest

ctx.fillStyle = "#000000"; // test fill for now
ctx.fillRect(0,0, canvas.width, canvas.height); // fill the screen

// get and play the background music
var prologue = document.getElementById("titlemusic");
prologue.load();
prologue.play();

// get the logo image and set style attributes for it
var logo_words = document.getElementById("logo");
logo_words.style.marginLeft  = "36px";
logo_words.style.marginTop   = "160px";
logo_words.style.position    = "absolute";
logo_words.style.zIndex      = "2";

// get the background logo image
var terraLogo = document.getElementById("terraMagLogo");

// get the background clouds
var clouds = document.getElementById("stormyclouds");
clouds.onload = animClouds;


// as soon as it's loaded, start animating
// logo_words.onload = animLogo;

// set width and height to view for test
//logo_words.style.width  = "300px";
//logo_words.style.height = "200px";

// animate the clouds background
var opacity = 0; // fade in the clouds at first
var cloudClipY = 10; // clipping y for cloud image
function animClouds()
{
    if(cloudClipY < 230){
        if(opacity < 1){
            ctx.globalAlpha = opacity;
            opacity += 0.0005; // slowly fade in
        }
        cloudClipY += 0.19;
        requestAnimationFrame(animClouds);
    }
    else{
        // after finished drawing the clouds start drawing the logo
        console.log("Done fading in clouds!\n");
        requestAnimationFrame(animLogo);
        return false; // finished animating the clouds
    }
    
    // draw the clouds on the canvas
    ctx.fillRect(0,0,canvas.width,canvas.height);
    ctx.drawImage(clouds, 0, cloudClipY, 236, 362, 0, 0, canvas.width, canvas.height);
    
}

// animate the logo intro
var logo_w = 0; var logo_h = 2;
var flashCounter = 0; // flash only once
function animLogo()
{
    logo_words.style.width  = String(logo_w) + "px";
    logo_words.style.height = String(logo_h) + "px";
    
    // expands the image horizontally across the screen
    if(logo_w < 560){
        logo_w += 8;
        requestAnimationFrame(animLogo); // run the function again
                                         // at a relative browser speed
    }
    
    // expand the words vertically across the screen
    else
    {
        // flash screen to look like lightning
        if( flashCounter < 10 ){
            ctx.fillStyle = "#FFFFFF";
            ctx.fillRect(0,0,canvas.width,canvas.height);
            flashCounter++;
        }
        else{
            ctx.fillStyle = "#000000";
            ctx.fillRect(0,0,canvas.width,canvas.height);
            ctx.drawImage(clouds, 0, cloudClipY, 236, 362, 0, 0, canvas.width, canvas.height);
        }
        
        logo_h += 1.5;
        if( logo_h < 80 ){
            
            // flash screen to look like lightning
            if( flashCounter < 20 ){
                ctx.fillStyle = "#FFFFFF";
                ctx.fillRect(0,0,canvas.width,canvas.height);
                flashCounter++;
            }
            else{
                ctx.fillStyle = "#000000";
                ctx.fillRect(0,0,canvas.width,canvas.height);
                ctx.drawImage(clouds, 0, cloudClipY, 236, 362, 0, 0, canvas.width, canvas.height);
            }
            
            requestAnimationFrame(animLogo);
        }
        else{
            console.log("Done animating logo!");
            
            // start drawing the background logo
            // reset the lightning flash counter
            flashCounter = 0;
            console.log("Flash counter = " + flashCounter);
            requestAnimationFrame(animMagitekLogo);
        }
    }
}

// location and size of background magitek logo
var mag_x = 180;
var mag_y = 50;
var mag_w = 300;
var mag_h = 200;

// how many frames to delay before adding the background logo
var delay = 0;

// animate the image of terra on a magitek armor behing the logo
function animMagitekLogo()
{
    // wait for music to make a big hit again
    if(delay < 275)
    {
        console.log("Delay time: " + delay);
        delay++;
        requestAnimationFrame(animMagitekLogo);
    }
    
    else
    {
        // draw lightning
        if(flashCounter < 10){
            console.log("Flash counter = " + flashCounter);
            ctx.fillStyle = "#FFFFFF";
            ctx.fillRect(0,0,canvas.width,canvas.height);
            flashCounter++;
            requestAnimationFrame(animMagitekLogo);
        }
        else{
            // use the black screen for another 10 frames - for delay
            if(flashCounter < 20){
                flashCounter++;
                ctx.fillStyle = "#000000";
                ctx.fillRect(0,0,canvas.width,canvas.height);

                ctx.drawImage(clouds, 0, cloudClipY, 236, 362, 0, 0, canvas.width, canvas.height);

                ctx.drawImage(terraLogo, mag_x, mag_y, mag_w, mag_h);
                requestAnimationFrame(animMagitekLogo);
            }
            // after the 10 frames delay flash again
            else if(flashCounter < 30){
                console.log("Flash counter = " + flashCounter);
                ctx.fillStyle = "#FFFFFF";
                ctx.fillRect(0,0,canvas.width,canvas.height);
                flashCounter++;
                requestAnimationFrame(animMagitekLogo);
            }
            // then go back to normal black background
            // gives it time to fill in completely
            else if(flashCounter < 40){
                flashCounter++;
                ctx.fillStyle = "#000000";
                ctx.fillRect(0,0,canvas.width,canvas.height);

                ctx.drawImage(clouds, 0, cloudClipY, 236, 362, 0, 0, canvas.width, canvas.height);

                ctx.drawImage(terraLogo, mag_x, mag_y, mag_w, mag_h);
                requestAnimationFrame(animMagitekLogo);
            }
            else{
                console.log("Finished adding terra magitek background!");
                return false;
            }
        }
    }
    //requestAnimationFrame(animMagitekLogo);
}
