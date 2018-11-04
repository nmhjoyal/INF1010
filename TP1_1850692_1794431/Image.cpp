///////////////////////////////////////////////////////////////////////////////////////
/// \file    Image.cpp
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-09-21
/// \since   Création : 2017-09-14
///
/// Ce fichier contient la définition des méthodes pour la classe Image.
//////////////////////////////////////////////////////////////////////////////////////

# include "Image.h"



Image::Image() { // à tester
	// commenter
	nombrePixelEnHauteur_ = 1;
	nombrePixelEnLargeur_ = 1;
	pixels_ = new Pixel*[nombrePixelEnLargeur_];
	pixels_[nombrePixelEnLargeur_] = new Pixel[nombrePixelEnHauteur_];
}
Image::~Image() {
	// Ne fonctionne pas à partir l'étape 9, cette modification solutionne le problème
	/*
	for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
		if (pixels_[i] != nullptr) {
			delete[] pixels_[i];
		}
	}
	 delete [] pixels_;
	 */
}

Image::Image(const string& nomImage, unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) {
	nomImage_ = nomImage;
	nombrePixelEnHauteur_ = nombrePixelHauteur;
	nombrePixelEnLargeur_ = nombrePixelLargeur;
	pixels_ = new Pixel*[nombrePixelEnLargeur_];
	for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnHauteur_];
	}
}

void Image::doublerTailleEnLargeur() {
	Pixel** temp = new Pixel*[nombrePixelEnLargeur_*2];
	for (unsigned int i = 0; i < nombrePixelEnLargeur_ * 2; i++) {
		if (i < nombrePixelEnLargeur_) {
			temp[i] = pixels_[i];
		}
		else {
			temp[i] = new Pixel[nombrePixelEnHauteur_]; // à vérifier
		}
	}
	for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
		if (pixels_[i] != nullptr) {
			delete[] pixels_[i];
		}
	}
	delete[] pixels_;
	nombrePixelEnLargeur_ *= 2;
	pixels_ = temp;
}
void Image::doublerTailleEnHauteur() {
	
	for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
		Pixel* temp = new Pixel[nombrePixelEnHauteur_ * 2];
		for (unsigned int j = 0; j < nombrePixelEnHauteur_ * 2; j++) {
			if (j < nombrePixelEnHauteur_) {
				temp[j] = pixels_[i][j];
			}
		}
		if (pixels_[i] != nullptr) {
			delete[] pixels_[i];
		}
		pixels_[i] = temp;
	}
	nombrePixelEnHauteur_ *= 2;
}

unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}
unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}
string Image::obtenirNomImage() const {
	return nomImage_;
}

void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}

void Image::afficherImage() const {
	cout << "Affichage de l'image : " << nomImage_ << endl;
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << "\t" ;
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
			pixels_[j][i].afficherPixel();
			
		}
		cout << endl;
	}
	cout << endl << "-----------------------------------------------------" << endl << endl;
}

bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionHauteur < nombrePixelEnHauteur_ && positionLargeur < nombrePixelEnLargeur_) {
		pixels_[positionLargeur][positionHauteur] = pixel;
		return true;
	}
	return false;
}

Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const {
	if (positionHauteur < nombrePixelEnHauteur_ && positionLargeur < nombrePixelEnLargeur_) {
		return pixels_[positionLargeur][positionHauteur];
	}
    cout <<Ê"Erreur : position invalide" << endl;
	return Pixel(); //verifier
}
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {
	if (positionHauteur < nombrePixelEnHauteur_ && positionLargeur < nombrePixelEnLargeur_) {
		if (couleur == 'R') {
			pixels_[positionLargeur][positionHauteur].modifierTeinteRouge(increment);
		}
		else if (couleur == 'G') {
			pixels_[positionLargeur][positionHauteur].modifierTeinteVert(increment);
		}
		else if (couleur == 'B') {
			pixels_[positionLargeur][positionHauteur].modifierTeinteBleu(increment);
		}
        else {
            cout << "Erreur : Couleur invalide" << endl;
        }
	}
}
