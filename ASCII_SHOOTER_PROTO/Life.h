#pragma once

#include "GameComponent.h"
#include "MessageHandler.h"

class GameObject;

/**	\brief Script gerant le vie d'un gameobject
*/
class Life : public GameComponent
{

public:

	/**
	*	cf. constructeur de GameComponent
	*/
	Life(GameObject*);

	virtual ~Life();

	/** \brief initialise la vie
	*	\param la valeur initiale de la vie
	*/
	virtual void init(int life = 1);

	/** \brief verifie que la vie est positive, supprime le GameObject sinon
	*/
	virtual void update();

	/** \brief modifie la vie par valeur passee en parametre
	*	\param une valeur positive augmente la vie, une valeur negative la diminue
	*/
	inline void changeLife(int value) { _life += value; }

	/** \brief Donne la valeur de la vie
	*	\return la valeur de la vie
	*/
	inline int getLife() { return _life; }

	/** \brief Prend en charge la reception d'un message CHANGE_LIFE 
	*	\param contient une valeur de modification de la vie
	*/
	virtual void operator()(CHANGE_LIFE const& e) { changeLife(e.value); }


protected:

	int _life;
};

