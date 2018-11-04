///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelGris.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Derni�re entr�e : 2017-10-22
/// \since   Cr�ation : 2017-10-22
///
/// Ce fichier contient la d�claration des m�thodes et attributs associ�s � la classe 
/// PixelGris.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelGris :
	public Pixel
{
public:
    // Constructeur par defaut
	PixelGris();
    // Constructeur par parametre
	PixelGris(unsigned int);
    // Destructeur
	~PixelGris();

    // Fonctions de conversion
	bool convertirPixelBN() const;
	unchar* convertirPixelCouleur() const;

    // Accesseur
	unsigned int obtenirDonnee() const;

    // Surcharge de l'operateur ==
	bool operator==(const PixelGris& pixel) const;
    
private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H