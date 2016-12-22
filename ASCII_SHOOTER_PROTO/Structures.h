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


enum UICONTEXT
{
	MENU,
	PAUSE,
	OPTION,
	END,
	QUIT,
	UICONTEXT_END
};


enum KEY
{
	KEY_START,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_FIRE1,
	KEY_FIRE2,
	KEY_FIRE3,
	KEY_FIRE4,
	KEY_PAUSE,
	KEY_ENTER,
	KEY_END
};
