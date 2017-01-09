#pragma once

#include "Component.h"
#include "MessageHandler.h"


class GameObject;

/** \brief Classe de base des scripts utilisateurs
*	
*	Offre une interface pour les fonctionalites de base des scripts utilisateurs
*
*/
class GameComponent : public Component, public GOMessageHandler
{

public:

	/** \brief Constructeur de GameComponent qui enregistre le GameObject qui le contient
	*	\param Un pointeur vers un GameObject
	*/
	GameComponent(GameObject*);
	virtual ~GameComponent();

	/** \brief Initialise le GameComponent */
	virtual void init() {}

	/** \brief Reset le GameComponent */
	virtual void wake() {}

	/** \brief Update le GameComponent a chaque tick */
	virtual void update() = 0;

	/** \brief Envoie un message au GameObject */
	void sendMessage(GOMessage);

	/** \brief Recoit et traite un message
	*	\param Un message a traiter
	*/
	virtual void receiveMessage(GOMessage);

protected:

	GameObject* _gameObject;
	Component* addComponent(Component*);
};

