#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#ifndef RESSOURCE_H
#define RESSOURCE_H

class Ressource{
protected :
	int note;
	bool publication;
	std::string type;
public :
	bool contientnote();
	
	bool estpubliee();
	void setPublie();
	int getNote();
	virtual std::string getType();
	void setNote(int newnote);
};

#endif;