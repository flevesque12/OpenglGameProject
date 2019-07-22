#ifndef HEADER_GAME_H_
#define HEADER_GAME_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>
#include <string>


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

private:
	//game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOuput();

	bool m_IsRunning;

	//create window using glfw
	GLFWwindow* m_Window;

	//std::unordered_map<std::string, int> m_Keys;
};

#endif // !HEADER_GAME_H_