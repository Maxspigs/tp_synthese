#include <iostream>
#include <vector>
using namespace std;
struct NoeudLex {
  char lettre;
  map<char, NoeudLex*> enfants;
  NoeudLex(string val = ''){
  	lettre = val;
  	enfants = NULL;
  };
  void addChild(NoeudLex *n){
  	enfants.insert({n->lettre,n});
  };
};