#pragma once

#include <string>

#include "MessageHandler.h"

class GameObject;


class Component : public MessageHandler
{

public:

	Component(GameObject*);
	virtual ~Component();
	
	virtual void update() {}


	void sendMessage(Message);

	virtual void receiveMessage(Message);

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	GameObject* _gameObject;
	Component* addComponent(Component*);

};

