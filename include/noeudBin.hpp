#include <iostream>
#include <vector>
using namespace std;
struct NoeudBin {
	string valeur;
	NoeudBin *leftChild;
	NoeudBin *rightChild;
	NoeudBin(string val = ""){
		valeur = val;
		leftChild = NULL;
		rightChild = NULL;
	};
	void setLeftChild(NoeudBin *n){
		leftChild = n;
	};
	void setRightChild(NoeudBin *n){
		rightChild = n;
	};
	void afficheNoeud(){
		cout << valeur << " {" << endl;
		if(leftChild != NULL){
			cout << "	";
			leftChild->afficheNoeud();
		}
		if(rightChild != NULL){
			rightChild->afficheNoeud();
		}
		cout << "}";
	};
	vector<string> getAll(){
		vector<string> retour;
		retour.push_back(valeur);
		if(leftChild != NULL){
			vector<string> vecTmp = leftChild->getAll();
			retour.insert(retour.end(),vecTmp.begin(),vecTmp.end());
		}
		if(rightChild != NULL){
			vector<string> vecTmp = rightChild->getAll();
			retour.insert(retour.end(),vecTmp.begin(),vecTmp.end());	
		}
		return retour;
	};
};