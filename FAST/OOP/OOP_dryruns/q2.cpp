// ---------------------Question # 2---------------------//
// ---------------------Syntax Errors---------------------//
// -----------Do not Run only point out Errors-------------//
#include <iostream>
using namespace std;
class D
{
    int y;
    void walk()
    {
        cout << "walk of D" << endl;
    }

public:
    D(int y1 = 0)
    {
        y1 = y;
    }
}  ;

class A
{

public:
    int x;
    void print()
    {
        cout << "----A----	x:" << x << endl;
    }
    A(int x1 = 0)
    {
        x = x1;
    }
};
class B : A
{
    D x;

public:
    D getx()
    {
        return x;
    }
    virtual void print() = 0;
    B(int x1, int y1) :x(y1), A(x1)
    {
    }
};
class C : B
{
public:
    int x;
    C(int x1 = 0, int x2 = 10, int x3 = 20) : B(x1, x2)//private constructor
    {
        x = x3;
    }
    void print()
    {
        cout << "----C----	x:" << x << endl;
        // A::print(); //private
        B::print(); //private
    }
    void fun()
    {
        cout << "its fun" << endl;
    }
};

int main()
{
    // B *p = new B; //abstract class obj error

    A *q = new A;

    q->print();

    // q->A(); //explicit call to constructor error

    B *ptr = new C; //private inheritance 
    // C *ptr = new C;
    ptr->x = 35; //x is inaccesible

    ptr->print(); //private fun call in there

    ptr->getx().walk();  //private fun call walk

    C *p1 = dynamic_cast<C *>(ptr);  

    (p1->fun()).fun();

    return 0;
}