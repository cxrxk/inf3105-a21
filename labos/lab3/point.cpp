/*  Classe Point.
 *  Lab3 -- Tableau dynamique générique
 *  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  http://cria2.uqam.ca/INF3105/lab3/
 */
#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(const Point& point)
  : x(point.x), y(point.y)  {
}

Point::Point(double x_, double y_) 
  : x(x_), y(y_) {
}

double Point::distance(const Point& point) const {
    // À compléter.
    return sqrt(pow((point.x - x),2)+pow((point.y - y),2));
}
bool Point::operator == (const Point& autre) const{
  return x==autre.x && y == autre.y;
}
std::ostream& operator << (std::ostream& os, const Point& point) {
    os << "(" << point.x << "," << point.y << ")";
    return os;
}

std::istream& operator >> (std::istream& is, Point& point) {
    char po, vir, pf;
    is >> po;
    if(is){
        is >> point.x >> vir >> point.y >> pf;
        assert(po=='(');
        assert(vir==',');
        assert(pf==')');
    }
    return is;
}

