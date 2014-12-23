#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#ifndef RESSOURCE_H
#define RESSOURCE_H

class Ressource{
private :
	int note;
	bool publication;
	//const char* type;
public :
	bool contientnote();
	
	bool estpubliee();

	void setPublie();
	int getNote();

	void setNote(int newnote);
};

#endif;