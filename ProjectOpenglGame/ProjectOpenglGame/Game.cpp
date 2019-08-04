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

//private function
void Game::UpdateGame()
{

	//compute delta time
	float currentFrame = glfwGetTime();
	m_DeltaTime = (currentFrame - m_LastFrame)/1000;
	m_LastFrame = currentFrame;

	//update all actors
	m_UpdatingActors = true;

	for (auto actor : m_Actors) {
		actor->Update(m_DeltaTime);
	}

	m_UpdatingActors = false;

	//move any pending actors to m_Actors
	for (auto pending : m_pendingActors) {
		m_Actors.emplace_back(pending);
	}
	//erase them when they are already added to m_Actors
	m_pendingActors.clear();

	//add any dead actors to a temp vector
	std::vector<Actor*> deadActors;
	for (auto actor : m_Actors) {
		if (actor->GetState() == Actor::EDead) {
			deadActors.emplace_back(actor);
		}
	}

	//delete dead actors (remove them from the m_actors)
	for (auto actor : deadActors) {
		delete actor;
	}
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
	//rendering here
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);




	//swap the buffer
	glfwSwapBuffers(m_Window);
}

void Game::AddActor(Actor* actor) {
	//if updating the actor, need to add to the pending
	if (m_UpdatingActors) {
		m_pendingActors.emplace_back(actor);
	}
	else
	{
		m_Actors.emplace_back(actor);
	}
}

void Game::Shutdown() {
	while (!m_Actors.empty())
	{
		delete m_Actors.back();
	}

	glfwTerminate();
	glfwDestroyWindow(m_Window);
	glfwDestroyWindow(m_Window);
}