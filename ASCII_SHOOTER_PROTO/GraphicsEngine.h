#pragma once


#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#include "Parametres.h"

class GraphicsEngine
{

public:

	GraphicsEngine();
	~GraphicsEngine();

	void initConsole();
	void render();


private:

	void clear();
	void swap();
	void draw();


	CHAR_INFO map[SCREEN_HEIGHT][SCREEN_WIDTH];

	HANDLE hOutput;
	HANDLE rOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
};

