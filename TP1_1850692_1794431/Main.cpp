///////////////////////////////////////////////////////////////////////////////////////
/// \file    Travail pratique #1 - Main.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-22
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la fonction main.
//////////////////////////////////////////////////////////////////////////////////////

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

const int TAILLE = 9;
const int TAILLE_IMAGE = 3;

int main()
{
	//1- Creez 9 pixels rouge  (255,0,0)	
	Pixel pixelsRouges[TAILLE];
	for (int i = 0; i < TAILLE; i++) {
		pixelsRouges[i] = Pixel(255, 0, 0);
	}

	//2-Creez 9 pixels verts (0,255,0)
	Pixel pixelsVerts[TAILLE];
	for (int i = 0; i < TAILLE; i++) {
		pixelsVerts[i] = Pixel(0, 255, 0);
	}
	
	//3- Creez une image de taille 3*3 
	Image image0 = Image("image0", TAILLE_IMAGE, TAILLE_IMAGE);

	//4- Ajouter à l'image créée à l'étape 3 les pixels rouges
	for (int i = 1; i <= TAILLE_IMAGE; i++) {
		for (int j = 1; j <= TAILLE_IMAGE; j++) {
			image0.ajouterPixel(pixelsRouges[i*j - 1], i - 1, j - 1);
		}
	}
	//5- Creez une deuxième image de taille 3*3 
	Image image1 = Image("image1", TAILLE_IMAGE, TAILLE_IMAGE);
	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	for (int i = 1; i <= TAILLE_IMAGE; i++) {
		for (int j = 1; j <= TAILLE_IMAGE; j++) {
			image1.ajouterPixel(pixelsVerts[i*j - 1], i - 1, j - 1);
		}
	}
	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupImage = GroupImage("groupe1", TAILLE_IMAGE);
	//8- Ajoutez les deux images crées precédament au groupe
	groupImage.ajouterImage(image0);
	groupImage.ajouterImage(image1);
	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupImage.obtenirImage(0).augmenterTeintePixel(1, 1, 50, 'B');
	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	groupImage.obtenirImage(0).augmenterTeintePixel(1, 1, -255, 'R');
	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	groupImage.obtenirImage(1).augmenterTeintePixel(2, 1, 100, 'B');
	//12- Affichez les images de ce groupe
	groupImage.afficherImages();
	//13- Doublez la taille de la premiere image du groupe en largeur	
	groupImage.doublerTailleImageEnLargeur(0);
	//14- Doublez la taille de la deuxieme image du groupe en hauteur
	groupImage.doublerTailleImageEnHauteur(1);
	//15- Afficher cette image 
	groupImage.obtenirImage(1).afficherImage();

	system("pause");
	return 0;
}