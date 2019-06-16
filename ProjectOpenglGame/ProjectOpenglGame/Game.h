#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};


class Game {
public:
	GameState State;
	GLboolean Keys[1024];
	GLuint Width, Height;
	Game(GLuint width, GLuint height);
	~Game();

	//init game
	void Init();

	//game loop
	void ProcessInput(GLfloat deltaTime);
	void Update(GLfloat deltaTime);
	void Render();
};