/* 
    Code du professeur
    C'est un programme qui provient du C et on doit le modifier pour le rendre C++ compatible.
    Il faut transformer ce programme en orienté objet.
*/
#include <iostream>
#include <stack>

using namespace std;

typedef struct noeud
{
    char lettre;
    struct noeud *fils, *frere;
} UN_NOEUD, *PTRdeNOEUD;

static struct
{
    char lettres[80];
    int n;
} pile;

PTRdeNOEUD noeud(char lettre, PTRdeNOEUD fils, PTRdeNOEUD frere)
{
    //PTRdeNOEUD p = (PTRdeNOEUD)(malloc(sizeof(UN_NOEUD)));
    PTRdeNOEUD p = new UN_NOEUD();
    p->lettre = lettre;
    p->fils = fils;
    p->frere = frere;
    return p;
}
int insere_dans_dict(const char mot[], PTRdeNOEUD ascendant)
{
    PTRdeNOEUD pr, pc;
    int i;
    for (i = 0;; i++)
    {
        pr = NULL;
        pc = ascendant->fils;
        while (pc != NULL && pc->lettre < mot[i])
        {
            pr = pc;
            pc = pc->frere;
        }
        if (pc != NULL && pc->lettre == mot[i])
        {
            if (mot[i] == '\0')
                return 1; /* le mot existait */
            ascendant = pc;
        }
        else
        {
            pc = noeud(mot[i], NULL, pc);
            if (pr != NULL)
                pr->frere = pc;
            else
                ascendant->fils = pc;
            while (mot[i] != '\0')
            {
                pc->fils = noeud(mot[++i], NULL, NULL);
                pc = pc->fils;
            }
            return 0; /* le mot est nouveau */
        }
    }
    
}
void parcours_le_dict(PTRdeNOEUD arbre)
{
    PTRdeNOEUD p;
    pile.lettres[pile.n++] = arbre->lettre;
    if (arbre->lettre == '\0')
        printf("%s\n", pile.lettres + 1);
    else
        for (p = arbre->fils; p != NULL; p = p->frere)
            parcours_le_dict(p);
    pile.n--;
}

int main(int argc, char *argv[])
{
    // ArbreLex a(’!’); ou ArbreBin a( NULL ); en C++
    PTRdeNOEUD racine = noeud('!', NULL, NULL);
    insere_dans_dict("face", racine);
    insere_dans_dict("fac", racine);
    // a.insere_dans_dict ("donc"); en C++
    insere_dans_dict("donc", racine);
    insere_dans_dict("dons", racine);
    insere_dans_dict("fou", racine);
    pile.n = 0;
    //a.parcours_le_dict(); en C++
    cout << "Début du parcours" << endl;
    parcours_le_dict(racine);
    insere_dans_dict("dont", racine);
    insere_dans_dict("faim", racine);
    insere_dans_dict("fais", racine);
    insere_dans_dict("don", racine);
    pile.n = 0;
    cout << "Début du parcours 2e" << endl;
    parcours_le_dict(racine);
}