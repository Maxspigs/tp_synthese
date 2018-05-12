#include <iostream>
#include "../include/arbreLex.hpp"
#include "../include/arbreBin.hpp"

using namespace std;

int main(){
    //Noeud *noeud = new Noeud('!', 0, 0, 0);
    //noeud->afficheValeur();
    vector<string> v1;
    v1.push_back("toto");
    v1.push_back("tata");
    v1.push_back("titi");
    Noeud *n2 = new Noeud("toto");
    ArbreBin *a1 = new ArbreBin(v1);
   	a1->affiche();
    ArbreLex *dictionnaire = new ArbreLex();
    
    cout << "test " << dictionnaire->estVide() << endl;
}