#ifndef ARBREBIN_HPP
  #define ARBREBIN_HPP

#include "arbre.hpp"
#include "noeudBin.hpp"
#include <vector>

class ArbreBin : public Arbre {
private:
	int compteurMots = 0;
public:
	NoeudBin *racine;
    ArbreBin();
    ArbreBin(vector<string>);
    void affiche();
    int insere_dans_dict(string);
    int getNbMots();
    NoeudBin* parcours_le_dict(string);
    vector<string> getAllMots();
    void sauvegarde(string);
    void lecture(string);
    void afficherMotsLongueur(int);
    void afficherMotsPrefixe(string);
    inline bool appartient(string);
    inline bool estVide();
};
#endif