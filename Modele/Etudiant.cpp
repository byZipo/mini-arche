#include "stdafx.h"
#include "Etudiant.h"

using namespace std;

Etudiant::Etudiant(string nom, string prenom, string mdp){
	this->setNom(nom);
	this->setPrenom(prenom);
	this->setMotDePasse(mdp);
}