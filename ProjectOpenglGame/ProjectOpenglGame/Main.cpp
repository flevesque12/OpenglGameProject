#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "VertexArray.h"
#include <iostream>
#include "stb_image.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main() {
	
	float vertices[] = {
   -0.5f,  0.5f, 0.0f,
	0.5f,  0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
   -0.5f, -0.5f, 0.0f,
   -0.5f,  0.5f, 0.0f,
	};

	float vertexBuffer[] = {
   -0.5f,   0.5f, 0.0f, // vertex 0
	0.5f,   0.5f, 0.0f, // vertex 1
	0.5f,  -0.5f, 0.0f, // vertex 2
	-0.5f, -0.5f, 0.0f  // vertex 3
	};

	unsigned int indexBuffer[] = {
	   0, 1, 2,
	   2, 3, 0
	};



	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//for mac
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Game in opengl", NULL, NULL);

	//make our window current context
	glfwMakeContextCurrent(window);
	
	if (window == NULL) {
		std::cout << "Window create failed" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	
	//initialize glad
	//We pass GLAD the function to load the adress of the OpenGL function pointers which is OS - specific.GLFW gives us glfwGetProcAddress that defines the correct function based on which OS we're compiling for.
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	//tell glfw we want to call this function on every window by registering
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// DeltaTime variables
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	//create vertex array
	VertexArray *mVertex = new VertexArray(vertexBuffer, 4, indexBuffer, 6);

	while (!glfwWindowShouldClose(window))
	{
		// calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//check and call event 
		glfwPollEvents();

		//input
		processInput(window);

		//update thing here

		//rendering here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
		

		//swap the buffer
		glfwSwapBuffers(window);		
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}




