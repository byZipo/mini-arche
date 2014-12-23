#ifndef CONTROLE_H
#define CONTROLE_H

//Librairies
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

//Nos classes
#include "Ressource.h"
#include "Devoir.h"

using namespace std;

class Controle : public Ressource{


public:
	virtual string getType();
private:
	string chemin;
	string nom;
	vector<std::string> listequestions;
	vector<std::string> listeprincipale;
	vector<std::string> listechoix;
}; 

#endif