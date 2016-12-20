#pragma once

#include "Component.h"

class GameObject;

class LifeComponent : public Component
{

public:

	LifeComponent(GameObject*);
	~LifeComponent();

	virtual void update();

	inline void setLife(int value) { _life = value; }
	inline void changeLife(int value) { _life += value; }

	inline int getLife() { return _life; }

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) { changeLife(e.value); }

protected:

	int _life;
};

