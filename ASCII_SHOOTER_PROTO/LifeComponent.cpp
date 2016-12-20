#include "LifeComponent.h"

#include "GameObject.h"


LifeComponent::LifeComponent(GameObject* obj) : Component(obj)
{
}


LifeComponent::~LifeComponent()
{
}


void LifeComponent::update()
{
	if (_life <= 0)
	{
		_gameObject->kill();
	}
}