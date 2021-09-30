/************************************************
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://cria2.uqam.ca/INF3105/lab1/
  Date : 10 septembre
INSTRUCTIONS:
  Vous devez compléter ce fichier.
*************************************************/

#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(const Point& point)
  : x(point.x), y(point.y) 
{
}

Point::Point(double _x, double _y) 
  : x(_x), y(_y)
{
}

double Point::distance(const Point& point) const {
  
  return sqrt(pow((point.x - x),2)+pow((point.y - y),2));
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


