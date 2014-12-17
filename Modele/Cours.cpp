
#include "stdafx.h"
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <list>
#include "Professeur.h"
#include "Etudiant.h"
#include "Cours.h"

using namespace std;

//Professeur *prof = new Professeur();

void Cours::addEtudiantListePrincipale(Etudiant e){

	cout << "Ajout de l'etudiant " << e.getPrenom() << " a la listeprincipale\n" << endl;
	listeprincipale.push_back(e);

}

void Cours::addEtudiantListeAttente(Etudiant e){

	cout << "Ajout de l'etudiant " << e.getPrenom() << "  la listeattente\n" << endl;
	listeattente.push_back(e);

}

void Cours::afficherListeAttente(){

	cout << "Affichage de la listeattente :\n" << endl;
	int j = listeattente.size();
	for (int i = 0; i < j; i++){
		cout << listeattente[i].getPrenom() << endl;
	}
	cout << "\n" << endl;

}

void Cours::afficherListePrincipale(){

	cout << "Affichage de la listeprincipale :\n" << endl;
	int j = listeprincipale.size();
	for (int i = 0; i < j; i++){
		cout << listeprincipale[i].getPrenom() << endl;
	}
	cout << "\n" << endl;
}

Etudiant Cours::getEtudiant(int i){

	return listeprincipale.at(i);

}

void Cours::suppEtudiantListeAttente(Etudiant e){
	int j = listeprincipale.size();
	for (int i = 0; i < j; i++){
		cout << i << endl;
		if (listeattente[i].getPrenom() == e.getPrenom()){
			listeattente.erase(listeattente.begin() + i);
		}
	}
}

/*
void Cours::suppEtudiant(Etudiant e){

	cout << "Suppression de l'etudiant " << e.getPrenom() << "\n" << endl;
	int j = listeprincipale.size();
	for (int i = 0; i < j; i++){
		if (listeprincipale[i].getPrenom() == e.getPrenom()){
			listeprincipale.erase(listeprincipale.begin() + i);
		}
		if (listeattente[i].getPrenom() == e.getPrenom()){
			listeattente.erase(listeattente.begin() + i);
		}
	}

}
*/

string Cours::getNomCours(){
	return nomC;
}



/*
Supprimer un élément d'un vector :

vector<string> trucmuche;
vector<string>::iterator it = trucmuche.begin();
while (it!=trucmuche.end()){
	if (...)
		it=trucmuche.erase(it);
	else
		++it;
}

Fonction pour supprimer un element d'un vector :

#include <map>
#include <string>
using std::map;
using std::string;
void m(){
	map<string, string> trucmuche;
	map<string, string>::iterator it = trucmuche.begin();
	while (it!=trucmuche.end()){
		if (true)
			it = trucmuche.erase(it); // edit
			else
			++it;
	}
}
*/