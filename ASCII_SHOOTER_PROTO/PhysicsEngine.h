#pragma once

#include "Structures.h"

class PhysicsEngine
{

public:

	PhysicsEngine();
	~PhysicsEngine();

	void update();


private:

	vector2 updatePosition(vector2 pos, vector2 vel, float speed);
	bool intersect(vector2 pos1, vector2 hitbox1, vector2 pos2, vector2 hitbox2);
};

