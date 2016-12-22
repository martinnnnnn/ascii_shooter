

#include "GameEngine.h"

#include <windows.h>
#include "Game.h"

#include <iostream>

using namespace std;


int main(void)
{
	
	//GameEngine engine;

	GameObject* game = GameEngine::instance().getNewGameObject("Game");
	Game* gameScript = new Game(game);
	gameScript->init();
	game->addComponent(gameScript);
	GameEngine::instance().init();
	GameEngine::instance().run();

	return 0;
}

