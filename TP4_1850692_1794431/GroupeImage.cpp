//
// Created by Gabriel Bernard
//

#include <iostream>
#include "GroupeImage.h"


using namespace std;

// Constructeur par défaut
GroupeImage::GroupeImage() {};

// FONCTION AJOUTÉE
// Constructeur par copie
GroupeImage::GroupeImage(const GroupeImage& groupe) {
	for (int i = 0; i < groupe.images_.size(); i++)
	{
		images_.push_back(groupe[i]);
	}
}

// Destructeur
GroupeImage::~GroupeImage() {};

// Fonction d'ajout d'images
bool GroupeImage::ajouterImage(Image* image) {
    for (unsigned int i = 0; i <  images_.size(); i++)
    {
        if (image->obtenirNomImage() == *(images_[i]))
        {
            cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
            return false;
        }
    }
    images_.push_back(image);
    std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
    return true;
}

// Fonction de retrait d'images
bool GroupeImage::retirerImage(const std::string& nom) {
    for (unsigned int i = 0; i < images_.size(); i++)
    {
        if (*(images_[i]) == nom)
        {
            images_[i] = images_.back();
            images_.pop_back();
            cout << nom << " a bien ete retire" << endl;
            return true;
        }
    }
    return false;
}

// Fonction d'affichage d'images
void GroupeImage::afficherImages(ostream& os ) const {

    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;

    for  (unsigned int j= 0; j < images_.size(); j++) {
        os << *images_[j] << "--------------------------------------------------" << endl;
    }
    os << endl;
}

// Accesseurs
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
    return images_[indiceImage];
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

// Surcharge d'opérateurs
GroupeImage& GroupeImage::operator+=(Image* image)
{
    ajouterImage(image);
    return *this;
}

GroupeImage& GroupeImage::operator-=(Image* image)
{
    retirerImage(image->obtenirNomImage());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
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

//FONCTION AJOUTÉE
GroupeImage& GroupeImage::operator=(const GroupeImage& groupe) {
	images_.clear();
	for (int i = 0; i < groupe.images_.size(); i++)
	{
		images_.push_back(groupe[i]);
	}
	return *this;
}

Image* GroupeImage::operator[](const unsigned int& indice) const {
    if(indice >= images_.size()) {
        cerr << "L'indice est plus grand que la quantite d'image present dans ce groupe." << endl;
        return nullptr;
    }
    return images_[indice];
}

// Mutateurs
void GroupeImage::toutMettreEnNB(){
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirNB();
    }
    cout << endl;
}
void GroupeImage::toutMettreEnGris() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirGris();
    }
    cout << endl;
}

void GroupeImage::toutMettreEnCouleur() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirCouleurs();
    }
    cout << endl;
}

void GroupeImage::toutEnregistrer() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        Image* image = images_[i];
		// Des changements ont été nécessaires car le chemin (directory) n'était pas trouvable
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
                     + "/im" + to_string(i) + image->obtenirNomImage();
        cout << "Sauvegarde de " << nom << endl;
        images_[i]->sauvegarderImage(nom);
    }
    cout << endl;
}

//FONCTION AJOUTÉE
void GroupeImage::toutMettreEnNegatif() {
	for (int i = 0; i < images_.size(); i++){
		// On met en négatif chaque pixel d'une image
		images_[i]->toutMettreEnNegatif();
	}
}