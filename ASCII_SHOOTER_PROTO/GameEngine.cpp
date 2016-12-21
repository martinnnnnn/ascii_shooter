#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"


#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "Player.h"

#include <iostream>
#include "stdio.h"

#define TIME_PER_FRAME 1000 / 30

using namespace std;

GameEngine::GameEngine()
{
	_graphics = new GraphicsEngine();
	_graphics->initConsole();
	_physics = new PhysicsEngine();
	_physics->initPhysics();
	_inputs = new InputEngine();


}


GameObject* GameEngine::getNewGameObject(string name, vector2 position)
{
	GameObject* o = new GameObject(name,position);
	_newObjects.push_back(o);
	return o;
}


GameEngine::~GameEngine()
{
}

void GameEngine::addNewObjects()
{
	for (GameObject* obj : _newObjects)
	{
		_objects.push_back(obj);
	}
	_newObjects.clear();
}

void GameEngine::run()
{
	_timer.start();

	double previous = _timer.getElapsedMs();
	double lag = 0.0;
	while (true)
	{
		double current = _timer.getElapsedMs();
		double elapsed = current - previous;
		previous = current;

		lag += elapsed;

		addNewObjects();
		takeCareOfDeadBodies();
		update();

		while (lag >= TIME_PER_FRAME)
		{
			updatePhysics();
			lag -= TIME_PER_FRAME;
		}
		render();
	}
}

void GameEngine::takeCareOfDeadBodies()
{
	for (unsigned int i = 0; i < _objects.size(); i++)
	{
		if (_objects[i]->isDead())
		{
			delete _objects[i];
			_objects.erase(_objects.begin() + i);
		}
	}
}

void GameEngine::update()
{
	_inputs->update();
	for (GameObject* obj : _objects)
	{
		obj->update();

	}
}

void GameEngine::updatePhysics()
{
	_physics->update();
}

void GameEngine::render()
{
	_graphics->render();
}

