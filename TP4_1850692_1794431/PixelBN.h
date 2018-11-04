//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXELBN_H
#define TP3_PIXELBN_H

#include "Pixel.h"
#include "TypePixel.h"

class PixelBN: public Pixel
{
public:
	// Constructeurs
	PixelBN();
	PixelBN(bool p);

	//Destructeur
	~PixelBN();

	// Convertisseurs
	virtual unchar* convertirPixelCouleur() const;
	virtual unchar convertirPixelGris() const;
	virtual bool convertirPixelBN() const;

	//Accesseurs
	bool obtenirDonnee() const;
	virtual unchar retournerR() const;
	virtual unchar retournerG() const;
	virtual unchar retournerB() const;

	//FONCTIONS AJOUTÉES
	virtual Pixel* retournerCopieProfonde() const;
	virtual void mettreEnNegatif();

private:
	bool donnee_;
};

#endif // TP3_PIXELBN_H