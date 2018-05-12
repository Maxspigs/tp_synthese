#include <iostream>
#include "noeud.hpp"

using namespace std;

int main(){
    Noeud *noeud = new Noeud('!', 0, 0, 0);
    noeud->afficheValeur();
}