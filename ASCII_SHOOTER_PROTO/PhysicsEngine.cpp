#include "PhysicsEngine.h"

#include "Parametres.h"
#include "GameObject.h"
#include "GameEngine.h"
#include "MovementComponent.h"

#include <iostream>

using namespace std;

PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}


void PhysicsEngine::update()
{
	for (GameObject* obj : GameEngine::instance().getObjects())
	{
		MovementComponent* physics = obj->getComponent<MovementComponent>();

		if (physics)
		{
			vector2 pos = obj->getPosition();	
			float speed = physics->getSpeed();
			vector2 vel = physics->getVelocity();

			obj->setPosition(updatePosition(pos, vel, speed));
		}
	}
}

vector2 PhysicsEngine::updatePosition(vector2 pos, vector2 vel, float speed)
{
	vector2 newPos;

	newPos.x = pos.x + (vel.x * speed);
	newPos.y = pos.y + (vel.y * speed);


	if (newPos.x >= 0 && newPos.x + 2 < SCREEN_WIDTH)
	{
		pos.x = newPos.x;
	}
	if (newPos.y >= 0 && newPos.y + 2 < SCREEN_HEIGHT)
	{
		pos.y = newPos.y;
	}

	return newPos;

	//return newPos;

}

bool PhysicsEngine::intersect(vector2 pos1, vector2 hitbox1, vector2 pos2, vector2 hitbox2)
{
	bool intersecting = false;
	if (pos1.x < pos2.x + hitbox2.x
		&& pos2.x < pos1.x + hitbox1.x
		&& pos1.y < pos2.y + hitbox2.y
		&& pos2.y < pos1.y + hitbox1.y)
	{
		intersecting =  true;
	}
	return intersecting;
}
