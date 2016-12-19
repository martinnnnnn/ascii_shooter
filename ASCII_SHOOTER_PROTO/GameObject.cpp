#include "GameObject.h"
#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "Player.h"

#include "FileReader.h"

#include <iostream>


using namespace std;

GameObject::GameObject(string name, vector2 position)
{
	_name = name;
	_position = position;
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