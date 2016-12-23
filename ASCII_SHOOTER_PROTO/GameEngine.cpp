#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"
#include "GameObject.h"

#include "GraphicsComponent.h"
#include "MovementComponent.h"
#include "Game.h"
#include "UI.h"
#include <iostream>
#include <vector>
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


GameEngine::~GameEngine()
{
}

GameObject* GameEngine::getNewGameObject(string name, vector2 position)
{
	GameObject* o = new GameObject(name, position);
	_currentNewObjects->push_back(o);
	return o;
}

void GameEngine::addNewObjects()
{
	for (GameObject* obj : *_currentNewObjects)
	{
		_currentObjects->push_back(obj);
	}
	_currentNewObjects->clear();
}

void GameEngine::passObject(GameObject* obj)
{
	_passingGameObjects.push_back(obj);
}


GameObject* GameEngine::findObjectWithTag(string tag)
{
	for (GameObject* obj : *_currentObjects)
	{
		if (obj->getTag() == tag)
		{
			return obj;
		}
	}
	return nullptr;
}



void GameEngine::gameInit()
{
	_currentObjects = &_gameObjects;
	_currentNewObjects = &_newGameObjects;

	_currentObjects->clear();
	_currentNewObjects->clear();

	GameObject* game = GameEngine::instance().getNewGameObject("Game");
	Game* gameScript = new Game(game);
	gameScript->init();
	game->addComponent(gameScript);

	initTime();
}

void GameEngine::uiInit()
{
	_currentObjects = &_uiObjects;
	_currentNewObjects = &_newUiObjects;

	_currentObjects->clear();
	_currentNewObjects->clear();

	GameObject* ui = GameEngine::instance().getNewGameObject("UI");
	UI* uiScript = new UI(ui);
	uiScript->init();
	ui->addComponent(uiScript);

	initTime();
}


void GameEngine::run()
{
	while (!_quit)
	{
		if (_newState) switchState();

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


void GameEngine::initTime()
{
	_timer.start();
	_previous = _timer.getElapsedMs();
	_lag = 0.0;
}



void GameEngine::switchState()
{
	_newState = false;
	_state = (_state == GAME) ? GAMESTATE_UI : GAME;

	switch (_state)
	{
	case GAME:
		_currentObjects = &_gameObjects;
		_currentNewObjects = &_newGameObjects;
		break;
	case GAMESTATE_UI:
		_currentObjects = &_uiObjects;
		_currentNewObjects = &_newUiObjects;
		break;
	}

	for (GameObject* obj : _passingGameObjects)
	{
		_currentNewObjects->push_back(obj);
	}
	_passingGameObjects.clear();

	initTime();

	for (GameObject* obj : *_currentObjects)
	{
		obj->wake();
	}
}



void GameEngine::takeCareOfDeadBodies()
{
	for (unsigned int i = 0; i < _currentObjects->size(); i++)
	{
		if ((*_currentObjects)[i]->isDead())
		{
			delete (*_currentObjects)[i];
			_currentObjects->erase(_currentObjects->begin() + i);
		}
	}
}

void GameEngine::update()
{
	_inputs->update();
	for (GameObject* obj : *_currentObjects)
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

