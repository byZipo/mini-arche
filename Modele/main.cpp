#include <iostream>
#include "Etudiant.h"
#include "Cours.h"
#include "resource.h"
using namespace std;

int main(){
	cout << "Bienvenue sur Mini-Arche !!\n" << endl;

	Cours *c1 = new Cours();
	Etudiant *e1 = new Etudiant();
	c1->addEtudiantListePrincipale(*e1);

	system("PAUSE");
	return(0);
}