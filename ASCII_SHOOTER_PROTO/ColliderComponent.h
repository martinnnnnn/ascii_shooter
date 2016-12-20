#pragma once


#include "Component.h"
#include "Structures.h"

class ColliderComponent : public Component
{

public:


	ColliderComponent(GameObject*);
	~ColliderComponent();

	inline void setHitBox(vector2 hitbox) { _hitbox = hitbox; }
	inline void setHitBox(float h1, float h2) { _hitbox = { h1,h2 }; }
	
	vector2 getHitBox() { return _hitbox; }


protected:

	vector2 _hitbox;

};

