#pragma once

#include "GameObject.h"
#include "NYTimer.h"

#include <string>

class PhysicsEngine;
class GraphicsEngine;
class InputEngine;

class GameEngine
{

public:

	~GameEngine();

	static GameEngine& instance()
	{
		static GameEngine *instance = new GameEngine();
		return *instance;
	}

	void run();


	std::vector<GameObject*>& getObjects() { return _objects; }

	GameObject* getNewGameObject(std::string name, vector2 position = { 0,0 });


	InputEngine* _inputs;

	NYTimer _timer;

protected:

	GameEngine();
	GameEngine(GameEngine const&) = delete;
	void operator=(GameEngine const&) = delete;

	void takeCareOfDeadBodies();
	void update();
	void updatePhysics();
	void render();
	void addNewObjects();


	std::vector<GameObject*> _objects;
	std::vector<GameObject*> _newObjects;

	GraphicsEngine* _graphics;
	PhysicsEngine* _physics;
};

