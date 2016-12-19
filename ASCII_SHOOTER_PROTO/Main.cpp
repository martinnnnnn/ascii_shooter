

#include "GameEngine.h"

#include <windows.h>
#include "Game.h"

#include <iostream>

using namespace std;


int main(void)
{
	
	//GameEngine engine;

	GameObject* game = GameEngine::instance().getNewGameObject("Game");
	game->addComponent(new Game(game));
	GameEngine::instance().run();

	return 0;
}

