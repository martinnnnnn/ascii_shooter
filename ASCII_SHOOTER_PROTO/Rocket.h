#pragma once

#include "Component.h"

class Rocket : public Component
{

public:


	Rocket(GameObject*);
	~Rocket();

	virtual void update();


	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void initComponent();
	void move();

	void initValues();
	
	float _speed;
};


