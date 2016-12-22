#pragma once

#include "Component.h"
#include "MessageHandler.h"


class GameObject;

class GameComponent : public Component, public MessageHandler
{

public:

	GameComponent(GameObject*);
	~GameComponent();

	virtual void init() {}
	virtual void wake() {}
	virtual void update() = 0;

	void sendMessage(Message);
	virtual void receiveMessage(Message);

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	GameObject* _gameObject;
	Component* addComponent(Component*);
};

