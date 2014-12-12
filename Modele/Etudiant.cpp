#include <iostream> // pour std::cout 
#include <string>   // pour std::string 

class Etudiant {

      std::string nom;
      std::string prenom;
      
      std::string getNom(){
             return nom; 
       }      
      
      void setNom(std::string chaine){
             nom = chaine;
      }
      
      std::string getPrenom(){
             return prenom;
      }
      
      void setPrenom(std::string chaine){
           prenom = chaine;
      }
};




