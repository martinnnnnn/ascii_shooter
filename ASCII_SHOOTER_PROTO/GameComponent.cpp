#include "GameComponent.h"
#include "GameObject.h"

using namespace std;


GameComponent::GameComponent(GameObject* obj)
{
	_gameObject = obj;
}


GameComponent::~GameComponent()
{
}



void GameComponent::sendMessage(Message message)
{
	_gameObject->sendMessage(message);
}

void GameComponent::receiveMessage(Message message)
{
	boost::apply_visitor(*this, message);
}

Component* GameComponent::addComponent(Component* comp)
{
	_gameObject->addComponent(comp);
	return comp;
}