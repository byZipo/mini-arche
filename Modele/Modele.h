#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include "Etudiant.h"
#include "Cours.h"
#include "Professeur.h"
#ifndef MODELE_H
#define MODELE_H
#include "shellapi.h"
#include <Windows.h>
#include "Ressource.h"

using namespace std;

class Modele {

private :

	vector<Cours> listeCours;
	vector<Etudiant> etudiants;
	vector<Professeur> profs;

public :

	void ajouterCours(Cours cours);
	bool Modele::estDisponible(string nom);
	bool Modele::verifUrlValide(string url);
	bool Modele::verifPDFValide(string chemin);
	bool Modele::verifDevoirValide(string chemin);
	bool Modele::ListePrincipaleDisponible(Cours c);
	Professeur Modele::getProfesseur(string nom, string prenom);
	Etudiant Modele::getEtudiant(string nom, string prenom);
	bool Modele::estProfesseur();
	bool Modele::estMemeCours(Cours c, Cours c2);
	void supprimerCours(Cours c);
	Cours Modele::getCoursAt(int i);
	void Modele::getListeCours();
	string Modele::donneExtension(string str);
};

#endif