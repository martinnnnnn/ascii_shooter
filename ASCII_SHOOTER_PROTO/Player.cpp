#include "Player.h"

#include "GameObject.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"
#include "LifeComponent.h"

#include "InputEngine.h"
#include "GameEngine.h"
#include "Structures.h"

#include "Rocket.h"

#include <iostream>

using namespace std;


Player::Player(GameObject* obj) : Component(obj)
{
	initValues();
	initComponent();
}


Player::~Player()
{
}


void Player::initComponent()
{
	_timer = &(GameEngine::instance()._timer);

	_previous = _timer->getElapsedMs();

	GraphicsComponent* graphics = new GraphicsComponent(_gameObject);
	graphics->setSprite("Ship1.txt");
	addComponent(graphics);

	MovementComponent* movement = new MovementComponent(_gameObject);
	addComponent(movement);

	LifeComponent* life = new LifeComponent(_gameObject);
	life->setLife(5);
	addComponent(life);

	//ColliderComponent* collider = new ColliderComponent(_gameObject);
	//collider->setHitBox(3.0, 3.0);
	//addComponent(collider);

}

void Player::initValues()
{
	_speed = 1.0;
	_fireRate = 100.0;
}

void Player::update()
{
	updateTime();
	
	move();
	fire();
}

void Player::updateTime()
{
	_elapsed = _timer->getElapsedMs() - _previous;
}

void Player::move()
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
		vel.x = -1;
	}
	else if (GameEngine::instance()._inputs->isKeyDown(RIGHT))
	{
		vel.x = 1;
	}

	vel.x *= _speed;
	vel.y *= _speed;

	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->setVelocity(vel);
	}
}

void Player::fire()
{


	if (GameEngine::instance()._inputs->isKeyDown(ZERO) && _elapsed > _fireRate)
	{
		_previous = _timer->getElapsedMs();

		vector2 firePos = _gameObject->getPosition();

		if (firePos1)
		{
			firePos.y += 2;
		}
		firePos1 = !firePos1;

		GameObject* rocket = GameEngine::instance().getNewGameObject("Rocket", firePos);
		rocket->addComponent(new Rocket(rocket));
	}
}


