#pragma once

//#include "GameObject.h"
#include "NYTimer.h"
#include "Structures.h"
#include "MessageHandler.h"

#include <vector>
#include <string>

class GameObject;
class PhysicsEngine;
class GraphicsEngine;
class InputEngine;
class Scene;



/** GameEngine
Takes care of initiating the other engines, handleling the scenes and running the game
*/
class GameEngine
{

public:

	~GameEngine();

	static GameEngine& instance()
	{
		static GameEngine *instance = new GameEngine();
		return *instance;
	}

	void addScene(Scene* scene);
	void defineStartingScene(std::string name);
	void defineStartingScene(Scene* scene);
	Scene* getCurrentScene();
	Scene* getScene(std::string name);

	void switchScene(std::string newScene);
	void sendSCMessage(SCMessage message);
	void sendGOMessage(const std::string sceneName, const GOMessage msg);
	void sendGOMessage(const Scene* scene, const GOMessage msg);

	void run();

	std::vector<GameObject*>& getCurrentObjects();
	GameObject* getNewGameObject(std::string name, vector2 position = { 0,0 });
	void addNewObjects();

	//void passObject(GameObject*);

	GameObject* findObjectWithTag(std::string tag);
	//std::vector<GameObject*>& findObjectsWithTag(std::string tag);

	InputEngine* _inputs;

	NYTimer _timer;

	inline void quit() { _quit = true; }
protected:

	GameEngine();
	GameEngine(GameEngine const&) = delete;
	void operator=(GameEngine const&) = delete;

	void resetTime();

	void goToNextScene();
	void goToPreviousScene();
	bool _switchScene;

	void cleanCurrentScene();

	void update();
	void updatePhysics();
	void render();

	std::vector<GameObject*> _newObjects;

	vector<Scene*> _scenes;
	Scene* _previousScene;
	Scene* _currentScene;
	Scene* _nextScene;


	//std::vector<GameObject*> _passingGameObjects;

	GraphicsEngine* _graphics;
	PhysicsEngine* _physics;


	double _previous;
	double _lag;
	double _current;
	double _elapsed;

	bool _quit = false;
};

