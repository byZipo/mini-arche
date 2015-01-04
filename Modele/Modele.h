#ifndef MODELE_H
#define MODELE_H

//Libraires
#include <iostream> 
#include <string>
#include "shellapi.h"
#include <shellapi.h>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <chrono>

//Nos classes
#include "Etudiant.h"
#include "Cours.h"
#include "Professeur.h"
#include "Ressource.h"
#include "URL.h"
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
	Professeur Modele::getProfesseur(string nom);
	Etudiant Modele::getEtudiant(string nom);
	bool Modele::estProfesseur(string nom);
	bool Modele::estMemeCours(Cours c, Cours c2);
	void supprimerCours(Cours c);
	Cours Modele::getCoursAt(int i);
	vector<Cours> Modele::getListeCours();
	string Modele::donneExtension(string str);
	bool Modele::existenceFichier(const string& Name);
	int Modele::getNbCoursEtudiant(Etudiant e);
	vector<Cours> Modele::getListeCoursEtudiant(Etudiant e);
	string Modele::getDateDuJour();
	Cours Modele::getCours(string nom);
	void Modele::ajouterProf(Professeur prof);
	void Modele::ajouterEtudiant(Etudiant etu);
	bool Modele::estEtudiant(string nom);

};

#endif