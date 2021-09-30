/************************************************
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://cria2.uqam.ca/INF3105/lab1/
*************************************************/
#include <limits>
#include <iostream>
#include "point.h"

/************************************************************************
INSTRUCTIONS:
   Suivez rigoureusement les tâches à http://cria2.uqam.ca/INF3105/lab1/.
   NE sautez PAS d'étape !
   Si vous sautez une étape ou tentez d'aller trop rapidement,
   alors vous risquez d'introduire des bogues!
*************************************************************************/

int main1(int argc, const char **args)
{
  std::cout << "Bienvenue au cours INF3105 en C++ !" << std::endl;
  return 0;
}

int main2(int argc, const char **args)
{
  Point point(3, 105);
  std::cout << point;
  std::cout << std::endl; // fin de ligne
  return 0;
}
/*
int main3(int argc, const char** args)
{
  Point point(1.2,5.7);
  std::cout << "point.x=" << point.x << "\tpoint.y=" << point.y << std::endl;
  return 0;
}
*/

int main4(int argc, const char **args)
{
  Point point;
  std::cout << "Entrez un point:" << std::endl;
  std::cin >> point;
  std::cout << "Revoici votre point:" << std::endl;
  std::cout << point << std::endl;
  return 0;
}

int main5(int argc, const char **args)
{
  Point a(0, 0);
  Point b(4, 3);
  double d = a.distance(b);
  std::cout << "Distance(" << a << "," << b << ")=" << d << std::endl;
  return 0;
}

int main(int argc, const char **args)
{
  Point tab[200000];
  float dist;
  float d = std::numeric_limits<float>::max();
  int nb;
  Point a, b;
  std::cin >> nb;

  for (int i = 0; i < nb; i++)
  {
    std::cin >> tab[i];
  }

  for (int i = 0; i < nb; i++)
  {
    for (int j = i + 1; j < nb; j++)
    {
      dist = tab[i].distance(tab[j]);
      if (dist < d)
      {
        d = dist;
        a = tab[i];
        b= tab[j];
      }
    }
  }
  std::cout << "Le distance entre " << a << "et " << b << " la plus petite est : " << d ;


  return 0;
}
