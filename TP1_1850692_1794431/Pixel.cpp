///////////////////////////////////////////////////////////////////////////////////////
/// \file    Pixel.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-22
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la définition des méthodes pour la classe Pixel. 
//////////////////////////////////////////////////////////////////////////////////////


#include "Pixel.h"


Pixel::Pixel() {
	tauxBleu_ = 0;
	tauxRouge_ = 0;
	tauxVert_ = 0;
}

Pixel::~Pixel() {}

Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) {
	tauxBleu_ = tauxBleu;
	tauxRouge_ = tauxRouge;
	tauxVert_ = tauxVert;
}

unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}
unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}
unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}

void Pixel::modifierTeinteRouge(int incrementRouge) {
	int tauxTemp = incrementRouge + tauxRouge_;
	if (tauxTemp > MAX_CONCENTRATION_COULEUR) {
		tauxRouge_ = MAX_CONCENTRATION_COULEUR;
	}
	else if (tauxTemp < MIN_CONCENTRATION_COULEUR) {
		tauxRouge_ = MIN_CONCENTRATION_COULEUR;
	}
	else {
		tauxRouge_ = tauxTemp;
	}
}
void Pixel::modifierTeinteVert(int incrementVert) {
	int tauxTemp = incrementVert + tauxVert_;
	if (tauxTemp > MAX_CONCENTRATION_COULEUR) {
		tauxVert_ = MAX_CONCENTRATION_COULEUR;
	}
	else if (tauxTemp < MIN_CONCENTRATION_COULEUR) {
		tauxVert_ = MIN_CONCENTRATION_COULEUR;
	}
	else {
		tauxVert_ = tauxTemp;
	}
}
void Pixel::modifierTeinteBleu(int incrementBleu) {
	int tauxTemp = incrementBleu + tauxBleu_;
	if (tauxTemp > MAX_CONCENTRATION_COULEUR) {
		tauxBleu_ = MAX_CONCENTRATION_COULEUR;
	}
	else if (tauxTemp < MIN_CONCENTRATION_COULEUR) {
		tauxBleu_ = MIN_CONCENTRATION_COULEUR;
	}
	else {
		tauxBleu_ = tauxTemp;
	}
}

void Pixel::afficherPixel() const {

	if (tauxRouge_ != 0 && tauxBleu_ == 0 && tauxVert_ == 0) {
		cout << "R";
	}
	else if (tauxRouge_ == 0 && tauxBleu_ != 0 && tauxVert_ == 0){
		cout << "B";
	}
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		cout << "G";
	}
	else {
		cout << "Q";
	}
}