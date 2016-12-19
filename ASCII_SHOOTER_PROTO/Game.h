#pragma once

#include "Component.h"


class Game : public Component
{

public:

	Game(GameObject*);
	~Game();

private:
	void initPlayer();


};

