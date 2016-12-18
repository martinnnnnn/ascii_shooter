#pragma once

#include "GameObject.h"
#include "NYTimer.h"

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

	InputEngine* _inputs;

private:
	GameEngine();
	void update();
	void updatePhysics();
	void render();

	NYTimer _timer;

	std::vector<GameObject*> _objects;

	GraphicsEngine* _graphics;
	PhysicsEngine* _physics;
};

