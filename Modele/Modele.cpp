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

void Modele::supprimerCours(Cours c){
	//int i = listecours.find_if(c);
	//listecours.erase(listecours.begin() + i);
}

Professeur Modele::getProfesseur(string nom, string prenom){
	for (int i = 0; i<profs.size(); i++){
		if (profs.at(i).getNom() == nom && profs.at(i).getPrenom() == prenom){
			return profs.at(i);
			
		}
	}

}

bool Modele::estProfesseur(){
	// Tester si est un prof ou est un eleve ou existe pas

}
Etudiant Modele::getEtudiant(string nom, string prenom){
	for (int i = 0; i<etudiants.size(); i++){
		if (etudiants.at(i).getNom() == nom && etudiants.at(i).getPrenom() == prenom){
			return etudiants.at(i);

		}
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

