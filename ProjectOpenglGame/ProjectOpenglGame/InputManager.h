#pragma once
#include <unordered_map>
#include <glm/glm.hpp>

namespace Engine {
	class InputManager {
	public:
		InputManager();
		~InputManager();

		void Update();
		void KeyPress(unsigned int keyID);
		void KeyRelease(unsigned int keyID);

		bool IsKeyDown(unsigned int keyID); //return true the key is held
		bool IsKeyPressed(unsigned int keyID);

		//of a plane that is the screen
		void SetMouseCoords(float mouseX, float mouseY);
		glm::vec2 GetMouseCoords() const { return m_MouseCoords; }

	private:
		bool WasKeyDown(unsigned int keyID);

		std::unordered_map<unsigned int, bool> m_KeyMap;
		std::unordered_map<unsigned int, bool> m_PreviousKeyMap;
		glm::vec2 m_MouseCoords;
	};
}