#include "stdafx.h"
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include "Etudiant.h"
#include "Cours.h"
#include "Modele.h"
#include <shellapi.h>
#include <Windows.h>

using namespace std;




void Modele::ajouterCours(Cours cours){
	Modele::listecours.push_back(cours);

}


bool Modele::estDisponible(string nom){
	bool dispo = true;
	for (int i = 0; i<listecours.size(); i++){
		if (listecours.at(i).getNomCours().compare(nom) == 0){
			dispo = false;
		}
	}
	return dispo;
}
	
bool Modele::verifUrlValide(string url){

	
	if (!url.empty()){

		if (32 <= (long)ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL)){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}

}

bool Modele::ListePrincipaleDisponible(Cours c){
	if (c.getMaxEtudiant() > c.getTailleListePrincipale()){
		return true;
	}
	else{
		return false;
	}

}

bool Modele::verifPDFValide(string chemin, string nom){



}