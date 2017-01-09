#pragma once

#include <unordered_map>
#include "Structures.h"

/**	\brief Classe prenant en charge la gestion des inputs utilisateur
*/
class InputEngine
{

public:

	InputEngine();
	~InputEngine();

	/**	\brief enregistre les inputs a chaque tour de gameloop */
	void update();

	/** \brief Permet de savoir si un input a ete utilise
	*	\param la touche que l'on veut verifier
	*	\return vrai si la touche correspondante a ete pressee, faux sinon
	*/
	bool isKeyDown(KEY);


private:

	std::unordered_map <KEY, bool> _keyPressedMap;


};



