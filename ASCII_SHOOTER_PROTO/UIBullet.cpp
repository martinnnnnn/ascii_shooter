#include "UIBullet.h"

#include "GameEngine.h"
#include "InputEngine.h"
#include "GraphicsComponent.h"
#include "UI.h"
#include "GameObject.h"

UIBullet::UIBullet(GameObject* obj) : GameComponent(obj)
{
}


UIBullet::~UIBullet()
{
}


void UIBullet::init()
{
	GraphicsComponent* graphics = new GraphicsComponent();
	graphics->setSprite("UIBullet.txt");
	addComponent(graphics);

	_positionsMenu.push_back({ 21,17 });
	_positionsMenu.push_back({ 21,23 });
	_positionsMenu.push_back({ 21,29 });

	_positionsPause.push_back({ 13,15 });
	_positionsPause.push_back({ 13,21 });
	_positionsPause.push_back({ 13,27 });
	_positionsPause.push_back({ 13,33 });

	_positionsOption.push_back({ 15,20 });

	_positionsEnd.push_back({ 15,20 });
	_positionsEnd.push_back({ 15,25 });
	_positionsEnd.push_back({ 15,30 });

	setContext(UICONTEXT{ "Menu" });
	_bulletPosition = 0;

}

void UIBullet::setContext(UICONTEXT context)
{
	_context = context;
	_bulletPosition = 0;

	if (_context.c == "Menu")
	{
		_bulletPosition = 0;
		_currentPositions = &_positionsMenu;
	}
	else if (_context.c == "Pause")
	{
		_currentPositions = &_positionsPause;
	}
	else if (_context.c == "Option")
	{
		_currentPositions = &_positionsOption;
	}
	else if (_context.c == "End")
	{
		_currentPositions = &_positionsEnd;
	}
}



void UIBullet::update()
{
	if (GameEngine::instance()._inputs->isKeyDown(KEY_UP))
	{
		_bulletPosition = (_bulletPosition + 1) % _currentPositions->size();
	}

	if (GameEngine::instance()._inputs->isKeyDown(KEY_DOWN))
	{
		_bulletPosition = (_bulletPosition - 1) % _currentPositions->size();
	}
	_gameObject->_position = (*_currentPositions)[_bulletPosition];

	if (GameEngine::instance()._inputs->isKeyDown(KEY_ENTER))
	{

		if (_context.c == "Menu")
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().switchScene("GAME");
			}
			else if (_bulletPosition == 1)
			{
				setContext(UICONTEXT{ "Option" });
				_ui->setContext(UICONTEXT{ "Option" });
			}
			else if (_bulletPosition == 2)
			{
				GameEngine::instance().quit();
			}
		}

		if (_context.c == "Pause")
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().switchScene("GAME");
			}
			else if (_bulletPosition == 1)
			{
				GameEngine::instance().switchScene("GAME");
			}
			else if (_bulletPosition == 2)
			{
				setContext(UICONTEXT{ "Option" });
				_ui->setContext(UICONTEXT{ "Option" });
			}
			else if (_bulletPosition == 3)
			{
				setContext(UICONTEXT{ "Menu" });
				_ui->setContext(UICONTEXT{ "Menu" });
			}
		}
		if (_context.c == "Option")
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().switchScene("GAME");
			}
		}
		if (_context.c == "End")
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().switchScene("GAME");
			}
			else if (_bulletPosition == 1)
			{
				setContext(UICONTEXT{ "Menu" });
				_ui->setContext(UICONTEXT{ "Menu" });
			}
			else if (_bulletPosition == 2)
			{
				GameEngine::instance().quit();
			}
		}
	}
}

//void UIBullet::operator()(UICONTEXT const& e)
//{
//	setContext(e);
//}
