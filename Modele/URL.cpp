#include "stdafx.h"
#include "URL.h"

using namespace std;

string URL::getType(){
	type = "URL";
	return type;
}

URL::URL(string adresse, string libelle){
	this->url = adresse;
	this->nom = libelle;

}