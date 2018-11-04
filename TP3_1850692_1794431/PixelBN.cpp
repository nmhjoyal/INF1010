///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelBN.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-22
/// \since   Création : 2017-10-22
///
/// Ce fichier contient la définition des méthodes associées à la classe PixelBN.
//////////////////////////////////////////////////////////////////////////////////////
#include "PixelBN.h"

// Constructeur par defaut
PixelBN::PixelBN() {
	donnee_ = false;
	type_ = NoireBlanc;
}

// Constructeur par parametres
PixelBN::PixelBN(bool p) {
	donnee_ = p;
	type_ = NoireBlanc;
}

// Destructeur
PixelBN::~PixelBN(){}

// Fonctions de conversion
unchar* PixelBN::convertirPixelCouleur() const{
	unchar* tableau = new unchar[3];
	if (donnee_) {
		for (int i = 0; i < 3; i++) {
			tableau[i] = VALEUR_MAX_PIXEL;
		}
	}
	else{
		for (int i = 0; i < 3; i++) {
			tableau[i] = VALEUR_MIN_PIXEL;
		}
	}
	return tableau;
}

unchar PixelBN::convertirPixelGris() const{
	if (donnee_) {
		return VALEUR_MAX_PIXEL;
	}
	else {
		return VALEUR_MIN_PIXEL;
	}
}

// Accesseur
bool PixelBN::obtenirDonnee() const {
    return donnee_;
}

// Surcharge de l'operateur ==
bool PixelBN::operator==(const PixelBN& pixel) const{
	return((type_ == pixel.type_) && (donnee_ == pixel.donnee_));
}