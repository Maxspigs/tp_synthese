#include "../include/arbreLex.hpp"

ArbreLex::ArbreLex(){
	this->racine = 0;
}

ArbreLex::ArbreLex(vector<string> mots){
    this->racine = new Noeud("!");
    /*
    for (auto i : mots) {
       this->racine = new ArbreLex(i.substr(i,1));
       
       PTRdeNOEUD racine = noeud(’!’, NULL, NULL);
    }
    */
}

ArbreLex::ArbreLex(string racine){
    this->racine = new Noeud(racine);
}

void ArbreLex::affiche(){

}

bool ArbreLex::estVide(){
	return this->racine == 0 ? true : false;
}

void ArbreLex::effaceArbre(){
    
}
 
int ArbreLex::insere_dans_dict(string mot){
    for (int i = 0; i < mot.length(); i++) {
         Noeud *nouveauNoeud = new Noeud(mot.substr(i,1));
         this->racine->addEnfant(nouveauNoeud);
         //cout << "test -> " << mot.substr(i,1) << endl;
    }
}
 
/*
// Fonction qui retourne un vecteur qui contient les string provenant du fichier.
vector<string> ArbreLex::lecture(string filename) {
	ifstream file; // fichier sans être ouvert
	file.open(filename); // on tente d'ouvrir le fichier
	if (!file.is_open()) { // Si le fichier n'est pas ouvert
		exit(EXIT_FAILURE); // Sort du programme
	} 
	vector<string> v;

	int lineCount = 0;
	
	// On lit le fichier ligne par ligne
	while (getline(file, line)) {
		lineCount++;
	}

	file.close(); // Ferme le fichier
	return v;
}*/