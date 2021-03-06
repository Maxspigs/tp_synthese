#include "../include/noeud.hpp"
/**
Noeud::Noeud(char lettre, Noeud *parent, Noeud *fils , Noeud *frere){
    this->lettre = lettre;
    this->fils = fils;
    this->frere = frere;
    this->parent = parent;
}
void Noeud::afficheValeur(){
    cout << "Le contenu de la lettre est : " << this->lettre << endl;
    cout << "Le contenu de fils est : " << this->fils << endl;
    cout << "Le contenu de frere est : " << this->frere << endl;
}
**/
//Constructeur
Noeud::Noeud(int *i){
	this->valeur = "";
	*this->compteurBin = 0;
}
Noeud::Noeud(string val){
	this->valeur = val;
	*this->compteurBin++;
}
//N'effectue aucune vérification sur l'ordre des enfants
void Noeud::addEnfant(Noeud *n){
	this->enfants.push_back(*n);
}
//Fonction d'accès à la valeur du noeud
string Noeud::getValeur(){
	return this->valeur;
}
//Mindfuck
void Noeud::afficheNoeud(){
	if(this->valeur == ""){
		std::cout << "RACINE" << " {";
	}else{
		std::cout << this->valeur << " {";
	}
	for(int i = 0; i < this->enfants.size(); i++){
		this->enfants.at(i).afficheNoeud();
		cout << " " << endl; 
	}
	std::cout << "}";
}

string Noeud::operator*(){
	return this->valeur;
}

bool Noeud::operator<(const Noeud &n){
	return this->valeur < n.valeur;
}

bool Noeud::operator>(const Noeud &n){
	return this->valeur > n.valeur;
}

bool Noeud::operator==(const Noeud &n){
	return this->valeur == n.valeur;
}