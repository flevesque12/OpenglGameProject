#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
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
	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath);
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

	void setVec2(const std::string &name, const glm::vec2 &value) const;
	void setVec2(const std::string &name, float x, float y) const;

	void setVec3(const std::string &name, const glm::vec3 &value) const;
	void setVec3(const std::string &name, float x, float y, float z) const;

	void setVec4(const std::string &name, const glm::vec4 &value) const;
	void setVec4(const std::string &name, float x, float y, float z, float w) const;

	void setMat2(const std::string &name, const glm::mat2 &mat) const;
	void setMat3(const std::string &name, const glm::mat3 &mat) const;
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
	void CheckCompileErrors(GLuint shader, std::string type);
};