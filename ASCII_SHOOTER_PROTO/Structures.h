#pragma once

#include <Windows.h>





struct vector2
{
	float x;
	float y;
};

struct pixel
{
	CHAR_INFO c;
	int x;
	int y;
};


enum KEY
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	FIRE1,
	FIRE2,
	FIRE3,
	FIRE4
};
