#pragma once
#include <glm/glm.hpp>
#include <glm/trigonometric.hpp>
#include <vector>

class Actor {
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	//update called from game
	void Update(float deltaTime);

	//update all the components attached to the actor
	void UpdateComponents(float deltaTime);

	//any actor specific update code
	virtual void UpdateActor(float deltaTime);

	//add / remove Components
	void AddComponent(class Component* component);
	void RemoveComponents(class Component* component);

private:
	State m_State;

	//Transform
	glm::vec3 m_Position = glm::vec3(0.0f,0.0f,0.0f);

	//uniform scale 1.0f for 100%
	glm::vec3 m_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	
	//rotation
	float m_Rotation;

	//component held by this actor
	std::vector<class Component*> m_Components;
	class Game* m_Game;
};