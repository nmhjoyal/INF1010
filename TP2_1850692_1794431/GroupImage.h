///////////////////////////////////////////////////////////////////////////////////////
/// \file    GroupImage.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-01
/// \since   Création : 2017-09-27
///
/// Ce fichier contient la déclaration des méthodes et attributs pour la classe 
/// GroupImage. 
//////////////////////////////////////////////////////////////////////////////////////

#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"

using namespace std;


class GroupImage
{
public:
	GroupImage(); // A modifier l'implementation
	~GroupImage(); // A modifier l'implementation

	void modifierType(const string &type);
	string obtenirType() const;

	// Modifier cette méthode par Image* obtenirImage(unsigned int indiceImage) const;
	Image* obtenirImage(unsigned int indiceImage) const;

	/**
	* La fonction ajouterImage ajoute une variable de type Image au vecteur
	* d'images appartenant au GroupImage.
	*
	* \param image
	*		 Ce paramètre représente le pointeur d'une image à ajouter au vecteur.
	*/
	void ajouterImage(Image* image);

	/**
	* La fonction retirerImage parcours un vecteur d'images afin de retrouver le nom de l'image
	* (transmis en paramètre) à supprimer.
	*
	* \param nomImage
	*		 Ce paramètre représente le nom de l'image à retirer.
	*/
	void retirerImage(const string& nomImage);
	
	void afficherImages(ostream& os);  
	
	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	
	/**
	* L'opérateur '+=' ajoute une image au groupe d'images courant.
	*
	* \param image
	*		 Ce paramètre représente l'image à ajoutée au groupe d'images.
	*
	* \return Le groupe d'images courant modifié de type GroupImage (*this)
	*/
	GroupImage& operator+= (Image& image);

	/**
	* L'opérateur '-=' retire une image du groupe d'images courant.
	*
	* \param image
	*		 Ce paramètre représente l'image à retirer du groupe d'images.
	*
	* \return Le groupe d'images courant modifié de type GroupImage (*this)
	*/
	GroupImage& operator-= (const Image& image);

	/**
	* L'opérateur '<<' ajoute un groupe d'images (droite de l'opérateur)
	*au ostream transmis (à gauche de l'opérateur) à l'aide de la fonction afficherImages.
	*
	* \param out
	*		 Ce paramètre représente la chaine de caractères présente qui recevra
	*		 les ajouts de caractères.
	*
	* \param groupe
	*		 Ce paramètre représente le groupe d'images à afficher.
	*
	* \return la chaîne de caractères modifiée
	*/
	friend ostream& operator<< (ostream& out, GroupImage& groupe);

private:

	string type_;
	unsigned int capacite_; 
	vector <Image*> images_;

};

#endif