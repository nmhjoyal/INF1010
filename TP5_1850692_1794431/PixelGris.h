///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelGris.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-11-19
/// \since   Cr�ation : 2017-11-01
///
/// Ce fichier contient la d�claration des m�thodes et attributs associ�s � la classe 
/// PixelGris.
//////////////////////////////////////////////////////////////////////////////////////

#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelBN;
class PixelCouleur;

class PixelGris :
	public Pixel
{
public:
	//Constructeur
	PixelGris();
	//Constructeurs par param�tre
	PixelGris(unsigned int);
	PixelGris(unchar);
	//Destructeur
	~PixelGris();

	//Convertisseurs
	bool convertirPixelBN();
    unchar convertirPixelGris();

	//Mutateur
	virtual void mettreEnNegatif();

	//Copie profonde
    virtual Pixel* retournerUneCopieProfonde();

	//Accesseurs
    unchar obtenirDonnee() const;
    virtual unchar retournerR() const;
    virtual unchar retournerG() const;
    virtual unchar retournerB() const;

	// TP5
	//Fonctions de test, retournent toujours false car les pixels n'ont 
	// aucune variation de couleurs
	virtual bool estMajoriteRouge() const { return false; };
	virtual bool estMajoriteVert() const { return false; };
	virtual bool estMajoriteBleu() const { return false; };

	//Fonction de calcul de l'intensit� moyenne d'un pixel
	virtual double retournerIntensiteMoyenne() const;


private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H