///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelBN.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-11-19
/// \since   Cr�ation : 2017-11-01
///
/// Ce fichier contient la d�claration des m�thodes et attributs associ�s � la classe 
/// PixelBN.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef TP3_PIXELBN_H
#define TP3_PIXELBN_H

#include "Pixel.h"

class PixelBN: public Pixel
{
public:
	//Contructeur
	PixelBN();
	//Constructeur par param�tre
	PixelBN(bool p);
	//Destructeur
	~PixelBN();
	
	//Concertisseurs
	virtual bool convertirPixelBN();
	virtual unchar convertirPixelGris();

	//Mutateurs
	virtual void mettreEnNegatif();

	//Copie profonde
	virtual Pixel* retournerUneCopieProfonde();

	//Accesseurs
	bool obtenirDonnee();
	virtual unchar retournerR() const;
	virtual unchar retournerG() const;
	virtual unchar retournerB() const;

	//TP5
	//Fonctions de test, retournent toujours false car les pixels n'ont 
	// aucune variation de couleurs
	virtual bool estMajoriteRouge() const { return false; };
	virtual bool estMajoriteVert() const { return false; };
	virtual bool estMajoriteBleu() const { return false; };

	//Fonction de calcul de l'intensit� moyenne d'un pixel
	virtual double retournerIntensiteMoyenne() const;

private:
	bool donnee_;
};

#endif // TP3_PIXELBN_H