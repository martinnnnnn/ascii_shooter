#include "Rocket.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "GameObject.h"


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
	graphics->setSprite("ZiziRocket.txt");
	addComponent(graphics);


	MovementComponent* p = new MovementComponent(_gameObject);
	p->setSpeed(5.0);
	_gameObject->addComponent(p);
}


void Rocket::move()
{

	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity({ 1, 0 });
	}
}