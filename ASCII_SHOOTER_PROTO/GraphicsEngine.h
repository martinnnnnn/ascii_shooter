#pragma once


#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#include "Parametres.h"

/**	\brief Classe permettant l'affichage du jeu
*
*	Initialise la console et le buffer
*	affiche les objets affichables dans la console a chaque tour de gameloop
*/
class GraphicsEngine
{

public:

	GraphicsEngine();
	~GraphicsEngine();

	/** \brief initialise la console */
	void initConsole();

	/**	\brief prend en charge l'affichage du jeu
	* 
	*	execute les actions suivantes :
	*		- clear le buffer
	*		- draw les objets dans le buffer
	*		- ecrit le buffer dans la console
	*/
	void render();


private:

	void clear();
	void draw();
	void swap();


	CHAR_INFO map[SCREEN_HEIGHT][SCREEN_WIDTH];

	HANDLE hOutput;
	HANDLE rOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
};

