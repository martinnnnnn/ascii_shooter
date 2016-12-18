#include "InputEngine.h"

#include <Windows.h>

using namespace std;

InputEngine::InputEngine()
{
	for (int i = UP; i < ZERO; i++)
	{
		KEY key = (KEY)i;
		_keyPressedMap[key] = false;
	}
}


InputEngine::~InputEngine()
{
}


void InputEngine::update()
{
	for (auto it = _keyPressedMap.begin(); it != _keyPressedMap.end(); ++it)
	{
		it->second = false;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		_keyPressedMap[UP] = true;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		_keyPressedMap[DOWN] = true;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		_keyPressedMap[LEFT] = true;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		_keyPressedMap[RIGHT] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
	{
		_keyPressedMap[ZERO] = true;
	}
}


bool InputEngine::isKeyDown(KEY key)
{
	return _keyPressedMap[key];
}
