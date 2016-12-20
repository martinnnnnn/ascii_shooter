#include "GameObject.h"
#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "Player.h"

#include "FileReader.h"

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