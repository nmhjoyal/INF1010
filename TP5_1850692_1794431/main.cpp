///////////////////////////////////////////////////////////////////////////////////////
/// \file    main.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-11-19
/// \since   Création : 2017-11-01
///
/// Ce fichier contient les instructions pour tester le code.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"
#include <queue>
#include "BaseDeDonnesSpecifique.h"
#include "Foncteur.h"
#include <functional>

using namespace  std;
using namespace placeholders;

const int NB_IMAGES = 9;

int main() {
	// Chemin vers les images
	string cheminLoad = "./Ensemble d'images/Originale/";
    // Nom des 9 images dans un tableau de string
	string image[NB_IMAGES] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "Monkey.bmp","WiC.bmp","Sloth.bmp","Green.bmp"};

    // Creer un conteneur de type QUEUE et ajouter les images dans la queue
	cout << "**************************************************" << endl;
	cout << "Creation de la file de travail" << std::endl;
	cout << "**************************************************" << endl << endl;
	
	//Créer un vecteur qui contient les mêmes pointeurs d'images contenues dans la queue, afin
	//de pouvoir facilement désallouer la mémoire à la fin du code
	vector<Image*> imageToDelete;
	queue<Image*> file;
	for (int i = 0; i < NB_IMAGES; i++)
	{
		Image* img = new Image(cheminLoad+image[i]);
		file.push(img);
		imageToDelete.push_back(img);
	}
	


	//Creez 3 GroupeImage
	GroupeImage* groupe1, *groupe2, *groupe3;

	groupe1 = new GroupeImage();
	groupe2 = new GroupeImage();
	groupe3 = new GroupeImage();

	// Creez un objet de type BaseDeDonnesSpecifique et ajoutez les 3 groupes a la base de donnes
	BaseDeDonnesSpecifique dataBase;
	
	dataBase.ajouter(groupe1);
	dataBase.ajouter(groupe2);
	dataBase.ajouter(groupe3);

	/*Faites repartir les elements de la queue de maniere uniforme et sequentielle dans les groupe
	 Vous devez avoir la composition suivante :
		groupe 1 a les images 0,3,6
		groupe 2 a les images 1,4,7
		groupe 3 a les images 2,5,8
	 ATTENTION : la repartition doit se faire dans une seule boucle ET vous devez utiliser les fonctions de l'objet de base de donnes
	 NB: La methode pop() de queue<> ne retourne pas l'element de la structure
	*/
	
	
	cout << "**************************************************" << endl;
	cout << "CHARGEMENT DES IMAGES\n\n";
	// TODO : Votre implementation ici

	for (int i = 0; i < NB_IMAGES; i++)
	{
		// triées selon le reste d'une division par 3 (3 groupes)
		if (i % 3 == 0) {
			dataBase.AssocierImage(groupe1, file.front());
			file.pop();
		}
		else if (i % 3 == 1) {
			dataBase.AssocierImage(groupe2, file.front());
			file.pop();
		}
		else if (i % 3 == 2) {
			dataBase.AssocierImage(groupe3, file.front());
			file.pop();
		}
		else
			cout << "Une erreur s'est produite lors de l'ajout des images" << endl;
	}

	cout << "**************************************************" << endl << endl;
	cout << "**************************************************" << endl;
	cout <<"AFFICHAGE DE LA BASE DE DONNESES\n" << endl;
	// TODO : Afficher la base de donnes au complet

	cout << dataBase << "**************************************************" << endl <<endl;

	// Pour chaque groupe, generez un nombre aleatoire. Le nombre aleatoire doit toujours donner un index valide
	// ET appliquez les modifications suivantes aux images obtenues avec le nombre aleatoire
	//GROUPE 1 - Mettre en negatif

	//Générer un nombre aléatoire en fonction du nombre d'images contenues dans le groupe
	FoncteurGenerateurNombresAlea index = FoncteurGenerateurNombresAlea(0, groupe1->obtenirNombreImages());
	
	groupe1->obtenirImageParIndex(index())->mettreEnNegatif();

	//GROUPE 2 - Mettre en gris

	index = FoncteurGenerateurNombresAlea(0, groupe2->obtenirNombreImages());

	groupe2->obtenirImageParIndex(index())->convertirGris();

	//GROUPE 3 - Mettre en noir et blanc
	
	index = FoncteurGenerateurNombresAlea(0, groupe3->obtenirNombreImages());

	groupe2->obtenirImageParIndex(index())->convertirBN();


	/*
	 *TRAITEMENT DE GROUPE 1
	 *Calculer l'intensite moyenne des images du groupe 1 et l'afficher
	 */

	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA MOYENNE \n\n";
	// TODO : Votre implementation ici
	double moyenneG1 = groupe1->obtenirIntensiteMoyenne();
	cout << "Moyenne du groupe 1 : " << moyenneG1 << endl << endl;

	cout << "MOYENNES DES IMAGES DANS LA BASE DE DONNES: \n";


	// Trouver toutes les images avec une intensite moyenne plus petite que la valeur trouve et
	// afficher leur nom et leur moyenne
	// ATTENTION : Faire ceci avec une boucle for intelligente de type 
	//															for (Type variable : conteneur)
	for (Image* img : dataBase.obtenirListImages()) {
		double moyenneImg = img->obtenirIntensiteMoyenne();
		if (moyenneImg < moyenneG1){
			cout << img->obtenirNomImage() << " avec une moyenne de : " << moyenneImg << endl;
		}
	}

	cout << "**************************************************" << endl << endl;



	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA TAILLE \n\n";
	// TODO : Votre implementation ici

	/*
	 *TRAITEMENT DE GROUPE 2
	 * Calculer la taille moyenne des images dans le groupe 2 et afficher l'afficher
	 */
	double tailleMoyenneG2 = groupe2->obtenirTailleMoyenne();
	cout << "Taille moyenne : " << tailleMoyenneG2 << endl;


	// Afficher le nombre d'images dans la base de donnes
	cout << "Nombre d'images totales dans la base de donnes : " << dataBase.obtenirListImages().size() << endl;

	// Trouver at afficher le nombre d'images qui ont une taille plus grande que la moyenne calculee
	// Utiliser les fonctions std::bind et std::placeholders pour effectuer le travail
	int nbImagesSuperieur = 0;
	for (Image* img : dataBase.obtenirListImages()) {
		double taille = img->obtenirTaille();
		if (taille > tailleMoyenneG2){
			nbImagesSuperieur++;
		}
	}

	// Calculer le nombre d'images avec une taille superieure a la taille moyenne
	// ASTUCE: utilisez la STL et les fonctions de decompte conditionel
	FoncteurObtenirTailleImage foncteurTaille;
	//On combine deux foncteurs pour former un prédicat
	auto superieurMoyenne = std::bind(greater<double>(), std::bind(foncteurTaille, _1), tailleMoyenneG2);

	auto listeImage = dataBase.obtenirListImages();

	int test = count_if(listeImage.begin(), listeImage.end(), superieurMoyenne);

	cout << "Nombre d'image dont la taille est plus grande que la moyenne : " << test << endl;


	// Afficher le nombre d'images dans la base de donnes avec une taille plus grande que la moyenne
	
	cout << "**************************************************" << endl << endl;


	/*
	 * TRAITEMENT DU GROUPE 3
	 *
	 * Mettre tout les images du groupe 3 en noir et blanc et sauvegarder
	 * ATTENTION : Vous devez utiliser la fonction generique "appliquerFoncteurUnaire"  demandee dans au TP5 et non une boucle sur les elements
	 */

	cout << "**************************************************" << endl;
	cout << "CONVERSION EN NOIR ET BLANC \n";
	// TODO : Votre implementation ici

	groupe3->appliquerFoncteurUnaire(FoncteurMettreEnBN());
	groupe3->toutEnregistrer();

	cout << "**************************************************" << endl << endl;

	//Désallocation des pointeurs
	delete groupe1;
	delete groupe2;
	delete groupe3;
	
	while (!imageToDelete.empty()) {
		delete imageToDelete.back();
		imageToDelete.pop_back();
	}

	// Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}