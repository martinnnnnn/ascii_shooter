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

	_positions[0].push_back({ 21,17 });
	_positions[0].push_back({ 21,23 });
	_positions[0].push_back({ 21,29 });

	_positions[1].push_back({ 13,15 });
	_positions[1].push_back({ 13,21 });
	_positions[1].push_back({ 13,27 });
	_positions[1].push_back({ 13,33 });

	_positions[2].push_back({ 15,20 });

	_positions[3].push_back({ 15,20 });
	_positions[3].push_back({ 15,25 });
	_positions[3].push_back({ 15,30 });

	_context = UICONTEXT::MENU;
	_bulletPosition = 0;
	_gameObject->_position = _positions[_context][_bulletPosition];
	
	GraphicsComponent* graphics = new GraphicsComponent();
	graphics->setSprite("UIBullet.txt");
	addComponent(graphics);
}

void UIBullet::update()
{
	if (GameEngine::instance()._inputs->isKeyDown(KEY_UP))
	{
		_bulletPosition = (_bulletPosition + 1) % _positions[_context].size();
	}

	if (GameEngine::instance()._inputs->isKeyDown(KEY_DOWN))
	{
		_bulletPosition = (_bulletPosition - 1) % _positions[_context].size();
	}
	_gameObject->_position = _positions[_context][_bulletPosition];

	if (GameEngine::instance()._inputs->isKeyDown(KEY_ENTER))
	{
		if (_context == UICONTEXT::MENU)
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().changeState();
			}
			else if (_bulletPosition == 1)
			{
				_ui->setContext(OPTION);
			}
			else if (_bulletPosition == 2)
			{
				GameEngine::instance().quit();
			}
		}
		if (_context == UICONTEXT::PAUSE)
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().changeState();
			}
			else if (_bulletPosition == 1)
			{
				GameEngine::instance().changeState();
			}
			else if (_bulletPosition == 2)
			{
				_ui->setContext(OPTION);
			}
			else if (_bulletPosition == 3)
			{
				_ui->setContext(MENU);
			}
		}
		if (_context == UICONTEXT::OPTION)
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().changeState();
			}
		}
		if (_context == UICONTEXT::END)
		{
			if (_bulletPosition == 0)
			{
				GameEngine::instance().changeState();
			}
			else if (_bulletPosition == 1)
			{
				_ui->setContext(MENU);
			}
			else if (_bulletPosition == 2)
			{
				GameEngine::instance().quit();
			}
		}
	}
}
