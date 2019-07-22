#include "Game.h"

Game::Game(){

}

Game::~Game()
{

}

bool Game::Init()
{
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
		return false;
	}
	else
	{
		return true;
	}

	//initialize glad
	//We pass GLAD the function to load the adress of the OpenGL function pointers which is OS - specific.GLFW gives us glfwGetProcAddress that defines the correct function based on which OS we're compiling for.

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}
	else
	{
		return true;
	}	
}

void Game::RunLoop(){
	while (m_IsRunning) {
		ProcessInput();
		UpdateGame();
		GenerateOuput();
	}
}


void Game::Shutdown(){
	glfwTerminate();
	glfwDestroyWindow(m_Window);
}


//private function
void Game::UpdateGame()
{

}


void Game::ProcessInput()
{	
	/*
	glfwPollEvents();
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(m_Window, true);
		m_IsRunning = false;
	}
	*/
}

void Game::GenerateOuput()
{

}