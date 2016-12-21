#include "Enemy.h"

#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "Life.h"

using namespace std;

Enemy::Enemy(GameObject* obj) : GameComponent(obj)
{
}


Enemy::~Enemy()
{
}


void Enemy::update()
{
	move();
}

void Enemy::init(int life, string path, float speed)
{
	initValues(speed);
	initComponents(life,path);
}


void Enemy::initComponents(int lifeValue, string path)
{

	GraphicsComponent* graphics = new GraphicsComponent(path/*_gameObject*/);
	//graphics->setSprite("Enemy1.txt");
	addComponent(graphics);


	MovementComponent* movement = new MovementComponent( -1 * _speed, 0 * _speed  /*_gameObject*/);
	//movement->_velocity = { -1 * _speed, 0 * _speed };
	addComponent(movement);

	ColliderComponent* collider = new ColliderComponent(3.0, 1.0/*_gameObject*/);
	//collider->setHitBox(3.0, 1.0);
	addComponent(collider);

	Life* life = new Life(_gameObject);
	life->init(lifeValue);
	addComponent(life);
}

void Enemy::initValues(float speed)
{
	_speed = speed;
}

void Enemy::move()
{
	//MovementComponent* movement = _gameObject->getComponent<MovementComponent>();
	//if (movement)
	//{
	//	movement->_velocity = { -1 * _speed, 0 * _speed };
	//}
}