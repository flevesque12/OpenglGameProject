#pragma once


class Component {
public:
	//update order the lower it update, the ealier the component updates
	Component(class Actor* Owner, int updateOrder = 100);

	//destructor
	virtual ~Component();

	//update this component by delata time
	virtual void Update(float deltaTime);

	int GetUpdateOrder()const { return m_UpdateOrder; }

protected:
	//owning actor
	class Actor* m_Owner;
	//update order of component
	int m_UpdateOrder;
};