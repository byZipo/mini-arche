// Win32Project1.cpp : définit le point d'entrée pour l'application.

#include "Modele.h"

int main(){
	Modele *m = new Modele();
	Cours *c = new Cours("Maths", 15);
	Etudiant *e = new Etudiant();
	//URL *urls = new URL("www.google.fr", "google");

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