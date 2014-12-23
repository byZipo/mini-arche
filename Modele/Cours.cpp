
#include "stdafx.h"
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <list>
#include "Professeur.h"
#include "Etudiant.h"
#include "Cours.h"
#include "Ressource.h"
using namespace std;

Professeur *prof = new Professeur();

Cours::Cours(string nom, int nbetu){
	this->nomC = nom;
	this->nbEtuMax = nbetu;

}

void Cours::addEtudiantListePrincipale(Etudiant e){
	listeprincipale.push_back(e);
	cout << "Ajout d'un etudiant" << endl;
	cout << "Taille de la liste listeprincipale= " << listeprincipale.size() << "\n" << endl;
}

void Cours::addEtudiantListeAttente(Etudiant e){
	listeattente.push_back(e);
	cout << "Ajout d'un etudiant" << endl;
	cout << "Taille de la liste listeattente= " << listeattente.size() << "\n" << endl;
}

Etudiant Cours::getEtudiant(int i){
	return listeprincipale.at(i);
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
	
	for (int i = 0; i < listeattente.size(); i++){
		if (estMemeEtudiant(listeattente.at(i), e)){
			listeattente.erase(listeattente.begin() + i);
		}
	}
	for (int i = 0; i < listeprincipale.size(); i++){
		if (estMemeEtudiant(listeprincipale.at(i), e)){
			listeprincipale.erase(listeprincipale.begin() + i);
		}
	}
}

int Cours::getMaxEtudiant(){
	return nbEtuMax;
}
int Cours::getTailleListePrincipale(){
	return listeprincipale.size();
}



void Cours::addRessources(Ressource r){
	ressources.push_back(r);
	cout << "Ajout d'une ressource" << endl;
	cout << "Taille de la liste des ressources= " << ressources.size() << "\n" << endl;
}

/*bool Cours::estMemeRessource(Ressource c, Ressource c2){
	if (c.getNom() == c2.getNom() && c.getPrenom() == c2.getPrenom()){
		return true;
	}
	else{
		return false;
	}
}*/

void Cours::supprimerRessource(Ressource r){

	for (int i = 0; i < ressources.size(); i++){
		//if (estMemeRessource(ressources.at(i), r)){
			ressources.erase(ressources.begin() + i);
		
	}

}
string Cours::getNomCours(){
	return nomC;
}


