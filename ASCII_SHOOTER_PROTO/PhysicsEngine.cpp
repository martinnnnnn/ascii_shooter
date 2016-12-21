#include "PhysicsEngine.h"

#include "Parametres.h"
#include "GameObject.h"
#include "GameEngine.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "MessageHandler.h"

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
			vector2 vel = movement->_velocity;

			current->setPosition(updatePosition(pos, vel));
		}

		ColliderComponent* currentCollider = current->getComponent<ColliderComponent>();
		if (currentCollider)
		{
			vector2 currentHitBox = currentCollider->_hitbox;
			vector2 currentPosition = current->getPosition();
			for (GameObject* other : gameObjects)
			{
				if (current != other)
				{
					ColliderComponent* otherCollider = other->getComponent<ColliderComponent>();
					if (otherCollider)
					{
						if (intersect(currentPosition, currentHitBox, other->getPosition(), currentCollider->_hitbox))
						{
							current->sendMessage(CHANGE_LIFE{ -1 });
							other->sendMessage(CHANGE_LIFE{ -1 });
						}
					}
				}
			}
		}
		
	}
}

vector2 PhysicsEngine::updatePosition(vector2 pos, vector2 vel)
{
	vector2 newPos;

	newPos.x = pos.x + (vel.x);
	newPos.y = pos.y + (vel.y);

	return newPos;
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
