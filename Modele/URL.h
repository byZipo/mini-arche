#ifndef URL_H
#define URL_H

//Libraires
#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string

//Nos classes
#include "Ressource.h"

using namespace std;

class URL : public Ressource{

public:
	virtual string getType();
	URL(string, string);
private :
	string url;
	string nom;

	
};

#endif