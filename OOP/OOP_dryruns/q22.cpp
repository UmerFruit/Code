//-------------Question----------//
#include <iostream>
using namespace std;
class Point
{
    int x, y;

public:
    Point(int x=0, int y=0)
    {
        this->x = x;
        Point::y = y;
        (*this)();
    }

    void operator()()
    {
        cout<<" ("<<x<<", "<<y<<") "<<endl;
    }

    Point& operator()(int y)
    {
        this->y = y;
        return *this;
    }

    ~Point()
    {
        cout<<"Point is going";
        (*this)();
    }
}p3;

int main()
{
    Point *p = new Point(5, 6);
    static Point p1(p3);
    p1(9)(8);
    delete p;
    Point p2(7);
    cout<<"----------"<<endl;
    return 0;
}