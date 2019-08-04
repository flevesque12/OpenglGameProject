//request glsl 3.3
#version 330 core
layout(location = 0) in vec3 aPos; //the position variable has attribute position 0
layout(location = 1) in vec3 aColor;

out vec3 ourColor; //specify a color output to the fragment shader 
//any vertex attribute go here in or out
//for now it a position
out vec3 ourPosition;

uniform float xOffset;

void main(){
	//you can process input and do graphic stuff
	//the vertex shader that it receive its input straight from the vertex data
	//you can use .x .y .z and .w or rgba for color or stpq for texture coordinate
	//output processed stuff to output variable

	//directly pass along inPosition to gl_Position
	gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0); //see how we give a vec3 to vec4 is constructor
	//ourColor = aColor; //set the output variable to a dark red color
	ourPosition = aPos;
}