#include "../include/arbreBin.hpp"
#include <algorithm>

ArbreBin::ArbreBin(){
    this->racine = NULL;
}

int ArbreBin::insere_dans_dict(string mot){
	if(this->racine != NULL){
		Noeud *nNoeud = new Noeud(mot);
		Noeud *mCourrant = this->racine;
		for(int i = 0; i < mCourrant->enfants.size(); i++){
			if(*nNoeud < mCourrant->enfants.at(i)){
				*mCourrant = mCourrant->enfants.at(i);
			}
		}
		mCourrant->addEnfant(nNoeud);
		sort(mCourrant->enfants.begin(),mCourrant->enfants.end());
		return 1;
	}else{
		this->racine = new Noeud(mot);
		return 1;
	}
	return 0;
}

ArbreBin::ArbreBin(vector<string> v){
	this->racine = new Noeud(v.at(0));
}

void ArbreBin::affiche(){
    std::cout << this->racine->getValeur() << std::endl;
}