#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/transform.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "VertexArray.h"
#include "Shader.h"
#include <iostream>
#include "stb_image.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void ShowMaxVertexSupported();
void TransformMatrix();
void TranslateMatrix();

const int width = 800;
const int height = 600;

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

		//configure global opengl state(z buffer)
		//----------------------------------------------
		glEnable(GL_DEPTH_TEST);

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
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		glm::vec3 cubePositions[] = {
			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(2.0f,  5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f,  2.0f, -2.5f),
			glm::vec3(1.5f,  0.2f, -1.5f),
			glm::vec3(-1.3f,  1.0f, -1.5f)
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
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
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			//update thing here
			
			shader.Use();

			float offset = 0.5f;
			shader.setFloat("xOffset", offset);
			

			#pragma region Camera

			glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);

			glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);


			// Projection matrix: 45 degree field of view, 4:3 ratio, display range: 0.1 unit <-> 100 units
			glm::mat4 projection = glm::perspective(glm::radians(50.0f), (float)width / (float)height, 0.1f, 100.0f);

			//or if you want an ortho camera :
			//glm::mat4 projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f); // In world coordinates

			//camera matrix
			glm::mat4 view = glm::lookAt(
				glm::vec3(0, 3, 3), // Camera is at (4,3,3), in World Space
				glm::vec3(0, 0, 0), // and looks at the origin
				glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);

			// Model matrix : an identity matrix (model will be at the origin)
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::rotate(model,(float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 0.0f, 1.0f));
			
			//retrieve the matrix uniform location
			unsigned int modelLocation = glGetUniformLocation(shader.ID, "model");
			unsigned int viewLocation = glGetUniformLocation(shader.ID, "view");
			
			//pass them to the shader 3 different way
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);

			// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
			shader.setMat4("projection", projection);

			// Our ModelViewProjection : multiplication of our 3 matrices
			//glm::mat4 mvp = projection * view * model; // Remember, matrix multiplication is the other way around

			#pragma endregion Camera
			
			//render container
			glBindVertexArray(VAO);
			for (unsigned int i = 0; i < 10; i++)
			{
				// calculate the model matrix for each object and pass it to shader before drawing
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, cubePositions[i]);
				float angle = 20.0f * i;
				model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
				shader.setMat4("model", model);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

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

	//homogeneous coordinates 
	//if w == 1 then the vector (x,y,z,1) is a position in space
	//if w == 0 then the vector (x,y,z,0) is a direction

	void TransformMatrix(){
		//Matrix * vertex in that order
		glm::mat4 myMatrix;
		glm::vec4 myVector;
		// fill myMatrix and myVector somehow
		glm::vec4 transformedVector = myMatrix * myVector; // Again, in this order ! this is important.
	}

	void TranslateMatrix(){
		glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(10.0f, 0.0f, 0.0f));
		glm::vec4 myVector(10.0f, 10.0f, 10.0f, 0.0f);
		glm::vec4 transformedVector = myMatrix * myVector; // guess the result


		//identity matrix 
		glm::mat4 myIndetityMat = glm::mat4(1.0f);
	}




