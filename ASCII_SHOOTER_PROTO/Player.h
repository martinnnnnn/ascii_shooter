#pragma once

#include "GameComponent.h"
#include "NYTimer.h"




class Player : public GameComponent
{

public:

	Player(GameObject* g);
	virtual ~Player();

	virtual void init(int life = 5, std::string path = "Ship1.txt", float speed = 4.0, float fireRate = 100.0);
	virtual void update();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void initValues(float speed, float fireRate);
	void initComponent(int life, std::string path);

	void move();
	void fire();

	void updateTime();


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

