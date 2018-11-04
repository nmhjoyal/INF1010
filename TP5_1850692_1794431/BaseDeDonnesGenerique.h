///////////////////////////////////////////////////////////////////////////////////////
/// \file    BaseDeDonnesGenerique.h
/// \author  Nicolas Bayard et Nicole Joyal
/// \version Dernière entrée : 2017-11-19
/// \since   Création : 2017-11-01
///
/// Ce fichier contient la déclaration des méthodes et attributs associés à la classe 
/// BaseDeDonnesGenerique.
//////////////////////////////////////////////////////////////////////////////////////
#ifndef BASE_DE_DONNES_GENERIQUE
#define BASE_DE_DONNES_GENERIQUE

#include <list>
#include <algorithm>
#include <iterator>

// Implementer toutes les methodes dans ce fichier

using namespace  std;
template<typename T, typename S> //T = Image, S = GroupeImage
class BaseDeDonnesGenerique
{
public:
	//Constructeur
	BaseDeDonnesGenerique();
	//Destructeur
	~BaseDeDonnesGenerique();
	//Accesseurs
	list<T*> obtenirListImages() const;
	list<S*> obtenirListGroupeImages() const;

	//Mutateurs
	void ajouter(T* t);
	void ajouter(S* s);

	bool supprimer(const T* t);
	bool supprimer(const S* s);

	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate);

	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate);

	void vider();

	//Surcharge d'opérateurs
	BaseDeDonnesGenerique& operator+=(T* t) {
		ajouter(t);
		return *this;
	};

	BaseDeDonnesGenerique& operator+=(S* s) {
		ajouter(s);
		return *this;
	};

	BaseDeDonnesGenerique& operator-=(T* t) {
		supprimer(t);
		return *this;
	};

	BaseDeDonnesGenerique& operator-=(S* s) {
		supprimer(s);
		return *this;
	};

protected:
	list<T*> listImage_;
	list<S*> listGroupeImage_;
};

//IMPLÉMENTATION
//Constructeur
template<typename T, typename S> //T = Image, S = GroupeImage
BaseDeDonnesGenerique<T,S>::BaseDeDonnesGenerique() {}

//Destructeur
template<typename T, typename S> //T = Image, S = GroupeImage
BaseDeDonnesGenerique<T,S>::~BaseDeDonnesGenerique() {}

//Accesseurs
template<typename T, typename S> //T = Image, S = GroupeImage
list<T*> BaseDeDonnesGenerique<T,S>::obtenirListImages() const {
	return listImage_;
}

template<typename T, typename S>
list<S*> BaseDeDonnesGenerique<T,S>::obtenirListGroupeImages() const {
	return listGroupeImage_;
}

//Mutateurs
template<typename T, typename S> //T = Image, S = GroupeImage
void BaseDeDonnesGenerique<T, S>::ajouter(T* t) {
	listImage_.push_back(t);
}

template<typename T, typename S> //T = Image, S = GroupeImage
void BaseDeDonnesGenerique<T, S>::ajouter(S* s) {
	listGroupeImage_.push_back(s);
}

template<typename T, typename S> //T = Image, S = GroupeImage
bool BaseDeDonnesGenerique<T, S>::supprimer(const T* t) {
	//Parcours de la liste
	list<T*>::iterator it = find(listImage_.begin(), listImage_.end(), t);
	if (it == listImage_.end()) {
		//Si l'itérateur est égal à end() de la liste, c'est-à-dire
		// que l'élément n'existe pas dans la liste
		cout << "Element non retire" << endl;
		return false;
	}
	listImage_.erase(it);
	return true;
}

template<typename T, typename S> //T = Image, S = GroupeImage
bool BaseDeDonnesGenerique<T, S>::supprimer(const S* s) {
	list<S*>::iterator it = find(listGroupeImage_.begin(), listGroupeImage_.end(), s);
	if (it == listGroupeImage_.end()) {
		cout << "Element non retire" << endl;
		return false;
	}
	listGroupeImage_.erase(it);
	return true;
}

template<typename T, typename S>
template<typename Predicate>
bool BaseDeDonnesGenerique<T, S>::supprimerImage(const Predicate& predicate) {
	remove_if(listImage_.begin(), listImage_.end(), predicate);
	return true;
}

template<typename T, typename S>
template<typename Predicate>
bool BaseDeDonnesGenerique<T, S>::supprimerGroupeImage(const Predicate& predicate) {
	remove_if(listGroupeImage_.begin(), listGroupeImage_.end(), predicate);
	return true;
}

template<typename T, typename S> //T = Image, S = GroupeImage
void BaseDeDonnesGenerique<T, S>::vider() {
	listImage_.clear();
	listGroupeImage_.clear();
}

#endif BASE_DE_DONNES_GENERIQUE
