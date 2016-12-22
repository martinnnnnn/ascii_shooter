#pragma once

#include "GameComponent.h"
#include "Structures.h"

class UIBullet;
class GraphicsComponent;

class UI : public GameComponent
{

public:


	UI(GameObject*);
	~UI();

	virtual void init();
	virtual void update();

	virtual void wake();
	void setContext(UICONTEXT context);


	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}


protected:

	UIBullet* _uiBullet;
	void setGraphics();
	void setBulletPositions();

	UICONTEXT _context;
	GraphicsComponent* _graphics;
};

