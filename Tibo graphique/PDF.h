#ifndef PDF_H
#define PDF_H

//Libraires
#include <iostream>
#include <string>

//Nos classes
#include "Ressource.h"

using namespace std;

class PDF : public Ressource{

public:
	//PDF(string, string);
	virtual string getType();
private:
	string chemin;
	string nom;
};

#endif