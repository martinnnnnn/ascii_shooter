#pragma once

#include "Component.h"

class PlayerComponent : public Component
{
public:

	PlayerComponent(GameObject* g) : Component(g) {}
	virtual ~PlayerComponent();

	virtual void update();
};

