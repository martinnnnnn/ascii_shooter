#pragma once


#include "Structures.h"
#include "Component.h"

#include <string>
#include <vector>

/**	\brief Component contenant un sprite a afficher dans la console
*/
class GraphicsComponent : public Component
{

public:

	/** \brief Creer un GraphicsComponent par defaut, vide
	*/
	GraphicsComponent() {}

	/** \brief Creer un GraphicsComponent a partir d'un path vers un fichier texte
	* \param path vers le fichier contenant un sprite sous format .txt
	*/
	GraphicsComponent(std::string path);

	virtual ~GraphicsComponent();

	/** \brief Set le sprite du GraphicsComponent a partir d'un path vers un fichier texte
	* \param path vers le fichier contenant un sprite sous format .txt
	*/
	void setSprite(std::string path);

	/** \brief Get le sprite
	*	\return le sprite
	*/
	std::vector<pixel>& getSprite()
	{
		return _sprite;
	}


private:


	std::vector<pixel> _sprite;

};

