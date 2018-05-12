#ifndef ARBRE_HPP
  #define ARBRE_HPP

#include "noeud.hpp"

class Arbre {
private:
   	// Sert à obliger les enfants d'implanter affiche avant de compiler.
public:
    Arbre(){};
    Arbre(vector<string>){};
    Noeud* racine;
    virtual void affiche()=0;
    virtual int insere_dans_dict(string)=0;
};

#endif