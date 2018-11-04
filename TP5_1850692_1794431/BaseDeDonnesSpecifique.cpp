///////////////////////////////////////////////////////////////////////////////////////
/// \file    BaseDeDonnesSpecifique.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-11-19
/// \since   Cr�ation : 2017-11-01
///
/// Ce fichier contient la d�finition des m�thodes associ�es � la classe 
/// BaseDeDonnesSpecifique.
//////////////////////////////////////////////////////////////////////////////////////
#include "BaseDeDonnesSpecifique.h"

//Mutateurs
bool BaseDeDonnesSpecifique::AssocierImage(GroupeImage* groupe, Image* image) {
	//ajout � la liste
	ajouter(image);
	//ajout au groupe
	return groupe->ajouterImage(image);
}
bool BaseDeDonnesSpecifique::EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
	//supression de la liste
	supprimerImage(FoncteurImagesDeMemeNom(nomImage));
	//supression du groupe
	return groupe->retirerImage(nomImage);
}

//Surcharge d'op�rateurs
ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {
	//On suppose que le nombre d'images d�pend uniquement du nombre d'images dans la liste d'images (listImage_)
	os << "Affichage base de donnees specifique" << endl
		<< "------------------------------------" << endl << endl
		<< "Nombre de groupes d'images : " << dataBase.listGroupeImage_.size() << endl
		<< "Nombre d'images :" << dataBase.listImage_.size() << endl << endl
		<< "Nom des images pr�sentes dans la base de donnee : " << endl;

	for (list<Image*>::const_iterator it = dataBase.listImage_.begin(); it != dataBase.listImage_.end(); it++)	{
		os << "- " << (*it)->obtenirNomImage() << endl;
	}
	return os;
}