#include "VertexArray.h"

VertexArray::VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices){

	//create vertex array object
	glGenVertexArrays(1, &mVertexArray);
	glBindVertexArray(mVertexArray);

	//create a vertex buffer(glBindBuffer)
	glGenBuffers(1, &mVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);

	glBufferData(
		GL_ARRAY_BUFFER, //the active buffer type to write to
		numVerts * 3 * sizeof(float), //number of bytes to copy
		verts, //source to copy from (pointer)
		GL_STATIC_DRAW // how we will use this data
	);

	//create a index buffer
	glGenBuffers(1, &mIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);

	//copy indices data into the index buffer
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, //index buffer
		numIndices * sizeof(unsigned int), //size of data
		indices, GL_STATIC_DRAW
	);

	//specify a vertex layout, also called the vertez attributes
	glEnableVertexAttribArray(0); //enable the first attribute 0
	
	//specify the attribute
	glVertexAttribPointer(
		0,                 // Attribute index (0 for first one)
		3,                 // Number of components (3 in this case)
		GL_FLOAT,          // Type of the components
		GL_FALSE,          // (Only used for integral types)
		sizeof(float) * 3, // Stride (usually size of each vertex)
		0                  // Offset from start of vertex to this attribute
	);
}

VertexArray::~VertexArray() {
	glDeleteBuffers(1, &mVertexBuffer);
	glDeleteBuffers(1, &mIndexBuffer);
	glDeleteVertexArrays(1, &mVertexArray);
}


void VertexArray::SetActive() {
	glBindVertexArray(mVertexArray);
}
