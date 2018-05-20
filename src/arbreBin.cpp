#include "../include/arbreBin.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;
inline bool ArbreBin::appartient(string mot){return this->parcours_le_dict(mot) != NULL;};
inline bool ArbreBin::estVide(){return this->compteurMots == 0;};
ArbreBin::ArbreBin(){
	racine = new NoeudBin();
}

ArbreBin::ArbreBin(vector<string> v){
	int taille = v.size();
	if(taille > 0){
		racine = new NoeudBin(v.at(0));
		this->compteurMots++;
		for (vector<string>::iterator i = v.begin() + 1; i != v.end(); ++i)	{
			this->insere_dans_dict(*i);
		}
	}
	else{
		racine = new NoeudBin();
	}
}

//Insertion préfixe
int ArbreBin::insere_dans_dict(string mot){
	NoeudBin *nouvMot = new NoeudBin(mot);
	if(racine->valeur == ""){
		racine = nouvMot;
		this->compteurMots++;
		return 1;
	}
	if(!this->appartient(mot)){
		NoeudBin *nCourrant;
		nCourrant = racine;
		while(true){
			if(mot < nCourrant->valeur){
				if(nCourrant->leftChild == NULL){
					nCourrant->setLeftChild(nouvMot);
					this->compteurMots++;
					return 1;
				}
				else{
					nCourrant = nCourrant->leftChild;
				}
			}
			else{
				if(nCourrant->rightChild == NULL){
					nCourrant->setRightChild(nouvMot);
					this->compteurMots++;
					return 1;
				}else{
					nCourrant = nCourrant->rightChild;
				}
			}
		}
	}
	return 0;
}

vector<string> ArbreBin::getAllMots(){
	vector<string> mots;
	if(racine->valeur != ""){
		mots = racine->getAll();
	}
	sort(mots.begin(),mots.end());
	return mots;
}

NoeudBin* ArbreBin::parcours_le_dict(string mot){
	if(racine->valeur != ""){
		NoeudBin *nCourrant;
		nCourrant = racine;
		int compteur = 0;
		while(true){
			compteur++;
			if(nCourrant->valeur == mot){
				return nCourrant;
			}
			else if(nCourrant->leftChild != NULL && nCourrant->leftChild->valeur < mot){
				nCourrant = nCourrant->leftChild;
			}
			else if(nCourrant->rightChild != NULL && nCourrant->rightChild->valeur > mot){
				nCourrant = nCourrant->rightChild;
			}
			else{
				return NULL;
			}
		}
	}
	return NULL;
}

void ArbreBin::sauvegarde(string fichier){
	ofstream ostream(fichier);
	vector<string> vecTmp = this->getAllMots();
	for (vector<string>::iterator i = vecTmp.begin(); i != vecTmp.end(); ++i) {
		string stmp = *i + ";";
		ostream << stmp;
	}
	ostream.close();
}

void ArbreBin::lecture(string fichier){
	ifstream istream(fichier);
	string stmp;
	int idx = 0;
	while(istream >> stmp){
		for(int i = 0; i < stmp.length(); ++i){
			if (stmp.at(i) == ';'){
				this->insere_dans_dict(stmp.substr(idx,i-idx));
				idx = i+1;
			}
		}
	}
}

void ArbreBin::afficherMotsLongueur(int longueur){
	cout << "Mots de longueur " << longueur << " :" << endl;
	vector<string> mots = this->getAllMots();
	for (vector<string>::iterator i = mots.begin(); i != mots.end(); ++i) {
		if(i->length() == longueur){
			cout << *i << " ";
		}
	}
	cout << " " << endl;
	cout << "Fin" << endl;
}
void ArbreBin::afficherMotsPrefixe(string prefixe){
	cout << "Mots avec le préfixe " << prefixe << ":";
	vector<string> mots = this->getAllMots();
	for (vector<string>::iterator i = mots.begin(); i != mots.end(); ++i) {
		if(i->substr(0,prefixe.length()) == prefixe){
			cout << *i << " ";
		}
	}
	cout << " " << endl;
	cout << "Fin" << endl;
}

int ArbreBin::getNbMots(){
	return this->compteurMots;
}

void ArbreBin::affiche(){
	if(racine->valeur != ""){
		racine->afficheNoeud();
	}
}