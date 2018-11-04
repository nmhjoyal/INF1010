///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelCouleur.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-11-19
/// \since   Création : 2017-11-01
///
/// Ce fichier contient la définition des méthodes associées à la classe 
/// PixelCouleur.
//////////////////////////////////////////////////////////////////////////////////////

#include "PixelCouleur.h"

//Constructeur
PixelCouleur::PixelCouleur() {
	assignerValeur(VALEUR_MIN_PIXEL);
}

//Constructeurs par paramètre
PixelCouleur::PixelCouleur(const bool& donnee) {
	if(donnee) {
        assignerValeur(VALEUR_MAX_PIXEL);
	}
	else {
        assignerValeur(VALEUR_MIN_PIXEL);
	}
}

PixelCouleur::PixelCouleur(const unchar& R, const unchar& G, const unchar& B) {
    donnee_[Couleur::R] = testPixel(R);
    donnee_[Couleur::G] = testPixel(G);
    donnee_[Couleur::B] = testPixel(B);
}

PixelCouleur::PixelCouleur(const unchar& donnee) {
	donnee_[Couleur::R] = testPixel(donnee);
	donnee_[Couleur::G] = testPixel(donnee);
	donnee_[Couleur::B] = testPixel(donnee);
}

PixelCouleur::PixelCouleur(const unsigned int& donnee) {
    assignerValeur(donnee);
}

//Destructeur
PixelCouleur::~PixelCouleur() {}

//Fonction de sommation
unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

//Convertisseurs
bool PixelCouleur::convertirPixelBN() {
	unsigned int moyenne = somme() / 3;
	if (moyenne > 127) {
		return true;
	}
	else {
		return false;
	}
}

unchar PixelCouleur::convertirPixelGris() {
	return (somme() / 3);
}

//Copie profonde
Pixel* PixelCouleur::retournerUneCopieProfonde() {
    PixelCouleur *copie = new PixelCouleur(donnee_[Couleur::R], donnee_[Couleur::G], donnee_[Couleur::B]);
    return copie;
}

void PixelCouleur::assignerValeur(const unsigned int& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

void PixelCouleur::assignerValeurs(const unchar& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

//Accesseurs
unchar PixelCouleur::retournerR() const {
    return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

//Mutateurs
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = testPixel((unsigned int) d);
}
void PixelCouleur::modifierTeinteVerte(unchar d) {
	donnee_[Couleur::G] = testPixel((unsigned int) d);
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = testPixel((unsigned int) d);
}

void PixelCouleur::mettreEnNegatif() {
	donnee_[Couleur::R] = 255 - donnee_[Couleur::R];
	donnee_[Couleur::G] = 255 - donnee_[Couleur::G];
	donnee_[Couleur::B] = 255 - donnee_[Couleur::B];
}

//FONCTIONS AJOUTÉES
//Fonctions de test
bool PixelCouleur::estMajoriteRouge() const {
	return (donnee_[Couleur::R] > donnee_[Couleur::G] && donnee_[Couleur::R] > donnee_[Couleur::B]);
}
bool PixelCouleur::estMajoriteVert() const {
	return (donnee_[Couleur::G] > donnee_[Couleur::R] && donnee_[Couleur::G] > donnee_[Couleur::B]);
}
bool PixelCouleur::estMajoriteBleu() const {
	return (donnee_[Couleur::B] > donnee_[Couleur::R] && donnee_[Couleur::B] > donnee_[Couleur::G]);
}

//Fonction qui retourne l'intensité moyenne des couleurs d'un pixel
double PixelCouleur::retournerIntensiteMoyenne() const {
	double moyenne = (donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B]) / 3;
	return(moyenne / 255);
}