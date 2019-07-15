#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
/*
This takes the pointers to the vertex to the vertex and index arrays so it can hand of the data to opengl(load data on graphic hardware) 

*/

class VertexArray {
public:

	VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices);
	
	~VertexArray();
	//activate the array so we can draw it
	void SetActive();

	unsigned int GetNumIndices() const { return mNumIndices; }
	unsigned int GetNumVert() const { return mNumVerts; }

private:
	//how many vertices in the vertex buffer
	unsigned int mNumVerts;

	//many indices in the vertex buffer
	unsigned int mNumIndices;

	//opengl ID of the vertex buffer
	unsigned int mVertexBuffer;

	//opengl ID of the index buffer
	unsigned int mIndexBuffer;

	//opengl ID of the vertex array object
	unsigned int mVertexArray;
};
