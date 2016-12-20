#pragma once

#include "Component.h"
#include "Structures.h"

class Rocket : public Component
{

public:


	Rocket(GameObject*);
	~Rocket();

	virtual void update();

	void init(int life = 1, vector2 velocity = { 1, 0 }, float speed = 3.0);

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void initComponent(int life = 1, vector2 velocity = { 1, 0 });
	void move();

	void initValues(float speed = 3.0);
	
	float _speed;
};


