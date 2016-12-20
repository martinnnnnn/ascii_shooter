#include "InputEngine.h"

#include <Windows.h>

using namespace std;

InputEngine::InputEngine()
{
	for (int i = UP; i < FIRE4; i++)
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

	if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
	{
		_keyPressedMap[UP] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD5) & 0x8000)
	{
		_keyPressedMap[DOWN] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
	{
		_keyPressedMap[LEFT] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
	{
		_keyPressedMap[RIGHT] = true;
	}
	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		_keyPressedMap[FIRE1] = true;
	}
	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		_keyPressedMap[FIRE2] = true;
	}
	if (GetAsyncKeyState(VK_F3) & 0x8000)
	{
		_keyPressedMap[FIRE3] = true;
	}
	if (GetAsyncKeyState(VK_F4) & 0x8000)
	{
		_keyPressedMap[FIRE4] = true;
	}
}


bool InputEngine::isKeyDown(KEY key)
{
	return _keyPressedMap[key];
}
