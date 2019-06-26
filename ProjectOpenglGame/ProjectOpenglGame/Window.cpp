#include "Window.h"

namespace Engine {

	Window::Window() {

	}

	Window::~Window() {

	}

	int Window::CreateWindow(std::string winName, int screenWidth, int screenHeight, unsigned int currentFlags) {

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		//for mac
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		//create window
		window = glfwCreateWindow(screenWidth, screenHeight, winName.c_str(), NULL, NULL);

		//make our window current context
		glfwMakeContextCurrent(window);

		if (window == NULL) {			
			glfwTerminate();
			return -1;
		}

		//initialize glad
		//We pass GLAD the function to load the adress of the OpenGL function pointers which is OS - specific.GLFW gives us glfwGetProcAddress that defines the correct function based on which OS we're compiling for.

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			return -1;
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		return 0;
	}

	void Window::SwapBuffer() {
		glfwSwapBuffers(window);
	}

}