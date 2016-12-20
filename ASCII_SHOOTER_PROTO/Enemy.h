#pragma once

#include "Component.h"


class Enemy : public Component
{

public:

	Enemy(GameObject*);
	~Enemy();

	virtual void update();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void move();
	void initComponents();

	void initValues();

	float _speed;

};

