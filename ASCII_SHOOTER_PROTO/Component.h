#pragma once

class GameObject;

/** \brief Interface de Component
*/
class Component 
{
public:

	Component(GameObject*);
	virtual ~Component();

	GameObject* getGameObject() { return _gameObject; }

protected:
	GameObject* _gameObject;
};

