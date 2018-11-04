//
// Created by Gabriel Bernard
//

#include "PixelBN.h"

// Constructeur par défaut
PixelBN::PixelBN() {
	donnee_ = false;
}

// Constructeur par paramètre
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

// Destructeur
PixelBN::~PixelBN() {}

// Convertisseurs
unchar* PixelBN::convertirPixelCouleur() const {
    unchar valeur = (unchar)VALEUR_MIN_PIXEL;
    if(donnee_) {
        valeur = (unchar)VALEUR_MAX_PIXEL;
    }

	unchar* ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = valeur;

	return ret;
}

unchar PixelBN::convertirPixelGris() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

bool PixelBN::convertirPixelBN() const {
	return donnee_;
}

// Accesseurs
bool PixelBN::obtenirDonnee() const {
	return donnee_;
}

unchar PixelBN::retournerR() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

unchar PixelBN::retournerG() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

unchar PixelBN::retournerB() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

//FONCTIONS AJOUTÉES
Pixel* PixelBN::retournerCopieProfonde() const {
	return new PixelBN(donnee_);
}
void  PixelBN::mettreEnNegatif() {
	donnee_ = !donnee_;
}