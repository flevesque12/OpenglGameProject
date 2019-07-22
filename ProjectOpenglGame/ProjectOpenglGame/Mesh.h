#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

/*
	Structure of a vertex data
*/
struct Vertex
{
	glm::vec3 m_Position;
	glm::vec3 m_Normal;
	glm::vec2 m_textureUV;
};

class Mesh {
public:
	Mesh();
	~Mesh();

	void Init(std::string pathToMesh, std::string pathToTexture);

	void Draw();
private:
	GLuint m_vao;
	GLuint m_vertexbuffer;
	GLuint m_uvbuffer;
	//GLTexture m_texture;

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec2> m_uvs;
	std::vector<glm::vec3> m_normals; // Won't be used at the moment.
};