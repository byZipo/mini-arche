
#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include <stdlib.h>
#include <list>
#include "Professeur.h"
#include "Etudiant.h"
#include "Cours.h"
#ifndef COURS_H
#define COURS_H
using namespace std;


//std::list<Ressource> ressources;
std::list<Etudiant> listeattente;
std::list<Etudiant> listeprincipale;
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

#endif

