///////////////////////////////////////////////////////////////////////////////////////
/// \file    GroupImage.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-22
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la définition des méthodes pour la classe GroupImage. 
//////////////////////////////////////////////////////////////////////////////////////

#include "GroupImage.h"


GroupImage::GroupImage(){
	type_ = "";
	nombreImages_ = 0;
	capaciteImages_ = 0;
	images_ = nullptr;

}
GroupImage::~GroupImage(){
	delete[] images_;
	images_ = nullptr;
}

GroupImage::GroupImage(const string &type, unsigned int capaciteImages):type_(type), capaciteImages_(capaciteImages){
	images_ = new  Image[capaciteImages];
	nombreImages_ = 0;
}

void GroupImage::modifierType(const string &type) {
	type_ = type;
}
string GroupImage::obtenirType() const {
	return type_;
}
Image GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}

void GroupImage::ajouterImage(const Image &image) {
	// On assume que, si le nombre d'image depasse la capacité, on ne peut plus en ajouter 
	if (nombreImages_ < capaciteImages_) {
		images_[nombreImages_] = image;
		nombreImages_++;
	}
}

void GroupImage::afficherImages() const {
	for (unsigned int i = 0; i < nombreImages_; i++) {
		images_[i].afficherImage();
	}
}


void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}