#pragma once

#include "GameComponent.h"
#include "Structures.h"

#include <vector>

class GameObject;
class UI;

class UIBullet : public GameComponent
{

public:

	UIBullet(GameObject*);
	~UIBullet();

	virtual void init();
	virtual void update();
	inline void setContext(UICONTEXT context) { _context = context; }

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

protected:

	UI* _ui;
	UICONTEXT _context;
	int _bulletPosition;
	std::vector<vector2> _positions[UICONTEXT::UICONTEXT_END - 1];
};

