#pragma once

#include "Component.h"
#include "MessageHandler.h"
#include "Structures.h"


class UIContextComponent : public Component
{
public:


	UIContextComponent();
	~UIContextComponent();

	UICONTEXT _context;

protected:

};

