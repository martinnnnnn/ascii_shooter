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

	double _fireRate;
	float _speed;


	NYTimer* _timer;
	double _previous;
	double _elapsed;

	bool firePos1 = false;

};

