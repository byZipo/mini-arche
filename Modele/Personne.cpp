#include "stdafx.h"
#include "Personne.h"

using namespace std;

string Personne::getNom(){
	return nom;
}

void Personne::setNom(string chaine){
	nom = chaine;
}

string Personne::getPrenom(){
	return prenom;
}

void Personne::setPrenom(string chaine){
	prenom = chaine;	
}

void Personne::setMotDePasse(string chaine){
	motdepasse = chaine;
}