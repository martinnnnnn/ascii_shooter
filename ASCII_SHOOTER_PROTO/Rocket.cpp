#include "Rocket.h"

#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "Life.h"


Rocket::Rocket(GameObject* obj) : GameComponent(obj)
{
}


Rocket::~Rocket()
{
}

void Rocket::update()
{
	move();
}


void Rocket::init(int life, vector2 velocity, float speed)
{
	initValues(speed);
	initComponent(life, velocity);
}

void Rocket::initComponent(int lifeValue, vector2 velocity)
{

	GraphicsComponent* graphics = new GraphicsComponent("Rocket.txt"/*_gameObject*/);
	//graphics->setSprite("Rocket.txt");
	addComponent(graphics);


	MovementComponent* movement = new MovementComponent(velocity.x * _speed, velocity.y * _speed /*_gameObject*/);
	//movement->setVelocity({ velocity.x * _speed, velocity.y * _speed });
	_gameObject->addComponent(movement);

	ColliderComponent* collider = new ColliderComponent(1.0, 1.0/*_gameObject*/);
	//collider->setHitBox(1.0, 1.0);
	addComponent(collider);

	Life* life = new Life(_gameObject);
	life->init(lifeValue);
	addComponent(life);
}

void Rocket::initValues(float speed)
{
	_speed = speed;
}


void Rocket::move()
{
	//MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	//if (movement)
	//{
	//	movement->setVelocity({ 0.6f * _speed, 0.4f * _speed });
	//}
}