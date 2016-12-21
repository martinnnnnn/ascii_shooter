#pragma once


#include "Structures.h"
#include "Component.h"

#include <string>
#include <vector>


class GraphicsComponent : public Component
{

public:

	GraphicsComponent(/*GameObject* g*/) {}
	GraphicsComponent(std::string path);

	virtual ~GraphicsComponent();

	void setSprite(std::string path);

	//std::vector<pixel>& getSprite();

	//virtual void operator()(DESTROY const& e) {}
	//virtual void operator()(CHANGE_LIFE const& e) {}

	std::vector<pixel> _sprite;

private:



};

