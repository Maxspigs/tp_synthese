#include "../include/arbreBin.hpp"

ArbreBin::ArbreBin(){
    this->racine = NULL;
}

int ArbreBin::insere_dans_dict(string mot){
	/**
	if(this->racine != NULL){
		Noeud mCourrant = this->racine;
		if(mCourrant.getEnfants)
	}else{
		this->racine = new Noeud(mot);
	}
	**/
	return 0;
}

ArbreBin::ArbreBin(vector<string> v){
	this->racine = new Noeud(v.at(0));
}

void ArbreBin::affiche(){
    std::cout << this->racine->getValeur() << std::endl;
}