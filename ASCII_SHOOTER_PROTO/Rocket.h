#pragma once

#include "GameComponent.h"
#include "Structures.h"

class Rocket : public GameComponent
{

public:

	/**
	*	cf. constructeur de GameComponent
	*/
	Rocket(GameObject*);
	virtual ~Rocket();

	/** \brief initialise le joueur avec les valeurs necessaires
	*	\param vie initiale du missile
	*	\param vitesse initiale du joueur
	*	\param fire rate du joueur
	*/
	void init(int life = 1, vector2 velocity = { 1, 0 }, float speed = 6.0);

	/**	\update la position du missile */
	virtual void update();

protected:

	void initValues(float speed);
	void initComponent(int life, vector2 velocity);

	void move();

	
	float _speed;
};


