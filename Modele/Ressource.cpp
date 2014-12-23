#include "stdafx.h"
#include "Ressource.h"
#include <iostream>

using namespace std;
	int note;
	bool publication;

	bool Ressource::contientnote(){

		if (note){
			return true;
		}else{
			return false;
		}
	}

	bool Ressource::estpubliee(){
		return publication;
	}

	string Ressource::getType(){
		return type;
	}
	int Ressource::getNote(){
		return note;
	}
     
	void Ressource::setNote(int newnote){
		note = newnote;
	}
     
	void Ressource::setPublie(){
		publication = true;
	}
      

