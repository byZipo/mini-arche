#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include "Etudiant.h"
#include "Cours.h"
#ifndef MODELE_H
#define MODELE_H

using namespace std;

class Modele {

private :

	std::list<Cours> listecours;


public :

	void ajoutercours(string cours);

};

#endif