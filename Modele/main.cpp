#include <iostream>
#include "Etudiant.h"
#include "Cours.h"
#include "resource.h"
using namespace std;

int main(){
	cout << "Bienvenue sur Mini-Arche !!\n" << endl;

	Cours *c1 = new Cours();
	Etudiant *e1 = new Etudiant();

	e1->setPrenom("Adrien");
	c1->addEtudiantListePrincipale(*e1);

	

	cout << "Le prenom est :" << endl;
	cout << c1->getEtudiant(0).getPrenom() << endl;
	cout << "\n" << endl;

	system("PAUSE");
	return(0);
}