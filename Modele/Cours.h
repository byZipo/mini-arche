#ifndef COURS_H
#define COURS_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include "Etudiant.h"
#include "Ressource.h"

using namespace std;

class Cours{

public :
	Cours(string, int);
	vector<Ressource> ressources;
	vector<Etudiant> listeattente;
	vector<Etudiant> listeprincipale;
	void addEtudiantListePrincipale(Etudiant e);
	void addEtudiantListeAttente(Etudiant e);
	void addRessources(Ressource r);
	Etudiant getEtudiant(int i);
	string getNomCours();
	int getMaxEtudiant();
	int getTailleListePrincipale();

private:
	
	string nomC;
	int nbEtuMax;

};

#endif