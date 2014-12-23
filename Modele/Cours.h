#ifndef COURS_H
#define COURS_H

//Libraires
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <string> 
#include <stdlib.h>

//Nos classes
#include "Etudiant.h"
#include "Ressource.h"
#include "Professeur.h"

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
	void Cours::supprimerEtudiant(Etudiant e);
	bool Cours::estMemeEtudiant(Etudiant e, Etudiant e1);
	bool Cours::estMemeRessource(Ressource e, Ressource e1);
	void Cours::supprimerRessource(Ressource r);
private:
	
	string nomC;
	int nbEtuMax;

};

#endif
