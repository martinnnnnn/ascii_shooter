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

	//inline void setHitBox(vector2 hitbox) { _hitbox = hitbox; }
	//inline void setHitBox(float h1, float h2) { _hitbox = { h1,h2 }; }
	//
	//vector2 getHitBox() { return _hitbox; }

	//virtual void operator()(DESTROY const& e) {}
	//virtual void operator()(CHANGE_LIFE const& e) {}

	vector2 _hitbox;

protected:



};

