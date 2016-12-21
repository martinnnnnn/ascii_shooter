#pragma once


#include "Structures.h"
#include "Component.h"

#include <string>
#include <vector>


class GraphicsComponent : public Component
{

public:

	GraphicsComponent() {}
	GraphicsComponent(std::string path);

	virtual ~GraphicsComponent();

	void setSprite(std::string path);


	std::vector<pixel> _sprite;

private:



};

