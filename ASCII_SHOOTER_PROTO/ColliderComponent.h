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
	ColliderComponent(GameObject* obj) : Component(obj) { _hitbox = { 0.0,0.0 }; }

	/** \brief Creer un Collider de taille (x,y)
	* \param x : taille x de la hitbox
	* \param y : taille y de la hitbox
	*/
	ColliderComponent(GameObject* obj, float x, float y) : Component(obj) { _hitbox = { x,y }; }
	
	/** \brief Creer un Collider a partir d'un vector2
	* \param vector2 qui sera copie dans la hitbox du Collider
	*/
	ColliderComponent(GameObject* obj, vector2 hitbox) : Component(obj) { _hitbox = hitbox; }

	virtual ~ColliderComponent() {}

	/**	\brief Setter de la hitbox par copie
	*	\param la hitbox a copier
	*/
	void setHitBox(const vector2 & hb)
	{
		_hitbox = hb;
	}

	/** \brief Setter de la hitbox a partir de 2 float
	*	\param valeurs x et y de la hitbox
	*/
	void setHitBox(const float x, const float y)
	{
		_hitbox.x = x;
		_hitbox.y = y;
	}

	/** \brief Getter de la hitbox
	*	\return une référence la hitbox
	*/
	vector2& getHitBox()
	{
		return _hitbox;
	}


protected:

	vector2 _hitbox;


};

