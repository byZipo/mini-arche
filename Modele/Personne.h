#ifndef PERSONNE_H
#define PERSONNE_H

//Libraires
#include "stdafx.h"
#include <iostream>
#include <string>

//Nos classes


using namespace std;

class Personne{
private :
	string nom;
	string prenom;

	
public :
	string Personne::getNom();
	void Personne::setNom(string chaine);
	string Personne::getPrenom();
	void Personne::setPrenom(string chaine);
};

#endif