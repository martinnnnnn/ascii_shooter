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



/** \brief Classe Singleton prenant en charge les Scene et la boucle de jeu
*/
class GameEngine
{

public:

	~GameEngine();

	/** \brief Methode static permettant de recuperer l'instance du Singleton ou de la creer si elle n'existe pas encore
	*	\return Une reference vers l'instance de GameEngine
	*/
	static GameEngine& instance()
	{
		static GameEngine *instance = new GameEngine();
		return *instance;
	}
	
	/** \brief Ajoute une scene au GameEngine
	*/
	void addScene(Scene* scene);

	/** \brief Definie la scene de depart, avant le lancement du jeu
	*	\param Le nom de la scene de depart
	*/
	void defineStartingScene(std::string name);

	/** \brief Ajoute une scene au GameEngine
	*	\param Un pointeur vers la Scene de depart
	*/
	void defineStartingScene(Scene* scene);

	/** \brief Permet d'acceder a la scene courante, celle updatee par le GameEngine
	*	\return Un pointeur vers la Scene courante
	*/
	Scene* getCurrentScene();

	/** \brief Recuperer une scene
	*	\param Le nom de la Scene
	*	\return Un pointeur vers la Scene
	*/
	Scene* getScene(std::string name);

	/** \brief Change la scene courante
	*	\param Le nom de la scene a passer en scene courante
	*/
	void switchScene(std::string newScene);

	/** \brief Change la scene courante
	*	\param Le nom de la scene a passer en scene courante
	*/
	//void sendSCMessage(SCMessage message);

	/** \brief Envoie un GOMessage a une scene, qui le dispatchera a tous ses GameObject
	*	\param Le nom de la scene
	*	\param Le GOMessage
	*/
	void sendGOMessage(const std::string sceneName, const GOMessage msg);

	/** \brief Envoie un GOMessage a une scene, qui le dispatchera a tous ses GameObject
	*	\param Un pointeur vers la Scene
	*	\param Le GOMessage
	*/
	void sendGOMessage(const Scene* scene, const GOMessage msg);

	/** \brief Lance la boucle de jeu
	*/
	void run();

	/** \brief Permet d'acceder aux GameObject courant, c'est a dire ceux possedes par la Scene courante
	*	\return La liste de GameObject courant 
	*/
	std::vector<GameObject*>& getCurrentObjects();
	
	/** \brief Instancie un nouvel GameObject, l'ajoute a la scene courante et en retourne un pointeur
	*	\param Le tag a donner au GameObject
	*	\param La position de depart du GameObject
	*	\return Un pointeur vers le GameObject cree
	*/
	GameObject* getNewGameObject(std::string tag, vector2 position = { 0,0 });
	
	/** \brief Ajoute les GameObjects crees (A modifier :: Cette methode devrait etre privee)
	*/
	void addNewObjects();

	/** \brief Trouver un GameObject possedant le tag passee en parametre
	*	\param Le tag
	*	\return Le premier GameObject trouve correspondant au tag
	*/
	GameObject* findObjectWithTag(std::string tag);

	//std::vector<GameObject*>& findObjectsWithTag(std::string tag);

	/** \brief L'InputEngine
	*/
	InputEngine* _inputs;

	/** \brief Le timer
	*/
	NYTimer _timer;

	/** \brief Quit le jeu, ferme le programme
	*/
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

