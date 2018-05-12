#ifndef NOEUD_HPP
  #define NOEUD_HPP
  
#include <iostream>

using namespace std;

class Noeud
  {
    private :
     
    
    public :
        char lettre;
        Noeud *parent, *fils, *frere; 

    Noeud(char lettre, Noeud *parent, Noeud *fils, Noeud *frere);
    
    void afficheValeur();

    char getLettre();
  };

#endif