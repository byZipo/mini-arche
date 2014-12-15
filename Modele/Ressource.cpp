#include "stdafx.h"
#include "Ressource.h"
#include <iostream>

      
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

    
	int Ressource::getNote(){
		return note;
	}
     
	void Ressource::setNote(int newnote){
		note = newnote;
	}
      
      

