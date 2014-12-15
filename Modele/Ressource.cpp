#include "stdafx.h"
#include "Ressource.h"
#include <iostream>

      
	int note;
	bool publication;

	bool contientnote(){

		if (note){
			return true;
		}else{
			return false;
		}
	}

	bool estpubliee(){
		return publication;
	}

    
	int getNote(){
		return note;
	}
     
	void setNote(int newnote){
		note = newnote;
	}
      
      

