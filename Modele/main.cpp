// Win32Project1.cpp�: d�finit le point d'entr�e pour l'application.
#include "stdafx.h"
#include "Modele.h"

int main(){
	Modele *m = new Modele();
	Cours *c1 = new Cours("Maths", 15);
	Cours *c2 = new Cours("Physique", 17);
	Cours *c3 = new Cours("SVT", 16);
	Etudiant *e1 = new Etudiant();
	Etudiant *e2 = new Etudiant();
	//URL *urls = new URL("www.google.fr", "google");

	m->ajouterCours(*c1);
	m->ajouterCours(*c2);
	m->ajouterCours(*c3);

	m->getListeCours();

	e1->setPrenom("Coralie");
	e1->setNom("DOUVILLE");

	e2->setPrenom("Aurelien");
	e2->setNom("ANDRE");

	cout << "\nTest sur l'etudiant " << e1->getPrenom() << "\n" << endl;

	c1->addEtudiantListePrincipale(*e1);
	cout << "Etudiant inscrit au cours de " << c1->getNomCours() << " : " << c1->getEtudiant(0).getPrenom() << endl;
	cout << "Taile de la liste principale du cours de " << c1->getNomCours() << " : " << c1->getTailleListePrincipale() << "\n" << endl;

	c2->addEtudiantListePrincipale(*e1);
	cout << "Etudiant inscrit au cours de " << c2->getNomCours() << " : " << c2->getEtudiant(0).getPrenom() << endl;
	cout << "Taile de la liste principale du cours de " << c2->getNomCours() << " : " << c2->getTailleListePrincipale() << "\n" << endl;

	c3->addEtudiantListePrincipale(*e1);
	cout << "Etudiant inscrit au cours de " << c3->getNomCours() << " : " << c3->getEtudiant(0).getPrenom() << endl;
	cout << "Taile de la liste principale du cours de " << c3->getNomCours() << " : " << c3->getTailleListePrincipale() << "\n" << endl;

	cout << "Nombre de cours ou " << e1->getPrenom() << " est inscrit(e) : " << m->getNbCoursEtudiant(*e1) << "\n" << endl;

	cout << "Suppression de l'etudiant " << e1->getPrenom() << " du cours de " << c1->getNomCours() << "\n" << endl;
	c1->supprimerEtudiant(*e1);

	cout << "Nombre de cours ou " << e1->getPrenom() << " est inscrit(e) : " << m->getNbCoursEtudiant(*e1) << "\n" << endl;

	cout << "CA MARCHE BAAAAAAAAAABBBBBBBBEEEEEEEEEEEEEE !!!!!!!!!! \n" << endl;

	//m->supprimerCours(*c);
	//cout << "Cours " + m->getCoursAt(0).getNomCours() + " de la liste" << endl;
	//cout << m->donneExtension("test.pdf") << endl;
	//m->verifPDFValide("C:\\Users\\Coralie-ASUS\\Documents\\Diag classe.txt");
	//cout << m->existenceFichier("C:\\Users\\Coralie-ASUS\\Documents\\doc2.txt") << endl;

	system("PAUSE");
	return 0;
}