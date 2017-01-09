#pragma once


#include "Component.h"
#include "Structures.h"

/**	\brief Component contenant la hitbox du GameObject qui le contient
*/
class ColliderComponent : public Component
{

public:

	/** \brief Creer un Collider de base de taille (0,0)
	*/
	ColliderComponent() { _hitbox = { 0.0,0.0 }; }

	/** \brief Creer un Collider de taille (x,y)
	* \param x : taille x de la hitbox
	* \param y : taille y de la hitbox
	*/
	ColliderComponent(float x, float y) { _hitbox = { x,y }; }
	
	/** \brief Creer un Collider a partir d'un vector2
	* \param vector2 qui sera copie dans la hitbox du Collider
	*/
	ColliderComponent(vector2 hitbox) { _hitbox = hitbox; }

	virtual ~ColliderComponent() {}


	vector2 _hitbox;

protected:



};

