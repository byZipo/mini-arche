#include "Modele.h"

using namespace std;

void Modele::getListeCours(){
	printf("Les cours disponible sur Arche sont :\n");
	for (unsigned i = 0; i < listeCours.size(); i++){
		cout << getCoursAt(i).getNomCours() << endl;
	}
}

Cours Modele::getCoursAt(int i){
	return listeCours.at(i);
}

void Modele::ajouterCours(Cours cours){
	listeCours.push_back(cours);
}

bool Modele::estDisponible(string nom){
	bool dispo = true;
	for (unsigned i = 0; i<listeCours.size(); i++){
		if (listeCours.at(i).getNomCours().compare(nom) == 0){
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
	for (unsigned i = 0; i < listeCours.size(); i++){
		if (estMemeCours(listeCours.at(i), c)){
			deleted = i;
		}

		
	}
	listeCours.erase(listeCours.begin() + deleted);
}

Professeur Modele::getProfesseur(string nom, string prenom){
	for (unsigned i= 0; i<profs.size(); i++){
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
	for (unsigned i = 0; i<etudiants.size(); i++){
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

string Modele::donneExtension(string str){
	string str1;
	int size = str.size();
	for (int i = 0; i < size; i++){
		if (str[i] == '.'){
			str1 = str.substr(i+1, size);
		}
	}
	return str1;
}

bool Modele::verifPDFValide(string chemin){

	if(32 >= (int)ShellExecuteA(NULL, "open", chemin.c_str(), "", NULL, SW_NORMAL)){
		return false;
	}
	else{
		if(donneExtension(chemin) == "pdf"){
			return true;
		}
		else{
			return false;
		}
	}
}

bool Modele::verifDevoirValide(string chemin){

	if (32 >= (int)ShellExecuteA(NULL, "open", chemin.c_str(), "", NULL, SW_NORMAL)){
		return false;
	}
	else{
		return true;
	}
}