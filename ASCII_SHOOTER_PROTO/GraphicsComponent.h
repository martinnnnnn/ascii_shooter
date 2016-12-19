#pragma once


#include "Structures.h"
#include "Component.h"

#include <string>
#include <vector>


class GraphicsComponent : public Component
{

public:

	GraphicsComponent(GameObject* g);
	virtual ~GraphicsComponent();

	void setSprite(std::string path);
	std::vector<pixel>& getSprite();

private:


	std::vector<pixel> _sprite;

};

