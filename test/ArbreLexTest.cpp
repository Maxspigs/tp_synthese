#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../include/noeudLex.hpp"

using namespace std;

struct Noeud {
  char lettre;
  map<char, Noeud*> enfants;
};

class ArbreLex {
  public:
    ArbreLex() { racine.lettre = '!'; };
    ArbreLex(vector<string> mots);
    ~ArbreLex();

    
    void insere_dans_dict(string mot);
    void Appartient(string mot, bool &result);

    void print_tree(map<char, Noeud*> tree);
    void print();
    
    //void parcours_le_dict(Noeud* arbre);
    void AfficherMotsLongueur(int longueurDonnee);
  protected:
    Noeud racine;
    // Keep all newly created node in an array, for the ease of
    // memory release.
    vector<Noeud*> enfants;
    Noeud* noeudFin();
};

ArbreLex::~ArbreLex() {
  for (int i=0; i<enfants.size(); ++i) {
    delete enfants[i];
  }
}

ArbreLex::ArbreLex(vector<string> mots) {
  racine.lettre = '!';
  for (auto i : mots) {
    insere_dans_dict(i);
  }
}

void ArbreLex::insere_dans_dict(string mot) {
  map<char, Noeud*> *arbreLex = &racine.enfants;
  map<char, Noeud*>::iterator it;

  for (int i=0; i<mot.length(); ++i) {
    char lettre = mot[i];

    if ((it = arbreLex->find(lettre)) != arbreLex->end()) {
      arbreLex = &it->second->enfants;
      continue;
    }

    if (it == arbreLex->end()) {
      // Display inserting position in the tree, for debug use
      //
      // cout << "Inserting " << lettre << endl;
      // cout << "on layer " << endl;
      // map<char, Node*>::iterator temp = arbreLex->begin();
      // for (; temp != arbreLex->end(); ++temp)
      //   cout << temp->first << endl;

      Noeud* nouveauNoeud = new Noeud();
      nouveauNoeud->lettre = lettre;
      (*arbreLex)[lettre] = nouveauNoeud;

      // For continuous inserting a mot.
      arbreLex = &nouveauNoeud->enfants;

      // For the ease of memory clean up.
      enfants.push_back(nouveauNoeud);
    }
  }
}

Noeud* ArbreLex::noeudFin(){
  Noeud* nouveauNoeud = new Noeud();
  nouveauNoeud->lettre = '\0';
  return nouveauNoeud;
}

void ArbreLex::Appartient(string mot, bool &result) {
  map<char, Noeud*> arbreLex = racine.enfants;
  map<char, Noeud*>::iterator it;

  for (int i=0; i<mot.length(); ++i) {
    if ((it = arbreLex.find(mot[i])) == arbreLex.end()) {
      result = false;
      return;
    }
    arbreLex = it->second->enfants;
  }
  result = true;
  return ;
}

void ArbreLex::AfficherMotsLongueur(int longueurDonnee){
  
}

void ArbreLex::print_tree(map<char, Noeud*> arbre) {
  if (arbre.empty()) {
    return;
  }

  for (map<char, Noeud*>::iterator it=arbre.begin(); it!=arbre.end(); ++it) {
    cout << it->first << endl;
    print_tree(it->second->enfants);
  }
}

void ArbreLex::print() {
  map<char, Noeud*> arbreLex = racine.enfants;
  print_tree(arbreLex);
}


/*void ArbreLex::parcours_le_dict(Noeud* arbre)
{
    
}*/

int main(int argc, char** argv)
{
  vector<string> mots; // {, , , };
  mots.push_back("face");
  mots.push_back("fac");
  mots.push_back("donc");
  mots.push_back("dons");
  mots.push_back("fou");
  mots.push_back("dont");
  mots.push_back("fais");
  mots.push_back("don");
  mots.push_back("foo");
  mots.push_back("bar");
  mots.push_back("baz");
  mots.push_back("barz");
  ArbreLex *dictionnaire = new ArbreLex(mots);
  //ArbreLex.ArbreLe(mots);
  cout << "All nodes..." << endl;
  dictionnaire->print();

  cout << "Appartienting..." << endl;
  bool estPresentDansArbreLexciographique = false;
  dictionnaire->Appartient("foo", estPresentDansArbreLexciographique);
  cout << "foo " << estPresentDansArbreLexciographique << endl;

  dictionnaire->Appartient("fooz", estPresentDansArbreLexciographique);
  cout << "fooz " << estPresentDansArbreLexciographique << endl;

  dictionnaire->Appartient("bar", estPresentDansArbreLexciographique);
  cout << "bar " << estPresentDansArbreLexciographique << endl;

  dictionnaire->Appartient("baz", estPresentDansArbreLexciographique);
  cout << "baz " << estPresentDansArbreLexciographique << endl;

  dictionnaire->Appartient("barzz", estPresentDansArbreLexciographique);
  cout << "barzz " << estPresentDansArbreLexciographique << endl;;

  dictionnaire->Appartient("bbb", estPresentDansArbreLexciographique);
  cout << "bbb " << estPresentDansArbreLexciographique << endl;;
  
  dictionnaire->print();
 //dictionnaire->parcours_le_dict();
  return 0;
}