#ifndef URL_H
#define URL_H

//Libraires
#include <iostream>
#include <string>

//Nos classes
#include "Ressource.h"

using namespace std;

class URL : public Ressource{

public:
	URL(string, string);
	virtual string getType();
private :
	string url;
	string nom;

	
};

#endif