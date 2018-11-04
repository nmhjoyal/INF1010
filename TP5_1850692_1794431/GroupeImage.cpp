//
// Created by Gabriel Bernard on 17-09-12.
//

#include "GroupeImage.h"


using namespace std;

//Constructeur
GroupeImage::GroupeImage() {};

//Constructeur par param�tre
GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_) {}

//Destructeur
GroupeImage::~GroupeImage() {};

//Surcharge d'op�rateurs
GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {
	if (this != &groupe) {
		// Vide les images du groupe
		images_.clear();
		list<Image*>::const_iterator it = images_.begin();
		//on ajoute chaque image du groupe en param�tre avec la fonction insert
		images_.insert(it, groupe.images_.begin(), groupe.images_.end());
	}
	return *this;
}

GroupeImage& GroupeImage::operator+=(Image* image)
{
	ajouterImage(image);
	return *this;
}

GroupeImage& GroupeImage::operator-=(Image* image)
{
	retirerImage(image->obtenirNomImage());
	return *this;
}

//Mutateurs
bool GroupeImage::ajouterImage(Image* image) {

	list<Image*>::iterator it = find_if(images_.begin(), images_.end(), FoncteurEgalImages(image));
	//Si l'image existe d�j� (on compare chaque image avec FoncteurEgalImage), on n'ajoute pas
	if (it != images_.end()) {
		cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
		return false;
	}
	//Sinon, on ajoute � la fin
	images_.push_back(image);
	std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
	return true;
}

bool GroupeImage::retirerImage(const std::string& nom) {
	auto it = find_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
	//Si l'image n'est pas retrouv�e (on arrive � la fin de la liste), on retourne false
	if (it == images_.end()) {
		return false;
	}
	//Sinon, on se sert de la fonction erase() et on retourne true
	images_.erase(it);
	std::cout << nom << " a bien ete retire" << std::endl;
	return true;
}

void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;
	//Se sert de la fonction copy() pour ajouter chaque image au stream
	copy(images_.begin(), images_.end(), ostream_iterator<Image*>(os, "-------------------------------------------------- \n"));
	os << endl;
}

//Accesseurs
Image* GroupeImage::obtenirImage(const string& nom) const {
	list<Image*>::const_iterator it = find_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));

	if (it == images_.end()) {
		//Si image non-trouv�e, on retourne un pointeur null
		return nullptr;
	}
	return *it;
}

//FONCTIONS AJOUT�ES
double GroupeImage::obtenirIntensiteMoyenne() {

	double sommeIntensite = 0.0;
	for (list<Image*>::iterator it = images_.begin(); it != images_.end(); ++it) {
		sommeIntensite += (*it)->obtenirIntensiteMoyenne();
	}
	return sommeIntensite / images_.size();
}

double GroupeImage::obtenirTailleMoyenne() {

	double sommeTaille = 0.0;
	for (list<Image*>::iterator it = images_.begin(); it != images_.end(); ++it) {
		sommeTaille += (*it)->obtenirTaille();
	}
	return sommeTaille / images_.size();
}

std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
{
	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	groupeImage.afficherImages(os);
	os << endl;

	return os;
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

void GroupeImage::toutMettreEnNB() {
	FoncteurMettreEnBN a;
	appliquerFoncteurUnaire(a);
}
void GroupeImage::toutMettreEnGris() {
	FoncteurMettreEnGris a;
	appliquerFoncteurUnaire(a);
}

void GroupeImage::toutMettreEnCouleur() {
	FoncteurMettreEnCouleur a;
	appliquerFoncteurUnaire(a);
}

void GroupeImage::toutMettreEnNegatif() {
	FoncteurMettreEnNegatif a;
	appliquerFoncteurUnaire(a);
}

void GroupeImage::toutEnregistrer() {
	cout << endl;
	list<Image*>::iterator it;
	unsigned int i = 1;
	for (it = images_.begin(); it != images_.end(); it++) {
		Image* image = *it;
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/im" + to_string(i) + image->obtenirNomImage();
		cout << "Sauvegarde de " << nom << endl;
		image->sauvegarderImage(nom);
		i++;
	}
}

Image* GroupeImage::obtenirImageParIndex(int index)
{
	auto it = images_.begin();
	advance(it, index);
	return  *it;
}