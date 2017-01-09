#pragma once

#include "GameComponent.h"
#include "NYTimer.h"




class Player : public GameComponent
{

public:

	/**
	*	cf. constructeur de GameComponent
	*/
	Player(GameObject* g);
	virtual ~Player();

	/** \brief initialise le joueur avec les valeurs necessaires
	*	\param vie initiale du joueur
	*	\param path vers le sprite du joueur
	*	\param vitesse initiale du joueur
	*	\param fire rate du joueur
	*/
	virtual void init(int life = 5, std::string path = "Ship1.txt", float speed = 20, float fireRate = 100.0);
	
	/** \brief gere le deplacement et le tire du joueur */
	virtual void update();


protected:

	void initValues(float speed, float fireRate);
	void initComponent(int life, std::string path);

	void move();
	void fire();

	void updateTime();

	float _speed;

	NYTimer* _timer;

	void fire1();
	double _fireRate1;
	double _previous1;
	double _elapsed1;

	void fire2();
	double _fireRate2;
	double _previous2;
	double _elapsed2;
};

