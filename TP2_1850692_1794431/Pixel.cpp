///////////////////////////////////////////////////////////////////////////////////////
/// \file    Pixel.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-01
/// \since   Création : 2017-09-27
///
/// Ce fichier contient la définition des méthodes pour la classe Pixel. 
//////////////////////////////////////////////////////////////////////////////////////


#include "Pixel.h"
#include <iostream>
#include "Const.h"

using namespace std;

Pixel::Pixel() : tauxRouge_(0),tauxVert_(0),tauxBleu_(0)
{
}


Pixel::~Pixel()
{
}

Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) :
	tauxRouge_(tauxRouge), tauxVert_(tauxVert), tauxBleu_(tauxBleu)
{
}


unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}

unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}

unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}

void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (incrementRouge < 0) {
		if (abs(incrementRouge) >= tauxRouge_) {
		    tauxRouge_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ -= incrementRouge;
		}
	}
	else {
		unsigned int temp = tauxRouge_ + incrementRouge;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxRouge_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ = temp;
		}
	}
}

void Pixel::modifierTeinteVert( int incrementVert) {
	if (incrementVert < 0) {
		if (abs(incrementVert) >= tauxVert_) {
		    tauxVert_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ -= incrementVert;
		}
	}
	else {
		unsigned int temp = tauxVert_ + incrementVert;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxVert_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ = temp;
		}
	}
}

void Pixel::modifierTeinteBleu( int incrementBleu) {
	if (incrementBleu < 0) {
		if (abs(incrementBleu) >= tauxBleu_) {
		    tauxBleu_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ -= incrementBleu;
		}
	}
	else {
		unsigned int temp = tauxBleu_ + incrementBleu;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxBleu_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ = temp;
		}
	}
}

char Pixel::retournerCouleur() const {
	// Teste les concentrations de chaque couleur afin de retourner le bon caractère.
	if (tauxVert_ == 0 && tauxBleu_ == 0 && tauxRouge_ != 0) {
		return'R';

	}
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		return 'G';

	}
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		return 'B';

	}
	else {
		//Retourne le caractère Q pour un mélange de couleurs différentes.
		return 'Q';
	}
}

ostream& operator<<(ostream& o, const Pixel& pixel) {
	//On se sert de la fonction retournerCouleur afin d'ajouter le caractère
	// retourné dans le ostream.
	o << pixel.retournerCouleur();
	return o;
}

bool Pixel::operator==(const Pixel& pixel) const{
	//Teste si la concentration des couleurs dans chaque pixel est égale.
	return (tauxBleu_ == pixel.tauxBleu_ &&
			tauxRouge_ == pixel.tauxRouge_ && 
			tauxVert_ == pixel.tauxVert_);
}

bool Pixel::operator==(const char& couleur) const {
	// Teste pour voir si la couleur du pixel (fonction retournerCouleur) est la 
	// même que le caractère de la couleur envoyée en paramètre.
	return (retournerCouleur() == couleur);
}

bool operator==(const char& couleur, const Pixel& pixel) {
	// On inverse l'ordre des paramètres afin de faire appel à l'opérateur
	// ci-haut qui effectue la comparaison.
	return (pixel == couleur);
}