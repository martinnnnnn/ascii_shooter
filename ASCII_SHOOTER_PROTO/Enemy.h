#pragma once

#include "GameComponent.h"

#include <string>


class Enemy : public GameComponent
{

public:

	Enemy(GameObject*);
	~Enemy();

	virtual void init(int life = 0, std::string = "Enemy1.txt", float speed = 1.0);
	virtual void update();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void initValues(float speed);
	void initComponents(int lifeValue, std::string path);
	
	void move();

	float _speed;

};

