#include "Game.h"

#include "GameObject.h"
#include "GameEngine.h"
#include "Player.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "Enemy.h"
#include "Parametres.h"
#include "NYTimer.h"

#include <random>

using namespace std;

Game::Game(GameObject* obj) : GameComponent(obj)
{
	//initPlayer();
	//initEnemyGenerator();
}


Game::~Game()
{
}


void Game::init()
{
	initPlayer();
	initEnemyGenerator();
}

void Game::update()
{
	_elapsed = _timer->getElapsedMs() - _previous;
	handleEnemies();
}


void Game::initPlayer()
{
	GameObject* playerObj = GameEngine::instance().getNewGameObject("Player", vector2{ 20.0, 10.0 });
	Player* player = new Player(playerObj);
	player->init();
	playerObj->addComponent(player);
}



void Game::initEnemyGenerator()
{
	_timer = &(GameEngine::instance()._timer);
	_previous = _timer->getElapsedMs();
	_enemySpawnRate = 500.0;

	_bernouilliDistribution = std::bernoulli_distribution(0.3);
	_uniformDistribution = std::uniform_int_distribution<int>(0, SCREEN_HEIGHT);
}

void Game::handleEnemies()
{

	if (_bernouilliDistribution(_generator) && _elapsed > _enemySpawnRate)
	{
		_previous = _timer->getElapsedMs();

		spawnEnemy({ static_cast<float>(SCREEN_WIDTH), static_cast<float>(_uniformDistribution(_generator)) });
	}
}

void Game::spawnEnemy(vector2 position)
{
	GameObject* enemyObj = GameEngine::instance().getNewGameObject("Enemy", position);
	Enemy* enemy = new Enemy(enemyObj);
	enemy->init();
	enemyObj->addComponent(enemy);
}