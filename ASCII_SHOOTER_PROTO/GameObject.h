#pragma once


#include "Structures.h"
#include "Component.h"

#include <vector>
#include <string>

class GameObject
{

public:

	GameObject();
	~GameObject();


	void addComponent(Component*);

	std::vector<Component*>& getComponents();
	template<class T>
	T* getComponent()
	{
		T* returnObj;
		for (Component* c : _components)
		{
			returnObj = dynamic_cast<T*>(c);
			if (returnObj)
			{
				return returnObj;
			}
		}
		return nullptr;
	}


	vector2& getPosition() { return _position; }
	std::string getName() { return _name; }

	void setPosition(vector2 pos) { _position = pos; }
	void setName(std::string name) { _name = name; }


	void sendMessage(std::string msg, int data);


private:

	std::string _name;

	vector2 _position;

	std::vector<Component*> _components;

};
