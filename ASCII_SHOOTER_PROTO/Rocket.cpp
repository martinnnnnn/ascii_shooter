#include "Rocket.h"

#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "LifeComponent.h"


Rocket::Rocket(GameObject* obj) : Component(obj)
{
	initValues();
	initComponent();
}


Rocket::~Rocket()
{
}

void Rocket::update()
{
	move();
}

void Rocket::initComponent()
{

	GraphicsComponent* graphics = new GraphicsComponent(_gameObject);
	graphics->setSprite("Rocket.txt");
	addComponent(graphics);


	MovementComponent* p = new MovementComponent(_gameObject);
	_gameObject->addComponent(p);

	ColliderComponent* collider = new ColliderComponent(_gameObject);
	collider->setHitBox(1.0, 1.0);
	addComponent(collider);

	LifeComponent* life = new LifeComponent(_gameObject);
	life->setLife(1);
	addComponent(life);
}

void Rocket::initValues()
{
	_speed = 3.0;
}


void Rocket::move()
{
	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity({ 1 * _speed, 0 * _speed });
	}
}