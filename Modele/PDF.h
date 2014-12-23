#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Ressource.h"

class PDF : public Ressource{

public:
	virtual std::string getType();
private:
	std::string chemin;
	std::string nom;
};