#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#ifndef RESSOURCE_H
#define RESSOURCE_H

class Ressource{
private :
	int note;
	bool publication;
public :
	bool contientnote();

	bool estpubliee();


	int getNote();

	void setNote(int newnote);
};

#endif;