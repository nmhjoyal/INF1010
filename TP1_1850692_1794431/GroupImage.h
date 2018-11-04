///////////////////////////////////////////////////////////////////////////////////////
/// \file    GroupImage.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-22
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la déclaration des méthodes et attributs pour la classe 
/// GroupImage. 
//////////////////////////////////////////////////////////////////////////////////////


#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <string>

using namespace std;

class GroupImage
{
public:

	/**
	* Constructeur par défaut
	*/
	GroupImage();

	/**
	* Destructeur
	*/
	~GroupImage();

	/**
	* Constructeur par paramètres
	*
	* \param [in] type
	* \param [in] capaciteImages
	*/
	GroupImage( const string &type, unsigned int capaciteImages);

	/**
	* La fonction modifierType modifie le type_ d'un groupe d'images donné.
	*
	* \param [in] type
	*/
	void modifierType(const string &type);

	/**
	* La fonction obtenirType est la fonction d'accès de l'attribut type_.
	*
	* \return l'attribut type_ du groupe d'images.
	*/
	string obtenirType() const;

	/**
	* La fonction obtenirImage est la fonction d'accès de l'attribut images_.
	*
	* \param [in] indiceImage
	*			  L'indice du tableau d'images du groupe d'images.
	*
	* \return l'attribut images_ du groupe d'images.
	*/
	Image obtenirImage(unsigned int indiceImage) const;

	/**
	* La fonction obtenirNombreImages est la fonction d'accès de l'attribut nombreImages_.
	*
	* \return l'attribut nombreImages_ du groupe d'images.
	*/
	unsigned int obtenirNombreImages() const;

	/**
	* La fonction ajouterImage ajoute une image à la fin de la liste d'images si la
	* capacité n'est pas encore atteinte. Elle incrémente aussi l'attribut nombreImages_.
	*
	* \param [in] image
	*			  L'image à ajouter au groupe d'images.
	*/
	void ajouterImage(const Image &image);

	/**
	* La fonction afficherImages parcours la liste d'images et affiche le code de couleur
	* de chacune.
	*/
	void afficherImages() const;
	
	/**
	* La fonction doublerTailleImageEnLargeur se sert de la fonction doublerTailleEnLargeur
	* de la classe Image afin de doubler la largeur d'une image précise du groupe.
	*
	* \param [in] indiceImage
	*			  L'indice qui correspond à l'image à modifier.
	*/
	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	/**
	* La fonction doublerTailleImageEnHauteur se sert de la fonction doublerTailleEnHauteur
	* de la classe Image afin de doubler la hauteur d'une image précise du groupe.
	*
	* \param [in] indiceImage
	*			  L'indice qui correspond à l'image à modifier.
	*/
	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	

private:

	string type_;
	unsigned int nombreImages_;
	unsigned int capaciteImages_;
	Image* images_;

};

#endif