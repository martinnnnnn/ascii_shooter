#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"

#include <iostream>
#include "stdio.h"

#define TIME_PER_FRAME 1000 / 30

using namespace std;

GameEngine::GameEngine()
{
	_graphics = new GraphicsEngine();
	_graphics->initConsole();

	_physics = new PhysicsEngine();

	_inputs = new InputEngine();
	
	_objects.push_back(new GameObject());

}


GameEngine::~GameEngine()
{
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

		update();

		while (lag >= TIME_PER_FRAME)
		{
			//cout << "update" << endl;
			updatePhysics();
			lag -= TIME_PER_FRAME;
		}
		render();

	}
}


void GameEngine::update()
{
	_inputs->update();
	for (GameObject* obj : _objects)
	{
		for (Component* comp : obj->getComponents())
		{
			comp->update();
		}
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

