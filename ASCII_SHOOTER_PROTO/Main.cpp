

#include "GameEngine.h"

#include <windows.h>
#include "Game.h"

#include <iostream>

using namespace std;


int main(void)
{
	

	GameEngine::instance().gameInit();
	GameEngine::instance().uiInit();

	GameEngine::instance().run();

	return 0;
}

