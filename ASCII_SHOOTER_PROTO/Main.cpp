

#include "GameEngine.h"
#include "Game.h"
#include "Scene.h"
#include "UI.h"
#include "GameObject.h"

#include <windows.h>
#include <iostream>

using namespace std;


int main(void)
{
	

	Scene uiScene("UI");
	Scene gameScene("GAME");

	GameEngine::instance().addScene(&gameScene);
	GameEngine::instance().addScene(&uiScene);

	GameEngine::instance().defineStartingScene("GAME");
	GameObject* game = GameEngine::instance().getNewGameObject("Game");
	Game* gameScript = new Game(game);
	gameScript->init();
	GameEngine::instance().addNewObjects();

	GameEngine::instance().defineStartingScene("UI");
	GameObject* ui = GameEngine::instance().getNewGameObject("UI");
	UI* uiScript = new UI(ui);
	uiScript->init();


	
	GameEngine::instance().run();


	



	return 0;
}

