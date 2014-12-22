#ifndef COURS_H
#define COURS_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include "Etudiant.h"


using namespace std;

class Cours{

public :

	//std::list<Ressource> ressources;
	vector<Etudiant> listeattente;
	vector<Etudiant> listeprincipale;
	void addEtudiantListePrincipale(Etudiant e);
	void addEtudiantListeAttente(Etudiant e);
	Etudiant getEtudiant(int i);
	string getNomCours();

private:
	
	string nomC;


};

#endif