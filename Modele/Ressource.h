#ifndef RESSOURCE_H
#define RESSOURCE_H

//Librairies
#include "stdafx.h"
#include <iostream>
#include <string>

//Nos classes


using namespace std;

class Ressource{
protected :
	int note;
	bool publication;
	string type;
	string nom;
public :
	bool contientnote();
	string getNom();
	bool estpubliee();
	void setPublie();
	int getNote();
	virtual string getType();
	void setNote(int newnote);
};

#endif;