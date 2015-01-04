#ifndef PERSONNE_H
#define PERSONNE_H

//Libraires
#include <iostream>
#include <string>

//Nos classes


using namespace std;

class Personne{
private :
	string nom;
	string prenom;
	string motdepasse;

	
public :
	string Personne::getNom();
	void Personne::setNom(string chaine);
	string Personne::getPrenom();
	void Personne::setPrenom(string chaine);
	void Personne::setMotDePasse(string chaine);
};

#endif