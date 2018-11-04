///////////////////////////////////////////////////////////////////////////////////////
/// \file    Image.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-21
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la déclaration des méthodes et attributs pour la classe Image.
/// Consulter Image.cpp pour la définition de chacune des fonction
//////////////////////////////////////////////////////////////////////////////////////


#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"
#include <string>
#include<iostream>

using namespace std;

class Image
{
public:
    // Constructeur par défaut
	Image();
    // Destructeur
	~Image();

    /**
     * Constructeur par paramètres
     *
     * \param [in] nomImage
     * \param [in] nombrePixelHauteur
     * \param [in] nombrePixelLargeur
     */
	Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur);

    /**
     * La fonction doublerTailleEnLargeur double la taille en largeur et alloue de nouveau pixel
     * noir dans la nouvelle moitié.
     */
	void doublerTailleEnLargeur();
    
    /**
     * La fonction doublerTailleEnHauteur double la taille en hauteur et alloue de nouveau pixel
     * noir dans la nouvelle moitié.
     */
	void doublerTailleEnHauteur();
    
    /**
     *  La fonction obtenirNombrePixelHauteur est la fonction d'accès à l'attribut nombrePixelEnHauteur_.
     *
     *  \return Retourne l'attribut nombrePixelEnHauteur_
     */
	unsigned int obtenirNombrePixelHauteur() const;à
    
    /**
     *  La fonction obtenirNombrePixelLargeur est la fonction d'accès à l'attribut nombrePixelEnLargeur_.
     *
     *  \return Retourne l'attribut nombrePixelEnLargeur_
     */
	unsigned int obtenirNombrePixelLargeur() const;
    
    /**
     *  La fonction obtenirNomImage est la fonction d'accès à l'attribut nomImage_.
     *
     *  \return Retourne l'attribut nomImage_
     */
    string obtenirNomImage() const;

    /**
     *  La fonction modifierNomImage permet de modifier l'attribut nomImage_.
     *
     *  \param [in] nomImage
     *         Le nouveau nom attribué à l'image.
     */
	void modifierNomImage(const string & nomImage);

    /**
     *  La fonction afficherImage affiche dans la console le nom et chaque pixel de l'image.
     */
	void afficherImage() const;

    /**
     * La fonction ajouterPixel ajoute un pixel passé en paramètre à la position passée inscrite.
     *
     * \param [in] pixel
     *        Le pixel à ajouter.
     * \param [in] positionLargeur
     * \param [in] positionHauteur
     *
     * \return Retourne un booléen qui indique true si le pixel a été ajouté correctement.
     */
	bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);
    
    /**
     * La fonction obtenirPixel renvoit le pixel demandé à la position passée en paramètre.
     *
     * \param [in] positionLargeur
     * \param [in] positionHauteur
     *
     * \return Retourne le pixel à la position demandé ou un nouveau pixel si la position n'existe pas.
     *         Le programme envoit un message d'erreur dans le deuxième cas.
     */
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const ;
    
    /**
     * La fonction augmenterTeintePixel incrémente la teinte d'un pixel à la position passée en paramètre
     * de la couleur et de la quantité demandées sans dépassé les bornes (0..255)
     *
     * \param [in] positionLargeur
     * \param [in] positionHauteur
     * \param [in] increment
     *        Valeur additionnée à la présente teinte d'un pixel.
     * \param [in] couleur
     *        R,G ou B pour choisir la couleur qui sera incrémentée
     */
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);


private :
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_;

};

#endif
