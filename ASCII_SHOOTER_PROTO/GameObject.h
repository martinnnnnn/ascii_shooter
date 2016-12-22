#pragma once


#include "Structures.h"
#include "Component.h"
#include "MessageHandler.h"

#include <vector>
#include <string>

class GameEngine;

class GameObject
{

public:

	GameObject(std::string tag, vector2 position = { 0,0 } );
	~GameObject();

	void update();
	void wake();

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


	std::string getName() { return _name; }

	void setName(std::string name) { _name = name; }

	void sendMessage(Message);

	bool tagged(std::string tag);
	std::string getTag();
	void setTag(std::string tag);

	static bool findTag(std::string tag);
	static std::vector<std::string> _Tags;

	inline void kill() { _dead = true; }
	inline bool isDead() { return _dead; }

	vector2 _position;
	bool _enabled;

private:

	std::string _name;
	std::string _tag;
	bool _dead;


	

	std::vector<Component*> _components;

	static void addTag(std::string tag);
};
