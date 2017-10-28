/* dialogue.js - for in game text/messages */

// true once started the speak interval
//var startedInterval = false;

// draw a character's dialogue with a message box and delay speed and all that
// ctx is the canvas context
// character is a string, message is a string
function characterDialogue(ctx, character, message)
{
  // width and height of the screen
  var s_width  = 640;
  var s_height = 480;
  
  // position and size of the dialog box
  var x = 55;
  var y = 300;
  var w = 535;
  var h = 152;
  
  // font to use for text
  var font      = "25px 'Sans Serif'";
  var textColor = "#FFFFFF";
  
  // apply the font/color to the canvas context
  ctx.font = font;
  ctx.fillStyle = textColor;
  
  // hold the dialogue box image
  var textBox;
  textBox = document.getElementById("textbox");
  
  // hold the image of the character
  var charLogo;
  charLogo = document.getElementById("terraPortrait");

  // TODO - do a switch to load each different character's portrait
  //if(character == "")
  
  // draw the dialog box
  ctx.drawImage(textBox, x, y, w, h);
  
  // draw the character portrait
  ctx.drawImage(charLogo, x + 10, y + 10, 75, 75);
  
  // draw the character's name and message
  ctx.fillText(character + ": ", x + 110, y + 30);
  
  // in progress
  var curChar = 0;
  function slowMessage()
  {
    //console.log("Message = " + message);
    console.log("Message[curChar] = " + message[curChar]);
    
    if( message[curChar] )
    {
      
      var tempMessage = "";
      for(i=0; i<curChar; i++)
      {
        tempMessage += message[i];
      }
      
      console.log("TempMEssage = " + tempMessage);
      curChar++;
      
      var font      = "25px 'Sans Serif'";
      var textColor = "#FFFFFF";
      var x         = 185;
      var y         = 310;
      
      console.log("About to fill text at " + x + "," + y);
      ctx.fillText(tempMessage, x, y);
      console.log("Filled text!");
    }
    else{
      curChar = 0;
      clearInterval(textInterval);
      setInterval(function(){
        console.log("Finished Function!");
      }, 1000);
    }
  }
  
  // prevent the starting of the interval to be called every frame
  //if( !startedInterval ) {
    // draw the text slowly at an interval and automatically stop itself
    var textInterval = setInterval( slowMessage,  75);
    //startedInterval = true;
  //}
}
