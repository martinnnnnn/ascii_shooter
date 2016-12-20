#pragma once

#include <unordered_map>
#include "Structures.h"

class InputEngine
{

public:

	InputEngine();
	~InputEngine();

	void update();

	bool isKeyDown(KEY);


private:

	std::unordered_map <KEY, bool> _keyPressedMap;


};



