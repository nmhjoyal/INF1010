//
// Created by Gabriel Bernard
//

#include "PixelCouleur.h"

// Constructeur par défaut
PixelCouleur::PixelCouleur() {
	donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = VALEUR_MIN_PIXEL;
}

// Constructeur par paramètre
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b){
    donnee_[Couleur::R] = testPixel(r);
    donnee_[Couleur::G] = testPixel(g);
    donnee_[Couleur::B] = testPixel(b);
}

// Destructeur
PixelCouleur::~PixelCouleur() {}

// Accesseurs
unchar PixelCouleur::retournerR() const {
	return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

// Fonction de sommation
unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

// Convertisseurs
bool PixelCouleur::convertirPixelBN() const {
	unsigned int moyenne = somme() / 3;
	return moyenne > 127;
}

unchar PixelCouleur::convertirPixelGris() const {
	return somme() / 3;
}

// Mutateurs
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = d;
}
void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[Couleur::G] = d;
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = d;
}

// FONCTIONS AJOUTÉES
Pixel* PixelCouleur::retournerCopieProfonde() const {
	return new PixelCouleur(donnee_[R], donnee_[G],donnee_[B]);
}

void PixelCouleur::mettreEnNegatif(){
	donnee_[R] = VALEUR_MAX_PIXEL - donnee_[R];
	donnee_[G] = VALEUR_MAX_PIXEL - donnee_[G];
	donnee_[B] = VALEUR_MAX_PIXEL - donnee_[B];
}