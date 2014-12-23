#ifndef PDF_H
#define PDF_H

//Libraires
#include "stdafx.h"
#include <iostream>
#include <string>

//Nos classes
#include "Ressource.h"

using namespace std;

class PDF : public Ressource{

public:
	virtual string getType();
private:
	string chemin;
	string nom;
};

#endif