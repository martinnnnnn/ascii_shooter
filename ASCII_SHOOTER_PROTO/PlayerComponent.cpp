#include "PlayerComponent.h"
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "InputEngine.h"
#include "GameEngine.h"


PlayerComponent::~PlayerComponent()
{
}

void PlayerComponent::update()
{

	vector2 vel{ 0,0 };

	if (GameEngine::instance()._inputs->isKeyDown(DOWN))
	{
		vel.y = 1;
	}
	else if (GameEngine::instance()._inputs->isKeyDown(UP))
	{
		vel.y = -1;
	}
	if (GameEngine::instance()._inputs->isKeyDown(LEFT))
	{
		vel.x= -1;
	}
	else if (GameEngine::instance()._inputs->isKeyDown(RIGHT))
	{
		vel.x = 1;
	}

	PhysicsComponent* physics = _gameObject->getComponent<PhysicsComponent>();
	if (physics)
	{
		physics->setVelocity(vel);
	}

}
