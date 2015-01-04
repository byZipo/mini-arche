#include "stdafx.h"
#include "Professeur.h"

using namespace std;

Professeur::Professeur(string nom, string prenom, string mdp){
	this->setNom(nom);
	this->setPrenom(prenom);
	this->setMotDePasse(mdp);
}