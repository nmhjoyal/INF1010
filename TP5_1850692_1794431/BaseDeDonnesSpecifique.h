///////////////////////////////////////////////////////////////////////////////////////
/// \file    BaseDeDonnesSpecifique.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-11-19
/// \since   Cr�ation : 2017-11-01
///
/// Ce fichier contient la d�claration des m�thodes et attributs associ�s � la classe 
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

	//Surcharge d'op�rateurs
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase);

};

#endif
