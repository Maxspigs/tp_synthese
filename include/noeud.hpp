#ifndef NOEUD_HPP
  #define NOEUD_HPP
  
#include <iostream>
#include <vector>

using namespace std;

class Noeud
  {
    private :
      string valeur;
    
    public :

    Noeud(string val);
    vector<Noeud> enfants;
    void addEnfant(Noeud *n);
    string getValeur();
    bool operator<(const Noeud &n);
    bool operator>(const Noeud &n);
    bool operator==(const Noeud &n);
  };

#endif