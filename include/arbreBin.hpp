#ifndef ARBREBIN_HPP
  #define ARBREBIN_HPP

#include "arbre.hpp"
#include <vector>

class ArbreBin : public Arbre {
public:
    ArbreBin();
    ArbreBin(vector<string>);
    void affiche();
};
#endif