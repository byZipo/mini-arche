#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Cours.h"



class Devoir : public Cours{
public :
	std::string chemin;
	std::string nom;
};