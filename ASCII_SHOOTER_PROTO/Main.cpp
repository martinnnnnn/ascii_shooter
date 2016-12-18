//
//
//#include "GameEngine.h"
//
//
//
//int main(void)
//{
//	HWND console = GetConsoleWindow();
//	RECT r;	
//	GetWindowRect(console, &r); //stores the console's current dimensions
//
//	MoveWindow(console, 50, 50, 1300, 600, TRUE); // 800 width, 100 height
//
//	_setmode(_fileno(stdout), _O_U16TEXT);
//
//
//	CHAR_INFO map[SCREEN_HEIGHT][SCREEN_WIDTH];
//
//	HANDLE hOutput;
//	HANDLE rOutput;
//	COORD dwBufferSize;
//	COORD dwBufferCoord;
//	SMALL_RECT rcRegion;
//
//	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
//	rOutput = (HANDLE)GetStdHandle(STD_INPUT_HANDLE);
//	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
//	dwBufferCoord = { 0, 0 };
//	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
//
//	SetConsoleWindowInfo(hOutput, TRUE, &rcRegion);
//	SetConsoleScreenBufferSize(hOutput, dwBufferSize);
//
//	WriteConsoleOutput(hOutput, (CHAR_INFO*)map, dwBufferSize,
//		dwBufferCoord, &rcRegion);
//
//	//GameEngine game;
//	//game.initConsole();
//	//game.run();
//
//
//
//	return 0;
//}
// ASCII_GAME.cpp : Defines the entry point for the console application.
//


#include "GameEngine.h"

#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <windows.h>



int main(void)
{
	
	GameEngine game = GameEngine::instance();
	game.run();

	return 0;
}

