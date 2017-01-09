#pragma once

#include "Structures.h"

#include <vector>

/** \brief Classe prenant en charge la gestion de la physique du jeu
*/
class PhysicsEngine
{

public:

	PhysicsEngine();
	~PhysicsEngine();
	
	/** \brief initialise la matrice d'ignore physics
	*/
	void initPhysics();

	/** \brief verifie les collisions entre tous les objets
	*/
	void update();
	
private:

	void initIgnoreMatrix();

	void updatePosition(vector2& pos, vector2 vel);
	bool intersect(vector2 pos1, vector2 hitbox1, vector2 pos2, vector2 hitbox2);

	bool ignore(std::string tag1, std::string tag2);

	std::vector<PhysicsIgnore> _ignoreMatrix;
};

