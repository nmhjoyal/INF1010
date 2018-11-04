//
// Created by Gabriel Bernard on 17-09-12.
//

#ifndef TP3_GROUPEIMAGE_H
#define TP3_GROUPEIMAGE_H

#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include "Image.h"
#include "Foncteur.h"

class GroupeImage {
public:
    GroupeImage();

    // Constructeur par copie
    GroupeImage(const GroupeImage& groupe);

    ~GroupeImage();

	Image* obtenirImage(const std::string& nom) const;

    // Partie à ajouter et à modifier
    bool ajouterImage(Image* image);
    bool retirerImage(const std::string& nom);

    void afficherImages(std::ostream& os) const; // Partie a modifier

    // Surcharge d'operateurs
    GroupeImage& operator=(const GroupeImage& groupe);
    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);

    unsigned int obtenirNombreImages() const;
	void toutEnregistrer();

	// A SUPPRIMER
	void toutMettreEnNB();
	void toutMettreEnGris();
	void toutMettreEnCouleur();
	void toutMettreEnNegatif();


	// TP5
	Image* obtenirImageParIndex(int index);

	// Méthode qui calcul l'intentsité moyenne de toutes les images du groupe
	double obtenirIntensiteMoyenne();

	// Méthode qui calcul la moyenne de la taille des images du groupe
	double obtenirTailleMoyenne();

	// A implementer dans ce fichier
	template<typename PredicatUnaire>
	void appliquerFoncteurUnaire(PredicatUnaire& foncteur) const;
	template<typename PredicatUnaire>
	void supprimerElements(PredicatUnaire& foncteur);


private:
	std::list<Image*> images_;

};

// A implementer dans ce fichier
template<typename PredicatUnaire>
void GroupeImage::appliquerFoncteurUnaire(PredicatUnaire& foncteur) const {
	for_each(images_.begin(), images_.end(), foncteur);
}
template<typename PredicatUnaire>
void GroupeImage::supprimerElements(PredicatUnaire& foncteur) {
	remove_if(images_.begin(), images_.end(), foncteur);
}


#endif //TP3_GROUPEIMAGE_H
