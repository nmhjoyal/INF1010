///////////////////////////////////////////////////////////////////////////////////////
/// \file    Pixel.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-22
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la déclaration des méthodes et attributs pour la classe Pixel. 
//////////////////////////////////////////////////////////////////////////////////////


#include "Const.h"
#include <iostream>

using namespace std;

#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
public:
	/**
	* Constructeur par défaut
	*/
	Pixel();

	/**
	* Constructeur par paramètres
	*
	* \param [in] tauxRouge
	* \param [in] tauxVert
	* \param [in] tauxBleu
	*/
	Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu);

	/**
	* Destructeur 
	*/
	~Pixel();

	/**
	*  La fonction obtenirTauxRouge est la fonction d'accès à l'attribut tauxRouge_.
	*
	*  \return l'attribut tauxRouge_
	*/
	unsigned int obtenirTauxRouge() const;

	/**
	*  La fonction obtenirTauxBleu est la fonction d'accès à l'attribut tauxBleu_.
	*
	*  \return l'attribut tauxBleu_
	*/
	unsigned int obtenirTauxBleu() const;

	/**
	*  La fonction obtenirTauxVert la fonction d'accès à l'attribut tauxVert_.
	*
	*  \return l'attribut tauxVert_
	*/
	unsigned int obtenirTauxVert() const;

	/**
	*  La fonction modifierTeinteRouge augmente ou diminue la concentration
	*  de la couleur rouge d'un pixel, tout en restant entre (0,255). 
	*
	*  \param [in] incrementRouge
	*			   Valeur positive ou négative ajoutée à l'attribut tauxRouge_.
	*/
	void modifierTeinteRouge(int incrementRouge);

	/**
	*  La fonction modifierTeinteVert augmente ou diminue la concentration
	*  de la couleur vert d'un pixel, tout en restant entre (0,255).
	*
	*  \param [in] incrementVert
	*			   Valeur positive ou négative ajoutée à l'attribut tauxVert_.
	*/
	void modifierTeinteVert( int incrementVert);

	/**
	*  La fonction modifierTeinteBleu augmente ou diminue la concentration
	*  de la couleur bleu d'un pixel, tout en restant entre (0,255).
	*
	*  \param [in] incrementBleu
	*			   Valeur positive ou négative ajoutée à l'attribut tauxBleu_.
	*/
	void modifierTeinteBleu(int incrementBleu);
	
	/**
	*  La fonction afficherPixel affiche la lettre correspondant à la concentration
	*  des couleurs d'un pixel; R = rouge, G = vert, B = bleu et Q = mélange.
	*/
	void afficherPixel() const;

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif