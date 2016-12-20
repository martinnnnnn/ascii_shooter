#include "GameObject.h"
#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "Player.h"
#include "FileReader.h"
#include "Parametres.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


vector<string> GameObject::_Tags = { "Default" };


GameObject::GameObject(string tag, vector2 position)
{
	setTag(tag);
	_position = position;
	_dead = false;
}


GameObject::~GameObject()
{
}

void GameObject::update()
{
	if (_position.x > SCREEN_WIDTH + 10)
	{
		kill();
	}
	for (Component* comp : _components)
	{
		comp->update();
	}
}

void GameObject::addComponent(Component* c)
{
	_components.push_back(c);
}

vector<Component*>& GameObject::getComponents()
{
	return _components;
}

void GameObject::sendMessage(Message message)
{
	for (Component* c : _components)
	{
		c->receiveMessage(message);
	}
}

void GameObject::addTag(string tag)
{
	if (find(GameObject::_Tags.begin(), _Tags.end(), tag) != _Tags.end())
	{
		GameObject::_Tags.push_back(tag);
	}
}

bool GameObject::findTag(std::string tag)
{
	return find(GameObject::_Tags.begin(), _Tags.end(), tag) != _Tags.end();
}


void GameObject::setTag(std::string tag)
{
	GameObject::addTag(tag);
	_tag = tag;
}


bool GameObject::tagged(std::string tag)
{
	return (_tag == tag);
}