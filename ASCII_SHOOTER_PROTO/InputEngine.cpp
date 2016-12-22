#include "InputEngine.h"

#include <Windows.h>

using namespace std;

InputEngine::InputEngine()
{
	for (int i = KEY_START; i < KEY_END; i++)
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
		_keyPressedMap[KEY_UP] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD5) & 0x8000)
	{
		_keyPressedMap[KEY_DOWN] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
	{
		_keyPressedMap[KEY_LEFT] = true;
	}
	if (GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
	{
		_keyPressedMap[KEY_RIGHT] = true;
	}
	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		_keyPressedMap[KEY_FIRE1] = true;
	}
	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		_keyPressedMap[KEY_FIRE2] = true;
	}
	if (GetAsyncKeyState(VK_F3) & 0x8000)
	{
		_keyPressedMap[KEY_FIRE3] = true;
	}
	if (GetAsyncKeyState(VK_F4) & 0x8000)
	{
		_keyPressedMap[KEY_FIRE4] = true;
	}
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		_keyPressedMap[KEY_PAUSE] = true;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		_keyPressedMap[KEY_ENTER] = true;
	}
}


bool InputEngine::isKeyDown(KEY key)
{
	return _keyPressedMap[key];
}
