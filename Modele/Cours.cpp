#include "stdafx.h"
#include "Cours.h"

using namespace std;

Professeur *prof = new Professeur();

Cours::Cours(string nom, int nbetu){
	this->nomC = nom;
	this->nbEtuMax = nbetu;
	this->listeprincipale = new vector<Etudiant>();
	this->listeattente = new vector<Etudiant>();
	this->ressources = new vector<Ressource*>();
}

void Cours::addEtudiantListePrincipale(Etudiant e){
	bool aux = true;
	for (unsigned i = 0; i < listeprincipale->size(); i++){
		if (estMemeEtudiant(listeprincipale->at(i), e)){
			aux = false;
		}
	}
	if (aux == true){
		listeprincipale->push_back(e);
	}
}

void Cours::addEtudiantListeAttente(Etudiant e){
	bool aux = true;
	for (unsigned i = 0; i < listeattente->size(); i++){
		if (estMemeEtudiant(listeattente->at(i), e)){
			aux = false;
		}
	}
	if (aux == true){
		listeattente->push_back(e);
	}
}

Etudiant Cours::getEtudiant(int i){
	return listeprincipale->at(i);
}

bool Cours::estMemeEtudiant(Etudiant c, Etudiant c2){
	if (c.getNom() == c2.getNom() && c.getPrenom() == c2.getPrenom()){
		return true;
	}
	else{
		return false;
	}
}

void Cours::supprimerEtudiant(Etudiant e){
	
	for (unsigned i = 0; i < listeattente->size(); i++){
		if (estMemeEtudiant(listeattente->at(i), e)){
			listeattente->erase(listeattente->begin() + i);
		}
	}
	for (unsigned i = 0; i < listeprincipale->size(); i++){
		if (estMemeEtudiant(listeprincipale->at(i), e)){
			listeprincipale->erase(listeprincipale->begin() + i);
		}
	}
}

int Cours::getMaxEtudiant(){
	return nbEtuMax;
}

int Cours::getTailleListePrincipale(){
	return listeprincipale->size();
}

void Cours::addRessources(Ressource *r){
	ressources->push_back(r);
	cout << "Ajout d'une ressource" << endl;
	cout << "Taille de la liste des ressources= " << ressources->size() << "\n" << endl;
}

bool Cours::estMemeRessource(Ressource c, Ressource c2){
	if (c.getType() == c2.getType() && c.getNom() == c2.getNom()){
		return true;
	}
	else{
		return false;
	}
}

void Cours::supprimerRessource(Ressource r){

	for (unsigned i = 0; i < ressources->size(); i++){
		if (estMemeRessource(*ressources->at(i), r)){
			ressources->erase(ressources->begin() + i);
		}
	}

}
Ressource* Cours::getRessource(int i){
	return ressources->at(i);

}

vector<Ressource*> Cours::getAllRessource(){
	return *ressources;
}

string Cours::getTypeRes(Ressource *r){
	return r->getType();
}

vector<Etudiant> Cours::getListeEtudiant(){
	return *listeprincipale;

}
string Cours::getNomCours(){
	return nomC;
}