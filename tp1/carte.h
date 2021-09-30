/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#if !defined(__CARTE_)
#define __CARTE_

#include <string>
#include "coordonnees.h"
#include "tableau.h"

class Mission {
  // À compléter.
  
};

class Carte {
  // À compléter.
  public:
    Tableau<unsigned int> topOrder(const Coordonnees& depart) const;
  
  private:
    Tableau<Mission> _vMission;
    
  friend std::istream& operator >> (std::istream&, Carte&);

};

#endif

