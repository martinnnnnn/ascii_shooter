#pragma once

#include "Component.h"
#include "Structures.h"


class MovementComponent : public Component
{

public:

	MovementComponent(vector2 v) : _velocity(v) {}
	MovementComponent(float x, float y) { _velocity = { x,y }; }
	MovementComponent() { _velocity = { 0.0,0.0 }; }

	~MovementComponent();

	vector2 _velocity;

private:


};

