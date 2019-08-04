// Request GLSL 3.3
#version 330 core
out vec4 FragColor;
in vec3 ourColor; // the input variable from the vertex shader(same name and same type)
in vec3 ourPosition;
//in type in_variable_name
//the fragment shader requires a vec4 color output variable, since the fragment shaders needs to generate a final output color
// This is output color to the color buffer

void main()
{
	FragColor = vec4(ourPosition, 1.0f);   
}