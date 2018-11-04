//
// Created by Gabriel Bernard
//

#ifndef TP3_GROUPEIMAGE_H
#define TP3_GROUPEIMAGE_H

#include <vector>
#include <string>
#include "Image.h"

class GroupeImage {
public:

	// Constructeur
    GroupeImage();

	// Destructeur
    ~GroupeImage();

	// Accesseurs
    Image* obtenirImage(unsigned int indiceImage) const;
	unsigned int obtenirNombreImages() const;

    // Partie à ajouter et à modifier
    bool ajouterImage(Image* image);
    bool retirerImage(const std::string& nom);

    void afficherImages(std::ostream& os) const; // Partie a modifier

	// Surcharge d'opérateurs
    // Partie à ajouter
    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);
	
    Image* operator[](const unsigned int& indice) const;

	//Mutateurs
    void toutMettreEnNB();
    void toutMettreEnGris();
    void toutMettreEnCouleur();

    void toutEnregistrer();

    // void modifierImagesParIndices(std::vector<unsigned int>& vec, void (Image::*function_handler) ());

	//FONCTIONS AJOUTÉES
	GroupeImage(const GroupeImage& groupe);
	GroupeImage& operator=(const GroupeImage& groupe);
	void toutMettreEnNegatif();

private:
    std::vector<Image*> images_;
};


#endif //TP3_GROUPEIMAGE_H
