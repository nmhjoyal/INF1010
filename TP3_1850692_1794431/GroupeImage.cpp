///////////////////////////////////////////////////////////////////////////////////////
/// \file    GroupeImage.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-22
/// \since   Création : 2017-10-22
///
/// Ce fichier contient la définition des méthodes associées à la classe GroupeImage.
//////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "GroupeImage.h"


using namespace std;

GroupeImage::GroupeImage() {};

GroupeImage::~GroupeImage() {
	// Rien car les pointeurs sont par agrégation
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

// Fonction qui ajoute une image au vecteur si elle n'est pas presente
bool GroupeImage::ajouterImage(Image* image) {
    for (unsigned int i = 0; i <  images_.size(); i++)
    {
		// test si le nom de l'image existe déjà dans le vecteur
        if (image->obtenirNomImage() == *(images_[i]))
        {
            cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
            return false;
        }
    }
	// ajoute l'image si la condition ci-haut n'est pas respectée
    images_.push_back(image);
    std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
    return true;
}

// Fonction qui retire une image au vecteur si elle est presente
bool GroupeImage::retirerImage(const std::string& nom) {
    for (unsigned int i = 0; i < images_.size(); i++)
    {
		// test si l'image existe dans le vecteur
        if (*(images_[i]) == nom)
        {
            images_[i] = images_.back();
			// on se sert de la fonction pop_back afin de retirer un élément du vecteur
            images_.pop_back();
            cout << nom << " a bien ete retire" << endl;
            return true;
        }
    }
    return false;
}

// Fonction qui permet de mettre chaque image du vecteur en noir et blanc
void GroupeImage::toutMettreEnNB() {
	for (int i = 0; i < images_.size(); i++) {
		images_[i]->convertirNB();
	}
	cout << endl;
}

// Fonction qui permet de mettre chaque image en gris
void GroupeImage::toutMettreEnGris() {
	for (int i = 0; i < images_.size(); i++) {
		images_[i]->convertirGris();
	}
	cout << endl;
}

// Fonction qui permet de mettre chaque image en couleur
void GroupeImage::toutMettreEnCouleur() {
	for (int i = 0; i < images_.size(); i++) {
		images_[i]->convertirCouleur();
	}
	cout << endl;
}

// Fonction qui permet de retourner une des images du vecteur
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
    return images_[indiceImage];
}

// Surcharge de l'operateur += qui ajoute une image au vecteur
GroupeImage& GroupeImage::operator+=(Image* image)
{
    ajouterImage(image);
    return *this;
}

// Surcharge de l'operateur -= qui reture une image au vecteur
GroupeImage& GroupeImage::operator-=(Image* image)
{
    retirerImage(image->obtenirNomImage());
    return *this;
}

// Surcharge de l'operateur de flux de sortie
ostream& operator<<(ostream& os, const GroupeImage& groupeImage)
{
    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;
    
    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++) {
        os << *groupeImage.images_[j] << "--------------------------------------------------" << endl;
    }
    
    os << endl;

    return os;
}

Image* GroupeImage::operator[](const unsigned int& indice) const {
	return images_[indice];
}

void GroupeImage::toutEnregistrer() {
	for (int i = 0; i < images_.size(); i++) {
		string emplacment = "./Ensemble d'images/" + images_[i]->obtenirTypeEnString() + "/" + "im" + to_string(i) + images_[i]->obtenirNomImage();
		cout << "Sauvegarde de " << emplacment << endl;
		images_[i]->sauvegarderImage(emplacment);
	}
	cout << endl;
}