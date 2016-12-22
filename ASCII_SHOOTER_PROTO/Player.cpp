#include "Player.h"

#include "GameObject.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"
#include "Life.h"

#include "InputEngine.h"
#include "GameEngine.h"
#include "Structures.h"

#include "Rocket.h"

#include <iostream>

using namespace std;


Player::Player(GameObject* obj) : GameComponent(obj)
{
	//initValues();
	//initComponent();
}


Player::~Player()
{
}

void Player::init(int life, string path, float speed, float fireRate)
{
	initValues(speed, fireRate);
	initComponent(life, path);
}


void Player::initComponent(int lifeValue, string path)
{
	_timer = &(GameEngine::instance()._timer);

	_previous1 = _timer->getElapsedMs();
	_previous2 = _timer->getElapsedMs();

	GraphicsComponent* graphics = new GraphicsComponent(path);
	addComponent(graphics);

	MovementComponent* movement = new MovementComponent();
	addComponent(movement);

	Life* life = new Life(_gameObject);
	life->init(lifeValue);
	addComponent(life);

	//ColliderComponent* collider = new ColliderComponent(_gameObject);
	//collider->setHitBox(3.0, 3.0);
	//addComponent(collider);

}

void Player::initValues(float speed, float fireRate)
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

	if (GameEngine::instance()._inputs->isKeyDown(KEY_DOWN))
	{
		vel.y = 1;
	}
	else if (GameEngine::instance()._inputs->isKeyDown(KEY_UP))
	{
		vel.y = -1;
	}
	if (GameEngine::instance()._inputs->isKeyDown(KEY_LEFT))
	{
		vel.x = -1;
	}
	else if (GameEngine::instance()._inputs->isKeyDown(KEY_RIGHT))
	{
		vel.x = 1;
	}

	vel.x *= _speed;
	vel.y *= _speed;

	MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	if (movement)
	{
		movement->_velocity = vel;
	}
}

void Player::fire()
{


	if (GameEngine::instance()._inputs->isKeyDown(KEY_FIRE1) && _elapsed1 > _fireRate1)
	{
		_previous1 = _timer->getElapsedMs();
		fire1();
	}
	if (GameEngine::instance()._inputs->isKeyDown(KEY_FIRE2) && _elapsed2 > _fireRate2)
	{
		_previous2 = _timer->getElapsedMs();
		fire2();
	}
}

void Player::fire1()
{
	vector2 firePos = _gameObject->_position;

	firePos.x += 2;
	firePos.y += 1;

	GameObject* rocket = GameEngine::instance().getNewGameObject("PlayerRocket", firePos);
	Rocket* rocketComp = new Rocket(rocket);
	rocketComp->init();
	rocket->addComponent(rocketComp);
}

void Player::fire2()
{

	vector2 firePos = _gameObject->_position;

	firePos.x += 2;
	firePos.y += 1;

	GameObject* rocket;
	Rocket* rocketComp;
	vector2 vel;
	for (double i = 0.0; i < 1.0; i += 0.2)
	{
		vel.x = 1.0;
		vel.y = (float) (0.5 - i);
		rocket = GameEngine::instance().getNewGameObject("PlayerRocket", firePos);
		rocketComp = new Rocket(rocket);
		rocketComp->init(1, vel, 3.0f);
		rocket->addComponent(rocketComp);
	}
}

