// Win32Project1.cpp�: d�finit le point d'entr�e pour l'application.
//

#include <iostream>
#include "Modele.h"
#include <string>

int main(){
	Modele *m = new Modele();
	Cours *c = new Cours("Maths", 15);
	m->ajouterCours(*c);
	cout << "Cours ajout� : " + c->getNomCours() + " " << endl;

	cout << "Cours "+m->getCoursAt(0).getNomCours()+" de la liste" << endl;

	m->supprimerCours(*c);
	//cout << "Cours " + m->getCoursAt(0).getNomCours() + " de la liste" << endl;
	system("PAUSE");
	return 0;
}