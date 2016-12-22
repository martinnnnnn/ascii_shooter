#pragma once

//#include "GameObject.h"
#include "NYTimer.h"
#include "Structures.h"

#include <vector>
#include <string>

class GameObject;
class PhysicsEngine;
class GraphicsEngine;
class InputEngine;

enum GAME_STATE
{
	GAME,
	GAMESTATE_UI
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

	void gameInit();
	void uiInit();
	void changeState() { _newState = true; }

	void run();
	/*void pauseRun();
	void startRun();
	void endRun();*/

	inline std::vector<GameObject*>* getObjects() { return _currentObjects; }
	GameObject* getNewGameObject(std::string name, vector2 position = { 0,0 });
	void passObject(GameObject*);

	GameObject* findObjectWithTag(std::string tag);
	//std::vector<GameObject*>& findObjectsWithTag(std::string tag);

	InputEngine* _inputs;

	NYTimer _timer;

	inline void quit() { _quit = true; }
protected:

	GameEngine();
	GameEngine(GameEngine const&) = delete;
	void operator=(GameEngine const&) = delete;

	void initTime();
	//void handleGameState();
	void switchState();

	void takeCareOfDeadBodies();

	void update();
	void updatePhysics();
	void render();
	void addNewObjects();


	std::vector<GameObject*>* _currentObjects;
	std::vector<GameObject*>* _currentNewObjects;

	std::vector<GameObject*> _gameObjects;
	std::vector<GameObject*> _newGameObjects;

	std::vector<GameObject*> _uiObjects;
	std::vector<GameObject*> _newUiObjects;

	std::vector<GameObject*> _passingGameObjects;

	GraphicsEngine* _graphics;
	PhysicsEngine* _physics;

	GAME_STATE _state;
	bool _newState = false;

	double _previous;
	double _lag;
	double _current;
	double _elapsed;

	bool _quit = false;
};

