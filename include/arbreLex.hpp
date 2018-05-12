#ifndef ARBRELEX_HPP
  #define ARBRELEX_HPP

#include "arbre.hpp"
#include <vector>

class ArbreLex : public Arbre {


	private :
     
    
    public :

    Noeud* racine;

    ArbreLex();

    ArbreLex(vector<string> mots);
    
    ArbreLex(string racine);

    int insere_dans_dict(string mot);

    void parcours_le_dict();

    void effaceMot(string mot);

    void affiche();

    bool estVide();

    void effaceArbre();

    void lecture();

    void sauvegarde();

    void appartient();

    void afficherMotsLongueur();

    void afficherMotsPrefixe();



};

#endif