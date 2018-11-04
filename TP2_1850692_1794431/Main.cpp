/**************************************************
 * Titre: Travail pratique #2 - Main.cpp
 * Date: Septembre 2017
 * Auteur(s): Nicolas Bayard et Nicole Joyal
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

const int TAILLE = 9;
const int TAILLE_IMAGE = 3;

/*
TODO : Veuillez répondre aux questions ici
1) Le constructeur par copie crée une nouvelle variable du même type que celle envoyée en paramètre, qui contiendra exactement
le même contenu que celle transmise. Ceci est utile lorsqu'on doit créer des variables temporaires, car la nouvelle variable
sera une copie exacte de l'ancienne variable, optimisant ainsi le code. L'affectation ('='), affecte la valeur d'une variable 
déjà existante à une autre variable du même type déjà existante. Ceci est utile losque nous voulons tout simplement changé la 
valeur d'une variable par celle d'une autre plus pertinante.

2) Quand nous traitons des pointeurs il faut absolument les implémenter. Car s'il n'existe aucun constructeur par copie,
le constructeur par défaut copiera le pointeur dans une nouvelle variable. Créant ainsi deux pointeurs pointant au même 
entité. Ceci est de même pour l'opérateur '='. Le constructeur par copie évite ce problème car il copie uniquement les entités
pointés par le pointeur transmis dans la nouvelle variable et non pas le pointeur en tant que tel.

3) L'opérateur '=' est utilisé uniquement lorsqu'on affecte une variable existante à une autre variable existante. Cependant, 
le constructeur par copie crée une nouvelle variable contenant les même valeurs que celle transmise en paramètre.
*/

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
	Image image0 = Image("image1", TAILLE_IMAGE, TAILLE_IMAGE);
	
	//4- Ajouter à l'image créées à l'étape 3 les pixels rouges
	for (int i = 1; i <= TAILLE_IMAGE; i++) {
		for (int j = 1; j <= TAILLE_IMAGE; j++) {
			image0.ajouterPixel(pixelsRouges[i*j - 1], i - 1, j - 1);
		}
	}
	
	//5- Creez une deuxième image de taille 3*3 
	Image image1 = Image("image2", TAILLE_IMAGE, TAILLE_IMAGE);
	
	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	for (int i = 1; i <= TAILLE_IMAGE; i++) {
		for (int j = 1; j <= TAILLE_IMAGE; j++) {
			image1.ajouterPixel(pixelsVerts[i*j - 1], i - 1, j - 1);
		}
	}

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupImage; // Le chargé de TD nous a dit que la capacité n'est pas utile

	//8- Ajoutez les deux images crées precédament au groupe
	groupImage += image0;
	groupImage += image1;

	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	image0.augmenterTeintePixel(1, 1, 50, 'B');

	// La notation suivante ne fonctionne plus à cause de la valeur de retour de obtenirImage,
	// nous avons donc choisi de modifier les images (qui possèdent un lien d'agrégation). Les
	// modifications sont donc également modifiées dans groupImage

	// groupImage.obtenirImage(0).augmenterTeintePixel(1, 1, 50, 'B'); Cette notation ne fonctionne pas à cause

	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	image0.augmenterTeintePixel(1, 1, -255, 'R');
	
	//groupImage.obtenirImage(0).augmenterTeintePixel(1, 1, -255, 'R');

	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités 
	image1.augmenterTeintePixel(2, 1, 100, 'B');
	
	//groupImage.obtenirImage(1).augmenterTeintePixel(2, 1, 100, 'B');

	//12- Afficher le groupe d'image
	cout << groupImage; 

	//13- Supprimer la premiere image du groupe d'image
	groupImage -= image0;

	//14- Afficher le groupe d'image
	cout << groupImage;

	system("pause");
	return 0;
}