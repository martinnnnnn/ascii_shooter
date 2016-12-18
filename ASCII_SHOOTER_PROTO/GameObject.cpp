#include "GameObject.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "PlayerComponent.h"

#include "FileReader.h"

using namespace std;

GameObject::GameObject()
{
	_position.x = 4.0;
	_position.y = 10.0;

	addComponent(new GraphicsComponent(this));
	addComponent(new PlayerComponent(this));
	PhysicsComponent* p = new PhysicsComponent(this);
	p->setSpeed(2.0);
	addComponent(p);

	
}


GameObject::~GameObject()
{
}

void GameObject::addComponent(Component* c)
{
	_components.push_back(c);
}

vector<Component*>& GameObject::getComponents()
{
	return _components;
}

void GameObject::sendMessage(string msg, int data)
{
	for (Component* c : _components)
	{
		c->receiveMessage(msg, data);
	}
}