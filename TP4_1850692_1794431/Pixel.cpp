//
// Created by Gabriel Bernard
//

#include "Pixel.h"

// Constructeur par défaut
Pixel::Pixel() {}

// Destructeur
Pixel::~Pixel() {}

// Fonctions test
unsigned int Pixel::testPixel(const unsigned int &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

unchar Pixel::testPixel(const unchar &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

// Surcharge d'opérateurs
bool Pixel::operator==(const Pixel& pixel) const {
	return(retournerB() == pixel.retournerB() && retournerG() == pixel.retournerG() && 
		retournerR() == pixel.retournerR());
}
