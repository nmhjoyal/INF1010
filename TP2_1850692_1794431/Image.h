///////////////////////////////////////////////////////////////////////////////////////
/// \file    Image.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-01
/// \since   Création : 2017-09-27
///
/// Ce fichier contient la déclaration des méthodes et attributs pour la classe Image.
//////////////////////////////////////////////////////////////////////////////////////

#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include "Pixel.h"

#include<iostream>

using namespace std;

class Image
{
public:
	Image();
	~Image();

	Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur);
	Image(const Image& image);

	// SI c'est nécessaire ajouter un constructeur par copie

	void doublerTailleEnLargeur();
	void doublerTailleEnHauteur();

	unsigned int obtenirNombrePixelHauteur() const;
	unsigned int obtenirNombrePixelLargeur() const;
	string obtenirNomImage() const;

	
	void modifierNomImage(const string & nomImage);

	// Methode à ignorer pour le TP2
	void afficherImage() const;

	bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const ;
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);

    
	/**
	* L'operateur '=' affecte les attributs de l'objet à droite de l'opérateur aux attributs
	* de l'objet à gauche.
	*
	* \param image
	*		 Ce paramètre contient les attributs à affecter à l'objet de gauche.
	*
	* \return l'objet courant de type Image.
	*/
	Image operator= (const Image& image);

	/**
	* L'operateur '<<' ajoute les chaînes de caractères à la chaîne à gauche de l'opérateur.
	*
	* \param out
	*		 Ce paramètre contient la chaîne de caractères à laquelle seront ajoutés d'autres
	*		 caractères.
	*
	* \param image
	*		 Ce paramètre représente l'image que l'on désire afficher.
	*
	* \return une chaîne de caractères de type ostream.
	*/
	friend ostream& operator<<(ostream& out, const Image& image);

	/**
	* L'operateur '==' compare chaque attribut de l'objet de type Image (à gauche de l'opérateur)
	* à celui transmis (à droite de l'opérateur).
	*
	* \param image
	*		 Ce paramètre représente l'image à laquelle on veut comparé à l'image courante.
	*
	* \return VRAI si chaque attribut est égal à celui de l'image transmis, FAUX sinon.
	*/
	bool operator==(const Image& image) const;

	/**
	* L'operateur '==' compare uniquement le nom de l'image courante à un nom transmis à
	* droite de l'opérateur.
	*
	* \param nomImage
	*		 Ce paramètre corresspond à un string d'un nom quelconque.
	*
	* \return VRAI si le nom de l'image corresspond à celui transmis, FAUX sinon.
	*/
	bool operator==(const string& nomImage) const;

	/**
	* L'operateur '==' inverse l'ordre des paramètres afin d'effectuer une comparaison
	* correcte.
	*
	* \param nomImage
	*		 Ce paramètre corresspond à un string d'un nom quelconque.
	*
	* \param image
	*		 Ce paramètre corresspond à l'image courante
	*
	* \return VRAI si le nom de l'image corresspond à celui transmis, FAUX sinon.
	*/
	friend bool operator==(const string& nomImage, const Image& image);

private :
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_; 
	

};

#endif