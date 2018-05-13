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
    int *compteurBin;
    Noeud(string val);
    Noeud(int *i);
    vector<Noeud> enfants;
    void addEnfant(Noeud *n);
    void afficheNoeud();
    Noeud();
    string getValeur();
    bool operator<(const Noeud &n);
    bool operator>(const Noeud &n);
    string operator*();
    bool operator==(const Noeud &n);
  };

#endif