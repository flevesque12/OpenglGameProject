//request glsl 3.3
#version 330

//any vertex attribute go here
//for now it a position
in vec3 inPosition;

void main(){
	//directly pass along inPosition to gl_Position
	gl_Position = vec4(inPosition,1.0);
}