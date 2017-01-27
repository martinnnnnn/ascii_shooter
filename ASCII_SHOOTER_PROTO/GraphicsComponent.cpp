#include "GraphicsComponent.h"

#include "FileReader.h"

#include <iostream>

using namespace std;

GraphicsComponent::GraphicsComponent(GameObject* obj, std::string path)  : Component(obj)
{
	FileReader::readSprite(path, _sprite);
}


GraphicsComponent::~GraphicsComponent()
{
}


void GraphicsComponent::setSprite(std::string path)
{
	FileReader::readSprite(path, _sprite);
}
