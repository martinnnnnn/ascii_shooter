#pragma once

#include "Component.h"


class Enemy : public Component
{

public:

	Enemy(GameObject*);
	~Enemy();

	virtual void update();


protected:

	void move();
	void init();
};

