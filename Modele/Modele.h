#ifndef MODELE_H
#define MODELE_H

//Libraires
#include "stdafx.h"
#include <iostream> 
#include <string>
#include "shellapi.h"
#include <shellapi.h>
#include <Windows.h>
#include <fstream>

//Nos classes
#include "Etudiant.h"
#include "Cours.h"
#include "Professeur.h"
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
	bool Modele::existenceFichier(const string& Name);
	void Modele::getNbCoursEtudiant(Etudiant e);
};

#endif