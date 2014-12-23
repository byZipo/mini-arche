#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string
#include "Ressource.h"



class URL : public Ressource{

public:
	virtual std::string getType();
private :
	std::string url;
	
};