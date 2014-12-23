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

Cours Modele::getCoursAt(int i){
	return listecours.at(i);
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

bool Modele::estMemeCours(Cours c, Cours c2){
	if (c.getNomCours() == c2.getNomCours() && c.getMaxEtudiant() == c2.getMaxEtudiant()){
		return true;
	}
	else{
		return false;
	}
}

void Modele::supprimerCours(Cours c){
	//int i = listecours.find_if(c);
	int deleted;
	for (int i = 0; i < listecours.size(); i++){
		if (estMemeCours(listecours.at(i), c)){
			deleted = i;
		}

		
	}
	listecours.erase(listecours.begin() + deleted);
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
	return 0;
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

	return false;

}

