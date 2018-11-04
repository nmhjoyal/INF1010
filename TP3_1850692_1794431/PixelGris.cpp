///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelGris.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-22
/// \since   Création : 2017-10-22
///
/// Ce fichier contient la définition des méthodes associées à la classe PixelGris.
//////////////////////////////////////////////////////////////////////////////////////
#include "PixelGris.h"

// Constructeur par defaut
PixelGris::PixelGris() {
	donnee_ = 0;
	type_ = NuanceDeGris;
}

// Constructeur par parametre
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = testPixel(donnee);
	type_ = NuanceDeGris;

}

// Destructeur
PixelGris::~PixelGris(){}

// Fonctions de conversion
bool PixelGris::convertirPixelBN() const{
	return(donnee_ > 127);
}

unchar* PixelGris::convertirPixelCouleur() const{
	unchar* tableau = new unchar[3];
	for (int i = 0; i < 3; i++) {
		tableau[i] = donnee_;
	}
	return tableau;
}

// Accesseur
unsigned int PixelGris::obtenirDonnee() const {
    return donnee_;
}

// Surcharge de l'operateur ==
bool PixelGris::operator==(const PixelGris& pixel) const{
	return((type_ == pixel.type_) && (donnee_ == pixel.donnee_));
}