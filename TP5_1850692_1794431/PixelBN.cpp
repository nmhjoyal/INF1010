///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelBN.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-11-19
/// \since   Cr�ation : 2017-11-01
///
/// Ce fichier contient la d�finition des m�thodes associ�es � la classe 
/// PixelBN.
//////////////////////////////////////////////////////////////////////////////////////

#include "PixelBN.h"

//Constructeur
PixelBN::PixelBN() {
	donnee_ = false;
}

//Constructeur par param�tre
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

//Destructeur
PixelBN::~PixelBN() {}

//Convertisseurs
unchar PixelBN::convertirPixelGris() {
    if(donnee_) {
        return VALEUR_MAX_PIXEL;
    } else {
        return VALEUR_MIN_PIXEL;
    }
}

bool PixelBN::convertirPixelBN() {
	return donnee_;
}

//Copie profonde
Pixel* PixelBN::retournerUneCopieProfonde() {
	PixelBN *copie = new PixelBN(donnee_);
	return copie;
}

//Accesseurs
bool PixelBN::obtenirDonnee() {
	return donnee_;
}

unchar PixelBN::retournerR() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

unchar PixelBN::retournerG() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

unchar PixelBN::retournerB() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

//Mutateurs
void PixelBN::mettreEnNegatif() {
    donnee_ = !donnee_;
}

//FONCTION AJOUT�E
double PixelBN::retournerIntensiteMoyenne() const {
	return(donnee_);
}