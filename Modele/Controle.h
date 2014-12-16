#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Cours.h"


class Controle : public Cours{
private:
	std::string chemin;
	std::string nom;
	std::list<std::string> listequestions;
	std::list<std::string> listeprincipale;
	std::list<std::string> listechoix;
}; 
