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

	Etudiant *e2 = new Etudiant();
	e2->setPrenom("Aurelien");

	Etudiant *e3 = new Etudiant();
	e3->setPrenom("Thibault");

	c1->addEtudiantListePrincipale(*e1);
	c1->addEtudiantListeAttente(*e2);
	c1->addEtudiantListeAttente(*e3);

	//c1->suppEtudiantListeAttente(*e2);
	c1->suppEtudiantListeAttente(*e3);

	c1->afficherListeAttente();
	c1->afficherListePrincipale();

	system("PAUSE");
	return(0);
}