
#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include <stdlib.h>
#include <list>
#include "Professeur.h"
#include "Etudiant.h"
#include "Cours.h"

using namespace std;


//std::list<Ressource> ressources;
std::list<Etudiant> listeattente;
std::list<Etudiant> listeprincipale;
	Professeur *prof = new Professeur();

	void Cours::addEtudiantListePrincipale(Etudiant e){
		listeprincipale.push_back(e);

	}



