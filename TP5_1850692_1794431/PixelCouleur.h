///////////////////////////////////////////////////////////////////////////////////////
/// \file    PixelCouleur.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-11-19
/// \since   Création : 2017-11-01
///
/// Ce fichier contient la déclaration des méthodes et attributs associés à la classe 
/// PixelCouleur.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef TP3_PIXEL_COULEUR_H
#define TP3_PIXEL_COULEUR_H

#include "Pixel.h"

enum Couleur { R, G, B };  // R = 0, G = 1, B = 2
const int LONGUEUR_TABLEAU = 3;  // donnee_[3]

class PixelCouleur :
	public Pixel
{
public:
	//Constructeur
	PixelCouleur();
	//Constructeurs par paramètres
	PixelCouleur(const bool& donnee);
	PixelCouleur(const unsigned int& donnee);
    PixelCouleur(const unchar& donnee);
    PixelCouleur(const unchar& R, const unchar& G, const unchar& B);
	//Destructeur
	~PixelCouleur();

	//Mutateurs
	void modifierTeinteRouge(unchar d);
	void modifierTeinteVerte(unchar d);
	void modifierTeinteBleue(unchar d);
	virtual void mettreEnNegatif();

	//Convertisseurs
	bool convertirPixelBN();
	unchar convertirPixelGris();
    
	//Copie profonde
    virtual Pixel* retournerUneCopieProfonde();

	//Accesseurs
    virtual unchar retournerR() const;
    virtual unchar retournerG() const;
    virtual unchar retournerB() const;

	//TP5
	//Fonctions de test, vérifient si la concentration d'une couleur est majoritaire
	virtual bool estMajoriteRouge() const;
	virtual bool estMajoriteVert() const;
	virtual bool estMajoriteBleu() const;

	//Fonction de calcul de l'intensité moyenne d'un pixel
	virtual double retournerIntensiteMoyenne() const;

private:
    void assignerValeurs(const unchar& donnee);
    void assignerValeur(const unsigned int& donnee);
	unsigned int somme() const;

	unchar donnee_[LONGUEUR_TABLEAU];
};

#endif // TP3_PIXEL_COULEUR_H