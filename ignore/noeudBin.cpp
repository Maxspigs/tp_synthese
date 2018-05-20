#include "../include/noeudBin.hpp"
NoeudBin::NoeudBin(string val = ""){
	this->valeur = val;
	leftChild = NULL;
	rightChild = NULL;
}

NoeudBin::setLeftChild(NoeudBin *n){
	leftChild = n;
}

NoeudBin::setRightChild(NoeudBin *n){
	rightChild = n;
}