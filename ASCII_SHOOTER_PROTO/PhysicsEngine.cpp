#include "PhysicsEngine.h"

#include "Parametres.h"
#include "GameObject.h"
#include "GameEngine.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "MessageHandler.h"
#include "FileReader.h"


#include <iostream>

using namespace std;

PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::initPhysics()
{
	initIgnoreMatrix();
}

void PhysicsEngine::initIgnoreMatrix()
{
	FileReader::readPhysicsIgnore("PhysicsIgnore.txt", _ignoreMatrix);
}

void PhysicsEngine::update()
{
	
	vector<GameObject*>& gameObjects = GameEngine::instance().getCurrentObjects();

	vector<ColliderComponent*> colliders;

	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		GameObject* current = gameObjects[i];
		if (current->isDead())
		{
			continue;
		}

		MovementComponent* movement = current->getComponent<MovementComponent>();
		if (movement)
		{
			updatePosition(current->_position, movement->getVelocity());
		}

		ColliderComponent* comp = current->getComponent<ColliderComponent>();
		if (comp != nullptr)
		{
			colliders.push_back(comp);
		}
	}

	for (int i = 0; i < colliders.size(); ++i)
	{
		for (int j = i + 1; j < colliders.size(); ++j)
		{
			if (colliders[j]->getGameObject()->isDead())
			{
				continue;
			}

			GameObject* currentObj = colliders[i]->getGameObject();
			GameObject* otherObj = colliders[j]->getGameObject();

			if (intersect(currentObj->_position, colliders[i]->getHitBox(), otherObj->_position, colliders[j]->getHitBox()))
			{
				if (!ignore(currentObj->getTag(), otherObj->getTag()))
				{
					currentObj->sendMessage(CHANGE_LIFE{ -1 });
					otherObj->sendMessage(CHANGE_LIFE{ -1 });
				}
			}
			
		}
	}


		//ColliderComponent* currentCollider = current->getComponent<ColliderComponent>();
		//if (currentCollider)
		//{
		//	for (unsigned int j = i+1; j < gameObjects.size(); ++j)
		//	{
		//		GameObject* other = gameObjects[j];
		//		if (other->isDead())
		//		{
		//			continue;
		//		}
		//		
		//		//ColliderComponent* otherCollider = other->getComponent<ColliderComponent>();
		//		ColliderComponent* otherCollider = other->getCollider();
		//		
		//		if (otherCollider)
		//		{
		//			if (intersect(current->_position, currentCollider->getHitBox(), other->_position, otherCollider->getHitBox()))
		//			{
		//				if (!ignore(current->getTag(), other->getTag()))
		//				{
		//					current->sendMessage(CHANGE_LIFE{ -1 });
		//					other->sendMessage(CHANGE_LIFE{ -1 });
		//				}
		//			}
		//		}
		//	}
		//}
		
	/*}*/
}

void PhysicsEngine::updatePosition(vector2& pos, vector2 vel)
{
	pos.x += vel.x;
	pos.y += vel.y;
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

bool PhysicsEngine::ignore(string tag1, string tag2)
{
	for (PhysicsIgnore ignore : _ignoreMatrix)
	{
		if (ignore.ignore(tag1, tag2))
		{
			return true;
		}
	}
	return false;
}
