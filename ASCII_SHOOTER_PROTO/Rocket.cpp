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

	GraphicsComponent* graphics = new GraphicsComponent(_gameObject, "Rocket.txt");
	addComponent(graphics);


	MovementComponent* movement = new MovementComponent(_gameObject, velocity.x * 10, velocity.y * 10);
	_gameObject->addComponent(movement);

	ColliderComponent* collider = new ColliderComponent(_gameObject, 1.0, 1.0);
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