#include "point.h"

class Rectangle{
  public:
    Rectangle();
    Rectangle(const Point& p1, const Point& p2);
  private:
    Point point1, point2;
};

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(const Point& p1, const Point& p2)
 : point1(p1)
{
    point2 = p2;
}

int main(){
    Rectangle* r1 = new Rectangle();
    Rectangle* r2 = new Rectangle(Point(0,0), Point(10,10));
    Rectangle* r3 = new Rectangle();
    *r3 = *r2;
    r1 = r3;// il faut oubien enlever ca oubien recuperer laddress dans une autre variable et la delete
    
    delete r1;
    delete r2;
    delete r3;
    return 0;
}