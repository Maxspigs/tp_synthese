#include <iostream>
#include "../include/arbreLex.hpp"
#include "../include/arbreBin.hpp"

using namespace std;

int main(){
    //Noeud *noeud = new Noeud('!', 0, 0, 0);
    //noeud->afficheValeur();
    Noeud *n2 = new Noeud("toto");
    ArbreBin *a1 = new ArbreBin();
    
    ArbreLex *dictionnaire = new ArbreLex();
    
    cout << "test " << dictionnaire->estVide() << endl;
}