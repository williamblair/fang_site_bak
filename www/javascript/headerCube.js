/* babylon.js cube to put in header 
 * make sure the canvas id is 'myCanvas'!!! */

// Get the canvas element from our HTML below
var canvas = document.querySelector("#myCanvas");
// Load the BABYLON 3D engine
var engine = new BABYLON.Engine(canvas, true);

// -------------------------------------------------------------
// Here begins a function that we will 'call' just after it's built
var createScene = function () {

	// Now create a basic Babylon Scene object
	var scene = new BABYLON.Scene(engine);

	// Change the scene background color to green.
	//scene.clearColor = new BABYLON.Color3(0, 1, 0);
	scene.clearColor = new BABYLON.Color3(0.918, 0.918, 0.918);

	// This creates and positions a free camera
	var camera = new BABYLON.FreeCamera("camera1", new BABYLON.Vector3(0, 5, -10), scene);

	// This targets the camera to scene origin
	camera.setTarget(BABYLON.Vector3.Zero());

	// remove control as it's not supposed to be interactive here
	// This attaches the camera to the canvas
	//camera.attachControl(canvas, false);

	// This creates a light, aiming 0,1,0 - to the sky.
	var light = new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(0, 1, 0), scene);

	// Dim the light a small amount
	light.intensity = .5;

	// Let's try our built-in 'sphere' shape. Params: name, subdivisions, size, scene
	var cube = BABYLON.Mesh.CreateBox("cube1", 5, scene);

	// Move the sphere upward 1/2 its height
	cube.position.y = -0.25;

	// stuff to do during loop - rotate the cube
	scene.registerBeforeRender( function(){ 
		cube.rotation.x += 0.05;
		cube.rotation.y += 0.03;
		cube.rotation.z += 0.01;

		if( cube.rotation.x > 2*Math.PI){ cube.rotation.x = 0.0; }
		if( cube.rotation.y > 2*Math.PI){ cube.rotation.y = 0.0; }
		if( cube.rotation.z > 2*Math.PI){ cube.rotation.z = 0.0; }
	});

	// Leave this function
	return scene;
}; // End of createScene function

// -------------------------------------------------------------
// Now, call the createScene function that you just finished creating
var scene = createScene();

// Register a render loop to repeatedly render the scene
engine.runRenderLoop(function () {
	scene.render();
});

// Watch for browser/canvas resize events
window.addEventListener("resize", function () {
	engine.resize();
});

