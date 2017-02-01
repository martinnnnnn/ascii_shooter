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

GameObject* GameEngine::getNewGameObject(string tag, vector2 position)
{
	GameObject* o = new GameObject(tag, position);
	_newObjects.push_back(o);
	return o;
}

void GameEngine::addNewObjects()
{
	for (GameObject* obj : _newObjects)
	{
		_currentScene->addObject(obj);
	}
	_newObjects.clear();
}


vector<GameObject*>& GameEngine::getCurrentObjects() 
{
	return _currentScene->getObjects(); 
}


//void GameEngine::passObject(GameObject* obj)
//{
//	_passingGameObjects.push_back(obj);
//}


GameObject* GameEngine::findObjectWithTag(string tag)
{
	for (GameObject* obj : _currentScene->getObjects())
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
	_switchScene = false;

	resetTime();
}

void GameEngine::goToPreviousScene()
{
	_nextScene = _previousScene;
	goToNextScene();
}

//void GameEngine::sendSCMessage(SCMessage message)
//{
//	for (Scene* scene : _scenes)
//	{
//		//scene->receiveMessage(message);
//	}
//}


void GameEngine::sendGOMessage(const string sceneName, const GOMessage msg)
{
	const Scene* scene = getScene(sceneName);
	sendGOMessage(scene,msg);
}

void GameEngine::sendGOMessage(const Scene* scene, const GOMessage msg)
{
	if (scene)
	{
		scene->sendGOMessage(msg);
	}
}


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



void GameEngine::cleanCurrentScene()
{
	_currentScene->takeCareOfDeadBodies();
}

void GameEngine::update()
{
	_inputs->update();
	_currentScene->update();
}

void GameEngine::updatePhysics()
{
	_physics->update();
}

void GameEngine::render()
{
	_graphics->render();
}

