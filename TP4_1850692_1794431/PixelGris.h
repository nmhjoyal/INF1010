//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelGris :
	public Pixel
{
public:

	// Constructeurs
	PixelGris();
	PixelGris(unsigned int);

	// Destructeur
	~PixelGris();

	// Convertisseurs
	virtual bool convertirPixelBN() const;
	virtual unchar* convertirPixelCouleur() const;
	virtual unchar convertirPixelGris() const;

	// Accesseurs
	unsigned int obtenirDonnee() const;
	virtual unchar retournerR() const;
	virtual unchar retournerG() const;
	virtual unchar retournerB() const;

	//FONCTIONS AJOUTÉES
	virtual Pixel* retournerCopieProfonde() const;
	virtual void mettreEnNegatif();
private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H