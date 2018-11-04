///////////////////////////////////////////////////////////////////////////////////////
/// \file    BaseDeDonnesSpecifique.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-11-19
/// \since   Création : 2017-11-01
///
/// Ce fichier contient la déclaration des méthodes et attributs associés à la classe 
/// BaseDeDonnesSpecifique.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	//Mutateurs
	bool AssocierImage(GroupeImage* groupe, Image* image);
	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage);

	//Surcharge d'opérateurs
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase);

};

#endif
