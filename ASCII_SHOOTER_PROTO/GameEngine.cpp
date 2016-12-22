#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"


#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "Player.h"

#include <iostream>
#include <Windows.h>
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


void GameEngine::init()
{
	initTime();
}

void GameEngine::initTime()
{
	_timer.start();
	_previous = _timer.getElapsedMs();
	_lag = 0.0;
}

void GameEngine::run()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_F9) & 0x8000)
		{
			pause();
		}

		_current = _timer.getElapsedMs();
		_elapsed = _current - _previous;
		_previous = _current;
		_lag += _elapsed;


		addNewObjects();
		takeCareOfDeadBodies();
		update();

		while (_lag >= TIME_PER_FRAME)
		{
			updatePhysics();
			_lag -= TIME_PER_FRAME;
		}
		render();
	}
}

void GameEngine::pause()
{
	bool unpause = false;

	while (!unpause)
	{
		int i = 0;
		if (GetAsyncKeyState(VK_F10) & 0x8000)
		{
			initTime();
			unpause = true;
		}
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

