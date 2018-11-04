///////////////////////////////////////////////////////////////////////////////////////
/// \file    Pixel.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-01
/// \since   Création : 2017-09-27
///
/// Ce fichier contient la déclaration des méthodes et attributs pour la classe Pixel. 
//////////////////////////////////////////////////////////////////////////////////////

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>


using namespace std;

class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int obtenirTauxRouge() const;
	unsigned int obtenirTauxVert() const;
	unsigned int obtenirTauxBleu() const;
		
	
	/**
	* La fonction retournerCouleur retourne le caractère de la couleur corresspondant
	* aux concentrations du pixel.
	*
	* \return un caractère correspondant à une couleur donnée. R = rouge, G = vert
	* B = bleu et Q = mélange de couleurs.
	*/
	char retournerCouleur() const;
	
	/**
	* L'operateur '<<' ajoute le caractère retourné par la fonction retournerCouleur
	* à une variable de type ostream.
	*
	* \param o
	*		 Ce paramètre représente la chaîne de caractères transmise à gauche de l'opérateur '<<'
	* \param pixel
	*		 Ce paramètre contient les valeurs des concentrations de couleur du pixel, qui seront
	*		 vérifiées dans la fonction retournerCouleur
	*
	* \return la chaîne de caractères avec l'ajout du caractère de la couleur du pixel transmis
	*/
	friend ostream& operator<<(ostream& o, const Pixel& pixel);

	/**
	* L'operateur '==' compare les valeurs contenues dans deux pixels, il est de type 'friend' afin
	* de pouvoir être utilisé à l'extérieur de la classe Pixel.
	*
	* \param pixel
	*		 Ce paramètre contient les valeurs des concentrations de couleur d'un pixel, qui seront
	*		 vérifiées dans la fonction retournerCouleur
	*
	* \return VRAI si les valeurs des concentrations du pixel à gauche de l'opérateur
	*		  sont égales à celles du pixel à droite de l'opérateur, FAUX sinon.
	*/
	friend bool operator==(const char& couleur, const Pixel& pixel);

	/**
	* L'operateur '==' compare le caractère corresspondant à un pixel (à gauche de l'opérateur)
	* avec un caractère quelconque, placé à droite de l'opérateur.
	*
	* \param couleur
	*		 Ce paramètre représente le caractère qui sert à la comparaison
	*
	* \return VRAI si le caractère du pixel à gauche de l'opérateur
	*		  est égal au caractère transmis, FAUX sinon.
	*/
	bool operator==(const Pixel& pixel) const;

	/**
	* L'operateur '==' inverse l'ordre de la transmission des paramètres afin de
	* pouvoir comparer le caractère de couleur d'un pixel à un caractère quelconque correctement
	* (fonction ci-haut).
	*
	* \param couleur
	*		 Ce paramètre représente le caractère qui sert à la comparaison
	*
	* \param pixel
	*		 Ce paramètre corresspond au pixel qui sera comparé au caractère transmis.
	*
	* \return VRAI si le caractère du pixel à gauche de l'opérateur
	*		  est égal au caractère transmis, FAUX sinon.
	*/
	bool operator==(const char& couleur) const;

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif