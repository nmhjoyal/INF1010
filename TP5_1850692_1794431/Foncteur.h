///////////////////////////////////////////////////////////////////////////////////////
/// \file    Foncteur.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-11-19
/// \since   Création : 2017-11-01
///
/// Ce fichier contient la déclaration des différents foncteurs utilisés.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef  FONCTEUR
#define  FONCTEUR

#include "GroupeImage.h"
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3

//Foncteur qui compare l'emplacement (pointeur) de deux Images
class FoncteurEgalImages
{
public:
	FoncteurEgalImages(Image* image) {
		image_ = image;
	}
	~FoncteurEgalImages() {}

	bool FoncteurEgalImages::operator() (Image* imageAComparer) const {
		return(*image_ == *imageAComparer);
	}

private:
	Image* image_;
};

// Foncteur qui compare deux Images par leurs noms
class FoncteurImagesDeMemeNom
{
public:
	FoncteurImagesDeMemeNom(const std::string& nom) {
		nom_ = nom;
	}
	~FoncteurImagesDeMemeNom() {};

	bool operator() ( Image* image) const {
		return(image->obtenirNomImage() == nom_);
	}

private:
	std::string nom_;
};

// Foncteur qui retourne la taille d'une Image
class FoncteurObtenirTailleImage
{
public:
	FoncteurObtenirTailleImage() {}
	~FoncteurObtenirTailleImage() {}

	unsigned int operator() (const Image* image) const {
		return(image->obtenirTaille());
	}
};

//Foncteur qui converti tous les pixels d'une image en gris
class FoncteurMettreEnGris
{
public:
	FoncteurMettreEnGris() {}
	~FoncteurMettreEnGris() {}

	void operator() (Image* image) {
		image->convertirGris();
	}

};

//Foncteur qui converti tous les pixels d'une image en couleur
class FoncteurMettreEnCouleur
{
public:
	FoncteurMettreEnCouleur() {}
	~FoncteurMettreEnCouleur() {}

	void operator() (Image* image) {
		image->convertirCouleur();
	}

};

//Foncteur qui converti tous les pixels d'une image en noir et blanc
class FoncteurMettreEnBN
{
public:
	FoncteurMettreEnBN() {}
	~FoncteurMettreEnBN() {}

	void operator() (Image* image) {
		image->convertirBN();
	}

};

//Foncteur qui converti tous les pixels d'une image en négatif
class FoncteurMettreEnNegatif
{
public:
	FoncteurMettreEnNegatif() {}
	~FoncteurMettreEnNegatif() {}

	void operator() (Image* image) {
		image->mettreEnNegatif();
	}

};

//Foncteur binaire qui génère un nombre aléatoire entre deux nombres envoyés
// en paramètre
class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
	}

	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
		min_ = min;
		max_ = max;
	}

	~FoncteurGenerateurNombresAlea() {}

	unsigned int operator() () const {
		return(rand() % (max_ - min_) + min_);
		
	}

private:
	unsigned int min_;
	unsigned int max_;
};

//FONCTEURS AJOUTÉS
//Addition pour la fonction obtenirIntensiteMoyenne
class FoncteurIntensite{
public:
	FoncteurIntensite() { sum_ = 0; }
	~FoncteurIntensite() {}
	double getSum() { return sum_; }

	void operator() (Image* image) { sum_ += image->obtenirIntensiteMoyenne(); }
private:
	double sum_;

};

//Addition pour la fonction obtenirTailleMoyenne
class FoncteurTaille {
public:
	FoncteurTaille() { sum_ = 0; }
	~FoncteurTaille() {}
	double getSum() { return sum_; }

	void operator() (Image* image) { sum_ += image->obtenirTaille(); }
private:
	double sum_;

};

#endif;