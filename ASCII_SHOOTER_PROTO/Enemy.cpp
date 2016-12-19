#include "Enemy.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "GameObject.h"

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
}


void Enemy::move()
{
	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity({ -1, 0 });
	}
}