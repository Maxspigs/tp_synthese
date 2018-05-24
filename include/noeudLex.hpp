#include <iostream>
#include <vector>
using namespace std;
struct NoeudLex {
  char lettre;
  NoeudLex* parent;
  map<char, NoeudLex*> enfants;
  NoeudLex(string val = '',NoeudLex *n = NULL){
  	lettre = val;
  	parent = n;
  	enfants = NULL;
  };
  void addChild(NoeudLex *n){
  	enfants.insert({n->lettre,n});
  };
  void afficheNoeud(){

  }
};