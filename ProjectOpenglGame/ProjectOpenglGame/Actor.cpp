#include "Actor.h"


void Actor::Update(float deltaTime) {
	if (m_State == State::EActive) {
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime) {
	for (auto component : m_Components) {
		component->Update(deltaTime);
	}
}
