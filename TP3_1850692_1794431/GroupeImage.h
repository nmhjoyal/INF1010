///////////////////////////////////////////////////////////////////////////////////////
/// \file    GroupeImage.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-10-22
/// \since   Cr�ation : 2017-10-22
///
/// Ce fichier contient la d�claration des m�thodes et attributs associ�s � la classe 
/// GroupeImage.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef TP3_GROUPEIMAGE_H
#define TP3_GROUPEIMAGE_H

#include <vector>
#include <string>

#include "Image.h"

class GroupeImage {
public:
    // Constructeur par defaut
    GroupeImage();
    ~GroupeImage();

    // Accesseur
    Image* obtenirImage(unsigned int indiceImage) const;
	unsigned int obtenirNombreImages() const;

    // Mutateurs
    bool ajouterImage(Image* image);
    bool retirerImage(const std::string& nom);

	// Convertisseur
	void toutMettreEnNB();
	void toutMettreEnGris();
	void toutMettreEnCouleur();

	// M�thode d'enregistrement
	void toutEnregistrer();

    // Surcharge d'operateurs
    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);
    
    Image* operator[](const unsigned int& indice) const;

private:
    // Vecteur de pointeurs d'images
    std::vector<Image*> images_;
};


#endif //TP3_GROUPEIMAGE_H
