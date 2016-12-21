#include "Life.h"

#include "GameObject.h"


Life::Life(GameObject* obj) : GameComponent(obj)
{
}


Life::~Life()
{
}


void Life::update()
{
	if (_life <= 0)
	{
		_gameObject->kill();
	}
}

void Life::init(int life)
{
	_life = life;
}