#include <iostream>
#include "../include/arbreLex.hpp"
#include "../include/arbreBin.hpp"

using namespace std;

int main(){
    //Noeud *noeud = new Noeud('!', 0, 0, 0);
    //noeud->afficheValeur();
    vector<string> v1;
    v1.push_back("bonjour");
    v1.push_back("jambon");
    v1.push_back("tortue");
    v1.push_back("elephant");
    v1.push_back("toto");
    v1.push_back("tata");
    v1.push_back("titi");
    v1.push_back("gogo");
    v1.push_back("gaga");
    v1.push_back("gigi");
    //a1->insere_dans_dict(*n2);
    ArbreBin *a1 = new ArbreBin();
    ArbreBin *a2 = new ArbreBin(v1);
    cout << "Il y a " << a2->getNbMots() << " mots dans l'arbre binaire a2" << endl;
    a2->insere_dans_dict("je");
    a2->insere_dans_dict("suis");
    a2->insere_dans_dict("une");
    a2->insere_dans_dict("crevette");    
    cout << "Il y a " << a2->getNbMots() << " mots dans l'arbre binaire a2" << endl;
    a2->affiche();
    vector<string> v2 = a2->getAllMots();
    for (std::vector<string>::iterator i = v2.begin(); i != v2.end(); ++i)
    {
        cout << "Mot:" << *i << endl;
    }
    a2->sauvegarde("../test/output.txt");
    cout << "Il y a " << a1->getNbMots() << " mots dans l'arbre binaire a1" << endl;
    a1->lecture("../test/output.txt");
    cout << "Il y a " << a1->getNbMots() << " mots dans l'arbre binaire a1" << endl;
    v2 = a1->getAllMots();
    for (std::vector<string>::iterator i = v2.begin(); i != v2.end(); ++i)
    {
        cout << "Mot:" << *i << endl;
    }
    ArbreLex *dictionnaire = new ArbreLex("!");
    
    cout << "test " << dictionnaire->racine->getValeur() << endl;
    
    dictionnaire->insere_dans_dict("pot");
    
    cout << "test " << dictionnaire->estVide() << endl;
}