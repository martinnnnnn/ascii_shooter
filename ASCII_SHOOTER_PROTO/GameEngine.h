#pragma once

#include "GameObject.h"
#include "NYTimer.h"

#include <string>

class PhysicsEngine;
class GraphicsEngine;
class InputEngine;

enum GAME_STATE
{
	START,
	RUN,
	PAUSE,
	END
};

class GameEngine
{

public:

	~GameEngine();

	static GameEngine& instance()
	{
		static GameEngine *instance = new GameEngine();
		return *instance;
	}

	void init();
	void run();
	void pause();

	std::vector<GameObject*>& getObjects() { return _objects; }

	GameObject* getNewGameObject(std::string name, vector2 position = { 0,0 });


	InputEngine* _inputs;

	NYTimer _timer;

protected:

	GameEngine();
	GameEngine(GameEngine const&) = delete;
	void operator=(GameEngine const&) = delete;

	void initTime();
	void takeCareOfDeadBodies();
	void update();
	void updatePhysics();
	void render();
	void addNewObjects();


	std::vector<GameObject*> _objects;
	std::vector<GameObject*> _newObjects;

	GraphicsEngine* _graphics;
	PhysicsEngine* _physics;

	GAME_STATE _state;

	double _previous;
	double _lag;
	double _current;
	double _elapsed;
};

