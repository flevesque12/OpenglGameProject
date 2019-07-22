#pragma once
#include <unordered_set>

/*
	In this class we wil going to use the component pattern
*/

class GameObject {
public:
	void AddComponent();
	void RemoveComponent();

private:
	//std::unordered_set<Component*> m_Components;
};