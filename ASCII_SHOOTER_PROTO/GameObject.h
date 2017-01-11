#pragma once



#include "Structures.h"
#include "MessageHandler.h"

#include <vector>
#include <string>

class Component;

/**
* 
* Recuperation a partir du GameEngine, qui ajoute directement l'object a la scene courante
* Conteneur de componsants,  
* Ajout de composants au GameObject, qui representent :
*	- Soit des fonctions de base (physique, graphique)
*   - Soit des scripts permet d'obtenir des comportements pour complexes
*
*/
class GameObject
{
public:

	GameObject(std::string tag, vector2 position = { 0,0 } );
	~GameObject();

	/** \brief Update le GameObject
	*
	*  Methode d'update, appelee a chaque tick par l'engine et qui appelle a son tour les update
	*  de tous les composants contenus dans le GameObect
	*
	*/
	void update();

	//void wake();

	/** \brief Ajoute un Component au GameObject
	*
	*  Le Component passe en parametre est ajoute a la liste de componsants du GameObject
	*
	* \param Pointeur sur Component
	*/
	void addComponent(Component*);

	/** \brief Recupere la liste des Component
	*
	*  \return Une référence vers le vector contenant les Component du GameObjet
	*/
	std::vector<Component*>& getComponents();

	/** \brief Recupere un Component
	* \templateparam Le type de Component que l'on veut recuperer
	*  \return Le premier Component qui a pour type le Type T passe en parametre
	*/
	template<class T>
	T* getComponent()
	{
		T* returnObj;
		for (Component* c : _components)
		{
			returnObj = dynamic_cast<T*>(c);
			if (returnObj)
			{
				return returnObj;
			}
		}
		return nullptr;
	}

	/** \brief Donne le nom du GameObject
	*
	* Le nom du GameObject n'ai pas utilise par l'enjmin, il ne sert qu'a organiser le code si le client le desire
	*
	*  \return Le nom du GameObject
	*/
	std::string getName() { return _name; }

	/** \brief Set le nom du GameObject
	*
	* Le nom du GameObject n'ai pas utilise par l'enjmin, il ne sert qu'a organiser le code si le client le desire
	*
	*	\param Le nom du GameObject
	*/
	void setName(std::string name) { _name = name; }

	/** \brief Envoie d'un message
	*
	* Fait passer le message a tous les Component contenus dans le GameObject
	*
	*	\param Le message a envoyer
	*/
	void sendMessage(const GOMessage) const;

	/** \brief Test sur le tag de l'object
	*
	* Compare le tag de l'objet avec celui passe en parametre
	*
	*	\param le tag a comparer
	*	\return true si les tags sont identiques, faux sinon
	*/
	bool isTagged(std::string tag);

	/** \brief 
	*
	*	\return Le tag du GameObject
	*/
	std::string getTag();
	/** \brief Set le tag du GameObject
	*
	*	\param le nouveau nom du tag
	*/
	void setTag(std::string tag);

	/** \brief Methode de classe qui recherche si le tag existe (si un object a deja utilise le tag)
	*
	*	\param le tag a rechercher
	*/
	static bool findTag(std::string tag);

	/** \brief Marque le GameObject comme mort, il sera supprime par le GameEngine lors de la tick suivante
	*
	*/
	inline void kill() { _dead = true; }
	
	/** \brief Donne l'etat de vie du GameObject
	*
	* Si la valeur de retour est false, le GameObject sera supprime au tick suivant
	*
	*	\return true si le GameObject est vivant, false sinon.
	*/
	inline bool isDead() { return _dead; }

	/** \brief Position de l'objet */
	vector2 _position;
	/** \brief etat d'activation de l'objet */
	bool _enabled;

private:

	std::string _name;
	std::string _tag;
	bool _dead;

	static std::vector<std::string> _Tags;

	

	std::vector<Component*> _components;

	static void addTag(std::string tag);
};
