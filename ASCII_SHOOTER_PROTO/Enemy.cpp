#include "Enemy.h"

#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"


Enemy::Enemy(GameObject* obj) : Component(obj)
{
	init();
}


Enemy::~Enemy()
{
}


void Enemy::update()
{
	move();
}


void Enemy::init()
{
	GraphicsComponent* graphics = new GraphicsComponent(_gameObject);
	graphics->setSprite("Enemy1.txt");
	addComponent(graphics);


	MovementComponent* movement = new MovementComponent(_gameObject);
	movement->setSpeed(1.0);
	addComponent(movement);

	ColliderComponent* collider = new ColliderComponent(_gameObject);
	collider->setHitBox(3.0, 1.0);
	addComponent(collider);
}


void Enemy::move()
{
	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity({ -1, 0 });
	}
}