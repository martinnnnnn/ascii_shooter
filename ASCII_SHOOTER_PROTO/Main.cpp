/**
@mainpage ASCII PROJECT - COURS C++
@authors Whitney Burner
@authors Raphael Bailly
@authors Martin Penard

Jeu ASCII de shoot 'em up.
Pour lancer le jeu, simplement lancer l'executable,
Pour utiliser le moteur du jeu :
	- Creer les scenes necessaires au jeu
	- Ajouter les scenes au singleton GameEngine
	- Ajouter un (ou des) GameObject a une scene :
		- Definir la scene comme scene de debut avec GameEngine::instance().defineStartingScene()
		- Ajouter le ou les nouveaux objects au GameEngine
		- Ajouter le ou les scripts (GameComponent) au GameObject
	- Definir la scene par lequel le jeu doit vraiment commencer
	- Appeler GameEngine::instance().run()
*/

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
	game->addComponent(gameScript);
	GameEngine::instance().addNewObjects();

	GameEngine::instance().defineStartingScene("UI");
	GameObject* ui = GameEngine::instance().getNewGameObject("UI");
	UI* uiScript = new UI(ui);
	ui->addComponent(uiScript);
	uiScript->init();


	
	GameEngine::instance().run();


	



	return 0;
}

