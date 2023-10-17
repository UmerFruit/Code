#include "Headers.h"
using namespace std;
class Int
{
    int a;

public:
    Int()
    {
        a = 5;
    }
    void display()
    {
        cout << a << endl;
    }
    Int (int a)
    {
        this->a = a;
    }
    int operator +(Int m)
    {
        return this->a + m.a;
    }


}; int main()
{
    Int l,m;
    l.display();
    fraction ad
    Int insh = l+m;        // l.operator+(Int m);
    insh.display();
   
}
