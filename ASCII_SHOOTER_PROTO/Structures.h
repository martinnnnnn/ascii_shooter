#pragma once

#include <Windows.h>
#include <string>

using namespace std;



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


struct PhysicsIgnore
{
	string tag1;
	string tag2;

	bool ignore(string t1, string t2)
	{
		return ((t1 == tag1 && t2 == tag2) || (t1 == tag2 && t2 == tag1));
	}
};





enum KEY
{
	KEY_START,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	FIRE1,
	FIRE2,
	FIRE3,
	FIRE4,
	KEY_END
};
