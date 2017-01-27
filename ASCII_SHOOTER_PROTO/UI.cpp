#include "UI.h"

#include "GameObject.h"
#include "GameEngine.h"
#include "InputEngine.h"
#include "GraphicsComponent.h"
#include "UIBullet.h"

UI::UI(GameObject* obj) : GameComponent(obj)
{
}


UI::~UI()
{
}


void UI::init()
{
	_context.c = "Menu";

	_graphics = new GraphicsComponent(_gameObject);
	addComponent(_graphics);

	_gameObject->_position = { 10, 5 };

	GameObject* obj = GameEngine::instance().getNewGameObject("UIBullet");
	_uiBullet = new UIBullet(obj);
	_uiBullet->init(this);
	obj->addComponent(_uiBullet);

	setGraphics();
}


void UI::update()
{

}


void UI::wake()
{
	setGraphics();
	setBulletPositions();
}


void UI::setContext(UICONTEXT const& context)
{
	_context.c = context.c;
	setGraphics();
	setBulletPositions();
}

void UI::setGraphics()
{

	string sprite = "";
	if (_context.c == "Menu")
	{
		sprite = "Menu.txt";
	}
	else if (_context.c == "Pause")
	{
		sprite = "Pause.txt";
	}
	else if (_context.c == "Option")
	{
		sprite = "Option.txt";
	}
	else if (_context.c == "End")
	{
		sprite = "End.txt";
	}
	_graphics->setSprite(sprite);
}

void UI::setBulletPositions()
{
	_uiBullet->setContext(_context);
}

void UI::operator()(UICONTEXT const& e)
{
	setContext(e);
}
