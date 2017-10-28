/* testing opaque text box with custom ffvi font */
/* needs to be within a function so google can load the font */
function textBoxTest()
{

  var canvas = document.getElementById("myCanvas");
  var ctx    = canvas.getContext("2d");

  canvas.width  = 640;
  canvas.height = 480;

  ctx.fillStyle = "#0000FF";
  ctx.fillRect(0,0, canvas.width, canvas.height);

  var bg = document.getElementById("bgImage");
  bg.onload = ctx.drawImage(bg, 0,0, canvas.width, canvas.height);
  //var bg = new Image();
  //bg.src = "images/narshecliffs.png";
  //bg.width  = 640;
  //bg.height = 480;

  // draw the background image
  //ctx.drawImage(bg, 0, 0, canvas.width, canvas.height);

  //var textbox = document.getElementById("textbox");

  // set the font
  //ctx.font = "30px 'Sans'";
  //ctx.font = "25px 'Sans Serif'";
  //ctx.fillStyle = "#FFFFFF";
  //ctx.shadowColor = "#000000";
  //ctx.shadowOffsetX = 2;
  //ctx.shadowOffsetY = 2;
  
  // located in dialogue.js
  //slowMessage("Test Text Here!");
  
  // draw the background
  //ctx.drawImage(bg, 0,0, canvas.width, canvas.height);
  
  // run a character dialogue
  //characterDialogue(ctx, "Terra", "Hello World!");
  
  // start the main loop
  //requestAnimationFrame(mainLoop);
  //function mainLoop()
  //{
    // clear the screen to the background image
    //ctx.drawImage(bg, 0, 0, canvas.width, canvas.height);
    
    // draw the text box
    //ctx.drawImage(textbox, 55, 300, 535, 152);
    
    // draw some sample text
    //ctx.fillText("Hello There!", 65, 335);
    
    // located in dialogue.js
    //characterDialogue(ctx, bg, "Terra", "Hello World!");
    
    //requestAnimationFrame(mainLoop);
  //}
  
}
