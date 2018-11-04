///////////////////////////////////////////////////////////////////////////////////////
/// \file    GroupImage.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-10-01
/// \since   Cr�ation : 2017-09-27
///
/// Ce fichier contient la d�finition des m�thodes pour la classe GroupImage. 
//////////////////////////////////////////////////////////////////////////////////////

#include "GroupImage.h"
#include <iostream>

using namespace std;

GroupImage::GroupImage(){
}

GroupImage::~GroupImage() {
	// On se sert de la fonction pr�d�finie associ�e � la classe Vector 'clear()'
	// qui supprime le vecteur en entier
	images_.clear();
}

void GroupImage::modifierType(const string & type) {
	type_ = type;
}

string GroupImage::obtenirType() const{
	return type_;
}

void GroupImage::ajouterImage(Image* image) {
	bool imageExiste = false;
	for (size_t i = 0; i < images_.size(); i++) {
		// imageExiste retourne VRAI si le nom de l'image transmise existe d�j� dans
		// le groupe d'images.
		imageExiste = ((*images_[i] == image->obtenirNomImage()));
		if (imageExiste) {
			// On sort de la boucle si l'image existe d�j� (ne peut pas avoir deux fois
			// la m�me image dans un groupe d'images.
			break;
		}
	}
	if (!imageExiste) {
		// Si l'image n'existe pas d�j�, on l'ajoute au vecteur d'images.
		images_.push_back(image);
		cout << image->obtenirNomImage().c_str() << " a bien �t� ajout� !" << endl;
	}
}

void GroupImage::retirerImage(const string& nomImage) {
	int position = -1; // -1 sert de bool�en
	for (size_t i = 0; i < images_.size(); i++) {
		if (*images_[i] == nomImage) {
			// D�s qu'on trouve l'image cherch�e, on sort de la boucle.
			position = i;
			break;
		}
	}
	if (position != -1) {
		// Si la position est diff�rente de la valeur � son initialisation,
		for (unsigned int i = position; i < (images_.size()-1); i++){
			// on �crase la valeur de gauche par la valeur de droite (� partir de 
			// la position trouv�e pr�c�demment) jusqu'� la derni�re case du vecteur. 
			images_[i] = images_[i + 1];
		}
		// � cause de la boucle pr�c�dente il exsite deux fois la derni�re valeur du vecteur,
		// on supprime donc la derni�re case.
		images_.pop_back();
		cout << nomImage.c_str() << " a bien �t� retire !" << endl;
	}
}

void GroupImage::afficherImages(ostream& os){

	os << "*********************************************" << endl;
	os << "Affichage des images du groupe :  ";
	os << obtenirType().c_str() << endl;
	os << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < images_.size(); i++) {

		os << *(images_[i]);
		os << endl;
		os << "---------------------------------------------" << endl;
	}
	os << endl;
}

Image* GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage]->doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage]->doublerTailleEnHauteur();
}

GroupImage& GroupImage::operator+= (Image& image) {
	ajouterImage(&image);
	return *this;
}

GroupImage& GroupImage::operator-= (const Image& image) {
	retirerImage(image.obtenirNomImage());
	return *this;
}

ostream& operator<< (ostream& out, GroupImage& groupe) {
	groupe.afficherImages(out);
	return out;
}

