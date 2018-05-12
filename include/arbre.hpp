#ifndef ARBRE_HPP
  #define ARBRE_HPP

#include "noeud.hpp"

class Arbre {

    Noeud* noeud;

    // Sert à obliger les enfants d'implanter affiche avant de compiler.
    virtual void affiche()=0;

};

#endif