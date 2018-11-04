///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelCouleur.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-22
/// \since   Création : 2017-10-22
///
/// Ce fichier contient la définition des méthodes associées à la classe PixelCouleur.
//////////////////////////////////////////////////////////////////////////////////////
#include "PixelCouleur.h"

// Constructeur par defaut
PixelCouleur::PixelCouleur() { 
	for (int i = 0; i < 3; i++){
		donnee_[i] = 0;
	}
	type_ = Couleur;
}

// Constructeur par parametre
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) {
	donnee_[0] = r;
	donnee_[1] = g;
	donnee_[2] = b;
	type_ = Couleur;
}

PixelCouleur::~PixelCouleur() {
	// mettre à zero
	donnee_[0] = 0;
	donnee_[1] = 0;
	donnee_[2] = 0;
}

// Accesseurs
unchar PixelCouleur::retournerR() const {
    return donnee_[0];
}

unchar PixelCouleur::retournerG() const {
    return donnee_[1];
}

unchar PixelCouleur::retournerB() const {
    return donnee_[2];
}


// Mutateurs
void PixelCouleur::modifierTeinteRouge(unchar d) {

}
void PixelCouleur::modifierTeinteVert(unchar d){

}
void PixelCouleur::modifierTeinteBleue(unchar d){

}

// Fonctions de conversion
bool PixelCouleur::convertirPixelBN() const{
	int moyenne = 0;
	for (int i = 0; i < 3; i++) {
		moyenne += donnee_[i];
	}
	return ((moyenne / 3) > 127);
}

unchar PixelCouleur::convertirPixelGris() const{
	int moyenne = 0;
	for (int i = 0; i < 3; i++) {
		moyenne += donnee_[i];
	}
	return (moyenne / 3);
}

// Surcharge de l'operateur ==
bool PixelCouleur::operator==(const PixelCouleur& pixel) const{
	// On compare chaque membre du tableau de donnee_
	return((type_ == pixel.type_) && (donnee_[0] == pixel.donnee_[0]) && (donnee_[1] == pixel.donnee_[1])
		&& (donnee_[2] == pixel.donnee_[2]));
}