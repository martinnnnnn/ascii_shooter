#include "Game.h"

#include "GameObject.h"
#include "GameEngine.h"
#include "InputEngine.h"
#include "Player.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "Enemy.h"
#include "Parametres.h"
#include "NYTimer.h"
#include "MessageHandler.h"
#include "Scene.h"

#include <random>
#include <string>

using namespace std;

Game::Game(GameObject* obj) : GameComponent(obj)
{

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
	handleInputs();
	handleEnemies();
}

void Game::handleInputs()
{
	if (GameEngine::instance()._inputs->isKeyDown(KEY_PAUSE))
	{
		GameEngine::instance().sendGOMessage("UI", UICONTEXT{ "Pause" });
		GameEngine::instance().switchScene("UI");
	}
}

void Game::initPlayer()
{
	GameObject* playerObj = GameEngine::instance().getNewGameObject("Player", vector2{ 20, 20 });
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
	_elapsed = _timer->getElapsedMs() - _previous;
	if (_bernouilliDistribution(_generator) && _elapsed > _enemySpawnRate)
	{
		_previous = _timer->getElapsedMs();

		spawnEnemy({ float(SCREEN_WIDTH), float(_uniformDistribution(_generator)) });
	}
}

void Game::spawnEnemy(vector2 position)
{
	GameObject* enemyObj = GameEngine::instance().getNewGameObject("Enemy", position);
	Enemy* enemy = new Enemy(enemyObj);
	enemy->init();
	enemyObj->addComponent(enemy);
}