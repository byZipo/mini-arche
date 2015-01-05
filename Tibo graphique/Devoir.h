#ifndef DEVOIR_H
#define DEVOIR_H

//Librairies
#include <iostream>
#include <string>

//Nos classes
#include "Ressource.h"

using namespace std;

class Devoir : public Ressource{

public:
	//Devoir(string, string);
	virtual std::string getType();
private :
	std::string chemin;
	std::string nom;
};

#endif;