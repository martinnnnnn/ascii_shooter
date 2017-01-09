#pragma once

#include "Structures.h"

#include <vector>
#include <string>
#include <utility>


namespace FileReader
{


	/**	\brief lit un fichier pour remplir une sprite
	*	\param path vers le fichier
	*	\param reference du sprite a remplir
	*/
	void readSprite(std::string path, std::vector<pixel>& sprite);

	/**	\brief lit un fichier pour remplir une matrice de physics ignore
	*	\param path vers le fichier
	*	\param reference de la matrice
	*/
	void readPhysicsIgnore(std::string path, std::vector<PhysicsIgnore>& ignore);

	/**	\brief separe une chaine de character
	*	\param chaine a spliter
	*	\param character delimitant les portions a spliter
	*	\param vector contenant les elements splites
	*/
	void split(const std::string &s, char delim, std::vector<std::string> &elems);

	/** \brief don't use this */
	std::vector<std::string> split(const std::string &s, char delim);

};