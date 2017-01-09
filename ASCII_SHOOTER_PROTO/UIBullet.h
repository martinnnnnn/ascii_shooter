#pragma once

#include "GameComponent.h"
#include "Structures.h"

#include <vector>

class GameObject;
class UI;

class UIBullet : public GameComponent
{

public:

	/**
	*	cf. constructeur de GameComponent
	*/
	UIBullet(GameObject*);
	virtual ~UIBullet();


	virtual void init();
	virtual void update();
	void setContext(UICONTEXT context);

	//virtual void operator()(UICONTEXT const& e);

protected:

	UI* _ui;
	UICONTEXT _context;
	int _bulletPosition;

	std::vector<vector2>* _currentPositions;

	std::vector<vector2> _positionsMenu;
	std::vector<vector2> _positionsPause;
	std::vector<vector2> _positionsOption;
	std::vector<vector2> _positionsEnd;
};

