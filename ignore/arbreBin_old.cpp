#include "../include/arbreBin.hpp"
#include <algorithm>

ArbreBin::ArbreBin(){
    this->valeur = "";
    this->leftChild = NULL;
    this->rightChild = NULL;
}

ArbreBin::ArbreBin(vector<string> v){
	int taille = v.size();
	if(taille > 0){
		
	}else{
		this->valeur = "";
	    this->leftChild = NULL;
	    this->rightChild = NULL;
	}
}

int ArbreBin::insere_dans_dict(string mot){
	Noeud *nNoeud = new Noeud(mot);
	Noeud *tmp = this->racine;
	Noeud *mCourrant = this->racine;
	if(mCourrant->enfants.size() == 1 || mCourrant->enfants.size() == 0){
		std::cout << "Première condition vérifiée..." << std::endl;
		std::cout << "Racine = " << this->racine->getValeur() << std::endl;
		mCourrant->addEnfant(nNoeud);sort(mCourrant->enfants.begin(), mCourrant->enfants.end());
		return 1;
	}else{
		std::cout << "Seconde condition vérifiée...";
		while(mCourrant->enfants.size() == 2){
			mot > *mCourrant->enfants.at(1) ? *mCourrant = mCourrant->enfants.at(1) : *mCourrant = mCourrant->enfants.at(0);	
			std::cout << "mot sélectionné: " << mCourrant->getValeur() << endl;
		}
		if(mCourrant->enfants.size() == 1 || mCourrant->enfants.size() == 0){
			std::cout << "Troisieme condition vérifiée...Courant = " << mCourrant->getValeur() << " ;" << endl;
			std::cout << "Racine = " << this->racine->getValeur() << endl;
			mCourrant->addEnfant(nNoeud);
			sort(mCourrant->enfants.begin(), mCourrant->enfants.end());
			*this->racine = *tmp;
			std::cout << "woo"<< endl;
			return 1;
		}
	}
	std::cout << "no action detected..." << std::endl;
}

void ArbreBin::affiche(){
    if(this->racine != NULL){
    	std::cout << "Début:" << std::endl;
    	this->racine->afficheNoeud();
    	std::cout << "Fin!" << std::endl;
    }else{
    	std::cout << "Arbre vide..." << std::endl;
    }
}