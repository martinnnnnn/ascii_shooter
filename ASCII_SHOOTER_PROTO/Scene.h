#pragma once

#include "MessageHandler.h"

#include <vector>
#include <string>

class GameObject;

/** \brief Classe gerant une scene, c'est a dire une liste de GameObject
*/
class Scene
{
public:


	Scene(std::string name);
	~Scene();

	/** \brief Initialise la scene
	*/
	void init();

	/** \brief Update tous les GameObject possedes par la scene
	*/
	void update();

	/** \brief Supprime les GameObject de la scene
	*/
	void clear();

	/** \brief Supprime tous les GameObject morts lors de l'update precedant
	*/
	void takeCareOfDeadBodies();

	/** \brief Ajout un GameObject a la scene
	*	\param Le GameObject a ajouter
	*/
	void addObject(GameObject*);

	/** \brief Supprime un GameObject a la scene
	*	\param Le GameObject a supprimer
	*/
	void removeObject(GameObject*);

	/** \brief Permet d'acceder aux GameObject de la Scene
	*	\return Les GameObjects possedes par la Scene
	*/
	std::vector<GameObject*>& getObjects();

	//void receiveMessage(SCMessage message);
	//void sendMessage(SCMessage message);

	/** \brief Envoie un GOMessage a tous les GameObject de la Scene
	*	\param Le GOMessage a envoyer
	*/
	void sendGOMessage(const GOMessage) const;

	/** \brief Le nom de la Scene
	*/
	std::string _name;



protected:

	std::vector<GameObject*> _objects;



};

