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
	MovementComponent(GameObject* obj) : Component(obj) { _velocity = { 0.0,0.0 }; }

	/** \brief Creer un Movement de taille (x,y)
	* \param x : velocite x du Movement
	* \param y : velocite y du Movement
	*/
	MovementComponent(GameObject* obj, float x, float y) : Component(obj) { _velocity = { x,y }; }

	/** \brief Creer un Movement a partir d'un vector2
	* \param vector2 qui sera copie dans la velocite du Movement
	*/
	MovementComponent(GameObject* obj, vector2 v) : Component(obj), _velocity(v) {}

	virtual ~MovementComponent();

	/**	\brief Getter de la velocite
	*	\return une reference vers la velocite
	*/
	vector2& getVelocity()
	{
		return _velocity;
	}

	/**	\brief Setter de la velocite par copie
	*	\param la velocite a copier
	*/
	void setVelocity(const vector2& v)
	{
		_velocity.x = v.x;
		_velocity.y = v.y;
	}

	/**	\brief Setter de la velocite a partir de 2 float
	*	\param valeurs x et y a assigner a la velocite
	*/
	void setVelocity(const float x, const float y)
	{
		_velocity.x = x;
		_velocity.y = y;
	}


private:

	vector2 _velocity;

};

