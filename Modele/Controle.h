#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Ressource.h"
#include <vector>

class Controle : public Ressource{


public:
	virtual std::string getType();
private:
	std::string chemin;
	std::string nom;
	std::vector<std::string> listequestions;
	std::vector<std::string> listeprincipale;
	std::vector<std::string> listechoix;
}; 
