#pragma once


#include "Component.h"
#include "Structures.h"

class ColliderComponent : public Component
{

public:


	ColliderComponent() { _hitbox = { 0.0,0.0 }; }
	ColliderComponent(float x, float y) { _hitbox = { x,y }; }
	ColliderComponent(vector2 hitbox) { _hitbox = hitbox; }

	~ColliderComponent() {}

	vector2 _hitbox;

protected:



};

