#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Cours.h"

class PDF : public Cours{
private:
	std::string chemin;
	std::string nom;
};