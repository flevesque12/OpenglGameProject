#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string>

namespace Engine {
	enum WindowFlags 
	{
		INVISIBLE = 0x1,
		FULLSCREEN = 0x2,
		BORDERLESS = 0x4
	};

	class Window {
	public:
		Window();
		~Window();

		int CreateWindow(std::string winName, int screenWidth, int screenHeight, unsigned int currentFlags);
		int GetScreenWidth() { return m_ScreenWidth; }
		int GetScreenHeight() { return m_ScreenHeight; }

		void SwapBuffer();

	private:
		GLFWwindow* window;
		int m_ScreenWidth;
		int m_ScreenHeight;

	};
}