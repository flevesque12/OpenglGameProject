#ifndef HEADER_GAME_H_
#define HEADER_GAME_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Actor.h"


enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};


class Game {
public:
	GameState m_State;
	GLboolean m_Keys[1024];
	GLuint m_Width, m_Height;
	Game();
	~Game();

	//init the game
	bool Init();
	//run loop until is game is over
	void RunLoop();
	//shut the game
	void Shutdown();

	//add actor to either m_pendingActor or m_Actors
	void AddActor(Actor* actor);
	//remove the actor from whichever of the two vector it is in
	void RemoveActor(Actor* actor);

private:
	//game loop
	void ProcessInput();
	void UpdateGame();
	//or rendering 
	void GenerateOuput();

	bool m_IsRunning;
	bool m_UpdatingActors;

	// DeltaTime variables
	float m_DeltaTime = 0.0f;
	float m_LastFrame = 0.0f;
	//create window using glfw
	GLFWwindow* m_Window;

	//for keys
	//std::unordered_map<std::string, int> m_Keys;
	
	//pending actor when while updating all the actors you decide to create new actor
	std::vector<Actor*> m_pendingActors;

	//active actor(iterate over it(cannot add element))
	std::vector<Actor*> m_Actors;

};

#endif // !HEADER_GAME_H_