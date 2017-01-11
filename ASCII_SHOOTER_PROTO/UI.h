#pragma once

#include "GameComponent.h"
#include "Structures.h"

class UIBullet;
class GraphicsComponent;

class UI : public GameComponent
{

public:

	/**
	*	cf. constructeur de GameComponent
	*/
	UI(GameObject*);
	virtual ~UI();

	virtual void init();
	virtual void update();

	virtual void wake();
	void setContext(UICONTEXT const& context);


	virtual void operator()(UICONTEXT const& e);


protected:

	UIBullet* _uiBullet;
	void setGraphics();
	void setBulletPositions();

	UICONTEXT _context;
	GraphicsComponent* _graphics;
};

