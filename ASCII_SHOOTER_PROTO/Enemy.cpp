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

	GraphicsComponent* graphics = new GraphicsComponent(_gameObject, path);
	addComponent(graphics);


	MovementComponent* movement = new MovementComponent(_gameObject, -1 * _speed, 0 * _speed );
	addComponent(movement);

	ColliderComponent* collider = new ColliderComponent(_gameObject, 3.0, 1.0);
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
	//	movement->_velocity = { 0 * _speed, 0 * _speed };
	//}
}