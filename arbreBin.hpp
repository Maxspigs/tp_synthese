#ifndef ARBREBIN_HPP
  #define ARBREBIN_HPP

#include "./arbre.hpp"
#include <vector>

class ArbreBin : public Arbre {

    Noeud* racine;

    ArbreBin();

    ArbreBin(vector<string> v);

    void affiche();

};

#endif