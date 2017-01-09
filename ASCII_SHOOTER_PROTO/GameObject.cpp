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
	_enabled = true;
}


GameObject::~GameObject()
{
	for (Component* c : _components)
	{
		delete c;
	}
}

void GameObject::update()
{
	if (_position.x > SCREEN_WIDTH + 10)
	{
		kill();
	}
	for (Component* comp : _components)
	{
		GameComponent* script = dynamic_cast<GameComponent*>(comp);
		if (script)
		{
			script->update();
		}
	}
}

//void GameObject::wake()
//{
//
//	for (Component* comp : _components)
//	{
//		GameComponent* script = dynamic_cast<GameComponent*>(comp);
//		if (script)
//		{
//			script->wake();
//		}
//	}
//}

void GameObject::addComponent(Component* c)
{
	_components.push_back(c);
}

vector<Component*>& GameObject::getComponents()
{
	return _components;
}

void GameObject::sendMessage(GOMessage message)
{
	for (Component* c : _components)
	{
		GameComponent* script = dynamic_cast<GameComponent*>(c);
		if (script)
		{
			script->receiveMessage(message);
		}
	}
}

void GameObject::addTag(string tag)
{
	if (find(GameObject::_Tags.begin(), _Tags.end(), tag) != _Tags.end())
	{
		GameObject::_Tags.push_back(tag);
	}
}

bool GameObject::findTag(string tag)
{
	return find(GameObject::_Tags.begin(), _Tags.end(), tag) != _Tags.end();
}


void GameObject::setTag(string tag)
{
	GameObject::addTag(tag);
	_tag = tag;
}

string GameObject::getTag()
{
	return _tag;
}

bool GameObject::isTagged(string tag)
{
	return (_tag == tag);
}