#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#ifndef PERSONNE_H
#define PERSONNE_H



class Personne{
	std::string nom;
	std::string prenom;

	std::string getNom();

	void setNom(std::string chaine);

	std::string getPrenom();

	void setPrenom(std::string chaine);
};

#endif