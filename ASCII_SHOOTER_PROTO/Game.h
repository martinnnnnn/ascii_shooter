#pragma once

#include "Component.h"
#include "Structures.h"
#include "NYTimer.h"

#include <random>
class Game : public Component
{

public:

	Game(GameObject*);
	~Game();


	virtual void update();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	void initPlayer();

	void initEnemyGenerator();
	void handleEnemies();
	void spawnEnemy(vector2 position);


	double _enemySpawnRate;

	NYTimer* _timer;
	double _previous;
	double _elapsed;

	std::default_random_engine _generator;
	std::bernoulli_distribution _bernouilliDistribution;
	std::uniform_int_distribution<int> _uniformDistribution;

};

