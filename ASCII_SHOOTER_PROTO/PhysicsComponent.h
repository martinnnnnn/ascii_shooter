#pragma once

#include "Component.h"
#include "Structures.h"


class PhysicsComponent : public Component
{

public:

	PhysicsComponent(GameObject* g) : Component(g) {}
	~PhysicsComponent();

	void setVelocity(float x, float y) { _velocity.x = x; _velocity.y = y; }
	void setVelocity(vector2 v) { _velocity = v; }

	void setSpeed(float speed) { _speed = speed; }

	float getSpeed() { return _speed; }
	vector2 getVelocity() { return _velocity; }


private:

	float _speed;
	vector2 _velocity;

};

