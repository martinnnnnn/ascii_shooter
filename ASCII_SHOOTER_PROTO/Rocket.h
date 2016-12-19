#pragma once

#include "Component.h"

class Rocket : public Component
{

public:


	Rocket(GameObject*);
	~Rocket();

	virtual void update();

protected:

	void init();
	void move();
};


