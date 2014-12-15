#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string


class Etudiant {

	std::string nom;
	std::string prenom;

	std::string getNom();

	void setNom(std::string chaine);

	std::string getPrenom();

	void setPrenom(std::string chaine);
};