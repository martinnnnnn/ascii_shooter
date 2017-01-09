#pragma once

#include "Component.h"
#include "Structures.h"

/**	\brief Component une velocite
*/
class MovementComponent : public Component
{

public:

	/** \brief Creer un Movement de base de taille (0,0)
	*/
	MovementComponent() { _velocity = { 0.0,0.0 }; }

	/** \brief Creer un Movement de taille (x,y)
	* \param x : velocite x du Movement
	* \param y : velocite y du Movement
	*/
	MovementComponent(float x, float y) { _velocity = { x,y }; }

	/** \brief Creer un Movement a partir d'un vector2
	* \param vector2 qui sera copie dans la velocite du Movement
	*/
	MovementComponent(vector2 v) : _velocity(v) {}

	virtual ~MovementComponent();

	vector2 _velocity;

private:


};

