#include <iostream>
using namespace std;
class Point{
  int x, y;
public:
  Point(int a=0, int b=0)
  {
    x=a;
    y=b;
    print();
  }
  void print()
  {
    cout<<" ("<<x<<","<<y<<") " <<endl;
  }
  ~Point()
  {
    cout<<"Point is going"<<endl;
  }
  
};
class Circle
{
  Point center;
  float radius;
public:
  Circle():center(0,0)
  {
    radius=0;
    cout<<"The basic circle"<<endl;
  }
  Circle(Point p):center(p){ }
  
  Circle(const Circle & c):center(c.center), radius(c.radius)
  {
    cout<<"The copied circle";
    center.print();
  }
  ~Circle()
  {
    cout<<"Circle is going"<<endl;
  }

};

int main() 
{
  Point p1;
  Circle c1;
  static Circle c2(p1);
  Circle c3(c2);
  return 0;
}
/*
(0,0)
(0,0)
The basic circle
Point is going
The copied circle (0,0)

Circle is going
Point is going
Circle is going
Point is going
Point is going
Circle is going
Point is going
*/