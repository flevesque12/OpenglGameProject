#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "VertexArray.h"
#include "Shader.h"
#include <iostream>
#include "stb_image.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void ShowMaxVertexSupported();

	int main() {


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
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
		Shader shader("Basic.vert", "Basic.frag",nullptr);
		
		float texCoords[] = {
			0.0f, 0.0f,  // lower-left corner  
			1.0f, 0.0f,  // lower-right corner
			0.5f, 1.0f   // top-center corner
		};

		float vertices[] = {
			// positions         // colors
			 0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 0.0f,  // bottom left
			 0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 1.0f   // top 
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//ShowMaxVertexSupported();
			

		while (!glfwWindowShouldClose(window))
		{
			// calculate delta time
			//GLfloat currentFrame = glfwGetTime();
			//deltaTime = currentFrame - lastFrame;
			//lastFrame = currentFrame;

			

			//input
			processInput(window);

			

			//rendering here
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			//update thing here
			
			shader.Use();
			float offset = 0.5f;
			shader.setFloat("xOffset", offset);

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			//swap the buffer
			glfwSwapBuffers(window);
			
			//check and call event 
			glfwPollEvents();
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

	void ShowMaxVertexSupported() {
		int nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	}




