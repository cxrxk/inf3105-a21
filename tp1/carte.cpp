/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#include "carte.h"
#include <cmath>
#include <istream>
#include <limits>
#include <string> 
#include <sstream>

Tableau<unsigned int> Carte::topOrder(const Coordonnees& depart) const
{
    Tableau<unsigned int> result;

double minDist = std::numeric_limits<double>::infinity();


/*
for (int i = 0 ; i < )
    


    TopOrder(Mission A = { a1, a2, ..., ama }, Mission B = { b1, b2, ..., bmb }, Mission C = { c1, c2, ..., cmc }, Point depart):
    mindist ← +∞
    result ← {0, 0, 0}
    pour toutes les missions ai dans A
      pour toutes les missions bj dans B
        pour toutes les missions ck dans C
          si distance(depart, ai) + distance(ai, bj) + distance(bj, ck) < mindist
              mindist ← distance(depart, ai) + distance(ai, bj) + distance(bj, ck)
              result ← {i, j, k}
    retourner result

    */

    return result;
}

std::istream& operator >> (std::istream& is, Mission& mission)
{

    std::string name;
    is >> name;

    int nb;
    is >> nb;

    // Code à compléter...
    
    return is;
}

std::istream& operator >> (std::istream& is, Carte& carte)
{
    int n;
    is >> n;
    if(!is || !(n > 0)) { // détecter une anomalie
        assert(false);
        return is;
    }

    for(int i=0; i<n; i++) {
        Mission mission;
        is >> mission;
        carte._vMission.ajouter(mission);
    }

    return is;
}

