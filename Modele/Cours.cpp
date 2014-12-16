
#include "stdafx.h"
#include <iostream>
#include <string> 
#include <stdlib.h>
#include <list>
#include "Professeur.h"
#include "Etudiant.h"
#include "Cours.h"

using namespace std;

Professeur *prof = new Professeur();

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