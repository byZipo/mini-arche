/* je suis un prof */
#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 



class Professeur{
	std::string nom;
	std::string prenom;

	std::string getNom();
	void setNom(std::string chaine);

};