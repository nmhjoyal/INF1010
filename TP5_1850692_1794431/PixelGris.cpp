///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelGris.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-11-19
/// \since   Cr�ation : 2017-11-01
///
/// Ce fichier contient la d�finition des m�thodes associ�es � la classe 
/// PixelGris.
//////////////////////////////////////////////////////////////////////////////////////

#include "PixelGris.h"

//Constructeur
PixelGris::PixelGris() {}

//Constructeurs par param�tres
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = testPixel(donnee);
}

PixelGris::PixelGris(unchar donnee): donnee_(donnee) {}

//Destructeur
PixelGris::~PixelGris() {}

//Convertisseurs
bool PixelGris::convertirPixelBN() {
    if (donnee_ > 127) {
        return true;
    } else {
        return false;
    }
}

unchar PixelGris::convertirPixelGris() {
    return donnee_;
}

//Copie profonde
Pixel* PixelGris::retournerUneCopieProfonde() {
    PixelGris* copie = new PixelGris(donnee_);
    return copie;
}

//Accesseurs
unchar PixelGris::retournerR() const {
    return (unchar) donnee_;
}

unchar PixelGris::retournerG() const {
    return (unchar) donnee_;
}

unchar PixelGris::retournerB() const {
    return (unchar) donnee_;
}

unchar PixelGris::obtenirDonnee() const {
	return donnee_;
}

//Mutateurs
void PixelGris::mettreEnNegatif() {
    donnee_ = -donnee_;
}

//FONCTIONS AJOUT�ES
double PixelGris::retournerIntensiteMoyenne() const {
	return ((double) donnee_ / 255);
}
