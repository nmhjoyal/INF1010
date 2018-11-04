///////////////////////////////////////////////////////////////////////////////////////
/// \file    main.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-22
/// \since   Création : 2017-10-22
///
/// Ce fichier contient les instructions servant à tester les différents codes.
//////////////////////////////////////////////////////////////////////////////////////

// Si plateforme windows
#ifdef _WIN32 
    #include <Windows.h>
    #define PAUSE system("PAUSE")
// S'il s'agit d'une plateforme UNIX
#else
    #include <unistd.h>
    #define PAUSE sleep(0)
#endif

#include "Image.h"
#include "GroupeImage.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	const int nbImage = 6;
	// Chemin vers les images

    string cheminLoad = "./Ensemble d'images/Originale/";
	// Nom des 6 images dans un tableau de string
    string image[nbImage] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

	// Creer un groupe d'image
	cout << "**************************************************" << endl;
	cout << "Creation du groupe d'image" << endl;
	cout << "**************************************************" << endl << endl;

	GroupeImage groupe;

	// Ajouter toutes les images au groupe en tant qu'image couleurs

	for (int i = 0; i <nbImage ; i++) {
		groupe.ajouterImage(new Image(cheminLoad+image[i], Couleurs));
	}

	// Afficher le contenu du groupe d'image

	cout << groupe;

	// Convertir toutes les images en couleurs

	groupe.toutMettreEnCouleur();

	// Enregistrer toutes les images convertie

	groupe.toutEnregistrer();

	// Convertir toutes les images en Nuance de Gris

	groupe.toutMettreEnGris();

	// Enregistrer toutes les images grises

	groupe.toutEnregistrer();

	// Convertir toutes les images en Noir et Blanc

	groupe.toutMettreEnNB();

	// Enretisgrer toutes les images

	groupe.toutEnregistrer();

	// Permet d'afficher le contenu de la console
    PAUSE;

	// Fin du programme
    return 0;
}