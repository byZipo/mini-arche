
#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include "Personne.h"


	std::string nom;
	std::string prenom;

	std::string Personne::getNom(){
		return nom;
	}

	void Personne::setNom(std::string chaine){
		nom = chaine;
	}

	std::string Personne::getPrenom(){
		return prenom;
	}

	void Personne::setPrenom(std::string chaine){
		prenom = chaine;
	}

