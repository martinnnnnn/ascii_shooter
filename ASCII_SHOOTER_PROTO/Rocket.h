#pragma once

#include "GameComponent.h"
#include "Structures.h"

class Rocket : public GameComponent
{

public:


	Rocket(GameObject*);
	~Rocket();

	virtual void update();

	void init(int life = 1, vector2 velocity = { 1, 0 }, float speed = 6.0);


protected:

	void initValues(float speed);
	void initComponent(int life, vector2 velocity);

	void move();

	
	float _speed;
};


