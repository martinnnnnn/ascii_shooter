#include "Game.h"

#include "GameObject.h"
#include "GameEngine.h"
#include "Player.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"

Game::Game(GameObject* obj) : Component(obj)
{
	initPlayer();
}


Game::~Game()
{
}


void Game::initPlayer()
{
	GameObject* player = GameEngine::instance().getNewGameObject("Player", vector2{ 20.0, 10.0 });

	player->addComponent(new Player(player));
}