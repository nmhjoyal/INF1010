///////////////////////////////////////////////////////////////////////////////////////
/// \file    Image.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-10-01
/// \since   Création : 2017-09-27
///
/// Ce fichier contient la définition des méthodes pour la classe Image.
//////////////////////////////////////////////////////////////////////////////////////

#include "Image.h"
#include <iostream>
#include "Const.h"

using namespace std;

Image::Image():nomImage_("Image Vide"),nombrePixelEnHauteur_(1),nombrePixelEnLargeur_(1)
{
	pixels_ = new Pixel*[1];
	pixels_[0] = new Pixel[1];
}


Image::~Image()
{
	/*
	for(unsigned int i = 0; i < nombrePixelEnHauteur_; i++){
		delete[] pixels_[i];
	}
	delete[] pixels_;
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr;
	*/
}

Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) :nomImage_(nomImage),
	nombrePixelEnHauteur_(nombrePixelHauteur), nombrePixelEnLargeur_(nombrePixelLargeur)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_;i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}

Image::Image(const Image& image) {
	nomImage_ = image.nomImage_;
	nombrePixelEnHauteur_ = image.nombrePixelEnHauteur_;
	nombrePixelEnLargeur_ = image.nombrePixelEnLargeur_;
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++){
			pixels_[i][j] = image.pixels_[i][j];
		}
	}

}



void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}


unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}


unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}

string Image::obtenirNomImage() const{
	return nomImage_;
}

bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionLargeur >= nombrePixelEnLargeur_ || positionHauteur >= nombrePixelEnHauteur_) {
		return false;
	}
	else {
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
	}
}

void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ *= 2;

	Pixel** imageTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0;i < nombrePixelEnHauteur_ / 2;i++) {
		imageTemp[i] = pixels_[i];
	}

	for (unsigned int i = nombrePixelEnHauteur_ / 2;i < nombrePixelEnHauteur_;i++) {
		imageTemp[i] = new Pixel[nombrePixelEnLargeur_];
	}	

	delete[] pixels_;
	pixels_ = imageTemp;
	imageTemp = nullptr;

}

void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ *= 2;

	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		Pixel* colonneImage = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0;j < nombrePixelEnLargeur_ / 2; j++) {
			colonneImage[j] = pixels_[i][j];
		}
		delete[] pixels_[i];
		pixels_[i] = colonneImage;

	}

	
}

void Image::afficherImage() const {

	cout << "Affichage de l'image :  " << obtenirNomImage().c_str()<< endl;
	
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << "    ";
			for (unsigned int j = 0; j < nombrePixelEnLargeur_;j++) {
					pixels_[i][j].retournerCouleur();
					// Nous avons remplacé la fonction afficherPixel par retournerCouleur 
		    }
		cout << endl;
	}
}

Pixel Image::obtenirPixel(unsigned int positionLargeur,unsigned int positionHauteur) const {
 
	return pixels_[positionHauteur][positionLargeur];

}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {

	if (couleur == 'R') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	}
	if (couleur == 'G') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	}
	if (couleur == 'B') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	}

}

Image Image::operator= (const Image& image){
	//On affecte les attributs du paramètre transmis aux attributs du paramètre courant (this) 
	//à gauche de l'opérateur '='.
	nomImage_ = image.nomImage_;
	nombrePixelEnHauteur_ = image.nombrePixelEnHauteur_;
	nombrePixelEnLargeur_ = image.nombrePixelEnLargeur_;
	pixels_ = image.pixels_;
	
	//On retourne 'this' car c'est l'objet courant de type Image qui sera modifié.
	return *this;
}

ostream& operator<<(ostream& out, const Image& image) {
	out << "Affichage de l'image :  " << image.nomImage_.c_str() << endl;
	for (unsigned int i = 0; i < image.nombrePixelEnHauteur_; i++) {
		for (unsigned int j = 0; j < image.nombrePixelEnLargeur_; j++) {
			// On ajoute le caractère associé à chaque pixel de l'image au ostream.
			out << image.pixels_[i][j];
		}
		out << endl;
	}
	return out;
}

bool Image::operator==(const Image& image) const {
	//On vérifie chaque attribut, dès qu'un attribut ne corresspond pas à celui
	// de l'image transmis (à droite de l'opérateur), on retourne FAUX.
	if (nomImage_ == image.nomImage_ && 
		nombrePixelEnHauteur_ == image.nombrePixelEnHauteur_ && 
		nombrePixelEnLargeur_ == image.nombrePixelEnLargeur_) {
		for (unsigned int i = 0; i < image.nombrePixelEnHauteur_; i++) {
			for (unsigned int j = 0; j < image.nombrePixelEnLargeur_; j++) {
				if (!(pixels_[i][j] == image.pixels_[i][j])) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool Image::operator==(const string& nomImage) const {
	return (nomImage_ == nomImage);
}

bool operator==(const string& nomImage, const Image& image){
	return (image == nomImage);
}



