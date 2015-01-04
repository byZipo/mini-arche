#include "stdafx.h"
#include "Devoir.h"

using namespace std;

Devoir::Devoir(string chemin, string nom){
	this->nom = nom;
	this->chemin = chemin;
}

string Devoir::getType(){
	type = "DEV";
	return type;
}