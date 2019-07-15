#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using std::string;

/*
	I used some element of the shader programm from learnopengl.com
	1. Load and compile the vertex shader.
	2. Load and compile the fragment shader.
	3. Link the two shaders together into a “shader program.”
*/

class Shader {

public:
	//program id
	unsigned int ID;

	/*
		param vsFileName	path to the vertex shader
		param fsFileName	path to the fragment shader
	*/
	Shader(const char* vsFileName, const char* fsFileName);
	~Shader();

	enum ShaderType 
	{
		VERTEX,
		FRAGMENT,
		PROGRAM
	};

	//use the shader program
	void Use();

	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
};