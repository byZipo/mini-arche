#include "stdafx.h"
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

bool Modele::existenceFichier(const string& Name){
	ifstream f(Name.c_str());
	return f.is_open();
}

bool Modele::verifPDFValide(string chemin){
	if ((existenceFichier(chemin)) && (donneExtension(chemin) == "pdf")){
		return true;
	}
	else{
		return false;
	}
}

bool Modele::verifDevoirValide(string chemin){
	if ((existenceFichier(chemin)) && ((donneExtension(chemin) == "txt") || (donneExtension(chemin) == "doc") || (donneExtension(chemin) == "docx") || (donneExtension(chemin) == "odt"))){
		return true;
	}
	else{
		return false;
	}
}

int Modele::getNbCoursEtudiant(Etudiant e){
	int var = 0;
	for (unsigned i = 0; i < listeCours.size(); i++){
		for (int j = 0; j < getCoursAt(i).getTailleListePrincipale(); j++){
			if (getCoursAt(i).getEtudiant(j).getNom() == e.getNom()){
				var++;
			}
		}
	}
	return var;
}

vector<Cours> Modele::getListeCoursEtudiant(Etudiant e){
	cout << "L'etudiant " << e.getPrenom() << " est inscrit(e) au(x) cour(s) suivant : \n" << endl;
	vector<Cours> *listeCoursEtudiant = new vector<Cours>();
	for (unsigned i = 0; i < listeCours.size(); i++){
		for (int j = 0; j < getCoursAt(i).getTailleListePrincipale(); j++){
			if (getCoursAt(i).getEtudiant(j).getNom() == e.getNom()){
				listeCoursEtudiant->push_back(getCoursAt(i));
				cout << getCoursAt(i).getNomCours() << endl;
			}
		}
	}
	cout << "\n" << endl;
	return *listeCoursEtudiant;
}

string Modele::getDateDuJour(){
	struct tm Today;
	time_t maintenant = time(&maintenant);
	localtime_s(&Today, &maintenant);
	int d = Today.tm_mday;
	int m = Today.tm_mon + 1;
	int y = Today.tm_year + 1900;
	string s = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
	return s;
	//printf("%2.2d / %2.2d / %4.4d \n", Today.tm_mday, Today.tm_mon + 1, Today.tm_year + 1900);
}