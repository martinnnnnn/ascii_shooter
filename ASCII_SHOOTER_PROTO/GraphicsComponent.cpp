#include "GraphicsComponent.h"

#include "FileReader.h"

#include <iostream>

using namespace std;

GraphicsComponent::GraphicsComponent(GameObject* obj) : Component(obj)
{
	//cout << _sprite->size() << endl;
	FileReader::readSprite("Ship1.txt", _sprite);
	//cout << " 2 : " << _sprite.size() << endl;

/*
	CHAR_INFO c;
	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,0,0 });

	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0;
	_sprite.push_back(pixel{ c,0,1 });

	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,0,2 });

	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,1,0 });

	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,1,1 });

	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,1,2 });


	c.Char.UnicodeChar = 92;
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,2,0 });

	c.Char.UnicodeChar = 'o';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,2,1 });

	c.Char.UnicodeChar = 47;
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,2,2 });


	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,3,0 });

	c.Char.UnicodeChar = ')';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,3,1 });

	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,3,2 });


	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,4,0 });

	c.Char.UnicodeChar = '>';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,4,1 });

	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	_sprite.push_back(pixel{ c,4,2 });*/
}


GraphicsComponent::~GraphicsComponent()
{
}


vector<pixel>& GraphicsComponent::getSprite()
{
	return _sprite;
}