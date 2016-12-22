#include "UI.h"

#include "GameObject.h"
#include "GameEngine.h"
#include "InputEngine.h"
#include "UIContextComponent.h"
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
	_context = UICONTEXT::MENU;

	_graphics = new GraphicsComponent();
	addComponent(_graphics);

	_uiBullet = new UIBullet(_gameObject);
	_uiBullet->init();
	addComponent(_uiBullet);

	setGraphics();
}


void UI::update()
{

}


void UI::wake()
{
	GameObject* context = GameEngine::instance().findObjectWithTag("UIContext");
	if (context)
	{
		UIContextComponent* contextComp = context->getComponent<UIContextComponent>();
		if (contextComp)
		{
			_context = contextComp->_context;
		}
		context->kill();
	}

	setGraphics();
	setBulletPositions();
}


void UI::setContext(UICONTEXT context)
{
	_context = context;
	setGraphics();
	setBulletPositions();
}

void UI::setGraphics()
{

	switch (_context)
	{
	case UICONTEXT::MENU:
		_graphics->setSprite("Menu.txt");
		break;
	case UICONTEXT::PAUSE:
		_graphics->setSprite("Pause.txt");
		break;
	case UICONTEXT::OPTION:
		_graphics->setSprite("Option.txt");
		break;
	case UICONTEXT::END:
		_graphics->setSprite("End.txt");
		break;
	}
}

void UI::setBulletPositions()
{
	_uiBullet->setContext(_context);
}