#include "Enemy.h"

#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "LifeComponent.h"

Enemy::Enemy(GameObject* obj) : Component(obj)
{
	initValues();
	initComponents();
}


Enemy::~Enemy()
{
}


void Enemy::update()
{
	move();
}


void Enemy::initComponents()
{

	GraphicsComponent* graphics = new GraphicsComponent(_gameObject);
	graphics->setSprite("Enemy1.txt");
	addComponent(graphics);


	MovementComponent* movement = new MovementComponent(_gameObject);
	addComponent(movement);

	ColliderComponent* collider = new ColliderComponent(_gameObject);
	collider->setHitBox(3.0, 1.0);
	addComponent(collider);

	LifeComponent* life = new LifeComponent(_gameObject);
	life->setLife(2);
	addComponent(life);
}

void Enemy::initValues()
{
	_speed = 1.0;
}

void Enemy::move()
{
	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity({ -1 * _speed, 0 * _speed });
	}
}