#ifndef ETUDIANT_H
#define ETUDIANT_H

//Libraires
#include <iostream>
#include <string>
#include <vector>
//Nos classes
#include "Personne.h"

using namespace std;

class Etudiant : public Personne{

public:
	Etudiant(string, string, string);

};
#endif