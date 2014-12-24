// Win32Project1.cpp�: d�finit le point d'entr�e pour l'application.

#include "Modele.h"

int main(){
	Modele *m = new Modele();
	Cours *c = new Cours("Maths", 15);
	Etudiant *e = new Etudiant();
	URL *adresse = new URL("www.google.fr", "google");
	c->addRessources(*adresse);
	cout << "Type : " << c->getTypeRes(c->getRessource(0)) << endl;
	m->ajouterCours(*c);
	cout << "Cours ajoute : " + c->getNomCours() + " " << endl;

	cout << "Cours "+m->getCoursAt(0).getNomCours()+" de la liste" << endl;

	m->supprimerCours(*c);
	//cout << "Cours " + m->getCoursAt(0).getNomCours() + " de la liste" << endl;

	//cout << m->donneExtension("test.pdf") << endl;
	//m->verifPDFValide("C:\\Users\\Coralie-ASUS\\Documents\\Diag classe.txt");
	cout << m->existenceFichier("C:\\Users\\Coralie-ASUS\\Documents\\doc2.txt") << endl;

	system("PAUSE");
	return 0;
}