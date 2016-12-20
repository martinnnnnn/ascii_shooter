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

	_previous1 = _timer->getElapsedMs();
	_previous2 = _timer->getElapsedMs();

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
	_fireRate1 = 100.0;
}

void Player::update()
{
	updateTime();
	
	move();
	fire();
}

void Player::updateTime()
{
	_elapsed1 = _timer->getElapsedMs() - _previous1;
	_elapsed2 = _timer->getElapsedMs() - _previous2;

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


	if (GameEngine::instance()._inputs->isKeyDown(FIRE1) && _elapsed1 > _fireRate1)
	{
		_previous1 = _timer->getElapsedMs();
		fire1();
	}
	if (GameEngine::instance()._inputs->isKeyDown(FIRE2) && _elapsed2 > _fireRate2)
	{
		_previous2 = _timer->getElapsedMs();
		fire2();
	}
}

void Player::fire1()
{
	vector2 firePos = _gameObject->getPosition();

	firePos.x += 2;
	firePos.y += 1;

	GameObject* rocket = GameEngine::instance().getNewGameObject("Rocket", firePos);
	Rocket* rocketComp = new Rocket(rocket);
	rocketComp->init();
	rocket->addComponent(rocketComp);
}

void Player::fire2()
{

	vector2 firePos = _gameObject->getPosition();

	firePos.x += 2;
	firePos.y += 1;

	GameObject* rocket;
	Rocket* rocketComp;
	vector2 vel;
	for (float i = 0.0; i < 0.5; i += 0.05)
	{
		vel.y = i;
		vel.x = 1 - i;
		rocket = GameEngine::instance().getNewGameObject("Rocket", firePos);
		rocketComp = new Rocket(rocket);
		rocketComp->init(40, vel, 3.0f);
		rocket->addComponent(rocketComp);
	}
}

