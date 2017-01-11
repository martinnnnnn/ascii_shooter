#include "GraphicsEngine.h"

#include "GameEngine.h"
#include "GameObject.h"
#include "GraphicsComponent.h"

#include <vector>

using namespace std;

GraphicsEngine::GraphicsEngine()
{
}


GraphicsEngine::~GraphicsEngine()
{
}


void GraphicsEngine::initConsole()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, 0, 0, 1920, 1080, TRUE); // 800 width, 100 height

	_setmode(_fileno(stdout), _O_U16TEXT);
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	rOutput = (HANDLE)GetStdHandle(STD_INPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	SetConsoleWindowInfo(hOutput, TRUE, &rcRegion);
	SetConsoleScreenBufferSize(hOutput, dwBufferSize);

}

void GraphicsEngine::render()
{
	clear();
	draw();
	swap();
}


void GraphicsEngine::draw()
{
	for (GameObject* obj : GameEngine::instance().getCurrentObjects())
	{
		int posX = (int)obj->_position.x;
		int posY = (int)obj->_position.y;

		if (posX < 0 || posX >= SCREEN_WIDTH || posY < 0 || posY >= SCREEN_HEIGHT)
		{
			continue;
		}

		GraphicsComponent* graphics = obj->getComponent<GraphicsComponent>();

		if (graphics)
		{
			for (pixel px : graphics->getSprite())
			{
				map[posY + px.y][posX + px.x] = px.c;
			}
		}
	}
}


void GraphicsEngine::clear()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			map[i][j].Char.AsciiChar = '\0';
			map[i][j].Char.UnicodeChar = '\0';
			map[i][j].Attributes = 0;
		}
	}
}


void GraphicsEngine::swap()
{
	WriteConsoleOutput(hOutput, (CHAR_INFO*)map, dwBufferSize,
		dwBufferCoord, &rcRegion);
}
