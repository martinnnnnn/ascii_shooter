#pragma once

#include "MessageHandler.h"

#include <vector>
#include <string>

class GameObject;


class Scene
{
public:


	Scene(std::string name);
	~Scene();


	void init();
	void update();
	void clear();
	void takeCareOfDeadBodies();

	void addObject(GameObject*);
	void removeObject(GameObject*);

	std::vector<GameObject*>& getObjects();

	//void receiveMessage(SCMessage message);
	//void sendMessage(SCMessage message);

	void sendMessage(GOMessage);


	std::string _name;



protected:

	std::vector<GameObject*> _objects;



};

