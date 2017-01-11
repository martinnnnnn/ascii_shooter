#include "Scene.h"

#include "GameEngine.h"
#include "GameObject.h"

using namespace std;

Scene::Scene(string name)
{
	_name = name;
}


Scene::~Scene()
{
	clear();
}



void Scene::init()
{

}

void Scene::update()
{
	for (GameObject* obj : _objects)
	{
		obj->update();
	}
}

void Scene::clear()
{
	for (GameObject* obj : _objects)
	{
		delete obj;
	}
	_objects.clear();
}

void Scene::takeCareOfDeadBodies()
{
	for (unsigned int i = 0; i <_objects.size(); i++)
	{
		if (_objects[i]->isDead())
		{
			delete _objects[i];
			_objects.erase(_objects.begin() + i);
		}
	}
}



void Scene::addObject(GameObject* obj)
{
	_objects.push_back(obj);
}

void Scene::removeObject(GameObject* obj)
{
	for (unsigned int i = 0; i < _objects.size(); i++)
	{
		if (_objects[i] == obj)
		{
			delete _objects[i];
			_objects.erase(_objects.begin() + i);
		}
	}
}

vector<GameObject*>& Scene::getObjects()
{
	return _objects;
}

//void Scene::receiveMessage(SCMessage message)
//{
//	boost::apply_visitor(*this, message);
//}
//
//
//void Scene::sendMessage(SCMessage message)
//{
//	GameEngine::instance().sendMessage(message);
//}


void Scene::sendMessage(GOMessage message)
{
	for (GameObject* obj : _objects)
	{
		obj->sendMessage(message);
	}
}
