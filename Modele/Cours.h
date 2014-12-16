#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include <list>
#include "Etudiant.h"

using namespace std;

class Cours{

public :

	void addEtudiantListePrincipale(Etudiant e);
	void addEtudiantListeAttente(Etudiant e);

private:
	
	string nomC;

};