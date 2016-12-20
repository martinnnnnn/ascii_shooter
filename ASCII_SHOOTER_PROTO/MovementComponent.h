#pragma once

#include "Component.h"
#include "Structures.h"


class MovementComponent : public Component
{

public:

	MovementComponent(GameObject* g) : Component(g) {}
	~MovementComponent();

	void setVelocity(float x, float y) { _velocity.x = x; _velocity.y = y; }
	void setVelocity(vector2 v) { _velocity = v; }

	vector2 getVelocity() { return _velocity; }

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

private:

	vector2 _velocity;

};

