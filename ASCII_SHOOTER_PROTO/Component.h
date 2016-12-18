#pragma once

#include <string>

class GameObject;


class Component
{

public:

	Component(GameObject*);
	virtual ~Component();
	
	virtual void update() {}

	virtual void sendMessage(std::string msg, int data);
	virtual void receiveMessage(std::string msg, int data) {}

protected:

	GameObject* _gameObject;
};

