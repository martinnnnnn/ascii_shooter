#include "Player.h"

#include "GameObject.h"
#include "MovementComponent.h"
#include "InputEngine.h"
#include "GameEngine.h"
#include "Structures.h"
#include "GraphicsComponent.h"
#include "Rocket.h"


#include <iostream>

using namespace std;


Player::Player(GameObject* obj) : Component(obj)
{
	init();
}


Player::~Player()
{
}


void Player::init()
{
	_timer = &(GameEngine::instance()._timer);

	_previous = _timer->getElapsedMs();

	_fireRate = 100.0;

	GraphicsComponent* graphics = new GraphicsComponent(_gameObject);
	graphics->setSprite("Ship1.txt");
	addComponent(graphics);

	MovementComponent* movement = new MovementComponent(_gameObject);
	movement->setSpeed(2.0);
	_gameObject->addComponent(movement);
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

		GameObject* rocket = GameEngine::instance().getNewGameObject("Rocket",_gameObject->getPosition());
		rocket->addComponent(new Rocket(rocket));
	}
}


