#pragma once

#include "GameComponent.h"

#include <string>


class Enemy : public GameComponent
{

public:

	/**
	*	cf. constructeur de GameComponent
	*/
	Enemy(GameObject*);
	virtual ~Enemy();

	/** \brief initialise l'enemy avec les valeurs necessaires
	*	\param vie initiale de l'enemy
	*	\param path vers le sprite de l'enemy
	*	\param vitesse initiale de l'enemy
	*/
	virtual void init(int life = 2, std::string = "Enemy1.txt", float speed = 1.0);

	/**	\update la position de l'enemy */
	virtual void update();


protected:

	void initValues(float speed);
	void initComponents(int lifeValue, std::string path);
	
	void move();

	float _speed;

};

