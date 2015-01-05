#include "stdafx.h"
#include "PDF.h"

using namespace std;

/*PDF::PDF(string chemin, string nom){
	this->nom = nom;
	this->chemin = chemin;
}
*/
string PDF::getType(){
	type = "PDF";
	return type;
}