#ifndef ARBREBIN_HPP
  #define ARBREBIN_HPP

#include "arbre.hpp"
#include <vector>

class ArbreBin : public Arbre {
private:
public:
    ArbreBin();
    ArbreBin(vector<string>);
    void affiche();
    int insere_dans_dict(string);
};
#endif