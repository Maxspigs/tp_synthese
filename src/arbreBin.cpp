#include "../include/arbreBin.hpp"
#include <algorithm>

ArbreBin::ArbreBin(){
    this->racine = new Noeud();
    std::cout << "taille enfants racine = " << this->racine->enfants.size() << ";";
    std::cout << "valeur noeud racine = " << this->racine->getValeur() << endl;
}

int ArbreBin::insere_dans_dict(string mot){
	std::cout << "entree fonction: " << mot << std::endl;
		Noeud *nNoeud = new Noeud(mot);
		Noeud *mCourrant = this->racine;
		bool aEteAjoute = false;
		std::cout << "tentative d'ajout du mot " << mot << std::endl;
		if(mCourrant == NULL){
			std::cout << "mCourrant == NULL..." << std::endl;
			Noeud *nNoeud = new Noeud(mot);
			mCourrant->addEnfant(nNoeud);
			std::cout << "mot " << mot << "ajouté" << std::endl;
			return 1;
		}
		if(this->racine->enfants.size() == 1){
			Noeud *nNoeud = new Noeud(mot);
			mCourrant->addEnfant(nNoeud);
			sort(mCourrant->enfants.begin(), mCourrant->enfants.end());
			return 1;
		}
		for(int i = 0; i < this->racine->enfants.size(); i++){
			Noeud *mCourrant = &this->racine->enfants.at(i);
			while(mCourrant->enfants.size() == 2){
				if(mCourrant->enfants.at(0) == mot || mCourrant->enfants.at(1) == mot){
					return 0;
				}
				if(*mCourrant < mCourrant->enfants.at(1)){
					*mCourrant = mCourrant->enfants.at(0);
					continue;
				}
				*mCourrant = mCourrant->enfants.at(1);
			}
			mCourrant->addEnfant(nNoeud);
			std::cout << "mot " << mot << " ajouté" << std::endl;
			sort(mCourrant->enfants.begin(), mCourrant->enfants.end());
			return 1;
		}
		/**
		while(){
			cout << "noeud observé..." << mCourrant->getValeur() << std::endl;
			switch(mCourrant->enfants.size()){
				case 0:
					std::cout << "mot " << mot << " ajouté" << std::endl;
					mCourrant->addEnfant(nNoeud);
					return 1;
				case 1:
					if(mCourrant->enfants.at(0) == mot){return 0;}
					if(*mCourrant < mCourrant->enfants.at(0)){
						mCourrant->addEnfant(nNoeud);
						std::cout << "mot " << mot << " ajouté" << std::endl;
						sort(mCourrant->enfants.begin(), mCourrant->enfants.end());
						return 1;
					}
					*mCourrant = mCourrant->enfants.at(0);
					break;
				case 2:
					if(mCourrant->enfants.at(0) == mot || mCourrant->enfants.at(1) == mot){return 0;}
					if(*mCourrant < mCourrant->enfants.at(0)){
						*mCourrant = mCourrant->enfants.at(0);
						break;
					}else if(*mCourrant < mCourrant->enfants.at(1)){
						*mCourrant = mCourrant->enfants.at(1);
						break;
					}
				default:
					std::cout << "OOPSIE WOOPSIE!! Uwu We make a fucky wucky!! A wittle fucko boingo! The code monkeys at our headquarters are working VEWY HAWD to fix this!" << std::endl;
					break;
			}
		}
		**/
	/**
	else{
		this->racine = new Noeud();
		Noeud *nNoeud = new Noeud(mot);
		this->racine->addEnfant(nNoeud);
		std::cout << "mot " << mot << "ajouté" << std::endl;
		return 1;
	}
	**/
}

ArbreBin::ArbreBin(vector<string> v){
	this->racine = new Noeud();
    std::cout << "taille enfants racine = " << this->racine->enfants.size() << ";";
    std::cout << "valeur noeud racine = " << this->racine->getValeur() << endl;
	for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i){
		int tmp;
		tmp = this->insere_dans_dict(*i);
		std::cout << "résultat ajout " << *i << ": " << tmp << std::endl;
	}
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