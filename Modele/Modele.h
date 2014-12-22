#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include "Etudiant.h"
#include "Cours.h"
#ifndef MODELE_H
#define MODELE_H
#include "shellapi.h"
#include <Windows.h>
using namespace std;

class Modele {

private :

	vector<Cours> listecours;


public :

	void ajouterCours(Cours cours);
	bool Modele::estDisponible(string nom);
	bool Modele::verifUrlValide(string url);
	bool Modele::verifPDFValide(string chemin, string nom);
	bool Modele::verifDevoirValide(string chemin, string nom);
	bool Modele::ListePrincipaleDisponible(Cours c);
};

#endif