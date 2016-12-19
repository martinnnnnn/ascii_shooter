#include "Component.h"
#include "GameObject.h"

using namespace std;


Component::Component(GameObject* obj)
{
	_gameObject = obj;
}


Component::~Component()
{
}

void Component::sendMessage(string msg, int data)
{
	_gameObject->sendMessage(msg, data);
}

Component* Component::addComponent(Component* comp)
{
	_gameObject->addComponent(comp);
	return comp;
}