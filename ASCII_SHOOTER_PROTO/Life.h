#pragma once

#include "GameComponent.h"
#include "MessageHandler.h"

class GameObject;

class Life : public GameComponent
{

public:

	Life(GameObject*);
	~Life();

	virtual void init(int life = 1);
	virtual void update();

	inline void changeLife(int value) { _life += value; }

	inline int getLife() { return _life; }

	//virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) { changeLife(e.value); }


protected:

	int _life;
};

