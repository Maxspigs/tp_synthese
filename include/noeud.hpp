#ifndef NOEUD_HPP
  #define NOEUD_HPP
  
#include <iostream>
#include <vector>

using namespace std;

class Noeud
  {
    private :
      string valeur;
      vector<Noeud> *enfants;
    
    public :

    Noeud(string val);
    
    vector<Noeud> getEnfants();
    string getValeur();
  };

#endif