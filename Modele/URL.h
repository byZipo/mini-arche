#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Ressource.h"



class URL : public Ressource{

public:
	virtual std::string getType();
	URL(std::string, std::string);
private :
	std::string url;
	std::string nom;

	
};