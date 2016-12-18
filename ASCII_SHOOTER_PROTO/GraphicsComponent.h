#pragma once


#include "Structures.h"
#include "Component.h"


#include <vector>


class GraphicsComponent : public Component
{

public:

	GraphicsComponent(GameObject* g);
	virtual ~GraphicsComponent();


	std::vector<pixel>& getSprite();

private:


	std::vector<pixel> _sprite;

};

