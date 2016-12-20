#pragma once

#include "Component.h"
#include "NYTimer.h"




class Player : public Component
{

public:

	Player(GameObject* g);
	virtual ~Player();

	virtual void update();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void initComponent();
	void move();
	void fire();

	void updateTime();

	void initValues();

	float _speed;

	NYTimer* _timer;

	void fire1();
	double _fireRate1;
	double _previous1;
	double _elapsed1;

	void fire2();
	double _fireRate2;
	double _previous2;
	double _elapsed2;
};

