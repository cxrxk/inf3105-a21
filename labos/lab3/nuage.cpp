/*  Classe Nuage.
 *  Lab3 -- Tableau dynamique générique
 *  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  http://cria2.uqam.ca/INF3105/lab3/
 */
#include "nuage.h"
#include <limits.h>




// Retourne une référence sur point le plus proche de p dans le nuage
const Point& Nuage::proche(const Point& p) const{
    // À compléter.
    int index = -1 ;
    double minD = 10000000;
    double distance ;
    for (int i = 0 ; i < points.taille();i++) {
        distance = p.distance(points[i]);
        if (distance < minD){
            minD = distance;
            index = i ;
        }

    }
    return points[index];
}

// Retourne un sous-nuage à l'intérieur d'un rayon autour de p
Nuage Nuage::proches(const Point& p, double rayon) const{
    // À compléter.
   
    Nuage ng ;
    for (int i = 0 ; i < points.taille();i++){
        double d = p.distance(points[i]);
        if (d <= rayon){
            ng.points.ajouter(points[i]);
        }
    }
    return ng;
}

// Retourne un sous-nuage contenant les n points les plus proches de p
Nuage Nuage::nproches(const Point& p, int n) const{
  Nuage cp = *this; //copie du nuage
  Nuage st =  Nuage() ;//sous nuage
if (n < points.taille()){

  for (int i = 0 ; i <=n ; i++){
      Point p2 = cp.proche(p);
      st.points.ajouter(p2);
      int index = cp.points.chercher(p2);
      cp.points.enlever(index);
  }
}else st = cp ;
    return st;
}

// Écriture d'un nuage de points
std::ostream& operator << (std::ostream& os, const Nuage& nuage){
    for(int i=0;i<nuage.points.taille();i++)
        os << nuage.points[i] << std::endl;
    return os;
}

// Lecture d'un nuage de points
std::istream& operator >> (std::istream& is, Nuage& nuage){
    nuage.points.vider();
    while(is){
        Point p;
        is >> p >> std::ws;
        if(is) // Détection de la fin du fichier
            nuage.points.ajouter(p);
    }
    return is;
}
