#include "PhysicsEngine.h"

#include "Parametres.h"
#include "GameObject.h"
#include "GameEngine.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"

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
	
	vector<GameObject*> gameObjects = GameEngine::instance().getObjects();
	for (GameObject* current : gameObjects)
	{
		MovementComponent* movement = current->getComponent<MovementComponent>();
		if (movement)
		{
			vector2 pos = current->getPosition();	
			float speed = movement->getSpeed();
			vector2 vel = movement->getVelocity();

			current->setPosition(updatePosition(pos, vel, speed));
		}

		ColliderComponent* currentCollider = current->getComponent<ColliderComponent>();
		if (currentCollider)
		{
			vector2 currentHitBox = currentCollider->getHitBox();
			vector2 currentPosition = current->getPosition();
			for (GameObject* other : gameObjects)
			{
				if (current != other)
				{
					ColliderComponent* otherCollider = other->getComponent<ColliderComponent>();
					if (otherCollider)
					{
						if (intersect(currentPosition, currentHitBox, other->getPosition(), currentCollider->getHitBox()))
						{
							//cout << "hello" << endl;
							current->sendMessage("TakeDamage", 1);
							other->sendMessage("TakeDamage", 1);
						}
					}
				}
			}
		}
		
	}
}

vector2 PhysicsEngine::updatePosition(vector2 pos, vector2 vel, float speed)
{
	vector2 newPos;

	newPos.x = pos.x + (vel.x * speed);
	newPos.y = pos.y + (vel.y * speed);

	return newPos;

	//if (newPos.x >= 0 && newPos.x + 2 < SCREEN_WIDTH)
	//{
	//	pos.x = newPos.x;
	//}
	//if (newPos.y >= 0 && newPos.y + 2 < SCREEN_HEIGHT)
	//{
	//	pos.y = newPos.y;
	//}


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
