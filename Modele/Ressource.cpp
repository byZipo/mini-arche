#include "stdafx.h"
#include "Ressource.h"

using namespace std;

int note;
bool publication;

Ressource::Ressource(string nom, string type){
	this->type = type;
	this->nom = nom;
}

bool Ressource::contientnote(){
	if (note){
		return true;
	}
	else{
		return false;
	}
}

bool Ressource::estpubliee(){
	return publication;
}

string Ressource::getNom(){
	return nom;
}

string Ressource::getType(){
	//type = "RES";
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