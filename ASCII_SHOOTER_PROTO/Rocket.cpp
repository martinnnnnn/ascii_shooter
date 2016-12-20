#include "Rocket.h"

#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"


Rocket::Rocket(GameObject* obj) : Component(obj)
{
	init();
}


Rocket::~Rocket()
{
}

void Rocket::update()
{
	move();
}

void Rocket::init()
{
	GraphicsComponent* graphics = new GraphicsComponent(_gameObject);
	graphics->setSprite("Rocket.txt");
	addComponent(graphics);


	MovementComponent* p = new MovementComponent(_gameObject);
	p->setSpeed(2.0);
	_gameObject->addComponent(p);

	ColliderComponent* collider = new ColliderComponent(_gameObject);
	collider->setHitBox(1.0, 1.0);
	addComponent(collider);
}


void Rocket::move()
{
	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity({ 1, 0 });
	}
}