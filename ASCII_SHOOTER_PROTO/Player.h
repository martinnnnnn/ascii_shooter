#pragma once

#include "Component.h"
#include "NYTimer.h"




class Player : public Component
{

public:

	Player(GameObject* g);
	virtual ~Player();

	virtual void update();

protected:

	void init();
	void move();
	void fire();
	void updateTime();

	double _fireRate;

	NYTimer* _timer;
	double _previous;
	double _elapsed;

	bool firePos1 = false;
};

