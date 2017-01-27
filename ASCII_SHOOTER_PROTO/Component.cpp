#include "Component.h"
//#include "GameObject.h"

//using namespace std;


Component::Component(GameObject* obj)
{
	_gameObject = obj;
}


Component::~Component()
{
}

//void Component::sendMessage(Message message)
//{
//	_gameObject->sendMessage(message);
//}
//
//void Component::receiveMessage(Message message)
//{
//	boost::apply_visitor(*this, message);
//}
//
//Component* Component::addComponent(Component* comp)
//{
//	_gameObject->addComponent(comp);
//	return comp;
//}