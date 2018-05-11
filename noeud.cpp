#include ".\noeud.hpp"


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