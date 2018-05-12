#include "../include/arbreLex.hpp"

ArbreLex::ArbreLex(){
	this->racine = 0;
}
/*
ArbreLex::ArbreLex(vector<string> v){

}
*/
void ArbreLex::affiche(){

}

bool ArbreLex::estVide(){
	return this->racine == 0 ? true : false;
}
/*
 void effaceArbre(){

 }

// Fonction qui retourne un vecteur qui contient les string provenant du fichier.
vector<string> lireFichierInitial(string filename) {
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