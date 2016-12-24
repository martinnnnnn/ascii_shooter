#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"
#include "GameObject.h"
#include "Scene.h"

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

	_switchScene = false;
	_currentScene = nullptr;
	_previousScene = nullptr;
	_nextScene = nullptr;
}


GameEngine::~GameEngine()
{
}

GameObject* GameEngine::getNewGameObject(string name, vector2 position)
{
	GameObject* o = new GameObject(name, position);
	_newObjects.push_back(o);
	return o;
}

void GameEngine::addNewObjects()
{
	for (GameObject* obj : _newObjects)
	{
		_currentScene->addObject(obj);
		//_currentObjects->push_back(obj);
	}
	_newObjects.clear();
}


vector<GameObject*>* GameEngine::getObjects() 
{
	return _currentScene->getObjects(); 
}


void GameEngine::passObject(GameObject* obj)
{
	_passingGameObjects.push_back(obj);
}


GameObject* GameEngine::findObjectWithTag(string tag)
{
	for (GameObject* obj : *(_currentScene->getObjects()))
	{
		if (obj->getTag() == tag)
		{
			return obj;
		}
	}
	return nullptr;
}


void GameEngine::addScene(Scene* scene)
{
	if (_scenes.empty())
	{
		_currentScene = scene;
	}
	_scenes.push_back(scene);
}

void GameEngine::defineStartingScene(std::string name)
{
	for (Scene* scene : _scenes)
	{
		if (scene->_name == name)
		{
			_previousScene = _currentScene;
			_currentScene = scene;
		}
	}
}

void GameEngine::defineStartingScene(Scene* sc)
{
	for (Scene* scene : _scenes)
	{
		if (scene == sc)
		{
			_previousScene = _currentScene;
			_currentScene = scene;
		}
	}
}

Scene* GameEngine::getCurrentScene()
{
	return _currentScene;
}

Scene* GameEngine::getScene(std::string name)
{
	for (Scene* scene : _scenes)
	{
		if (scene->_name == name)
		{
			return scene;
		}
	}
	return nullptr;
}


void GameEngine::switchScene(std::string name)
{
	Scene* newScene = getScene(name);
	if (newScene)
	{
		_switchScene = true;
		_nextScene = newScene;
	}
}


void GameEngine::goToNextScene()
{
	_previousScene = _currentScene;
	if (_nextScene) _currentScene = _nextScene;
	_nextScene = nullptr;

	resetTime();
	_switchScene = false;
}

void GameEngine::goToPreviousScene()
{
	_nextScene = _previousScene;
	goToNextScene();
}

void GameEngine::sendMessage(SCMessage message)
{
	for (Scene* scene : _scenes)
	{
		//scene->receiveMessage(message);
	}
}

//
//void GameEngine::gameInit()
//{
//	_currentObjects = &_gameObjects;
//	_currentNewObjects = &_newGameObjects;
//
//	_currentObjects->clear();
//	_currentNewObjects->clear();
//
//	GameObject* game = GameEngine::instance().getNewGameObject("Game");
//	Game* gameScript = new Game(game);
//	gameScript->init();
//	game->addComponent(gameScript);
//
//	initTime();
//}
//
//void GameEngine::uiInit()
//{
//	_currentObjects = &_uiObjects;
//	_currentNewObjects = &_newUiObjects;
//
//	_currentObjects->clear();
//	_currentNewObjects->clear();
//
//	GameObject* ui = GameEngine::instance().getNewGameObject("UI");
//	UI* uiScript = new UI(ui);
//	uiScript->init();
//	ui->addComponent(uiScript);
//
//	initTime();
//}


void GameEngine::run()
{
	while (!_quit)
	{
		if (_switchScene) goToNextScene();

		_current = _timer.getElapsedMs();
		_elapsed = _current - _previous;
		_previous = _current;
		_lag += _elapsed;


		addNewObjects();
		cleanCurrentScene();

		update();

		while (_lag >= TIME_PER_FRAME)
		{
			updatePhysics();
			_lag -= TIME_PER_FRAME;
		}
		render();
	}
}


void GameEngine::resetTime()
{
	_timer.start();
	_previous = _timer.getElapsedMs();
	_lag = 0.0;
}



//void GameEngine::switchState()
//{
//	_newState = false;
//	_state = (_state == GAME) ? GAMESTATE_UI : GAME;
//
//	switch (_state)
//	{
//	case GAME:
//		_currentObjects = &_gameObjects;
//		_currentNewObjects = &_newGameObjects;
//		break;
//	case GAMESTATE_UI:
//		_currentObjects = &_uiObjects;
//		_currentNewObjects = &_newUiObjects;
//		break;
//	}
//
//	for (GameObject* obj : _passingGameObjects)
//	{
//		_currentNewObjects->push_back(obj);
//	}
//	_passingGameObjects.clear();
//
//	initTime();
//
//	for (GameObject* obj : *_currentObjects)
//	{
//		obj->wake();
//	}
//}



void GameEngine::cleanCurrentScene()
{
	_currentScene->takeCareOfDeadBodies();
}

void GameEngine::update()
{
	_inputs->update();
	for (GameObject* obj : *(_currentScene->getObjects()))
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

