// Win32Project1.cpp : définit le point d'entrée pour l'application.
//

#include <iostream>
#include "Modele.h"
#include <string>

int main(){
	Modele *m = new Modele();
	URL urls = new URL("www.google.fr");
	m->ajouterCours(*c);
	cout << "Cours ajouté : " + c->getNomCours() + " " << endl;

	cout << "Cours "+m->getCoursAt(0).getNomCours()+" de la liste" << endl;

	m->supprimerCours(*c);
	//cout << "Cours " + m->getCoursAt(0).getNomCours() + " de la liste" << endl;
	system("PAUSE");
	return 0;
}