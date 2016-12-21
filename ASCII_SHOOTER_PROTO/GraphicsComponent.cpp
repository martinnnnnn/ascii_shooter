#include "GraphicsComponent.h"

#include "FileReader.h"

#include <iostream>

using namespace std;

GraphicsComponent::GraphicsComponent(std::string path) 
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
