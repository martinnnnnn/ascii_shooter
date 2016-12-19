#include "GraphicsComponent.h"

#include "FileReader.h"

#include <iostream>

using namespace std;

GraphicsComponent::GraphicsComponent(GameObject* obj) : Component(obj)
{
	//FileReader::readSprite("Ship1.txt", _sprite);
}


GraphicsComponent::~GraphicsComponent()
{
}


vector<pixel>& GraphicsComponent::getSprite()
{
	return _sprite;
}


void GraphicsComponent::setSprite(std::string path)
{
	FileReader::readSprite(path, _sprite);
}
